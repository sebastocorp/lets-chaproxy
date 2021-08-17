FROM debian:buster-slim as base

# Install base packages
RUN apt-get update --yes && \
    apt-get install --yes --no-install-recommends \
        cron \
        certbot \
        haproxy

# Prepare app directory
RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

# Configure entrypoint
COPY build/bin/docker-entrypoint.sh /usr/local/bin/
RUN chmod 0775 /usr/local/bin/docker-entrypoint.sh
ENTRYPOINT ["docker-entrypoint.sh"]
CMD ["lets", "watch"]


FROM base as build
# Install base packages
RUN apt-get update --yes && \
    apt-get install --yes \
        g++ \ 
        make

# Build the application
COPY . /usr/src/app/
RUN make


FROM base as application
COPY --from=build /usr/src/app/build/ /usr/src/app/

# Prepare executable permissions
RUN chmod -R 0775 /usr/src/app/bin

RUN ln -s /usr/src/app/bin/service /usr/local/bin/service && \
    chmod +x /usr/local/bin/service

# Link the lets CLI
RUN ln -s /usr/src/app/bin/lets /usr/local/bin/lets && \
    chmod +x /usr/local/bin/lets


FROM application as debug
# Install debug packages
RUN apt-get update --yes && \
    apt-get install --yes --no-install-recommends \
        bash \
        procps

FROM alpine:3.15.0

RUN apk update 
RUN apk add --no-cache mariadb mariadb-client

RUN mkdir /clsaad_container_data

COPY ./data/start.sh /clsaad_container_data/start.sh

RUN chmod +x /clsaad_container_data/start.sh

CMD ["/bin/sh", "/clsaad_container_data/start.sh"]

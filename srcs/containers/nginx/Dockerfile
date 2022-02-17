FROM alpine:3.14.3

EXPOSE 443

ARG DOCKER_TLS_KEY
ARG DOCKER_TLS_CERTIFICATE

RUN apk update 
RUN apk add --no-cache nginx openssl

# Configuring NGINX

RUN mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.bak
COPY ./data/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /var/www/html

# Configuring SSL
RUN mkdir -p /etc/nginx/ssl
WORKDIR /etc/nginx/ssl

COPY $DOCKER_TLS_KEY /etc/nginx/ssl/server.key
COPY $DOCKER_TLS_CERTIFICATE /etc/nginx/ssl/server.crt

RUN chmod 400 server.key
RUN chmod 444 server.crt

CMD ["nginx", "-g", "daemon off;"]

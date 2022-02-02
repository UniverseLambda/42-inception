FROM alpine:3.15.0

RUN apk update 
RUN apk add --no-cache nginx openssl bash

# FROM debian:buster

# RUN apt update && apt -y upgrade
# RUN apt -y install nginx openssl

# Configuring NGINX

RUN mv /etc/nginx/nginx.conf /etc/nginx/nginx.conf.bak
COPY ./data/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /var/www/html
RUN echo "hellooooo" > /var/www/html/index.html

# Configuring SSL
RUN mkdir -p /etc/nginx/ssl
WORKDIR /etc/nginx/ssl
RUN openssl req -new -x509 -nodes -newkey rsa:4096 -keyout server.key -out server.crt -subj "/C=HR/ST=Grand Line/L=Marineford/O=.../OU=.../CN=.../emailAddress=..."
RUN chmod 400 server.key
RUN chmod 444 server.crt

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
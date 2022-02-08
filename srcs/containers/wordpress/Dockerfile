FROM alpine:3.15.0

RUN apk update 
RUN apk add --no-cache php8 php8-fpm php8-mysqli bash

COPY ./data/www.conf /etc/php8/php-fpm.d/www.conf

EXPOSE 9000

ARG USER_NAME
ARG USER_PASSWORD

RUN mkdir /clsaad_container_data
WORKDIR /clsaad_container_data
COPY ./data/wp-config.php /clsaad_container_data/wp-config.php
COPY ./data/start.sh /clsaad_container_data/start.sh

RUN wget https://wordpress.org/latest.zip

RUN echo $USER_NAME

RUN sed -i "s|%%WORDPRESS_DB_USER%%|$USER_NAME|" /clsaad_container_data/wp-config.php
RUN sed -i "s|%%WORDPRESS_DB_PSSWD%%|$USER_PASSWORD|" /clsaad_container_data/wp-config.php

CMD ["bash", "/clsaad_container_data/start.sh"]

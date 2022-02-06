FROM alpine:3.15.0

RUN apk update 
RUN apk add --no-cache php7 php7-fpm

COPY ./data/www.conf /etc/php7/php-fpm.d/www.conf

EXPOSE 9000

RUN mkdir /clsaad_container_data
WORKDIR /clsaad_container_data

RUN wget https://wordpress.org/latest.zip
COPY ./data/wp-config.php /clsaad_container_data/wp-config.php

CMD ["php-fpm7", "-F", "-R"]

FROM alpine:3.15.0

RUN apk update 
RUN apk add --no-cache php7 php7-fpm # php7-opcache

COPY ./data/www.conf /etc/php7/php-fpm.d/www.conf

EXPOSE 9000

RUN mkdir -p /var/www/html

CMD ["php-fpm7", "-F", "-R"]

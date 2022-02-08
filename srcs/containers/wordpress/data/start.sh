#!/bin/sh

# Checking if we need to setup mysql database
if [[ ! -d /var/www/html/wordpress ]]; then
    mkdir -p /var/www/html/wordpress
    unzip /clsaad_container_data/latest.zip -d /var/www/html
    cp /clsaad_container_data/wp-config.php /var/www/html/wordpress
fi

php-fpm8 -F -R

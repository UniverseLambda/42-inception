#!/bin/bash

# Checking if we need to setup mysql database
if [[ ! -d /var/lib/mysql/LuffyForEver_Wordpress ]]; then
    mysql_install_db --ldata=/var/lib/mysql --user=mysql

    service mysql start

    mysql -u root -e "CREATE DATABASE LuffyForEver_Wordpress;
    CREATE USER '$USER_NAME' IDENTIFIED BY '$USER_PASSWORD';
    GRANT ALL PRIVILEGES ON LuffyForEver_Wordpress.* TO '$USER_NAME'@'%';
    UPDATE mysql.user SET plugin = '' WHERE user = 'root' AND host = 'localhost';
    FLUSH PRIVILEGES;"

    mysql -u root LuffyForEver_Wordpress < /clsaad_container_data/wp-db.mysql
    
    mysqladmin -u root password "$ROOT_PASSWORD"

    service mysql stop

fi

/bin/sh /usr/bin/mysqld_safe

#!/bin/sh

# Checking if we need to setup mysql database
if [[ ! -d /var/lib/mysql ]]; then
    mysql_install_db --ldata=/var/lib/mysql
    service mysql start
    mysqladmin -u root password toor
    mysql -u root -e "CREATE DATABASE LuffyForEver_Wordpress; CREATE USER '$USER_NAME' IDENTIFIED BY '$USER_PASSWORD'; GRANT ALL PRIVILEGES ON LuffyForEver_Wordpress.* TO '$USER_NAME';"
    mysql -u root -e "CREATE USER 'SupremCommander' IDENTIFIED BY '$ADMIN_PASSWORD'; GRANT ALL, GRANT_OPTION ON * TO '$ADMIN_PASSWORD';"
    service mysql stop
fi

/bin/sh /usr/bin/mysqld_safe

#!/bin/sh

# Checking if we need to setup mysql database
if ! [ "$(find /var/lib/mysql -mindepth 1 -print -quit 2>/dev/null)" ]; then
    touch /var/lib/mysql/mdr
    mysql_install_db --ldata=/var/lib/mysql --user=mysql

    service mysql start

    echo "0"
    mysql -u root -e "CREATE DATABASE LuffyForEver_Wordpress;
    CREATE USER '$USER_NAME' IDENTIFIED BY '$USER_PASSWORD';
    GRANT ALL PRIVILEGES ON LuffyForEver_Wordpress.* TO '$USER_NAME'@'%';
    CREATE USER 'suprem_commander'@'%' IDENTIFIED BY '$ADMIN_PASSWORD';
    GRANT ALL PRIVILEGES ON *.* TO 'suprem_commander'@'%' WITH GRANT OPTION;
    FLUSH PRIVILEGES;"

    service mysql stop
fi

/bin/sh /usr/bin/mysqld_safe

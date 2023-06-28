#!/bin/bash 

if [ ! -d /var/lib/mysql/${WORDPRESS_DB_NAME} ]; then
    echo "Start settings MaridDB..."

    mariadb-install-db

    service mariadb start

    mysql -u root -e "CREATE DATABASE $WORDPRESS_DB_NAME;"
    mysql -u root -e "CREATE user $WORDPRESS_DB_USER@'%' identified by '$WORDPRESS_DB_PASSWORD';"
    mysql -u root -e "GRANT ALL PRIVILEGES ON $WORDPRESS_DB_NAME.* TO $WORDPRESS_DB_USER@'%';"
    mysql -u root -e "FLUSH PRIVILEGES;"

    service mariadb stop

    echo "MaridDB settings complete"
else
    echo "MaridDB already setted"
fi

mysqld --user=root
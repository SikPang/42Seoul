#!/bin/bash 

mariadb-install-db

service mariadb start

mysql -u root -p -e "CREATE DATABASE mydb;"
mysql -u root -p -e "CREATE USER 'kwsong'@'mariadb' IDENTIFIED BY '1234';"
mysql -u root -p -e "GRANT ALL ON wordpress.* TO 'kwsong'@'mariadb' ;"
mysql -u root -p -e "FLUSH PRIVILEGES;"
mysql -u root -p -e "EXIT;"

service mariadb stop

mysqld --user=root



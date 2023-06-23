#!/bin/bash 

#mariadb-install-db

mysqld --user=root

mysql -u root -p
CREATE DATABASE mydb;
CREATE USER 'kwsong'@'mariadb' IDENTIFIED BY '1234';
GRANT ALL ON wordpress.* TO 'kwsong'@'mariadb' ;
FLUSH PRIVILEGES;
EXIT;


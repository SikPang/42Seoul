#!/bin/bash 

mariadb-install-db

mysqld --user=root

mysql -u root -p < ./my.sql


# select Host,Db,User from mysql.db;
#!/bin/bash 

mariadb-install-db

mysqld --user=mysql

mysql -u mysql -p < ./my.sql

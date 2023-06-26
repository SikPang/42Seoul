#!/bin/bash 

tar -xzf /tmp/wordpress.tar.gz -C /var/www/html/

chown www-data: /var/www/html/ -R

/usr/sbin/php-fpm7.4 -F
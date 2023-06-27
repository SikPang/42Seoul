#!/bin/bash 

if [ ! -c /var/www/html/wordpress/index.php ]; then
    wp core download --allow-root --path=/var/www/html/wordpress/
    
    mv /var/www/html/wp-config.php /var/www/html/wordpress/wp-config.php 
    
    chown www-data: /var/www/html/ -R

    wp core install --url=localhost --title=my_blog --admin_email=kwsong@42.fr --admin_password=1234 --admin_name=song --allow-root --path=/var/www/html/wordpress/
fi

/usr/sbin/php-fpm7.4 -F
#!/bin/bash 

if [ ! -e /var/www/html/wordpress/index.php ]; then
    wp core download --allow-root --path=/var/www/html/wordpress/
    mv /var/www/html/wordpress/wp-config-sample.php  /var/www/html/wordpress/wp-config.php 
    #mv /var/www/html/wp-config.php /var/www/html/wordpress/wp-config.php 
    
    chown www-data: /var/www/html/ -R
    
    wp config create --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --dbhost=$WORDPRESS_DB_HOST --locale=en_US --allow-root --path=/var/www/html/wordpress/
    wp core install --url=localhost --title=my_blog --admin_email=kwsong@42.fr --admin_password=1234 --admin_name=song --allow-root --path=/var/www/html/wordpress/
    wp user create human human@42.fr --user_pass=1234 --role=subscriber --allow-root --path=/var/www/html/wordpress/
fi

/usr/sbin/php-fpm7.4 -F
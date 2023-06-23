FROM	debian:bullseye

RUN 	apt-get -y update \
	#&& apt-get -y install curl \
	&& apt-get -y install php7.4 \
	&& apt-get -y install php7.4-fpm php7.4-mysql mariadb-client wget
	#&& apt-get -y install dumb-init

VOLUME	["/home/kwsong/data/wordpress"]

EXPOSE	9000

RUN	mkdir /run/php \
	&& chmod 777 /run/php

RUN wget http://wordpress.org/latest.tar.gz -P /var/www/html \
	&& tar -xzf /var/www/html/latest.tar.gz

RUN chown www-data: /var/www/html/ -R

COPY	wp-config.php /etc/php/7.4/fpm/pool.f/wp-config.php
COPY	www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY	my.cnf /etc/mysql/my.cnf

#ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["/usr/sbin/php-fpm7.4", "-F"]


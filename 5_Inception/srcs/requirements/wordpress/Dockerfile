FROM	debian:bullseye

RUN 	apt-get -y update \
		&& apt-get -y install dumb-init

RUN		apt-get -y install php7.4 php7.4-fpm php7.4-mysql curl \
		&& mkdir /run/php \
		&& chmod 777 /run/php \
		&& curl -o /tmp/wordpress.tar.gz -SL https://wordpress.org/latest.tar.gz

COPY	conf/wp-config.php /var/www/html/wordpress/wp-config-sample.php
COPY	conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY	tools/settings.sh .

RUN		chmod 777 settings.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["./settings.sh"]

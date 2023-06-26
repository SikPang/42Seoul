FROM	debian:bullseye

RUN 	apt-get -y update \
		&& apt-get -y install dumb-init

RUN		apt-get -y install php7.4 php7.4-fpm php7.4-mysql curl

VOLUME	["/home/kwsong/data/wordpress"]

EXPOSE	9000

RUN	mkdir /run/php \
	&& chmod 777 /run/php

RUN curl -o /tmp/wordpress.tar.gz -SL https://wordpress.org/latest.tar.gz

COPY	conf/wp-config.php /etc/php/7.4/fpm/pool.f/wp-config.php
COPY	conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY	conf/my.cnf /etc/mysql/my.cnf
COPY	tools/settings.sh .

RUN		chmod 777 settings.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["./settings.sh"]


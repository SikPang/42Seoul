FROM	debian:bullseye

RUN 	apt-get -y update \
		&& apt-get -y install dumb-init

RUN		apt-get -y install mariadb-server

RUN		mkdir /run/mysqld \
		&& chmod 777 /run/mysqld \
		&& chmod 777 /var/lib/mysql \
		&& rm -rf /var/lib/mysql/aria_log_control

COPY	tools/settings.sh .
COPY	tools/my.sql .
#COPY	conf/my.cnf /etc/mysql/my.cnf
COPY	conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN		chmod 777 ./settings.sh

EXPOSE		3306

VOLUME		["/home/kwsong/data/mariadb"]

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD		["./settings.sh"]


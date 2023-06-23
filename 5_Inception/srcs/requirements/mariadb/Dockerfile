FROM		debian:bullseye

RUN		apt-get -y update \
		#&& apt-get -y install dumb-init \
		&& apt-get -y install mariadb-server \
		&& mkdir /run/mysqld \
		&& chmod 777 /run/mysqld \
		&& chmod 777 /var/lib/mysql

RUN		rm -rf /var/lib/mysql/aria_log_control

#ENV		MYSQL_DATA=mydb \
#		MYSQL_ROOT_PASSWORD=root

#COPY		settings.sh .
COPY		my.cnf /etc/mysql/my.cnf

EXPOSE		3306

VOLUME		["/home/kwsong/data/mariadb"]

#ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD		["mysqld", "--user=root"]

FROM	debian:bullseye

RUN 	apt-get -y update \
		&& apt-get -y install dumb-init

RUN 	apt-get -y install nginx openssl \
		&& mkdir -p /etc/nginx/ssl/ \
		&& chmod 777 /etc/nginx/ssl
		
RUN		echo "\n\n\n\n\n\n\n" | openssl req -x509 -days 365 -nodes -newkey rsa:2048 -keyout /etc/nginx/ssl/nginx.pem -out /etc/nginx/ssl/nginx.crt

COPY	conf/default /etc/nginx/sites-enabled/default

ENTRYPOINT ["/usr/bin/dumb-init"]

CMD		["/usr/sbin/nginx", "-g", "daemon off;"]

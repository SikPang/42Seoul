FROM debian:bullseye

RUN 	apt-get -y update \
		&& apt-get -y install dumb-init

RUN 	apt-get -y install nginx

VOLUME ["/home/kwsong/data/wordpress"]

COPY	conf/default /etc/nginx/sites-enabled/default
COPY	tools/server.crt /etc/nginx/ssl/nginx.crt
COPY	tools/server_pkey.pem /etc/nginx/ssl/nginx.pem

EXPOSE 443

ENTRYPOINT ["/usr/bin/dumb-init"]

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]


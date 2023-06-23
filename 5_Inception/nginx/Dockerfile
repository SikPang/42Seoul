FROM debian:bullseye

RUN apt-get -y update \
	&& apt-get -y install nginx
	#&& apt-get -y install openssl\
	#&& apt-get -y install dumb-init

VOLUME ["/home/kwsong/data/wordpress"]

#COPY	nginx.conf /etc/nginx/nginx.conf
COPY	conf /etc/nginx/sites-enabled/default

EXPOSE 8080

#ENTRYPOINT ["/usr/bin/dumb-init"]

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]


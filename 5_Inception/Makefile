NAME		= .inception
DOMAIN_NAME	= kwsong.42.fr

all		: $(NAME)

$(NAME) :
	@touch $(NAME)
	@if ! grep -e '^127.0.0.1\s\+$(DOMAIN_NAME)' /etc/hosts; then \
		echo "--- Add domain name ---"; \
		sudo sh -c 'echo "127.0.0.1    $(DOMAIN_NAME)" >>  /etc/hosts'; \
	else \
		echo "--- Domain name already setted ---"; \
	fi
	cd ./srcs && docker-compose up
down	: 
	cd ./srcs && docker-compose down
	@rm -rf $(NAME)

rmi		:
	docker image prune -a

clean	:
	make down
	docker system prune -a

fclean	:
	make clean
	sudo rm -rf /home/kwsong/data/*

re		:
	make fclean
	make all

em	:
	docker exec -it mariadb bash

en	:
	docker exec -it nginx bash

ew	:
	docker exec -it wordpress bash

.PHONY	: all down rmi clean fclean re em en ew
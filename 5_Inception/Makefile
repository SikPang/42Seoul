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
	mkdir -p /home/kwsong/data/wp;
	mkdir -p /home/kwsong/data/db;
	cd ./srcs && docker-compose up --build

down	: 
	cd ./srcs && docker-compose down
	@rm -rf $(NAME)

clean	:
	make down
	docker system prune -a

fclean	:
	make clean
	docker volume rm -f srcs_db srcs_wp
	sudo rm -rf /home/kwsong/data/wp/*
	sudo rm -rf /home/kwsong/data/db/*

re		:
	make fclean
	make all

em	:
	docker exec -it mariadb bash

en	:
	docker exec -it nginx bash

ew	:
	docker exec -it wordpress bash

.PHONY	: all down clean fclean re em en ew
NAME	= .inception

all		: $(NAME)

$(NAME) :
	@touch $(NAME)
	cd ./srcs && docker-compose up

down	: 
	cd ./srcs && docker-compose down
	@rm $(NAME)

rmi		:
	docker image prune -a

clean	:
	make down
	docker system prune -a

fclean	:
	make clean
	cd /home/kwsong/data && sudo rm -rf *

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
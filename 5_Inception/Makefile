up : 
		cd ./srcs && docker-compose up

down : 
		cd ./srcs && docker-compose down

clean :
		make down
		docker image prune -a

fclean:
		make down
		docker system prune -a


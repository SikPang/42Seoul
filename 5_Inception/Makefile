up : 
		cd ./srcs && docker-compose up

clean : 
		cd ./srcs && docker-compose down

fclean :
		make clean
		docker image prune -a

destroy:
		docker container prune

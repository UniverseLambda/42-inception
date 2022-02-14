.PHONY: start stop clean fclean re bootstrap-vm
.DEFAULT: start

all: start

start:
	mkdir -p $(HOME)/data
	cd ./srcs/ && docker compose up --build -d

stop:
	cd ./srcs/ && docker compose down

clean: stop

fclean: clean

re: stop start

bootstrap-vm:
	sudo sh -c "echo '127.0.0.1  clsaad.42.fr' >> /etc/hosts"

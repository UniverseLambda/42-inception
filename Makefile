.PHONY: start stop clean fclean re bootstrap-vm
.DEFAULT: start

all: start

start:
	mkdir -p /home/clsaad/data
	mkdir -p /home/clsaad/data/wordpress-files
	mkdir -p /home/clsaad/data/wordpress-db
	cd ./srcs/ && docker compose up --build -d

stop:
	cd ./srcs/ && docker compose down

clean: stop

fclean: clean

re: stop start

bootstrap-vm:
	sudo pacman -Syyu --noconfirm
	sudo pacman -S --noconfirm  docker docker-compose
	sudo systemctl enable docker
	sudo chmod 666 /var/run/docker.sock
	sudo sh -c "echo '127.0.0.1  clsaad.42.fr' >> /etc/hosts"

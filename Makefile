.PHONY: start stop clean re bootstrap-vm
.DEFAULT: start

all: start

start:
	cd ./srcs/ && docker compose up --build -d

stop:
	cd ./srcs/ && docker compose down

clean: stop

fclean: clean

re: stop start

bootstrap-vm:
	mkdir -p $(HOME)/data

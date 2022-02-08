FROM debian:buster

EXPOSE 3306

RUN apt update && apt -y upgrade
RUN apt install -y mariadb-server # mariadb-client

RUN mkdir /clsaad_container_data

COPY ./data/start.sh /clsaad_container_data/start.sh

RUN chmod +x /clsaad_container_data/start.sh

RUN sed -i "s|#port |port  |" /etc/mysql/mariadb.conf.d/50-server.cnf
RUN sed -i "s|bind-address *= 127\\.0\\.0\\.1|bind-address = 0.0.0.0|" /etc/mysql/mariadb.conf.d/50-server.cnf
# RUN sed -i "s|#bind-address=0.0.0.0|bind-address=0.0.0.0|" /etc/my.cnf.d/mariadb-server.cnf
# RUN sed -i "s|skip-networking|#skip-networking|" /etc/my.cnf.d/mariadb-server.cnf

# CMD ["tail", "-f"]
CMD ["/bin/sh", "/clsaad_container_data/start.sh"]

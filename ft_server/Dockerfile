FROM debian:buster

RUN apt update && \
            apt install -y nginx openssl mariadb-server php-fpm php-mysql

COPY ./srcs/default /etc/nginx/sites-available
COPY ./srcs/init.sql /tmp/init.sql
COPY ./srcs/index.html /var/www/html/
COPY ./srcs/wordpress/ /var/www/html/wordpress
COPY ./srcs/phpmyadmin/ /var/www/html/phpmyadmin

RUN service mysql start && \
    mysql -u root --password= < /tmp/init.sql

RUN openssl req -x509 -nodes -days 365 \
   -newkey rsa:2048 -subj "/C=SP/ST=Spain/L=Madrid/0=42/CN=127.0.0.1" \
   -keyout /usr/local/share/default.key \
   -out /usr/local/share/default.crt && \
   openssl dhparam -out /etc/nginx/dhparam.pem 1000

EXPOSE 80 443

CMD service nginx start && \
    service mysql start && \
    service php7.3-fpm start && \
    bash
FROM arm64v8/php:7.1-apache
RUN docker-php-ext-install mysqli pdo pdo_mysql
RUN a2enmod rewrite
RUN apt-get update -y && apt-get install -y libpng-dev
RUN docker-php-ext-install gd
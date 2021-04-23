FROM python:3

WORKDIR /usr/src/app

COPY index.html index.html
COPY ./js/ ./js/

CMD [ "python", "-m", "http.server", "80" ]
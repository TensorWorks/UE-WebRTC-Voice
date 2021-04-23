docker build -t bidiwebserver:latest ./Web/
docker run --rm -it -p 80:80 bidiwebserver:latest
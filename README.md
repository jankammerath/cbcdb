
## copy header files from the container ##
Copy the header files like this to be able to use them on the container host:
docker cp cbcdb:/usr/include/libconfig.h++ .header/libconfig.h++
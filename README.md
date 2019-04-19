# CBCDB - Cryptographic Blockchain Database

# Architecture

## URL Structure

GET /chain                              lists all chains in the collection
GET /chain/mychainname                  lists all blocks in the chain "mychainname"
GET /chain/mychainname/myblockid        lists the block "myblockid" in the chain "mychainname"

Reserved internal chain names: user, peer

## Development information
Development of cbcdb can be done inside the docker container

### copy header files from the container
Copy the header files like this to be able to use them on the container host:
docker cp cbcdb:/usr/include/libconfig.h++ .header/libconfig.h++
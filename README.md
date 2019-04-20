# CBCDB - Cryptographic Blockchain Database

# Architecture

## URL Structure

GET /                           all chains in the collection
GET /mychainname                all blocks in the chain "mychainname"
GET /mychainname/myblockid      the block "myblockid" in the chain "mychainname"

Reserved internal chain names: user, peer

## File structure

The following file structure is used inside the storagePath.

/chain                          where all the chains are
/chain/mychainname              folder for the chain "mychainname"
/chain/mychainname/block        folder for all blocks in "mychainname"


## Development information
Development of cbcdb can be done inside the docker container

### copy header files from the container
Copy the header files like this to be able to use them on the container host:
docker cp cbcdb:/usr/include/libconfig.h++ .header/libconfig.h++
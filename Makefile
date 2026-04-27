SERVER = server
CLIENT = client

SRC_S = server.c utils.c
SRC_C = client.c utils.c

OBJ_S = $(SRC_S:%.c=%.o)
OBJ_C = $(SRC_C:%.c=%.o)

%.o : %.c
	cc -Wall -Werror -Wextra -c $< -o $@

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S)
	cc -Wall -Werror -Wextra $(OBJ_S) -o $(SERVER)

$(CLIENT) : $(OBJ_C)
	cc -Wall -Werror -Wextra $(OBJ_C) -o $(CLIENT)

clean :
	rm -f $(OBJ_S) $(OBJ_C)

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re bonus

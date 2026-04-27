SERVER = server
CLIENT = client

INCLUDE = minitalk.h

SRC_S = server.c utils.c
SRC_C = client.c utils.c

OBJ_S = $(SRC_S:%.c=%.o)
OBJ_C = $(SRC_C:%.c=%.o)

%.o : %.c
	gcc -Wall -Werror -Wextra -I $(INCLUDE) -c $< -o $@

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S)
	gcc -Wall -Werror -Wextra -I $(INCLUDE) $(OBJ_S) -o $(SERVER)

$(CLIENT) : $(OBJ_C)
	gcc -Wall -Werror -Wextra -I $(INCLUDE) $(OBJ_C) -o $(CLIENT)

clean :
	rm -f $(OBJ_S) $(OBJ_C)

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re bonus

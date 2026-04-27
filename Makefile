SERVER = server
CLIENT = client

SRC = server.c client.c utils.c
INCLUDE = minitalk.h

OBJ_S = $(SRC:%.c = %.o)

%.o : %.c
	gcc -Wall -Error -Extra -I $(INCLUDE) -c $< -o $@

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S)
	gcc -Wall -Werror -Wextra -I $(INCLUDE) $(OBJ_S) -o $(SERVER)

$(CLIENT) : $(OBJ_S)
	gcc -Wall -Werror -Wextra -I $(INCLUE) $(OBJ_S) -o $(CLIENT)

clean : $(OBJ_S)
	rm -f $(OBJ_S)

fclean : clean
	rm -f $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re bonus

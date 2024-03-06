SRCS =	server.c
SRCC =	client.c
LIBFT = libft.a

NAMES = server
NAMEC = client

RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all:	$(NAMEC) $(NAMES)

$(NAMEC):
	make -C libft
	cc $(CFLAGS) $(SRCC) libft/libft.a -o $(NAMEC)

$(NAMES):
	make -C libft
	cc $(CFLAGS) $(SRCS) libft/libft.a -o $(NAMES) 

clean:
		make clean -C libft

fclean: clean
		make fclean -C libft
		$(RM) $(NAMES)
		$(RM) $(NAMEC)

re:		fclean all


.PHONY: all clean fclean re

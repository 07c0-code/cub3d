NAME	:= cub3d
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iminilibx-linux -g3 -fsanitize=address
MLXFLG	:= -lXext -lX11 -Lminilibx-linux
MLXLIB	:= minilibx-linux/libmlx.a
MLXDIR	:= minilibx-linux
LIBFT	:= libft/lib/libft.a
LFTDIR	:= libft
RM		:= rm -rf
SRC		:=
OBJ		:= ${SRC:.c=.o}
BNOBJ	:= ${BNSRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ} ${MLXLIB} ${LIBFT}
	${CC} ${OBJ} ${CFLAGS} ${MLXFLG} ${LIBFT} ${MLXLIB} -o ${NAME}

submodules:
	git submodule init && git submodule update

${MLXLIB}:	submodules
	make -C ${MLXDIR}

${LIBFT}:	submodules
	make -C ${LFTDIR}

clean:
	${RM} ${OBJ}
	cd ${LFTDIR} &&	make clean
	cd ${MLXDIR} &&	make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT}
	${RM} ${MLXLIB}

re: fclean all

.PHONY:	all clean fclean re bonus

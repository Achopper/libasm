# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achopper <achopper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 17:33:47 by achopper          #+#    #+#              #
#    Updated: 2021/05/04 20:21:10 by achopper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
AS = nasm
ASMFL = -f macho64 -g -l dc.list
OBJ = ft_write.o ft_read.o ft_strlen.o ft_strcmp.o ft_strcpy.o ft_strdup.o

all:		${NAME}

%.o: 		%.s
	${AS} ${ASMF} $< ${DEPFLAGS}

DEPS  := $(patsubst %.o,%.d,${OBJ})
-include ${DEPS}
DEPFLAGS = ${ASMFL} -MF $(@:.o=.d)

${NAME}:	${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

test:		main.c
	gcc main.c ${NAME}

clean:
	-rm -f ${OBJ} ${DEPS}

fclean:
	-rm -f ${NAME}

re:			fclean all

.PHONY:		clean fclean re all
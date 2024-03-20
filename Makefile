##
## EPITECH PROJECT, 2024
## RUSH03
## File description:
## Makefile
##

CC 			= 	g++

NAME		=	arcade

#-------- src --------#
SRC			:= 	main.cpp	\
				Core.cpp

VPATH		:=	src/	\
				src/core

vpath %.c $(VPATH)

BUILD_DIR	=	build

OBJ			=	$(SRC:%.cpp=$(BUILD_DIR)/%.o)

IFLAGS		=	$(foreach dir,$(VPATH),-I $(dir))
CPPFLAGS	=	-Wall -Wextra $(IFLAGS)

TMP_FILES	=	*.gcno					\
    			*.gcda					\
    			vgcore.*				\
    			*.log					\
    			temp.txt				\
    			-r $(BUILD_DIR)			\
    			$(OBJ)

# ------ DISPLAY -------- #

ECHO 		= echo
C_RESET 	= \033[00m
C_RED		= \e[31m
C_GREEN 	= \e[32m
C_YELLOW 	= \e[33m
C_BLUE		= \e[34m
C_PINK		= \e[35m
C_FULL_RED	= \e[41m
# ----------------------- #

all:	$(NAME)

%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

%.cpp:
	@ $(ECHO) "$(C_RED)[KO] -> $@$(C_RESET)"

$(BUILD_DIR)/%.o: %.cpp
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS)
	@ $(ECHO) "$(C_GREEN)[OK] -> $<$(C_RESET)"

$(NAME):  $(OBJ)
	@ $(CC) -o $@ $^ $(CPPFLAGS)
	@ $(ECHO) "$(C_PINK)|==========> $(NAME) compiled. <==========|$(C_RESET)"

clean:
	@ $(RM) $(TMP_FILES)

fclean:		clean
	@ $(RM) $(NAME)

re:		fclean all

debug: CFLAGS += -g
debug: CFLAGS += -Werror
debug: re

.PHONY: all re clean fclean debug

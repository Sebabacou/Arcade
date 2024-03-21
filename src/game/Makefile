##
## EPITECH PROJECT, 2024
## RUSH03
## File description:
## Makefile
##

CC 			= 	g++
LD			=	ld

NAME		=	libtemplate.so

#-------- src --------#
SRC			:= 	template.cpp

VPATH		:=	./
VPATH		+=	../common/
VPATH		+=	template/

vpath %.cpp $(VPATH)

BUILD_DIR	=	../../build/game

OBJ			=	$(SRC:%.cpp=$(BUILD_DIR)/%.o)

IFLAGS		=	$(foreach dir,$(VPATH),-I $(dir))
CPPFLAGS	=	-Wall -Wextra $(IFLAGS) -f elf64 -fPIC
LDFLAGS		=	-shared

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
	@ $(CC) -c $< -o $@ $(CPPFLAGS)
	@ $(ECHO) "$(C_GREEN)[OK] -> $<$(C_RESET)"

$(NAME):  $(OBJ)
	@ $(LD) -o $@ $^ $(LDFLAGS)
	@ $(ECHO) "$(C_PINK)|==========> $(NAME) compiled. <==========|$(C_RESET)"

clean:
	@ $(RM) $(TMP_FILES)

fclean:		clean
	@ $(RM) $(NAME)

re:		fclean all

debug: CPPFLAGS += -g
debug: CPPFLAGS += -Werror
debug: re

.PHONY: all re clean fclean debug

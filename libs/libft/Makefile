# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:28:03 by samunyan          #+#    #+#              #
#    Updated: 2022/04/04 13:28:06 by samunyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

#Directories
OBJDIR			= 	./objs
SRCDIR			=	./srcs
HEADDIRS		=	./include

#Files
FILES	=	ft_atoi.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_strchr.c \
            ft_strdup.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strnstr.c \
            ft_strstr.c \
            ft_strncmp.c\
            ft_strrchr.c \
            ft_tolower.c \
            ft_toupper.c \
            ft_calloc.c \
            ft_strdup.c \
            ft_substr.c \
            ft_strjoin.c \
            ft_strtrim.c \
            ft_split.c \
            ft_split_set.c \
            ft_itoa.c \
            ft_strmapi.c \
            ft_striteri.c \
            ft_putchar_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
            ft_s_lstnew.c \
			ft_s_lstadd_front.c \
			ft_s_lstsize.c \
			ft_s_lstlast.c \
			ft_s_lstadd_back.c \
			ft_s_lstdelone.c \
			ft_s_lstclear.c \
			ft_s_lstiter.c \
			ft_s_lstmap.c \
			ft_s_lstfind_content.c \
			ft_s_lstfind_position.c \
			ft_s_lstnode_at.c \
			ft_isspace.c \
			ft_skip_space.c \
			ft_islower.c \
			ft_isupper.c \
			ft_free_arr_until.c \
			ft_free_arr.c \
			ft_strndup.c \
			ft_append.c \
			ft_strnjoin.c \
			ft_ultoa_base.c \
			ft_prepend.c \
			ft_memappend.c \
			ft_strupcase.c \
			ft_strcmp.c \
			ft_get_next_line.c \
			ft_max.c \
			ft_min.c \
			ft_lis.c \
			ft_lis_utils.c \
			ft_abs.c \
			ft_binary_search.c \
			ft_insertion_sort.c \
			ft_quicksort.c \
			ft_selection_sort.c \
			ft_swap.c \
			ft_atoi_base.c \
			ft_lerp.c \
			ft_error.c \
			ft_malloc.c \
			ft_atof.c
FT_PRINTF	= ft_printf.c \
			ft_dprintf.c \
            ft_parse_format.c \
            ft_get_spec.c \
			ft_convert_diux.c \
			ft_convert_scp.c \
			ft_convert_percent.c \
			ft_helpers_1.c \
			ft_helpers_2.c
FILES	+= $(addprefix ft_printf/, $(FT_PRINTF))
OBJS	=	$(addprefix $(OBJDIR)/, $(FILES:.c=.o))
SRCS	= 	$(addprefix $(SRCDIR)/, $(FILES))

#Compiler
SYSTEM		 := $(shell uname)
ifeq ($(SYSTEM),Linux)
CC			=	clang
else
CC			= 	gcc
endif
CFLAGS	=	-Wall -Werror -Wextra $(HEADDIRS:%=-I %) -D BUFFER_SIZE=200 -D MAX_LINE=4096
ifeq ($(SANITIZER), 1)
		CFLAGS	+=	-g -fsanitize=address
endif
ifeq ($(DEBUG), 1)
		CFLAGS	+=	-g
endif

.PHONY:		all clean fclean re sanitizer debug bonus

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@test -z '$(filter %.o,$?)' || (echo ✅ $(BBlue) [$(NAME)]"\t"$(BGreen)Compilation done.$(Color_Off) && \
				echo $(White)"\t\t\t"Compiler flags: $(CFLAGS)$(Color_Off))

$(OBJDIR)/%.o:  $(SRCDIR)/%.c
			@mkdir -p $(dir $@)
			@echo ⌛ $(BBlue)[$(NAME)]"\t"$(Yellow)Compiling $<$(Color_Off)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@if [ -d $(OBJDIR) ]; then \
  					rm -rf $(OBJDIR); \
  					echo 🗑$(BBlue)[$(NAME)]"\t"$(BGreen)Object files removed.$(Color_Off); \
  			fi


fclean:		clean
			@if [ -f $(NAME) ]; then \
					rm -rf $(NAME); \
					echo 🗑$(BBlue)[$(NAME)]"\t"$(BGreen)Library removed.$(Color_Off); \
			fi

re:			fclean all

sanitizer:
			@SANITIZER=1 make re

debug:
			@DEBUG=1 make re

bonus:		all

# Colors
## Reset
Color_Off='\033[0m'       # Text Reset
## Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White
## Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White
## Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White
## Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White
## Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue

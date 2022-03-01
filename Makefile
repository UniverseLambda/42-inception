.PHONY:	all re clean fclean distclean
.SUFFIX: .cpp .o

NAME :=	ircserv

SRCS = src/main.cpp

include src/internal/Include.mk
include src/data/Include.mk

INCS :=

SRCS_DIR := src
OBJS_DIR := .objs

CXX :=	c++
LD := $(CXX)

CXX_FLAGS := -g3 -Wall -Wextra -Werror -std=c++98 -Iinc #-fsanitize=address -fsanitize=undefined
LD_FLAGS := -g3 -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -fsanitize=undefined

OBJS :=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all:		$(NAME)

$(NAME):	$(OBJS)
	$(LD) $(LD_FLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: %.cpp	$(INCS) Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean:		clean
	rm -f ircserv

distclean:	fclean

re: distclean all

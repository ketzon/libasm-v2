NAME = libasm.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
ASM = nasm
ASMFLAGS = -f elf64
LDFLAGS = -z noexecstack

ASM_SRCS = ft_strlen.s ft_strcpy.s  ft_strcmp.s ft_write.s  ft_read.s ft_strdup.s 
ASM_OBJS = $(ASM_SRCS:.s=.o)

# pour les tests
C_SRCS = main.c
C_OBJS = $(C_SRCS:.c=.o)
TEST = test

all: $(NAME)

$(NAME): $(ASM_OBJS)
	ar rcs $(NAME) $(ASM_OBJS)
	@echo "✅ bibliothèque $(NAME) cree"

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@
	@echo "🔧 assemblage de $<"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST): $(NAME) $(C_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(C_OBJS) -L. -lasm -o $(TEST)
	@echo "🎯 executable de test cree"

clean:
	rm -f $(ASM_OBJS) $(C_OBJS)
	@echo "🧹 delete les fichiers objets"

fclean: clean
	rm -f $(NAME) $(TEST)
	@echo "🧹 delete les fichiers objets + executable"

re: fclean all

.PHONY: all clean fclean re test

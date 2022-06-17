NAME=fractol_image_test
OBJ:=test_image.o
INC=/usr/include
INCLIB=$(INC)/../lib
LFLAGS = -L. -lmlx -L$(INCLIB) -lXext -lX11 -lm
CFLAGS= -I$(INC) -O3 -I. -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -Lmlx -L./minilibx -lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	gcc -I./minilibx -Imlx -O3 -c $< -o $@
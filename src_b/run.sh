
gcc -Wall -Wextra -Wextra -fsanitize=address *.c ./print_flags/*.c ../libft/libft.a && ./a.out
rm -rf ./a.out

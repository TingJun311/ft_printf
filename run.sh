
gcc -Wall -Wextra -Werror -fsanitize=address *.c libft/libft.a  && ./a.out

rm -rf a.out

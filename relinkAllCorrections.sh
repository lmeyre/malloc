list=`ls ./Testing/correction/*.c`

for script in $list
do
	clang -o $script.bin $script ./libft_malloc.so
done

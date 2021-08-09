list=`ls ./Testing/correction/*.c`
declare -i y=0

for script in $list
do
	#echo $y
	clang  -o $script.bin $script ./libft_malloc.so
	#y++;
done

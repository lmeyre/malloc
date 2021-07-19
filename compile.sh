#!/bin/sh
make re
sh run.sh
clang Testing/customTests/*.c libft_malloc_x86_64.so

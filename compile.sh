#!/bin/sh
make re
sh run.sh
#sh run2.sh
clang tests/main.c libft_malloc_x86_64.so

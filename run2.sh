#!/bin/sh
LD_PATH=$(pwd) LD_PRELOAD="${LD_PATH}/libft_malloc.so" $@      

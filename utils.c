#include "includes.h"

t_data_type return_type(size_t size)
{
    t_data_type type;
    
    if (size <= TINY_BLOCK_SIZE)
		type = TINY;
    else if (size <= SMALL_BLOCK_SIZE)
		type = SMALL;
    else
        type = LARGE;
}
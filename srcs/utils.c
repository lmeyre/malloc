#include "../includes/malloc.h"

t_data_type return_type(size_t size)
{
    t_data_type type;
    
    if (size <= (size_t)TINY_BLOCK_SIZE)
		  type = TINY;
    else if (size <= (size_t)SMALL_BLOCK_SIZE)
		  type = SMALL;
    else
      type = LARGE;
    return type;
}
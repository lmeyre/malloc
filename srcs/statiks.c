#include "../includes/malloc.h"

t_heap* first_heap()
{
	return (*first_origin());
}

t_heap **first_origin()
{
	static t_heap *origin = NULL;

	return (&origin);
}
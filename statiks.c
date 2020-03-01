#include "includes.h"

t_heap* first_heap()
{
	static t_heap* first = NULL;

	return (first);
}
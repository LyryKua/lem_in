//
// Created by Kyrylo Hrecheniuk on 5/16/18.
//

#include <stdlib.h>
#include "libft.h"

void error_exit(char *msg, char **as)
{
	ft_strdel(as);
	ft_putendl_fd(msg, 2);
	exit(42);
}
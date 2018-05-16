//
// Created by Kyrylo Hrecheniuk on 5/16/18.
//

#include <stdlib.h>
#include "libft.h"

void error_exit(char *line)
{
	ft_putendl_fd(line, 2);
	exit(42);
}
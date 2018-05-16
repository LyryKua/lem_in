//
// Created by Kyrylo Hrecheniuk on 5/16/18.
//

#include <printf.h>
#include "libft.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("[%s] is %s\n", argv[1],
			   ft_isnumber(argv[1]) ? "NUMBER" : "NOT NUMBER");
		printf("[%s] is %d\n", argv[1], ft_isnumber(argv[1]));
	}
	return (0);
}

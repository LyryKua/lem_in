//
// Created by Kyrylo Hrecheniuk on 5/16/18.
//

#include <printf.h>
#include "libft.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("1) [%s] is %s\n", argv[1], ft_isnumber(argv[1]) ? "NUMBER" : "NOT NUMBER");
		printf("2) [%s] is %s\n", argv[1], ft_isnumber("") ? "NUMBER" : "NOT NUMBER");
	}
	return (0);
}

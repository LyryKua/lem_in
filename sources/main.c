/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:45:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/20 16:45:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	main(void)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return 0;
}

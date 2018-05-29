/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:45:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/20 16:45:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct s_room	t_room;
typedef struct s_link	t_link;

enum	e_status
{
	usual,
	start,
	end
};

struct	s_room
{
	char			*name;
	int				x;
	int				y;
	enum e_status	status;
	unsigned int	number_ants;
};

struct	t_link
{
	t_room	*room1;
	t_room	*toom2;
};

t_list	*read_rooms(void);
void	error_exit(char *msg, char **as);

#endif

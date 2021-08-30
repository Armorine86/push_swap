/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 09:40:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/30 10:06:28 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(int i, int *ret, int fd)
{
	char	c;
	char	*str;
	
	if(!read(fd, &c, 1))
		c = 0;
	if (c == '\n' || c == 0)
	{
		str = malloc(sizeof(char) * (i + 1));
		str[i] = 0;
		*ret = 1;
		if (c == 0)
			*ret = 0;
		return (str);
	}
	else
	{
		str = read_line(i + 1, ret, fd);
		str[i] = c;
	}
	return (str);
}

int	get_next_line(char **line)
{
	int	ret;

	ret = 1;
	*line = read_line(0, &ret, 0);
	return (ret);
}
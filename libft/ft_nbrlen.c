/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:55:51 by mmondell          #+#    #+#             */
/*   Updated: 2021/06/11 11:39:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

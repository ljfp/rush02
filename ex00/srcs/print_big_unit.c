/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaires-r <jaires-r@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:11:51 by jaires-r          #+#    #+#             */
/*   Updated: 2025/07/27 17:41:22 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/rush02.h"

int		nbr_chunks(char *str)
{
	int strlen;
	
	strlen = ft_strlen(str);
	if (strlen < 4)
		return (0);
	else 
	{
		if (strlen % 3)
			return (3 * (strlen / 3));
		else
			return (3 * ((strlen / 3) - 1));
	}
}

char	*big_unit(int nbr_chnks)
{
	int		i;
	char	*to_find;
	
	to_find = (char *) malloc(3 + nbr_chnks * sizeof(char));
	if (to_find == NULL)
		return (NULL);
	to_find[0] = 1;
	i = 1;
	while (i < nbr_chnks + 1)
	{
		to_find[i] = '0';
		i++;
	}
	to_find[nbr_chnks + 1] = ':';
	to_find[nbr_chnks + 2] = '\0';
	return (to_find);
}


void	print_big_units(char *str, int	nbr_chnks)
{
	char	*to_find;
	char	*dup;

	to_find = big_unit(nbr_chnks);
	ft_strstr(str,to_find);
	dup = ft_extract(str);
	write(1, dup, ft_strlen(dup));
}

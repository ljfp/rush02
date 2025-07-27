/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaires-r <jaires-r@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:11:51 by jaires-r          #+#    #+#             */
/*   Updated: 2025/07/27 19:01:04 by jaires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/rush02.h"

char	*big_unit(int nbr_chnks)
{
	int		i;
	char	*to_find;
	
	to_find = (char *) malloc(3 + 3 * nbr_chnks * sizeof(char));
	if (to_find == NULL)
		return (NULL);
	to_find[0] = 1;
	i = 1;
	while (i < 3 * nbr_chnks + 1)
	{
		to_find[i] = '0';
		i++;
	}
	to_find[3 * nbr_chnks + 1] = ':';
	to_find[3 * nbr_chnks + 2] = '\0';
	return (to_find);
}


void	print_big_units(int	nbr_chnks, char *dict_name)
{
	char	*to_find;

	to_find = big_unit(nbr_chnks);
	print_num(to_find, dict_name);
}

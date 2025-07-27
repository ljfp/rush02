/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_unit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaires-r <jaires-r@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:11:51 by jaires-r          #+#    #+#             */
/*   Updated: 2025/07/27 14:33:37 by nponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*big_unit(int nbr_chunks)
{
	int		i;
	char	*to_find;
	
	to_find = (char *) malloc((nbr_chunks + 3) * sizeof(char));
	if (to_find == NULL)
		return (NULL);
	to_find[0] = 1;
	i = 1;
	while (i < nbr_chunks + 1)
	{
		to_find[i] = '0';
		i++;
	}
	to_find[nbrchunks + 1] = ':';
	to_find[nbrchunks + 2] = '\0';
	return (to_find);
}


void	print_big_units(char *str)
{
	int		nbr_chunks;
	char	*to_find;
	char	*dup;

	nbr_chunks = nbr_chunks(str);
	to_find = big_unit(nbr_chunks);
	ft_strstr(str,to_find);
	dup = ft_extract(str);
	write(1, dup, ft_strlen(dup));	
}

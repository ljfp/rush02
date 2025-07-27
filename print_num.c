/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaires-r <jaires-r@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:10:08 by jaires-r          #+#    #+#             */
/*   Updated: 2025/07/27 16:27:47 by jaires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rushheader.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
	{
		return (str);
	}
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0'
			&& to_find[j] != '\0'
			&& str[i + j] == to_find[j])
		{
			j++;
		}
		if ((to_find[j] == '\0') && (str[i + j] < '0' || str [i + j] > '9'))
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}


void print_num(char *str)
{
	int fd;
	char buffer[691];
	char *tmpres;
	char *result;
	
	fd = open("numbers.dict", O_RDONLY);
	read(fd, buffer, 700);
	close(fd);
	tmpres = ft_strstr(buffer, str);
	result = ft_extract(tmpres);
	write (1, result, 20);
}

int	main(void)
{
	chunks("1230");
	return (0);
}

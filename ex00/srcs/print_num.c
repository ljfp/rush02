/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaires-r <jaires-r@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:10:08 by jaires-r          #+#    #+#             */
/*   Updated: 2025/07/27 22:31:08 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

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

void	print_num(char *str, char *dict_name)
{
	int		fd;
	char	buffer[691];
	char	*tmpres;
	char	*result;

	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		exit(1);
	}
	read(fd, buffer, 691);
	close(fd);
	tmpres = ft_strstr(buffer, str);
	result = ft_extract(tmpres);
	write (1, result, ft_strlen(result));
	free(result);
}

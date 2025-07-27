/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:24:56 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/27 11:51:32 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_return_len(int argc, char **argv)
{
	int	len;

	len = 0;
	if (argc == 2)
	{
		while (argv[1][len])
		{
			len++;
		}
	}
	if (argc == 3)
	{
		while (argv[2][len])
		{
			len++;
		}
	}
	return (len);
}

char	*ft_convert_args(int argc, char **argv)
{
	char	*str;
	int		len;

	len = ft_return_len (argc, argv);
	str = malloc (len * sizeof(char));
	if (argc == 2)
		str = argv[1];
	if (argc == 3)
		str = argv[2];
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:15:07 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/26 16:13:50 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 3 || argc < 2)
		return (1);
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return (1);
			i++;
		}
	}
	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (!(argv[2][i] >= '0' && argv[2][i] <= '9'))
				return (1);
			i++;
		}
	}
	return (0);
}

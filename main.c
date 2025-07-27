/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:17:05 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/27 11:55:09 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_check_args(int argc, char **argv);
char	*ft_convert_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	char	*str;

	if (ft_check_args (argc, argv) == 1)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	str = ft_convert_args(argc, argv);
	printf("%s", str);
	return (0);
}

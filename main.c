/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egalindo <egalindo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:17:05 by egalindo          #+#    #+#             */
/*   Updated: 2025/07/27 14:56:36 by egalindo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_check_args(int argc, char **argv);
char	*ft_convert_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	char	*str_num;
	char	*dict_name;

	if (ft_check_args (argc, argv) == 1)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	str_num = ft_convert_args(argc, argv);
	if(argc == 2)
		dict_name="numbers.dict";
	if(argc ==3)
		dict_name=argv[1];
	
	printf("%s", str_num);
	printf("%s", dict_name);
	return (0);
}

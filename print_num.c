#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_extract(char *str);
int chunks(char *str);
void decompose(char digit1, char digit2, char digit3);
void print_num(char *str);


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
	int i;
	int fd;
	char buffer[691];
	char *tmpres;
	char *result;
	
	i = 0;
	fd = open("numbers.dict", O_RDONLY);
	read(fd, buffer, 700);
	close(fd);
	tmpres = ft_strstr(buffer, str);
	result = ft_extract(tmpres);
	write (1, result, 20);
}

int	main(void)
{
	chunks("123");
	return (0);
}

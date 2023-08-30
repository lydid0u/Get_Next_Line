#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*new_line(char *str)
{
	int i;
	char *line;

	i = 0;
	line = malloc(sizeof(char) * (ft_strlen(str) + 1));

	if (line == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] != '\0')
	{
		line[i] = '\n';
		i++;
	}

	line[i] = '\0';

	return (line);
}

char	*clean_stock(char *str, int i, int j) 
{
	char *clean;

	if (!str[0]) //cest pas parce que ca rentre la que il ny a plus rien a lire dans le fichier, ta condition de sorti de gnl, cest read renvoie 0, et dans mon stock il est vide
	{
		free(str);
		return (NULL); //ca va te free ton stock et le remplacer par NULL mais cest pas force que ya plus rien a dire
	}
	clean = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (clean == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
		clean[j] = str[i];
		i++;
		j++;
	}
	clean[j] = '\0';
	free(str);
	return(clean);
}

char    test(char *str)
{
    str = new_line(str);
}

int	main(void)
{
	char *str = malloc(sizeof(char) * 8);
	str[0] = '1';
    str[1] = '\n';
	str[2] = '2';
	str[3] = '\n';
	str[4] = '3';
	str[5] = '\n';
	str[6] = '4';
	str[7] = '\0';
	char *result;

	result[0] = test(str);
	printf("Résultat -1: %s\n strlen : %ld\n", result, ft_strlen(result));
	result[1] = test(result);
	printf("Résultat-2 : %s\n strlen : %ld\n", result, ft_strlen(result));
	result[2] = test(result);
	printf("Résultat-3 : %s\n strlen : %ld\n", result, ft_strlen(result));
	result[3] = test(result);
	printf("Résultat-4 : %s\n strlen : %ld\n", result, ft_strlen(result));
	result[4] = test(result);
	return (0);
}

//int main ()
//{
//    char    str[] = "test\nla\n";
//    char *result = test(str);
//
//    printf("Résultat : %s\n", result);
//}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:12:14 by lboudjel          #+#    #+#             */
/*   Updated: 2023/08/30 17:12:14 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
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

char	*ft_strjoin(char *s1, char *s2)
{	
	int     i;
    int     j;
    char	*str;
	int		len;

    i = 0;
    j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (s1 == NULL || s2 == NULL || str == NULL)
		return (NULL);
        
    while (s1[i] != '\0') 
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') 
    {
        str[i] = s2[j];
        i++;
        j++;
    }
	str[i] = '\0';
	return (free(s1), str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
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

char	*get_next_line(int fd)
{
	static char	*stock;
    char		*buffer;
	char		*line;
	int			char_read;

	char_read = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
    
    while (char_read > 0 && !ft_strchr(stock, '\n'))
    {
        char_read = read(fd, buffer, BUFFER_SIZE);
	    if (char_read == -1)
	       return (free(buffer), NULL); 
        stock = ft_strjoin(stock, buffer);
        if (!stock)
            return (free(buffer), NULL);
    }
    line = new_line(stock);
    stock = clean_stock(stock, 0, 0);
    return (free(buffer), line);
}


/*int	main(void)
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

	result = test(str);
	printf("Résultat -1: %s\n strlen : %ld\n", result, ft_strlen(result));
	//result = test(result);
	//printf("Résultat-2 : %s\n strlen : %ld\n", result, ft_strlen(result));
	//result = test(result);
	//printf("Résultat-3 : %s\n strlen : %ld\n", result, ft_strlen(result));
	//result = test(result);
	//printf("Résultat-4 : %s\n strlen : %ld\n", result, ft_strlen(result));
	//result = test(result);
	return (0);
}*/

//int main ()
//{
//    char    str[] = "test\nla\n";
//    char *result = test(str);
//
//    printf("Résultat : %s\n", result);
//}
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



#include "get_next_line.h"
# include <sys/uio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
		i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	size_t     i;
    size_t     j;
    char	*str;
	int		len;

    i = 0;
    j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
        
    while (i < ft_strlen(s1)) 
    {
        str[i] = s1[i];
        i++;
    }
    while (j < ft_strlen(s2))  
    {
        str[i] = s2[j];
        j++;
		i++;
    }
	str[i] = '\0';
	return (free(s1), str);
}

int	ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str)
	{	
		while (str[i])
		{
			if (str[i] == (unsigned char)c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*new_line(char *str)
{
	size_t i;
	size_t j;
	char *line;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	while (j <= i)
	{
		line[j] = str[j];
		j++;
	}
	if (str[i] != '\0')
	{
		line[j] = '\n';
		i++;
	}

	line[j] = '\0';
	return (line);
}

char	*clean_stock(char *str, size_t i, size_t j) 
{
	char *clean;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL); 
	clean = malloc(sizeof(char) * (ft_strlen(str)));
	if (!clean)
		return (free(str), NULL); 
	if (str[i] == '\n')
		i++;
	while (str[i])
	{
		clean[j] = str[i];
		i++;
		j++;
	}
	clean[j] = '\0';
	return(free(str), clean);
}

char	*get_next_line(int fd)
{
	static char	*stock;
    char		*buffer;
	char		*line;
	int			char_read;

	char_read = 1;
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
		buffer[char_read] = '\0';
        stock = ft_strjoin(stock, buffer);
        if (!stock)
            return (free(buffer), NULL);
    }
    line = new_line(stock);
    stock = clean_stock(stock, 0, 0);
    return (free(buffer), line);
}

  int	main(int argc, char **argv)
   {
   char	*str;
   int		fd;

   if (argc != 2)
   return (1);
   fd = open(argv[1], O_RDONLY);
   str = get_next_line(fd);
   while (str)
   {
  	 printf("%s", str);
  	 free(str);
  	 str = get_next_line(fd);
   }
   free(str);
   return (0);
   }

//int main ()
//{
//    char    str[] = "test\nla\n";
//    char *result = test(str);
//
//    printf("Résultat : %s\n", result);
//}
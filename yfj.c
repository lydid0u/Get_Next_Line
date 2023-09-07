#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
# include <sys/uio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


size_t	ft_strlen(const char *str)
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

	if (!str || !ft_strchr(str, '\n')) //cest pas parce que ca rentre la que il ny a plus rien a lire dans le fichier, ta condition de sorti de gnl, cest read renvoie 0, et dans mon stock il est vide
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

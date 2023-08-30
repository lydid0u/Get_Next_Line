
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        i++;
    }

    return (i);   
}

char    *newline(char *str)
{
    int i;
    char *line;

    i = 0;
    line = malloc(sizeof(char) * (ft_strlen(str) + 1));

    if (line == NULL)
        return NULL;
    while(str[i] != '\0' && str[i] != '\n')
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

char    *clean_stock(char *str)
{
    int i;
    int j;
    char    *clean;

    i = 0;
    j = 0;
    clean = malloc(sizeof(char) * (ft_strlen(str) + 1));

    if (clean == NULL)
        return (NULL);

    while(str[i] && str[i] != '\n')
    {
        i++;
    }

    if (str[i] == '\n') {
        i++;
    }

    while (str[i])
    {
        clean[j] = str[i];
        i++;
        j++;
    }

    clean[j] = '\0';

    return (clean);
}

int main() {
    char str[] = "s\n1\n2\nfdf";
    char *result = clean_stock(str);

    if (result != NULL) {
        printf("Résultat : %s\n", result);
        free(result); // Libérer la mémoire allouée
    } else {
        printf("Échec d'allocation mémoire\n");
    }

    return 0;
}

/*char	*get_next_line(int fd)
{
	static char	*stock;
    char		*buffer;
	char		*line;
	int			char_read;

	char_read = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = '\0';

    }

    line = newline(stock);
    stock = clear_stock(stock);
}*/

/*int main (MAIN DE NEWLINE)
{
    char    str[] = "test               t \n fesfsdefef";
    char *result = newline(str);
    printf("Résultat : %s\n", result);
}*/
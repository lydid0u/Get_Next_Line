#include <unistd.h>

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str)
    {
        i++;
    }

    return (i);   
}

    static char buffer[BUFFER_SIZE];
    static char *stock = NULL;
    static int position = 0;
    static int bytes_lus = 0;

char *get_next_line(int fd)
{

    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);

    return 1; // Retourne 1 si une ligne a été lue avec succès, 0 sinon 
}


// jutilise read sur fd

void    read_stock()
{
    if (position == bytes_lus)
    {
        position = 0;
        bytes_lus = read(fd, buffer, BUFFER_SIZE);
    }
}

// ajouter le contenu du buffer dans le stock

void    add_to_stock()

//checker /n dans stock et si ya je deplace stock dans Line et je clean_stock

void    check_line()
{
    size_t i;
    size_t len;
    
    i = 0;
    len = ft_strlen(stock);
    while (i < stock_len)
    {
        if (stock[i] == '/n')
        {
            stock[i] = '/0';
        }
    }
}

//vider Stock

void    clean_stock()
{
    free(stock);
    stock = NULL;
}
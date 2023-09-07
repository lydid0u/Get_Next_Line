#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *str)
{
    size_t i = 0;

    while (str[i])
        i++;
    return (i);
}

int ft_strchr(const char *str, int c)
{
    size_t i = 0;

    while (str[i])
    {
        if (str[i] == (unsigned char)c)
            return (1);
        i++;
    }
    return (0);
}

char *new_line(const char *str)
{
    size_t i = 0;
    char *line;

    while (str[i] && str[i] != '\n')
        i++;

    line = malloc(sizeof(char) * (i + 2)); // +2 pour le caractère de saut de ligne et le caractère nul

    if (line == NULL)
        return (NULL);

    for (size_t j = 0; j <= i; j++)
        line[j] = str[j];

    line[i + 1] = '\0';

    return (line);
}

char *clean_stock(const char *str)
{
    size_t i = 0;
    size_t j = 0;
    char *clean;

    while (str[i] && str[i] != '\n')
        i++;

    if (str[i] == '\0')
        return (NULL);

    i++; // Avancer au-delà du caractère de saut de ligne

    clean = malloc(sizeof(char) * (ft_strlen(&str[i]) + 1));

    if (clean == NULL)
        return (NULL);

    while (str[i])
    {
        clean[j] = str[i];
        i++;
        j++;
    }

    clean[j] = '\0';

    return (clean);
}

char *process_string(const char *str)
{
    char *line = new_line(str);

    if (line == NULL)
        return (NULL);

    char *cleaned = clean_stock(str);

    if (cleaned == NULL)
    {
        free(line);
        return (NULL);
    }

    free(line);

    return (cleaned);
}

int main() {
    char *input_string = "This is a test string\nThis is another line\n";
    char *result = process_string(input_string);
    
    if (result != NULL) {
        printf("Processed Line: %s\n", result);
        free(result);
                input_string = input_string + ft_strlen(result) + 1;

    } else {
        printf("No more lines to process.\n");
    }
    
    return 0;
}

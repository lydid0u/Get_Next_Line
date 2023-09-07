/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:12:10 by lboudjel          #+#    #+#             */
/*   Updated: 2023/09/05 17:42:02 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*get_next_line(int fd);
char	*clean_stock(char *str, size_t i, size_t j);
char	*new_line(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:07:12 by david             #+#    #+#             */
/*   Updated: 2026/06/11 15:29:20 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strleno(char *s);
int		ft_strchro(char *line);
char	*ft_strdupo(char *s, int position);
char	*ft_strjoino(char *s1, char *s2);
char	*ft_strcpyo(char *line, int *position);
char	*get_next_line(int fd);
#endif
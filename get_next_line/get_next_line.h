/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:07:12 by david             #+#    #+#             */
/*   Updated: 2025/11/04 20:11:14 by david            ###   ########.fr       */
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
# include "../libft/libft.h"

/* GNL-specific utils (different signatures from libft) */
int     gnl_strchr(char *line);
char    *gnl_strdup(char *s, int position);
char    *gnl_strcpy(char *line, int *position);

/* Main GNL function */
char    *get_next_line(int fd);

#endif

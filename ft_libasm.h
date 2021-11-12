/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libasm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:09:08 by achopper          #+#    #+#             */
/*   Updated: 2021/04/30 18:42:43 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_FT_LIBASM_H
#define LIBASM_FT_LIBASM_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include  <fcntl.h>

ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char*		ft_strcpy(char *dst, const char *src);
char*     	ft_strdup(const char *s1);



#endif

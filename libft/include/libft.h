/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:30:40 by bsouchet          #+#    #+#             */
/*   Updated: 2016/05/20 15:42:36 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

# define BUFF_SIZE 1
# define D (double)

int				ft_abs(int n);

int				ft_atoi(char *str, int *k, int r, int s);

void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);

void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);

void            ft_cpy(char *s1, char *s2);

size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
char			*ft_strnew(size_t size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin2(char *s1, char *s2, int type);

int				ft_strcmp(char *s1, char *s2);

char			*ft_firstupper(char *str);

int				ft_rand(int min, int max);

int				ft_darken_color(int clr, double val);
int				ft_lighten_color(int clr, double val);
int				ft_gradient_color(int clr1, int clr2, double val);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 13:30:40 by bsouchet          #+#    #+#             */
/*   Updated: 2016/06/09 15:24:17 by bsouchet         ###   ########.fr       */
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
# define MIN_V 135

typedef struct	s_hsv
{
	double		h;
	double		s;
	double		v;
}				t_hsv;

typedef struct	s_percent
{
	double		r;
	double		g;
	double		b;
}				t_percent;

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct	s_var
{
	int			e;
	int			m;
	int			x;
	int			y;
	int			sl;
	int			len;
	int			nbr;
	int			num;
	int			bpp;
	int			end;
	int			rot;
	int			clr;
	char		*d;
	char		*nam;
	char		ftl[3][12];
	float		minx;
	float		miny;
	double		i;
	double		z;
	double		imax;
	double		padx;
	double		pady;
	double		clr_h;
	double		clr_s;
	double		clr_v;
	long double	jr;
	long double	ji;
	long double	mr;
	long double	mi;
	long double	zr;
	long double	zi;
	long double	tmp;
	long double	mod;
	void		*img;
	void		*mlx;
	void		*win;
}				t_var;

int				ft_abs(int n);

double			ft_min(double num1, double num2);
double			ft_max(double num1, double num2);

int				ft_atoi(char *str, int *k, int r, int s);

void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);

void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);

void			ft_cpy(char *s1, char *s2);

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

t_hsv			ft_random_color(void);
int				ft_tint_color(int clr, double val);
int				ft_shade_color(int clr, double val);
int				ft_gradient_color(int clr1, int clr2, double val);

t_percent		ft_rgb_to_percent(t_rgb rgb);
t_rgb			ft_hsv_to_rgb(t_hsv hsv);
t_rgb			ft_hex_to_rgb(int hex);
int				ft_rgb_to_hex(t_rgb rgb);
int				ft_hsv_to_hex(double h, double s, double v);

#endif

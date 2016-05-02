/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:16:33 by bsouchet          #+#    #+#             */
/*   Updated: 2016/04/12 16:58:38 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void			*mlx_init();

void			*mlx_new_window(void *mlx_ptr, int pos_x, int pos_y,
				int size_x, int size_y, char *title);

int				mlx_width_screen(void);

int				mlx_clear_window(void *mlx_ptr, void *win_ptr);

int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
				int color);

void			*mlx_new_image(void *mlx_ptr,int width,int height);
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
				int *size_line, int *endian);

int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
				void *img_ptr, int x, int y);

unsigned int	mlx_get_color_value(void *mlx_ptr, int color);

int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);

int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
				int color, char *string);

void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
				int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
				int *width, int *height);

int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int				mlx_hook(void *win_ptr, int x_event, int x_mask,
				int (*funct)(), void *param);

int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);

#endif

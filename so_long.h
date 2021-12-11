/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:15:56 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/11 13:18:42 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#define W_KEY 13
#define S_KEY 1
#define D_KEY 2
#define A_KEY 0
#define ESC_KEY 53

typedef struct s_palyer{
	int x;
	int y;
}
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
} t_data;
typedef struct s_img
{
	int width;
	int height;
	int pos_i;
	int pos_j;

} t_img;
int ft_strlen(char *result);
void ft_join(char *str, char *s1, char *s2);
char *ft_strjoin(char *s1, char *s2);
char *get_file(int fd);
int count_word(char const *s, char c);
int ft_count_and_alloc(char *s, char c);
int ft_split_2(char const *s, char c, char **str, int i);
char **ft_split(char const *s, char c);
int ft_width(char **result);
int ft_height(char **result);
int ft_designe_game(t_data data, char **res);
char **get_map(char *url);
int key_hook(int key, t_data *data);
#endif
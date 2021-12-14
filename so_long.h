/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:15:56 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/14 13:40:32 by ojamil           ###   ########.fr       */
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

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	char **map;
	int x;
	int y;
	int cp;
} t_data;

int ft_strlen(char *result);
void ft_join(char *str, char *s1, char *s2);
char *ft_strjoin(char *s1, char *s2);
char *get_file(int fd);
int count_word(char *s, char c);
int ft_count_and_alloc(char *s, char c);
int ft_split_2(char *s, char c, char **str, int i);
char **ft_split(char *s, char c);
int ft_width(char **result);
int ft_height(char **result);
int ft_designe_game(t_data data);
char **get_map(char *url);
int key_hook(int key, t_data *data);
char *ft_strstr(char *str, char *s);
int ft_mapfermer(char **res);
int ft_strcmp(char *s1, char *s2);
void find_player(t_data *m);
int cherche_map(char **res, char c);
#endif
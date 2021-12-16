/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:15:56 by ojamil            #+#    #+#             */
/*   Updated: 2021/12/16 17:36:22 by ojamil           ###   ########.fr       */
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

typedef struct s_img
{
	void *wall_img;
	void *mario_img;
	void *Money_img;
	void *
} t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	char **map;
	int x;
	int y;
	int cp;
	int left_orright_annimation;
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
int key_hook_bonus(int key, t_data *data);
char *ft_strstr(char *str, char *s);
int ft_mapfermer(char **res);
int ft_strcmp(char *s1, char *s2);
void find_player(t_data *m);
int cherche_map(char **res, char c);
char *ft_itoa(int n);
void ft_grafic_bonnus(t_data data);
void put_img_bonus(t_data data, int i, int j, char *url);
int ft_designe_game_bonus(t_data data);
int ft_exit(t_data *data);
int key_loop_hook(t_data *data);
int ft_x_position(t_data *data);
int ft_y_position(t_data *data);
int check_mab_caracter(char **res);
int check_mab_caracter_bonus(char **res);
int ft_rermplir_gams_animation(t_data *data, int a, int i, int j, char *k);
void ft_mouvement_bonus(t_data *data, int a, int b);
#endif
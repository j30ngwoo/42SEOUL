/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwoo <jeongwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:55:55 by jeongwoo          #+#    #+#             */
/*   Updated: 2023/07/26 12:05:49 by jeongwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mandatory_srcs/so_long.h"
# include "time.h"

// enemy
void	init_enemy_img(t_game_info *game);
void	init_enemy_coords(t_game_info *game);
void	update_enemy(t_game_info *game);
void	move_enemy(int enemy_index, t_game_info *game);
void	draw_enemy(t_game_info *game);

// game render
int		render_game_bonus(t_game_info *game);
void	draw_move_count(t_game_info *game);

// key input process
int		key_input_proc_bonus(int keycode, t_game_info *game);
void	check_game_over(t_game_info *game);

void	game_over(t_game_info *game);
void	game_clear(t_game_info *game);

#endif
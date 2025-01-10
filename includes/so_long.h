/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:42:33 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 19:44:30 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*****************************************************************************/
/*                               > INCLUDES <                                 */
/*****************************************************************************/
# include "../MacroLibX/includes/mlx.h"
# include "../libft/libft.h"

/*****************************************************************************/
/*                                > MACROS <                                 */
/*****************************************************************************/
# define TILE_SIZE  64
# define WALL       '1'
# define SPACE      '0'
# define ALAN       'C'
# define GRUNT      'G'
# define START_POS  'P'
# define EXIT       'E'
# define FPS        120

/*****************************************************************************/
/*                             > ENUMERATIONS <                              */
/*****************************************************************************/
/**
 * @enum KeyCode
 * Énumération pour la gestion des touches du clavier.
 */
typedef enum KeyCode
{
	Up = 26,
	Down = 22,
	Right = 4,
	Left = 7,
	Space = 44,
}	t_KeyCode;

/*****************************************************************************/
/*                             > STRUCTURES <                                */
/*****************************************************************************/
/**
 * @struct environment
 * Contient tous les pointeurs vers les sprites, assets, etc.
 */
typedef struct environment
{
	void	*start;
	void	*game_over;
	void	*victory;
	void	*score[10];
	void	*b1;
	void	*b2;
	void	*b3;
	void	*b4;
	void	*alan1;
	void	*alan2;
	void	*alan3;
	void	*alan4;
	void	*alan5;
	void	*alan6;
	void	*grunt_idle1;
	void	*grunt_idle2;
	void	*wall;
	void	*stand;
	void	*standfck;
	void	*ship_exit;
	void	*walk1;
	void	*walk2;
	void	*back1;
	void	*back2;
	void	*right1;
	void	*right2;
	void	*left1;
	void	*left2;
}	t_environment;

/**
 * @struct t_data
 * Structure principale stockant l'état global du jeu, 
 * les pointeurs de MLX, la map, etc.
 */
typedef struct t_data
{
	void			*mlx;
	void			*win;
	int				frame;
	int				fail;
	int				fail_msg;
	int				move;
	int				collectibles;
	int				alan;
	int				center_x;
	int				center_y;
	int				move_up;
	int				move_down;
	int				move_right;
	int				move_left;
	int				start_button;
	int				game_over;
	int				victory;
	int				count_p;
	int				count_e;
	int				count_c;
	int				count_g;
	int				start_x;
	int				start_y;
	int				x;
	int				y;
	char			*map;
	char			**map_tab;
	int				sprite_toggle_up;
	int				sprite_toggle_down;
	int				sprite_toggle_left;
	int				sprite_toggle_right;
	t_environment	*env;
}	t_data;

/*****************************************************************************/
/*                          > FONCTIONS PUBLIQUES <                          */
/*****************************************************************************/

/* ----- Initialisation et parsing ----- */
int		init_data(t_data *data, char *filename);
char	map_core(char *str, t_data *data);
int		parse_map(t_data *data);
int		find_path(t_data *data);

/* ----- Vérifications de la map ----- */
int		ft_check_col(t_data *data);
int		ft_check_line(t_data *data);
int		ft_check_line_edges(t_data *data, int map_y);
int		ft_check_other(t_data *data);
int		ft_check_format(t_data *data);
char	ft_free_map(t_data *data);

/* ----- Initialisation des éléments graphiques ----- */
int		init_background(t_data *data, t_environment *env_data);
int		init_startpos(t_data *data);
int		init_exit(t_data *data);
int		init_sprites(t_data *data, t_environment *env_data);
int		init_assets(t_data *data, t_environment *env_data);
int		init_assets_score(t_data *data, t_environment *env_data);
int		init_score(t_data *data);
int		init_map(t_data *data);

/* ----- Gestion du jeu ----- */
int		check_game_over(t_data *data);
void	handle_interaction(t_data *data, int map_x, int map_y);

/* ----- Déplacements ----- */
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);

/* ----- Hooks (clavier, fermeture de fenêtre, etc.) ----- */
int		key_hook(int key, void *param);
int		key_up(int key, t_data *data);
int		key_down(int key, t_data *data);
int		key_right(int key, t_data *data);
int		key_left(int key, t_data *data);
int		close_hook(int event, void *param);
int		exit_hook(int key, t_data *data);

/* ----- Affichage ----- */
int		display(void *param);
void	display_movement_right(t_data *data);
void	display_movement_left(t_data *data);
void	display_movement_stand(t_data *data);
void	display_movement_down(t_data *data);
void	display_movement_up(t_data *data);

/* ----- Nettoyage ----- */
void	destroy_data(t_data *data);

#endif

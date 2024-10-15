/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:07:28 by uzanchi           #+#    #+#             */
/*   Updated: 2024/10/01 17:28:35 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "so_long.h"

static void	ft_copy_map_for_flood_fill(t_game *game)
{
	int	i;

	game->flood_file_check = (char **)malloc(sizeof(char *)
			* (game->map.rows + 1));
	if (!game->flood_file_check)
		ft_error_msg("Memory allocation failed for flood fill map", game);
	i = 0;
	while (i < game->map.rows)
	{
		game->flood_file_check[i] = ft_strdup(game->map.full[i]);
		if (!game->flood_file_check[i])
		{
			ft_free_flood_fill_map(game);
			ft_error_msg("Memory allocation failed for flood fill map", game);
		}
		i++;
	}
	game->flood_file_check[i] = NULL;
}

static void	flood_fill(t_game *game, int x, int y)
{
	if (game->flood_file_check[y][x] == '1' ||
		game->flood_file_check[y][x] == 'K')// || game->flood_file_check[y][x] == 'E')
		return ;
	game->flood_file_check[y][x] = 'K';
	if (game->flood_file_check[y - 1][x] != '1')
		flood_fill(game, x, y - 1);
	if (game->flood_file_check[y + 1][x] != '1')
		flood_fill(game, x, y + 1);
	if (game->flood_file_check[y][x - 1] != '1')
		flood_fill(game, x - 1, y);
	if (game->flood_file_check[y][x + 1] != '1')
		flood_fill(game, x + 1, y);
}

void	check_flood_fill(t_game *game)
{
	int	x;
	int	y;

	ft_copy_map_for_flood_fill(game);
	flood_fill(game, game->map.player.x, game->map.player.y);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->flood_file_check[y][x] == 'C')
			{
				ft_free_flood_fill_map(game);
				ft_error_msg("Uncollectable collectible detected!", game);
			}
			if (game->flood_file_check[y][x] == 'E')
			{
				if (game->map.coins > 0)
				{
					ft_free_flood_fill_map(game);
					ft_error_msg("Exit not accessible until all coins are collected!", game);
				}
			}
			x++;
		}
		y++;
	}
	ft_free_flood_fill_map(game);
}

void	ft_free_flood_fill_map(t_game *game)
{
	int	i;

	if (game->flood_file_check == NULL)
		return ;
	i = 0;
	while (i < game->map.rows)
	{
		if (game->flood_file_check[i] != NULL)
			free(game->flood_file_check[i]);
		i++;
	}
	free(game->flood_file_check);
	game->flood_file_check = NULL;
}*/
#include "so_long.h"

static void	ft_copy_map_for_flood_fill(t_game *game)
{
	int	i;

	game->flood_file_check = (char **)malloc(sizeof(char *)
			* (game->map.rows + 1));
	if (!game->flood_file_check)
		ft_error_msg("Memory allocation failed for flood fill map", game);
	i = 0;
	while (i < game->map.rows)
	{
		game->flood_file_check[i] = ft_strdup(game->map.full[i]);
		if (!game->flood_file_check[i])
		{
			ft_free_flood_fill_map(game);
			ft_error_msg("Memory allocation failed for flood fill map", game);
		}
		i++;
	}
	game->flood_file_check[i] = NULL;
}

static void	flood_fill(t_game *game, int x, int y)
{
	if (game->flood_file_check[y][x] == '1' ||
		game->flood_file_check[y][x] == 'K' ||
		(game->flood_file_check[y][x] == 'E' && game->map.coins > 0))
		return ;
	game->flood_file_check[y][x] = 'K';
	if (game->flood_file_check[y - 1][x] != '1')
		flood_fill(game, x, y - 1);
	if (game->flood_file_check[y + 1][x] != '1')
		flood_fill(game, x, y + 1);
	if (game->flood_file_check[y][x - 1] != '1')
		flood_fill(game, x - 1, y);
	if (game->flood_file_check[y][x + 1] != '1')
		flood_fill(game, x + 1, y);
}

void	check_flood_fill(t_game *game)
{
	int	x;
	int	y;

	ft_copy_map_for_flood_fill(game);
	flood_fill(game, game->map.player.x, game->map.player.y);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->flood_file_check[y][x] == 'C')
			{
				ft_free_flood_fill_map(game);
				ft_error_msg("Uncollectable collectible detected!", game);
			}
			x++;
		}
		y++;
	}
	ft_free_flood_fill_map(game);
}

void	ft_free_flood_fill_map(t_game *game)
{
	int	i;

	if (game->flood_file_check == NULL)
		return ;
	i = 0;
	while (i < game->map.rows)
	{
		if (game->flood_file_check[i] != NULL)
			free(game->flood_file_check[i]);
		i++;
	}
	free(game->flood_file_check);
	game->flood_file_check = NULL;
}

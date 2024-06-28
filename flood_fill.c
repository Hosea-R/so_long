#include "so_long.h"

void flood_fill(char **map, int x, int y, t_game *game)
{
    if (x < 0 || x >= game->width || y < 0 || y >= game->height || map[y][x] == '1' || map[y][x] == 'F')
        return;
    if (map[y][x] == 'C')
        game->collectibles--;
    else if (map[y][x] == 'E')
        game->exits--;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, game);
    flood_fill(map, x - 1, y, game);
    flood_fill(map, x, y + 1, game);
    flood_fill(map, x, y - 1, game);
}

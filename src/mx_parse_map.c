#include "../inc/header.h"

char *mx_parse_map(Map *map, int startX, int startY, int endX, int endY) {
  mx_wave_func(&map, startX, startY, 0);
  Map *path = NULL;
  const int maxDistance = mx_get_max_distance(map);
  char *result = malloc(1);
  if (!mx_get_path(map, &path, endX, endY, 0))
    return NULL;
  for (int i = 0; i < map->height; i++) {
    for (int j = 0; j < map->width; j++) {
      if (map->points[i][j] == -2)
        result = mx_str_append(result, '#');
      else if (map->points[i][j] == -1)
        result = mx_str_append(result, '.');
      else if (map->points[i][j] == maxDistance)
        result = ((path->points[i][j] == 1) ? mx_str_append(result, 'X') : mx_str_append(result, 'D'));
      else if (path->points[i][j] == 1)
        result = mx_str_append(result, '*');
      else
        result = mx_str_append(result, '.');
    }
    result = mx_str_append(result, '\n');
  }
  return result;
}


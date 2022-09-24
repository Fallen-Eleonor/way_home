#include "../inc/header.h"

int mx_get_max_distance(Map *map){
	int max = -1;
	for(int i = 0; i < map->height; i++)
		for(int j = 0; j < map->width; j++)
			if(map->points[i][j] > max)
				max = map->points[i][j];
	return max;
}

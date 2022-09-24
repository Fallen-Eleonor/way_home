#include "../inc/header.h"

Map *mx_build_map(char **mapText){
	Map *map = malloc(sizeof(Map));
	map->width = 0;
	map->height = 0;
	for(char **i = mapText; *i != NULL; i++){
		if(map->width == 0)
			map->width = mx_strlen(*i);
		else
			if(map->width != mx_strlen(*i))
				mx_printerr("map error\n");
		map->height++;
	}
	map->points = malloc(sizeof(int*) * map->height);
	for(int i = 0; i < map->height; i++){
		map->points[i] = malloc(sizeof(int) * map->width);
		for(int j = 0; j < map->width; j++){
			if(mapText[i][j] == '#')
				map->points[i][j] = -2;
			if(mapText[i][j] == '.')
				map->points[i][j] = -1;
		}
	}
	return map;
}

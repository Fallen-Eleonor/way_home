#include "../inc/header.h"

bool mx_get_path(Map *source, Map **dist, int x, int y, int n) {
	if(*dist == NULL) {
		*dist = malloc(sizeof(Map));
		(*dist)->width = source->width;
		(*dist)->height = source->height;
		(*dist)->points = malloc(sizeof(int*) * source->height);
		for(int i = 0; i < source->height; i++){
			(*dist)->points[i] = malloc(sizeof(int) * source->width);
			for(int j = 0; j < source->width; j++)
				(*dist)->points[i][j] = 0;
		}
		n = source->points[y][x];
		if(source->points[y][x] < 0)
			return false;
		(*dist)->points[y][x] = 1;
	}
	
	if(source->points[y][x] == 0){
		(*dist)->points[y][x] = 1;
		return true;
	}
	if(x + 1 < source->width)
		if(source->points[y][x + 1] == n - 1){
			(*dist)->points[y][x + 1] = 1;
			return mx_get_path(source, dist, x + 1, y, n - 1);
		}
		
	if(x - 1 >= 0)
		if(source->points[y][x - 1] == n - 1){
			(*dist)->points[y][x - 1] = 1;
			return mx_get_path(source, dist, x - 1, y, n - 1);
		}
		
	if(y + 1 < source->height)
		if(source->points[y + 1][x] == n - 1){
			(*dist)->points[y + 1][x] = 1;
			return mx_get_path(source, dist, x, y + 1, n - 1);
		}
		
	if(y - 1 >= 0)
		if(source->points[y - 1][x] == n - 1){
			(*dist)->points[y - 1][x] = 1;
			return mx_get_path(source, dist, x, y - 1, n - 1);
		}
	return false;
}

#include "../inc/header.h"

void mx_wave_func(Map **map, int x, int y, int n) {
	if( x < 0 || x >= (*map)->width 
	|| y < 0 || y >= (*map)->height)
		return;
	if((*map)->points[y][x] == -2)
		return;
	if((*map)->points[y][x] == -1)
		(*map)->points[y][x] = n;
	if(y + 1 < (*map)->height)
		if((*map)->points[y + 1][x] == -1 || (*map)->points[y + 1][x] > n + 1)
			(*map)->points[y + 1][x] = n + 1;
	if(y - 1 >= 0)
		if((*map)->points[y - 1][x] == -1 || (*map)->points[y - 1][x] > n + 1)
			(*map)->points[y - 1][x] = n + 1;
	if(x + 1 < (*map)->width)
		if((*map)->points[y][x + 1] == -1 || (*map)->points[y][x + 1] > n + 1)
			(*map)->points[y][x + 1] = n + 1;
	if(x - 1 >= 0)
		if((*map)->points[y][x - 1] == -1 || (*map)->points[y][x - 1] > n + 1)
			(*map)->points[y][x - 1] = n + 1;
	if(y + 1 < (*map)->height)
		if((*map)->points[y + 1][x] >= n + 1)
			mx_wave_func(map, x, y + 1, n + 1);
	if(y - 1 >= 0)
		if((*map)->points[y - 1][x] >= n + 1)
			mx_wave_func(map, x, y - 1, n + 1);
	if(x + 1 < (*map)->width)
		if((*map)->points[y][x + 1] >= n + 1)
			mx_wave_func(map, x + 1, y, n + 1);
	if(x - 1 >= 0)
		if((*map)->points[y][x - 1] >= n + 1)
			mx_wave_func(map, x - 1, y, n + 1);
}


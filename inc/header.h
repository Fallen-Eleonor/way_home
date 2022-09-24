#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct sMap{                                                    
	int width;                                                  
	int height;                                                  
	int **points;                            
}	           Map;

bool mx_isspace(char c);
bool mx_isdigit(char c);
int mx_atoi(const char *str);

void mx_write_file(char *path, char *data);
Map *mx_build_map(char **mapText);
bool mx_get_path(Map *source, Map **dist, int x, int y, int n);
int mx_get_dot_distance(Map *map, int x, int y);
int mx_get_max_distance(Map *map);
char *mx_open_file(char *path);
char *mx_parse_map(Map *map, int startX, int startY, int endX, int endY);
char **mx_parse_text(char *text);
void mx_wave_func(Map **map, int x, int y, int n);

int mx_strlen(char *s);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(char *str);

char *mx_strnew(int size);
char *mx_str_append(char *str, char symbol);

void check_error_argc(int argc);
void check_error_result(char *result);


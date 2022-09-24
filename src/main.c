#include "../inc/header.h"

int main(int argc, char *argv[]) {
	check_error_argc(argc);
	char *mapS = mx_open_file(argv[1]);
	Map *map = mx_build_map(mx_parse_text(mapS));
	if(mx_atoi(argv[2]) < 0 || mx_atoi(argv[2]) >= map->width || mx_atoi(argv[4]) < 0 || mx_atoi(argv[4]) >= map->width
		|| mx_atoi(argv[3]) < 0 || mx_atoi(argv[3]) >= map->height || mx_atoi(argv[5]) < 0 || mx_atoi(argv[5]) >= map->height)
		mx_printerr("points are out of map range\n");
	if(map->points[mx_atoi(argv[3])][mx_atoi(argv[2])] == -2)
		mx_printerr("entry point cannot be an obstacle\n");
	if(map->points[mx_atoi(argv[5])][mx_atoi(argv[4])] == -2)
		mx_printerr("exit point cannot be an obstacle\n");
	char *result = mx_parse_map(map, mx_atoi(argv[2]), mx_atoi(argv[3]), mx_atoi(argv[4]), mx_atoi(argv[5]));
	check_error_result(result);
	mx_printstr("dist=");
	mx_printint(mx_get_max_distance(map));
	mx_printchar('\n');
	mx_printstr("exit=");
	mx_printint(mx_get_dot_distance(map, mx_atoi(argv[4]), mx_atoi(argv[5])));
	mx_printchar('\n');
	mx_write_file("path.txt", result);
    free(result);
    return 0;
}


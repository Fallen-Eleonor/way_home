#include "../inc/header.h"

char *mx_open_file(char *path){
	int fd = open(path, O_RDWR);
		char chm;
	int refer;
	if(fd < 0)
		mx_printerr("map does not exist\n");
	char *result = mx_strnew(0);
	while ((refer = read(fd, &chm, 1)) > 0) {
		if (refer < 0)
			mx_printerr("map does not exist\n");
		if(chm != '#' && chm != '.' && chm != ',' && chm != '\n' && chm != '\r')
			mx_printerr("map error\n");
		if(chm != '\r')
			result = mx_str_append(result, chm);
	}
	close(fd);
	return result;
}


void mx_write_file(char *path, char *data){
	int fd = open(path, O_CREAT | O_RDWR);
	write(fd, data, mx_strlen(data));
    close(fd);
}


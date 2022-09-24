#include "../inc/header.h"

void check_error_argc(int argc) {
	if(argc != 6)
		mx_printerr("usage: ./way_home [file_name] [x1] [x2] [y1] [y2]\n");
}

void check_error_result(char *result) {
	if(result == NULL)
		mx_printerr("route not found\n");
}


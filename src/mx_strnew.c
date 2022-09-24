#include "../inc/header.h"

char *mx_strnew(int size){
	char *s = malloc(sizeof(char)*(size+1));
	for(int i = 0; i < size+1; i++)
		s[i] = '\0';
	return s;
}

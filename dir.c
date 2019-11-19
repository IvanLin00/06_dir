#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	printf("Listing all files\n");
	DIR *stream = opendir(argv[1]);
	if(stream == NULL){
		printf("Error Number: %d %s\n", errno, strerror(errno));
		return 0;
	}
	struct dirent *directory = readdir(stream);
	if(directory == NULL){
		printf("Error Number: %d %s\n", errno, strerror(errno));
		return 0;
	}
	int total_size = 0;
	while(directory != NULL){
		printf("%s", directory->d_name);
		if(directory->d_type==DT_DIR) printf(".dir\n");
		else printf("\n");
		struct stat s;
		stat(directory->d_name, &s);
		total_size += s.st_size;
		directory = readdir(stream);
	}
	printf("Total size: %d\n",total_size);
	return 0;
	
}

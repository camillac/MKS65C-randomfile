#include <stdio.h>
#include <stdlib.h>

int rand_int(){
	int read = calloc(1, sizeof(int));
	int file_num = open("/dev/rand", O_RDONLY);
	read(file_num, read, sizeof(int));
	int rand_num = *read;
	close(file_num);
	free(read);
	return rand_num;
}

int main(){
	int* array = calloc(10, sizeof(int));
	printf("Generating random numbers...\n");
	for (int x = 0; x < 10; x++){
		int r = rand_int();
		printf("random %d: %d\n", x, r);
		*(array + x) = r;
	}
	
	printf("\n");

	int file_num = open("test.txt", O_CREAT | O_WRONLY);
	printf("Writing to file...\n");
	write("test.txt", file_num, 10 * sizeof(int));
	close(file_num);
	
	int* read_new = calloc(10, sizeof(int));
	file_num = open("test.txt", O_RDONLY);
	printf("Reading to file...\n");
	read(file_num, read_new, 10 * sizeof(int));
	close(file_num);
	
	printf("Checking if it's correct:\n");
	for(int i = 0; i < 10; I++){
		printf("random %d: %d\n", i, *(read_new + i));
	}
	
	
}
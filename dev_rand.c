#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int rand_int(){
	int * read_here = calloc(1, sizeof(int));
	int file_num = open("/dev/random", O_RDONLY);
	read(file_num, read_here, sizeof(int));
	int rand_num = *read_here;
	close(file_num);
	free(read_here);
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
	printf("Writing to file...\n\n");
	write(file_num, array, 10 * sizeof(int));
	close(file_num);

	int* read_new = calloc(10, sizeof(int));
	file_num = open("test.txt", O_RDONLY);
	printf("Reading to file...\n\n");
	read(file_num, read_new, 10 * sizeof(int));
	close(file_num);

	printf("Checking if it's correct:\n");
	for(int i = 0; i < 10; i++){
		printf("random %d: %d\n", i, *(read_new + i));
	}

	free(read_new);
	free(array);

}

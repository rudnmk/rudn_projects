#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // <- file operations 
#include <stdlib.h>


//.txt - data in the form of ASCII characters
//		Each line - new line character (�\n�)
//		Each line - new line character (�\n�)

//FILE* my_file
//Create a file + Open the file
// - fopen(file_name, access_mode)
			//[const char]	[const char]

//access_mode:
	//Read the file
		// fscanf()
		// fgets()
		// fgetc()
		// fread() - read N bytes in the binary file
	//Write to the file (write on, append)
		// fprintf()
		// fputs()
		// fputc()
		// fwrite() - write N bytes in the binary file

//Navigate in the file

//Close file

int i = 0;
enum { SIZE = 5 };
int main(int argc, char* argv[]) {
	FILE* my_file = fopen("test.txt", "a");
	if (my_file == NULL) {
		printf("Oops! I cannnot handle the file!\n");
		return -1;
	}
	else {
		printf("Everything is good!\n");
	}

	//int* symb = (int*)malloc(sizeof(int));
	//fscanf(my_file, "%d", symb);
	//printf("%d\n", *symb);
	//free(symb);

	//char string[15] = "NO";
	////fgets(string, 10, my_file);
	//string[0] = fgetc(my_file);
	//string[0] = fgetc(my_file);
	//printf("%s\n\n", string);
	//for (int i = 0; i < 15; i++) {
	//	printf("%u\n", string[i]);
	//}
	

	//int arr[3] = { 12 };
	//int* ptr = &arr[0];
	//printf("*ptr = %d\n\n", *ptr);
	//printf("*arr = %d\n\n", *arr);
	//printf("arr[0] = %d\n\n", arr[0]);
	//printf("*(&arr[0]) = %d\n\n", *(&arr[0]));


	//double a[SIZE] = { 1.,2.,3.,4.,5. };
	//FILE* fp = fopen("test.bin", "wb"); // must use binary mode
	//fwrite(a, sizeof *a, SIZE, fp); // writes an array of doubles
	//fclose(fp);

	//double b[SIZE];
	//fp = fopen("test.bin", "rb");
	//fread(b, sizeof *b, SIZE, fp); // reads an array of doubles
	//puts("Array read successfully, contents: ");
	//for (int n = 0; n < SIZE; ++n) printf("%f ", b[n]);
	//putchar('\n');

	fprintf(my_file, "%d", 12);
	fputc('\n', my_file);
	fputc('A', my_file);
	fputc('\n', my_file);
	fputs("It's the whole new line!\n", my_file);

	fclose(my_file);

	FILE* file_for_seek = fopen("seek.txt", "a");
	printf("%ld\n", ftell(file_for_seek));
	for (i = 0; i < 5; i++) fputs("-----\n", file_for_seek);
	printf("%ld\n", ftell(file_for_seek));
	rewind(file_for_seek);
	printf("%ld\n", ftell(file_for_seek));
	fseek(file_for_seek, 2, SEEK_SET);
	fputc('A', file_for_seek);
	fclose(file_for_seek);
	return 0;
}
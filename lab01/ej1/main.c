#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

void print_help(char *program_name) {
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the max_size of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *file = fopen (filepath, "r");        /*"r" me indica que va a abrir el archivo en modo lectura*/
    if (file == NULL) {
        printf ("No se pudo abrir el archivo\n");
        exit (EXIT_FAILURE);
    }

    
    fscanf (file, "%u", &max_size);

    for (unsigned int i = 0; i< max_size; i++) {
        fscanf (file, "%d", &array[i]);
    }

    fclose(file);
    return max_size;

}

void array_dump(int a[], unsigned int max_size) {
    printf ("[ ");
    for (unsigned int i=0; i < max_size; i++){
        printf ("%d", a[i]);
        if (i<max_size - 1){
            printf (", ");
        }
    }

    printf (" ]\n");

}


int main(int argc, char *argv[]) {
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);
    
    int array[MAX_SIZE];
    
    unsigned int max_size = array_from_file(array, MAX_SIZE, filepath);
    
    array_dump(array, max_size);
    
    return EXIT_SUCCESS;
}

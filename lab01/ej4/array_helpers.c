
#include "array_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

bool array_is_sorted(int a[], unsigned int length){
    if (length<=1){
        return true;
    }
    
    for (unsigned int i=0; i<length-1; i++){
      if  (a[i]> a[i+1]){ 
        return false;
      }
    }
    return true;
}

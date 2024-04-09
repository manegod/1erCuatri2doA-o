#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H




unsigned int array_from_file (int array[], unsigned int max_size, const char *filepath);

void array_dump (int a[], unsigned int max_size);



#endif 

/* #ifndef ______ "if not defined" Verifica que el simbolo especificado no este definido
   #define ______ define el simbolo especificado y asegura que el codigo dentro de #ifndef 
   se procese una sola vez
   #endif indica el final del bloque de codigo iniciado por #ifndef
*/
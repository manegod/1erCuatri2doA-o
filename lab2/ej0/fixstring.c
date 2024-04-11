#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {

unsigned int i=0;

    do{
        i=i+1;
    } while (s[i]!='\0');

return i;

}

bool fstring_eq(fixstring s1, fixstring s2) {

bool esigual = true;

for (unsigned int i=0; (i<FIXSTRING_MAX) && (esigual); i++){

    if (s1[i]!=s2[i]){
        esigual = false;
    } 
}

return esigual;

}

bool fstring_less_eq(fixstring s1, fixstring s2) {

bool menoroigual = true;
unsigned int i = 0;

if (!fstring_eq(s1,s2)){

    while (menoroigual && i<fstring_length(s1) && i<fstring_length(s2)){
        menoroigual = (s1[i]<=s2[i]) && menoroigual;
        i++;
    }
}

return menoroigual;

}




#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {

int n = a[i];
int j = i-1;

    while ((j>=0) && (goes_before (n,a[j]))){
        swap (a, j, j+1);
        j = j-1;
    }

a[j+1] = n;

}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        assert (array_is_sorted (a,i+1)); /*si el segmento no esta ordenado el programa va a mostrar error*/
    }
}

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {

unsigned int i,j,ppiv;

ppiv = izq;
i = izq + 1;
j = der;

while (i<=j){

    while ((a[i]<=a[ppiv]) && (i<=der))
    {
        i++;
    }

    while ((a[j]>=a[ppiv]) && (j>=izq))
    {
        j--;
    }
    
    if (i<j) {
        swap (a, i ,j);
    }
    i++;
    j--;
}

    swap (a, ppiv, j);

return j;

}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {

if (der>=izq){

    unsigned int ppiv = partition (a,izq,der);

    quick_sort_rec (a,izq,ppiv-1);
    quick_sort_rec (a,ppiv+1,der);
}

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


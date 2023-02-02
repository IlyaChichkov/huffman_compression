#include <math.h>
#include "types.h"

double entropy_count(symbol* symbols, int* k)
{
    double entropy = 0;
    for (int j = 0; j < *k; ++j) {
        entropy += symbols[j].freq * log(symbols[j].freq);
    }
    return -entropy;
}

double bcost(int *fsize_2, double file_length)
{
   // :)
}

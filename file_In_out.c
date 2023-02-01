#include <stdio.h>
#include "types.h"

void reading_from_file(FILE *fp, symbol *symbols, int *uniqueSymbolsArray, int *kk, int *k) {
    int sym;
    while (1) {
        sym = fgetc(fp);
        if (sym == EOF) {
            if (feof(fp) != 0) {
                printf("\nReading finished.\n");
                break;
            } else {
                printf("\nError while reading file!\n");
                break;
            }
        }
        printf("%c", sym);
    }

}

void writing_to_file(FILE *fp2, FILE *fp3, symbol *simbols, int *kolvo, int *kk, int *k, int *fsize2) {
    // :)
}


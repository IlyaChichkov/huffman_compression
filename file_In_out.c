#include <stdio.h>
#include "types.h"

void reading_from_file(FILE *fp, symbol *symbols, int *uniqueSymbolsArray, int *kk, int *k) {
    // если в текущем массиве уникальных символов есть текущий символ - пропускаем, если нет - добавляем и увеличиваем счетчик

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

        ++*kk; // счетчик знаков в файле;
        ++*k; // счетчик уникальных символов

        //printf("\nReading new symbol: %c; k = %d", sym, *k);
        //printf("\n---unique symbols array check---");
        for (int i = 0; i < *k; ++i) {
            //printf("\n > uniqueSymbolsArray[%d] = %c", i, uniqueSymbolsArray[i]);
            if (uniqueSymbolsArray[i] == sym) {
                //printf("\n > [Found same symbol in array]");
                // Found same symbol in array
                --*k;
                //printf("\n");
                for (int j = 0; j < *k; ++j) {
                    //printf(" (*) Symbol[%d]: %c, Freq = %f\n", j, symbols[j].ch, symbols[j].freq);
                    if (symbols[j].ch == sym) {
                        //printf(" > [Found same symbol in symbols array] Symbol: %c \n", sym);
                        symbols[j].freq += 1.0f;
                        break;
                    }
                }
                break;
            }
            if (i + 1 == *k) {
                //printf("\n > [New unique symbol]");
                // New unique symbol
                uniqueSymbolsArray[*k - 1] = sym;
                symbols[*k - 1].ch = sym;
                symbols[*k - 1].freq = 1.0f;
            }
        }

        printf("%c", sym);
    }
}

void writing_to_file(FILE *fp2, FILE *fp3, symbol *simbols, int *kolvo, int *kk, int *k, int *fsize2) {
    // :)
}


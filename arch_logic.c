#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareFreq( const void* a, const void* b)
{
    symbol *symbol_A = (symbol *)a;
    symbol *symbol_B = (symbol *)b;

    if ( symbol_A->freq == symbol_B->freq ) return 0;
    else if ( symbol_A->freq > symbol_B->freq ) return -1;
    else return 1;
}

symbol* sortSymbolsByFreq(symbol* psym, int k){
    qsort( psym, k, sizeof(symbol), compareFreq);
}

symbol* makeTree(symbol* psym[], int k)
{
    // Рекурсивная функция создания дерева Хаффмана.
    // Передаем по указателю значение нового пришедшего элемента.
    // В данном случае, самого нижнего. Также передаем общее количество символов k.
    // Возвращаем - указатель на новую структуру типа symbol

    printf("\n > k: [%d]", k);
    if(k == 1) {
        printf("End");
        return psym;
    }
    symbol *temp = NULL;
    temp->left = psym[k - 2];
    temp->right = psym[k - 1];
    //temp->freq = psym[k - 2]->freq + psym[k - 1]->freq;
    psym[k - 2] = temp;

    return makeTree(psym, k - 1);
}


void makeCodes(symbol* root)
{
    // Рекурсивная функция кодирования.
    // На вход принимает указатель на полученный корень дерева
}


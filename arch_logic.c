#include "types.h"
#include <stdlib.h>
#include <string.h>

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

symbol* makeTree(symbol* psym[], int k)     //рeкурсивная функция создания дерева Хафмана. Передаем по указателю значение нового пришедшего элемента. В данном случае, самого нижнего. Также передаем общее количество символов k. Возвращаем - указатель на новую структуру типа symbol
{
    // :)
}


void makeCodes(symbol* root)//Рекурсивная функция кодирования. На вход приниает указатель на полученный корень дерева
{
   // :)
}


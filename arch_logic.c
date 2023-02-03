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

int comparePointersFreq( const void* a, const void* b)
{
    const symbol *symbol_A, *symbol_B;
    symbol_A=*(const symbol**)a;
    symbol_B=*(const symbol**)b;

    //printf("Symbols compare: %c and %c", symbol_A->ch, symbol_B->ch);
    if ( symbol_A->freq == symbol_B->freq ) return 0;
    else if ( symbol_A->freq > symbol_B->freq ) return -1;
    else return 1;
}

symbol* sortSymbolPointersByFreq(symbol* psym[], int k){
    qsort( psym, k, sizeof(symbol**), comparePointersFreq);
}

symbol* sortSymbolsByFreq(symbol* psym, int k){
    qsort( psym, k, sizeof(symbol), compareFreq);
}

symbol* makeTree(symbol** psym, int k)
{
    // Рекурсивная функция создания дерева Хаффмана.
    // Передаем по указателю значение нового пришедшего элемента.
    // В данном случае, самого нижнего. Также передаем общее количество символов k.
    // Возвращаем - указатель на новую структуру типа symbol

    // сортировка
    sortSymbolPointersByFreq(psym, k);

    if(k == 1) {
        return *psym;
    }

    symbol* newNode = malloc(sizeof(symbol));
    symbol* lastSymbolA = (void *)psym[k - 1]; // последний символ по частоте
    symbol* lastSymbolB = (void *)psym[k - 2]; // предпоследний символ по частоте
    newNode->left   = lastSymbolA;
    newNode->right  = lastSymbolB;
    newNode->ch     = 255;
    memset(newNode->code, 0, 255);
    newNode->freq   = psym[k - 2]->freq + psym[k - 1]->freq;

    psym[k - 2] = newNode;
    psym[k - 1] = NULL;

    return makeTree(psym,k - 1);
}

void showRoot(symbol* root, int layer){
    //printf("\n >");
    for (int i = 0; i < layer; ++i) {
        printf(">>");
    }
    printf("[%d]", layer);
    if(root->ch != 255){
        printf(" symbol: %c, code: %s\n", root->ch, root->code);
    }else{
        printf("\n");
    }
    if(root->left != NULL){
        showRoot(root->left, layer + 1);
    }
    if(root->right != NULL){
        showRoot(root->right,  layer + 1);
    }
}

void makeCodes(symbol* root)
{
    if(root->left != NULL){
        for (int i = 0; i < 255; ++i) {
            if(root->code[i] == '\0'){
                root->left->code[i] = '0';
                break;
            }
            root->left->code[i] = root->code[i];
        }
        makeCodes(root->left);
    }
    if(root->right != NULL){
        for (int i = 0; i < 255; ++i) {
            if(root->code[i] == '\0'){
                root->right->code[i] = '1';
                break;
            }
            root->right->code[i] = root->code[i];
        }
        makeCodes(root->right);
    }
}


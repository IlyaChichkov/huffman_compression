#ifndef FILE_H5
#define FILE_H5
int compareFreq( const void*, const void*);
symbol* sortSymbolsByFreq(symbol*, int);
symbol* makeTree(symbol**, int);
void makeCodes(symbol*);  
#endif

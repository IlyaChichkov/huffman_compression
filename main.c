#include <stdio.h>
#include <math.h> 
#include "types.h"
#include "arch_logic.h"
#include "information.h"
#include "file_In_out.h"
#include "math_func.h"
#include <locale.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Error with arguments\n");
        return 1;
    }

    printf("Program started...\n");
    FILE* fp, * fp2, * fp3;                       //указатели на файлы
    fp = fopen(argv[1], "rb");      //открываем конкретный файл
    fp2 = fopen("temp.txt", "wb");  //открываем файл для записи бинарного кода
    fp3 = fopen(argv[2], "wb");     //открываем файл для записи сжатого файла

    unsigned int chh;                           // в эту переменную читается информация из файла
    int uniqueSymbolsCount = 0;                 // счётчик количества различных букв, уникальных символов
    int symbolsCount = 0;                       // счётчик количества всех знаков в файле
    int uniqueSymbolsArray[256] = { 0 };        // инициализируем массив количества уникальных символов
    symbol symbols[256] = { 0 };                // инициализируем массив записей
    symbol* psym[256];                          // инициализируем массив указателей на записи
    int fsize2 = 0;                             // счётчик количества символов из 0 и 1 в промежуточном файле temp

    //Обработка ошибок чтения файла
    if (fp == NULL)
    {
        puts("File not open");
        return 0;
    }
    
    reading_from_file(fp, symbols, uniqueSymbolsArray, &symbolsCount, &uniqueSymbolsCount);  //Эту функцию опишите самостоятельно

    // Расчёт частоты встречаемости
    for (int j = 0; j < uniqueSymbolsCount; ++j) {
        printf("Symbol[%d]: %c, Freq = %f, ", j, symbols[j].ch, symbols[j].freq);
        symbols[j].freq = symbols[j].freq / symbolsCount;
        printf("New Freq = %f\n", symbols[j].freq);
    }

    printf("symbolsCount: %d\n", symbolsCount);
    printf("uniqueSymbolsCount: %d\n", uniqueSymbolsCount);

    double entropy = entropy_count(symbols, &uniqueSymbolsCount);
    printf("entropy: %f\n", entropy);

    // В массив указателей psym заносим адреса записей
    for (int j = 0; j < uniqueSymbolsCount; ++j) {
        psym[j] = &symbols[j];
    }

    // Сортировка по убыванию по частоте
    //sortSymbolsByFreq(symbols, uniqueSymbolsCount);

    symbol* root = makeTree(psym, uniqueSymbolsCount); //вызов функции создания дерева Хаффмана

    makeCodes(root);//вызов функции получения кода

    printf("\n --show root-- \n");
    showRoot(root, 0);

    rewind(fp); //возвращаем указатель в файле в начало файла
    //в цикле читаем исходный файл, и записываем полученные в функциях коды в промежуточный файл
    while ((chh = fgetc(fp)) != EOF)
    {
        for (int i = 0; i < uniqueSymbolsCount; i++)
            if (chh == symbols[i].ch)
                fputs(symbols[i].code, fp2);
    }
    fclose(fp2);

    //writing_to_file(fp2, fp3, symbols, uniqueSymbolsArray, &symbolsCount, &uniqueSymbolsCount, &fsize2);  //Эту функцию опишите самостоятельно
    //set_information(symbols, &uniqueSymbolsCount, &symbolsCount, &fsize2);
   
    fclose(fp);
    fclose(fp3);
    printf("\nProgram ended.\n");
    return 0;
}

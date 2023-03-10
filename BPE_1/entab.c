//
// Created by joan_ on 5.3.2023 г..
// Напишете програма entab, която заменя низ от шпации с минимален брой табулации и шпации,
// така че да се запази същото празно пространство. Използвайте същите позиции на табулатора както при detab.
// Когато и табулатор, и една-единствена шпация удовлетворяват условието да стигнат до позицията на табулатора, кое от двете ще предпочетете?

#include "stdio.h"

#define TAB_WIDTH 4
#define END 94

void stringify(char s[]) {
    char c;
    unsigned int i = 0;

    while ((c = s[i++])) {
        switch (c) {
            case '\t': printf("\\t"); break;
            case '\b': printf("\\b"); break;
            case '\\': printf("\\\\"); break;
            default: printf("%c", c);
        }
    }
}

void entab(char s[]) {
    unsigned int new_index = 0, old_index = 0, spaces = 0, counter = 0, width, window;
    char c;

    do {
        width = ++counter % TAB_WIDTH;
        while (s[old_index++] == ' ') spaces++;
//        printf("#");
        old_index--;
        if (spaces < (window = TAB_WIDTH - width + 1)) old_index -= spaces;
        else {
            while (spaces >= window) {
//                printf("-");
                s[new_index++] = '\t';
                spaces -= window;
                counter += window;
                width = counter % TAB_WIDTH;
                window = TAB_WIDTH - width + 1;
            }
            for (int k = 0; k < spaces; k++) s[new_index++] = ' ';
//            printf("O");
        }
        spaces = 0;
    } while ((s[new_index++] = s[old_index++]) != 0);
//    printf("\n");
}

int main(void) {
    char c, line[200];
    unsigned int i = 0;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        if ((line[i++] = c) == '\n') {
            line[--i] = 0;
            entab(line);
            printf("%s\n", line);
            stringify(line);
            printf("\n");
            i = 0;
        }
    }
}

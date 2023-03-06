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
    unsigned int i = 0, j = 0, spaces = 0, counter = 0;
    char c;

    while ((s[j++] = s[i++])) {
        if (++counter > TAB_WIDTH) counter = 1;
        while (s[i++] == ' ') spaces++;
        if (spaces == 0) i--;
        else if (spaces >= TAB_WIDTH - counter + 1) {
            s[j++] = '\t';
            for (int k = 0; k < spaces - (TAB_WIDTH - counter + 1); k++) s[j++] = ' ';
        }
        else i -= spaces;
        spaces = 0;
    }
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

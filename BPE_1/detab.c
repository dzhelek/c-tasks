//
// Created by joan_ on 5.3.2023 г..
// Напишете програма detab, която заменя табулациите от входа с подходящ брой шпации,
// така че да се запази разстоянието до следващата позиция на табулатора.
// Допуснете, че разполагате с фиксиран набор от позиции на табулатора,
// да кажем на всеки п колони. Трябва ли n да бъде променлива или символен параметър?
#include "stdio.h"

#define TAB_WIDTH 4
#define END 94

int main(void) {
    char c;
    unsigned int counter = 0;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        if (++counter > TAB_WIDTH) counter = 1;
        //printf("\n counter = %d\n", counter);
        if (c == '\t') {
            for (int i = 0; i < TAB_WIDTH - counter + 1; i++) printf(" ");
            counter += TAB_WIDTH - counter + 1;
        }
        else printf("%c", c);
        if (c == '\n') counter = 0;
    }
}

//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която отпечатва входа си, като всяка дума е поставена на отделен ред.
#include <stdio.h>

#define END 94

int main(void) {
    char c;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        if (c == ' ') printf("\n");
        else printf("%c", c);
    }
}

//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която отпечатва хистограма, отразяваща колко често се срещат различните символи на входа.
#include <stdio.h>

#define END 94

int main(void) {
    char c;
    unsigned int i = 0, frequencies[256];

    for (i = 0; i <= 255; i++) frequencies[i] = 0;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        frequencies[c]++;
    }
    printf("\nHistogram of words based on their frequency:");
    i = ' ';
    while (i <= 255) {
        printf("\n'%c'\t", i);
        for (int j = 0; j < frequencies[i]; j++) printf("#");
        while (frequencies[++i] == 0);
    }
}

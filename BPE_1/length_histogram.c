//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която отпечатва хистограма с дължините на думите, подадени на входа.
// По-лесно е да начертаете хистограма хоризонтално; вертикалната хистограма е по-предизвикателна.
#include <stdio.h>

#define END 94

int main(void) {
    char c;
    unsigned int max = 0, length = 0, lengths[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (length > 14) length = 14;
            lengths[length]++;
            if (length > max) max = length;
            length = 0;
        }
        else length++;
    }
    printf("\nHistogram of words based on their length:");
    for (int i = 1; i < max; i++) {
        printf("\n%d:\t", i);
        for (int j = 0; j < lengths[i]; j++) printf("#");
    }
}

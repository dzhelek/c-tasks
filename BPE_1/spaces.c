//
// Created by joan_ on 5.3.2023 г..
//Напишете програма, която копира входа си на изхода, като замества всеки низ, съставен от една или повече шпации, с една-единствена шпация.

#include <stdio.h>

#define END 94

int main(void) {
    char c, previous_c = 0;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        if (c != ' ' || previous_c != ' ') printf("%c", c);
        previous_c = c;
    }
}


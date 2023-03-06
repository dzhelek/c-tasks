//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която преброява шпациите, табулациите и новите редове.

#include <stdio.h>

#define END 94

int main(void) {
    char c;
    unsigned int spaces, tabs, lines;

    spaces = tabs = lines = 0;
    printf("Enter text including new lines, then hit Enter and ^D:\n");
    while ((c = getchar()) != END) {
        switch (c) {
            case ' ': spaces++; break;
            case '\t': tabs++; break;
            case '\n': lines++; break;
        }
    }
    printf("spaces: %d\ntabs: %d\nlines: %d\n\n", spaces, tabs, lines);
}
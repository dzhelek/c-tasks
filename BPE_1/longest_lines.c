//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която отпечатва всички входни редове, които са по-дълги от 80 символа.

#include "stdio.h"

#define END 94
#define MAXLINES 10
#define MAXCHARACTERS 200

char c, lines[MAXLINES][MAXCHARACTERS];
unsigned int length = 0, line_index = 0;

int main(void){
    printf("Enter text including new lines, then hit Enter and ^D:\n");
    while ((c = getchar()) != END) {
        if ((lines[line_index][length++] = c) == '\n') {
            lines[line_index][length] = 0;
            if (length > 80) line_index++;
            length = 0;
        }
    }
    printf("lines longer than 80 symbols: \n");
    for (int i = 0; i < line_index; i++) printf("%s", lines[i]);
}
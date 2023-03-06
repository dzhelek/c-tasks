//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която премахва последните шпации и табулации от всеки входен ред и изтрива празните редове.
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
            if (length == 1) {
                length = 0;
                continue;
            }
            length -= 2;
            while (lines[line_index][length] == ' ' || lines[line_index][length] == '\t') --length;
            lines[line_index][++length] = '\n';
            lines[line_index][++length] = 0;
            length = 0;
            line_index++;
        }
    }
    for (int i = 0; i < line_index; i++) printf("%s", lines[i]);
}

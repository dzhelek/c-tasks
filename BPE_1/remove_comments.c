//
// Created by joan_ on 2.4.2023 г..
//
/* Напишете програма, която премахва всички коментари от С програма.
   Не забравяйте да обърнете специално внимание на коментарите, поставени в низове в кавички и в символни константи.
   Коментарите в С не се вграждат. */
#include "stdio.h"

#define END 94
#define MAXCHARACTERS 10000

char c, text[MAXCHARACTERS], previous = 0;
unsigned int length = 0, is_skipping_line = 0, is_skipping_block = 0, is_in_string = 0;

int main(void/* it may be not void */){
// hello world
    printf("Enter text including new lines and // comments, then hit Enter and ctrl+D:\n"); // hahaha comment
    while ((c = getchar()) != END) {
        if (c == '\"' && text[length-1] != '\\') is_in_string ^= 1;
        if (!is_skipping_line && !is_skipping_block) text[length++] = c;
        else if (c == '\n'){
            is_skipping_line = 0;
            text[length++] = '\n';
        }
        if (is_skipping_block) {
            if (c == '*') previous = '*';
            else if (c == '/' && previous == '*') {
                is_skipping_block = 0;
                previous = 0;
            }
        }
//        if (length != 0 && c == '/' && text[length-2] == '*') is_skipping_block = 0;
        if (length != 0 && !is_in_string) {
            if (c == '/' && text[length-2] == '/') {
                is_skipping_line = 1;
                length -= 2;
            }
            else if (c == '*' && text[length-2] == '/') {
                is_skipping_block = 1;
                length -= 2;
            }
        }
    }
    for (int i = 0; i < length; i++) printf("%c", text[i]);

    return 0;
}

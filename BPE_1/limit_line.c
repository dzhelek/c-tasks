//
// Created by joan_ on 2.4.2023 г..
//
// Напишете програма, която разделя дългите входни редове на два или повече по-кратки след последния символ,
// различен от празно пространство, който се появява преди и-тата колона от входа.
// Уверете се, че програмата ви ще работи с много дълги редове и ако преди определената колона няма шпации или табулации.
#include <stdio.h>
#include <string.h>

#define END 94
#define MAXCHARACTERS 120

void print_line(char* line, unsigned int bytes) {
    unsigned j;
    for (j = 0; j < bytes; ++j) printf("%c", line[j]);
}

int main(void) {
    char c, line[MAXCHARACTERS];
    unsigned i = 0, last_space_index = MAXCHARACTERS;

    printf("Enter text including new lines, then hit Enter and ^D:\n");
    while ((c = getchar()) != END) {
        line[i++] = c;
        if (c == '\n'){
            print_line(line, i);
            i = 0;
            continue;
        }
        if (c == ' ') last_space_index = i;
        if (i == MAXCHARACTERS){
            print_line(line, last_space_index);
            printf("\n");
            i = MAXCHARACTERS - last_space_index;
            if (i) memcpy(line, &line[last_space_index], i);
        }
    }
}

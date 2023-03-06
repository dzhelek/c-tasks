//
// Created by joan_ on 5.3.2023 г..
// Напишете програма, която копира входа си на изхода, като замества всеки табулатор с \t, всяко връщане със символ
// назад с \b и всяка обратно наклонена черта с \\.
// По този начин табулациите и връщането със символ назад стават видими по един недвусмислен начин.

#include <stdio.h>

#define END 94

int main(void) {
    char c;

    printf("End program with ^D:\n");
    while ((c = getchar()) != END) {
        switch (c) {
            case '\t': printf("\\t"); break;
            case '\b': printf("\\b"); break;
            case '\\': printf("\\\\"); break;
            default: printf("%c", c);
        }
    }
}

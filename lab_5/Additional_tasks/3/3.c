#include <stdio.h>
#include <string.h>
#include <stdbool.h>



void main() {
    char str_1[] = "dsadsadad dsadadasda xcxzczczxcxzczcz Mama Papa Maldives";
    char str_2[] = "d";

    int k = 1;
    bool flag;
    for (int i = 1; i < strlen(str_1); i++) {
        flag = true;
        for (int j = 0; j < strlen(str_2); j++) {
            // printf("%c // ", str_1[i]);
            // printf("%c /// ", str_2[j]);
            // printf("%s \n", str_2);
            if (str_2[j] == str_1[i]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            printf("%c", str_1[i]);
            str_2[k] = str_1[i];
            k++;
        }
    }
    //printf("%s", str_2);
}
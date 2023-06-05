#include <stdio.h>
#include <string.h>

char c;
void from_keyboard();
void from_file();

void main() {
    int choice;
    printf("Выберите способ ввода данных. 1 - с клаиватуры, 2 - с файла .txt\n");
    scanf("%d", &choice);
    if (choice == 1) {
        from_keyboard();
        printf("EOF!");
    }
    else if (choice == 2) {
        from_file();
        printf("EOF!");
    }
}


void from_keyboard() {
    int flag = 0;
    while((c = getchar()) != EOF) {
        if (flag == 0) {
            flag++;
        }
        else {
           if(c == '\n' || c == '\t') {
                if(c == '\n') {
                    printf("[10] - \\n\n");
                }
                if(c == '\t') {
                    printf("[9] - \\t\n");
                }
                }
            else {
                printf("[%d] - %c\n", c, c);
            }   

        }
    }
}

void from_file(){
    int tab_count;
    FILE* file = fopen("task_2.txt", "r");
    while ((c = fgetc(file)) != EOF) {
        if(c == '\n') {
            printf("[10] - \\n\n");
        }
        else {
            printf("[%d] - %c\n", c, c);
        }
    }
    fclose(file);
}

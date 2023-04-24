int main() {
   int* ptr;
   int arrTwo[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
           printf("arrTwo[%d][%d] = %d\t\t", i, j, arrTwo[i][j]);
           printf("address = %p\n", &arrTwo[i][j]);
       }
   }

   printf("\n\nNew life:\n\n");
   int i = 0;
   int j = 0;
   for (ptr = &arrTwo[0][0]; ptr <= &arrTwo[2][3]; ptr++) {
       printf("arrTwo[%d][%d] = %d\n", i, j, *ptr);
       j++;
       if (j == 4) {
           i++;
           j = 0;
       }
   }
   printf("\n%p\n", arrTwo);
   //printf("\n\n%p", arrTwo[][4]);
   printf("%p\n", &arrTwo[0][0]);
   printf("%p\n", arrTwo[0]);
   printf("%p\n", &arrTwo[1][0]);
   printf("%p\n", arrTwo[1]);      //Не хватает звезды, синтаксис возвращает указатель
   printf("%d\n", *arrTwo[0]);
   printf("%d\n", arrTwo[1][3]);

   printf("%d\n", *(arrTwo + 1));
   printf("%d\n", *(*(arrTwo + 1) + 1));


   return 0;
}
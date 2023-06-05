#include <stdio.h>
#include <math.h>
#include <string.h>

float We = 7.2921159 / 100000;
float Mu = 398600.4;
float i = 63.4;
float Rp;
float Va;
float Vw;
int flag = 0;


void main() {
    FILE* file = fopen("task_1.txt", "w");
    fprintf(file, "Ra: Va                    Vw\n");
    Rp = (pow(We, 2) * pow(45000, 4) * pow(cos(i), 2)) / ((2 * Mu) - (pow(We * pow(10, -5), 2) * pow(45000, 3) * pow(cos(i), 2)));
    for (int Ra = 10; Ra < 60010; Ra = Ra + 10) {
        Va = sqrt((2 * Mu * Rp) / (Ra * (Ra + Rp)));
        Vw = We * Ra * cos(i);
        if (flag != 0 || Va <= Vw) {
            if (flag == 0) {
                float Va_tmp;
                float Vw_tmp;
                for (int tmp = Ra - 9; tmp < Ra + 1; tmp++) {
                    Va_tmp = sqrt((2 * Mu * Rp) / (tmp * (tmp + Rp)));
                    Vw_tmp = We * tmp * cos(i);
                    fprintf(file, "%i: %f            %f\n", tmp, Va_tmp, Vw_tmp);
                    if (Va_tmp <= Vw_tmp) {
                        break;
                    }
                }
            }
            fprintf(file, "%i: %f\n", Ra, Va);
            flag = 1;
        }
        else {
            fprintf(file, "%i: %f            %f\n", Ra, Va, Vw);
        }
        
    }
    fclose(file);
}
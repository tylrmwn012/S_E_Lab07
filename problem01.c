#include <stdio.h>

int combinations(int score) { 
    int TD = 6;
    int FG = 3;
    int safety = 2;
    int TDwPP = 8;
    int TDFG = 7;




    return printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety");
}


void main() {
    int score = 2;

    while (score != 0 || score != 1) {
        printf("Enter 0 or 1 to STOP");
        scanf("Enter the NFL score: %d", &score);

        printf(combinations(score));
    }
    return 0;
}
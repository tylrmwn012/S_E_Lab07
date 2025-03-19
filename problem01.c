#include <stdio.h>

void combinations(int score) { 
    int td_8, td_7, td_6, fg, safety;
    int found = 0;

    printf("Possible combinations of scoring plays if a teams score is %d:\n", score);

    for (td_8 = 0; td_8 * 8 <= score; td_8++) {
        for (td_7 = 0; td_7 * 7 <= score; td_7++) {
            for (td_6 = 0; td_6 * 6 <= score; td_6++) {
                for (fg = 0; fg * 3 <= score; fg++) {
                    for (safety = 0; safety * 2 <= score; safety++) {
                        if ((td_8 * 8) + (td_7 * 7) + (td_6 * 6) + (fg * 3) + (safety * 2) == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_8, td_7, td_6, fg, safety);
                            found = 1;
                        }
                    }
                }
            }
        }
    }

    if (!found) {
        printf("No valid combinations for a score of %d.\n", score);
    }
}

int main() {
    int score = 2;

    while (score != 0 && score != 1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score != 0 && score != 1) {
            combinations(score);  
        }
    }

    return 0;
}

/* Program Title: EECS 348 Lab 07
   Description: This C project prompts a user to enter the number of points a team in the NFL
                has received, then returns every possible combination of points possible 
                to get to that score.
   Inputs: The score of the NFL football game as an integer
   Outputs: Every combination of points to get to that score
   Collaborators: None
   Sources: None
   Author: Tyler Mowen
   Creation Date: 19 March, 2025 */
#include <stdio.h> // import the standard C library

int count_combinations(int points) {
    int td_8, td_7, td_6, fg, safety;
    int count = 0;

    for (td_8 = 0; td_8 * 8 <= points; td_8++) {
        for (td_7 = 0; td_7 * 7 <= points; td_7++) {
            for (td_6 = 0; td_6 * 6 <= points; td_6++) {
                for (fg = 0; fg * 3 <= points; fg++) {
                    for (safety = 0; safety * 2 <= points; safety++) {
                        if ((td_8 * 8) + (td_7 * 7) + (td_6 * 6) + (fg * 3) + (safety * 2) == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}

void print_combinations(int points) {
    int td_8, td_7, td_6, fg, safety;
    int found = 0;

    printf("Possible combinations of scoring plays for %d points:\n\n", points);

    for (td_8 = 0; td_8 * 8 <= points; td_8++) {
        for (td_7 = 0; td_7 * 7 <= points; td_7++) {
            for (td_6 = 0; td_6 * 6 <= points; td_6++) {
                for (fg = 0; fg * 3 <= points; fg++) {
                    for (safety = 0; safety * 2 <= points; safety++) {
                        if ((td_8 * 8) + (td_7 * 7) + (td_6 * 6) + (fg * 3) + (safety * 2) == points) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_8, td_7, td_6, fg, safety);
                            found = 1;
                        }
                    }
                }
            }
        }
    }

    if (!found) {
        printf("No valid combinations for %d points.\n", points);
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score == 0 || score == 1) {
            break;
        }
        
        printf("Total combinations: %d\n", count_combinations(score));
        print_combinations(score);
    }

    return 0;
}

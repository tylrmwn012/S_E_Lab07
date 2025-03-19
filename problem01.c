#include <stdio.h> // import the standard C library

void combinations(int score) { // initialize function which takes score and calculates each possible combination to reach score
    int td_8, td_7, td_6, fg, safety; // initialize integer variables
    int found = 0; // initialize found as an integer set to 0

    printf("Possible combinations of scoring plays if a teams score is %d:\n", score); // display the number of combinations to get score
    printf(" \n"); // print blank line between prompt and possibilities

    // each of the following for loops depends on the previous loops number of occurences in the current combination
    for (td_8 = 0; td_8 * 8 <= score; td_8++) { // loop through number of td_8 that can add up to almost the score
        for (td_7 = 0; td_7 * 7 <= score; td_7++) { // loop through number of td_7 that can add up to almost the score
            for (td_6 = 0; td_6 * 6 <= score; td_6++) { // loop through number of td_6 that can add up to almost score
                for (fg = 0; fg * 3 <= score; fg++) { // loop through number of fg that can add up to score
                    for (safety = 0; safety * 2 <= score; safety++) { // loop through number of safety that add up to almost score
                        if ((td_8 * 8) + (td_7 * 7) + (td_6 * 6) + (fg * 3) + (safety * 2) == score) { // if the combo adds up to score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_8, td_7, td_6, fg, safety); // display the combo
                            found = 1; // set found equal to 1
                        } // close for loop
                    } // close for loop
                } // close for loop
            } // close for loop
        } // close for loop
    } // close for loop

    if (!found) { // if no combination is found...
        printf("No valid combinations for a score of %d.\n", score); // tell user no combinations were found to reach score
    } // close if statement
} // close function

int main() { // initialize function main() 
    int score = 2; // initialize score as 2 before entering the loop

    while (score != 0 && score != 1) { // while the score is not 0 and not 1...
        printf("Enter 0 or 1 to STOP\n"); // let user know to enter 0 or 1 to exit the loop
        printf("Enter the NFL score: "); // prompt user to enter a score
        scanf("%d", &score); // take user's input and set as score

        if (score != 0 && score != 1) { // if score is not 0 and not 1
            combinations(score); // call function to display every possible combo/number of combos
        } // close if statement 
    } // close while loop

    return 0; // retunr null
} // close main function

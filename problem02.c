#include <stdio.h> // import functions from standard library like printf
#include <string.h> // import functions from library like strcmp

float celsius_to_fahrenheit(float celsius) { // initialize function to convert celsius to fahrenheit
    return (9.0 / 5) * celsius + 32; // return value in fahrenheit
} // close function

float fahrenheit_to_celsius(float fahrenheit) { // initialize function to convert fahrenheit to celsius
    return (5.0 / 9) * (fahrenheit - 32); // return value in celsius
} // closer function

float celsius_to_kelvin(float celsius) { // initialize function to convert celsius to kelvin
    return celsius + 273.15; // return value in kelvin
} // close function

float kelvin_to_celsius(float kelvin) { // initialize function to convert kelvin to celsius
    return kelvin - 273.15; // return value in celsius
} // close function

float kelvin_to_fahrenheit(float kelvin) { // initialize function to convert kelvin to fahrenheit
    return 1.8 * (kelvin - 273.15) + 32; // return value in fahrenheit
} // close function

float fahrenheit_to_kelvin(float fahrenheit) { // initialize function to convert fahrenheit to kelvin
    return (fahrenheit - 32) / 1.8 + 273.15; // return value in kelvin
} // close fucntion

const char* categorize_temperature(float celsius) { // initialize function to return string depending on degrees in celsius
    if (celsius < 0) { // if celsius is below zero
        return "Temperature category: Freezing\nWeather advisory: Stay Indoors"; // display category and advisory
    } else if (celsius < 10) { // else if celsius is less than 10...
        return "Temperature category: Cold\nWeather advisory: Wear a Coat"; // display category and advisory
    } else if (celsius < 25) { // else if celsius is less than 25...
        return "Temperature category: Comfortable\nWeather advisory: Go Outside"; // display category and advisory
    } else if (celsius < 35) { // else if celsius is less than 35...
        return "Temperature category: Hot\nWeather advisory: Drink Plenty of Water"; // display category and advisory
    } else { // else...
        return "Temperature category: Extreme Heat\nWeather advisory: Stay Indoors"; // display category and advisory
    } // close else statement
} // close function

int main() { // initialize main function
    float tempValue; // initialize tempValue as float
    char tempScale[10], tempConv[10]; // initialize tempScale and tempConv as char arrays of length 10

    printf("Enter the temperature: "); // prompt user to enter their temperature
    scanf("%f", &tempValue); // store input in tempValue

    printf("Choose the current scale (Celsius, Fahrenheit, Kelvin): "); // prompt user to enter value of entered temp
    scanf("%s", tempScale); // store input in tempScale

    printf("Convert to (Celsius, Fahrenheit, Kelvin): "); // prompt user to enter temp to convert to
    scanf("%s", tempConv); // store input in tempConv

    float convertedTemp = 0; // initialize float convertedTemp as 0

    if (strcmp(tempScale, "Fahrenheit") == 0) { // checks if the string entered is Fahrenheit (== 0 would return True)
        if (strcmp(tempConv, "Fahrenheit") == 0) { // checks if the string entered is Fahrenheit (== 0 would return True)
            printf("Error: Invalid Conversion\n"); // displays error message to user
            return 0; // return null
        } else if (strcmp(tempConv, "Celsius") == 0) { // checks if the string entered is Celsius (== 0 would return True)
            convertedTemp = fahrenheit_to_celsius(tempValue); // call function to convert fahrenheit to celsius
        } else if (strcmp(tempConv, "Kelvin") == 0) { // checks if the string entered is Kelvin (== 0 would return True)
            convertedTemp = fahrenheit_to_kelvin(tempValue); // call function to convert fahrenheit to kelvin
        }
    } else if (strcmp(tempScale, "Celsius") == 0) { // checks if the string entered is Celsius (== 0 would return True)
        if (strcmp(tempConv, "Fahrenheit") == 0) { // checks if the string entered is Fahrenheit (== 0 would return True)
            convertedTemp = celsius_to_fahrenheit(tempValue); // call function to convert celsius to fahrenheit
        } else if (strcmp(tempConv, "Kelvin") == 0) { // checks if the string entered is Kelvin (== 0 would return True)
            convertedTemp = celsius_to_kelvin(tempValue); // call function to convert celsius to kelvin
        } else if (strcmp(tempConv, "Celsius") == 0) {  // checks if the string entered is Celsius (== 0 would return True)
            printf("Error: Invalid Conversion\n"); // display error message to user
            return 0; // return null
        }
    } else if (strcmp(tempScale, "Kelvin") == 0) { // checks if the string entered is Kelvin (== 0 would return True)
        if (strcmp(tempConv, "Fahrenheit") == 0) { // checks if the string entered is Fahrenheit (== 0 would return True)
            convertedTemp = kelvin_to_fahrenheit(tempValue); // call function to convert Kelvin to Fahrenheit
        } else if (strcmp(tempConv, "Celsius") == 0) { // checks if the string entered is Celsius (== 0 would return True)
            convertedTemp = kelvin_to_celsius(tempValue); // call function to convert kelvin to celsius
        } else if (strcmp(tempConv, "Kelvin") == 0) { // checks if the string entered is Kelvin (== 0 would return True)
            printf("Error: Invalid Conversion\n"); // display that the conversion is invalid
            return 0; // return null
        } // close else if statement
    } else { // else...
        printf("Error: Invalid Scale Entered\n"); // display the error to user
        return 0; // return null
    } // close else

    printf("\nConverted temperature: %.2f\n", convertedTemp); // display the user's converted temperature

    float celsius; // initialize celsius as float
    if (strcmp(tempScale, "Fahrenheit") == 0) {
        celsius = fahrenheit_to_celsius(tempValue); // set celsius equal to the tempValue converted to celsius
    } else if (strcmp(tempScale, "Kelvin") == 0) { // checks if the string entered is Kelvin (== 0 would return True)
        celsius = kelvin_to_celsius(tempValue); // set celsius equal to the entered temperature converted to celsius
    } else { // else...
        celsius = tempValue; // set celsius equal to the tempValue
    } // close else statement

    printf("%s\n", categorize_temperature(celsius)); // print the temperature's category and weather advisory

    return 0; // return null
} // close main function

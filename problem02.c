#include <stdio.h>

float celsius_to_fahrenheit (float celsius) {
    return (9/5) * celsius + 32;
}

float fahrenheit_to_celsius (float fahrenheit) {
    return (5/9) * (fahrenheit - 32);
}

float celsius_to_kelvin (float celsius) {
    return celsius + 273.15 ;
}

float kelvin_to_celsius (float kelvin) {
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit (float kelvin) {

}

float fahrenheit_to_kelvin (float fahrenheit) {

}

void categorize_temperature(float celsius) {


}


void main () {
    float tempValue;
    char tempScale[10];
    char tempConv[10];

    printf("Enter the temperature: ");
    scanf("%d", &tempValue);
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%s", &tempScale);
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%s", &tempConv);

    if (tempScale == "Farenheit") {
        if (tempConv == "Farenheit") {
            printf("Error: Invalid Conversion");
        } else if (tempConv == "Celsius") {
            printf("Converted temperature: %d", fahrenheit_to_celsius(tempScale[10]));
        } else if (tempConv == "Kelvin") {
            // faren to kelvin
            printf("Converted temperature: %d", fahrenheit_to_kelvin(tempScale[10]));
        }

    } else if (tempScale == "Celsius") {
        if (tempConv == "Farenheit") {
            printf("Converted temperature: %d", celsius_to_fahrenheit(tempScale[10]));
        } else if (tempConv == "Celsius") {
            printf("Error: Invalid Conversion");
        } else if (tempConv == "Kelvin") {
            printf("Converted temperature: %d", celsius_to_kelvin(tempScale[10]));
        }

    } else if (tempScale == "Kelvin") {
        if (tempConv == "Farenheit") {
            printf("Converted temperature: %d", kelvin_to_fahrenheit(tempScale[10]));
        } else if (tempConv == "Celsius") {
            printf("Converted temperature: %d", kelvin_to_celsius(tempScale[10]));
        } else if (tempConv == "Kelvin") {
            printf("Error: Invalid Conversion");
        }
    }

}


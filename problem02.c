#include <stdio.h>
#include <string.h>

float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float kelvin_to_fahrenheit(float kelvin) {
    return 1.8 * (kelvin - 273.15) + 32;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return (fahrenheit - 32) / 1.8 + 273.15;
}

const char* categorize_temperature(float celsius) {
    if (celsius < 0) {
        return "Temperature category: Freezing\nWeather advisory: Stay Indoors";
    } else if (celsius < 10) {
        return "Temperature category: Cold\nWeather advisory: Wear a Coat";
    } else if (celsius < 25) {
        return "Temperature category: Comfortable\nWeather advisory: Go Outside";
    } else if (celsius < 35) {
        return "Temperature category: Hot\nWeather advisory: Drink Plenty of Water";
    } else {
        return "Temperature category: Extreme Heat\nWeather advisory: Stay Indoors";
    }
}

int main() {
    float tempValue;
    char tempScale[10], tempConv[10];

    printf("Enter the temperature: ");
    scanf("%f", &tempValue);

    printf("Choose the current scale (Celsius, Fahrenheit, Kelvin): ");
    scanf("%s", tempScale);

    printf("Convert to (Celsius, Fahrenheit, Kelvin): ");
    scanf("%s", tempConv);

    float convertedTemp = 0;

    if (strcmp(tempScale, "Fahrenheit") == 0) {
        if (strcmp(tempConv, "Fahrenheit") == 0) {
            printf("Error: Invalid Conversion\n");
            return 0;
        } else if (strcmp(tempConv, "Celsius") == 0) {
            convertedTemp = fahrenheit_to_celsius(tempValue);
        } else if (strcmp(tempConv, "Kelvin") == 0) {
            convertedTemp = fahrenheit_to_kelvin(tempValue);
        }
    } else if (strcmp(tempScale, "Celsius") == 0) {
        if (strcmp(tempConv, "Fahrenheit") == 0) {
            convertedTemp = celsius_to_fahrenheit(tempValue);
        } else if (strcmp(tempConv, "Kelvin") == 0) {
            convertedTemp = celsius_to_kelvin(tempValue);
        } else if (strcmp(tempConv, "Celsius") == 0) {
            printf("Error: Invalid Conversion\n");
            return 0;
        }
    } else if (strcmp(tempScale, "Kelvin") == 0) {
        if (strcmp(tempConv, "Fahrenheit") == 0) {
            convertedTemp = kelvin_to_fahrenheit(tempValue);
        } else if (strcmp(tempConv, "Celsius") == 0) {
            convertedTemp = kelvin_to_celsius(tempValue);
        } else if (strcmp(tempConv, "Kelvin") == 0) {
            printf("Error: Invalid Conversion\n");
            return 0;
        }
    } else {
        printf("Error: Invalid Scale Entered\n");
        return 0;
    }

    printf(" \n");
    printf("Converted temperature: %.2f\n", convertedTemp);

    float celsius;
    if (strcmp(tempScale, "Fahrenheit") == 0) {
        celsius = fahrenheit_to_celsius(tempValue);
    } else if (strcmp(tempScale, "Kelvin") == 0) {
        celsius = kelvin_to_celsius(tempValue);
    } else {
        celsius = tempValue;
    }

    printf("%s\n", categorize_temperature(celsius));

    return 0;
}

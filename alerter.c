#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int sendTemperatureAlert(float temperatureInCelsius) {
    printf("ALERT: Temperature is %.1f Celsius.\n", temperatureInCelsius);
    return (temperatureInCelsius > 200.0) ? 500 : 200;
}

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void checkTemperature(float fahrenheit) {
    float celsius = convertFahrenheitToCelsius(fahrenheit);
    int responseCode = sendTemperatureAlert(celsius);
    if (responseCode != 200) {
        alertFailureCount++;
    }
}

int main() {
    checkTemperature(400.5);  // Should fail (high temp)
    checkTemperature(303.6);  // Should fail (high temp)
    checkTemperature(150.0);  // Should pass (lower temp)

    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 2);  // Should be true if the logic is correct
    printf("All is well (maybe!)\n");
    return 0;
}


int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}

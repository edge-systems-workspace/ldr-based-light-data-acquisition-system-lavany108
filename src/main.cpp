/**
 * @file main.cpp
 * @brief Light intensity monitor using an LDR (photoresistor) and Arduino.
 *
 * @details
 * This example reads an analog value from an LDR connected to an analog input
 * and maps the 10-bit ADC reading (0-1023) to a percentage (0-100). Both the
 * raw ADC value and the computed light percentage are printed to the Serial
 * console at 9600 baud every 500 ms.
 *
 * Hardware connections (typical):
 *  - Connect the LDR as part of a voltage divider to the analog pin defined
 *    by `ldrPin` (A0). Example: 5V -> LDR -> A0 -> fixed resistor -> GND.
 *  - Ensure the board's GND is common with the sensor ground.
 *
 * @author Lavanya
 * @date 2026-02-28
 * @version 1.0
 */

#include <Arduino.h>

/**
 * @brief Analog pin used for the LDR voltage divider.
 *
 * @note Change this macro if you connect the LDR to a different analog pin.
 */
#define ldrPin A0

/**
 * @brief Arduino setup function.
 *
 * @details Initializes the serial console (9600 baud), configures the LDR
 * pin as an input, and prints an initial identification message. This
 * function runs once when the board powers up or resets.
 *
 * @return void
 */
void setup() {
// write your initialization code here
    Serial.begin(9600);
    pinMode(ldrPin,INPUT);
    Serial.println("LDR Test");
}

/**
 * @brief Arduino main loop function.
 *
 * @details
 * Executes repeatedly after setup() finishes. This implementation:
 *  - Reads the raw analog-to-digital converter (ADC) value from @c ldrPin.
 *  - Maps the 0-1023 ADC range to a 0-100 percentage using Arduino's map().
 *  - Prints both the raw ADC value and the computed percentage to Serial.
 *  - Delays for 500 ms between samples.
 *
 * @note The map() function used here performs integer arithmetic. For
 * higher-resolution percentage values, consider using floating-point math and
 * scaling accordingly.
 *
 * @return void
 */
void loop() {
// write your code here
    int ldrRaw= analogRead(ldrPin);
    //Map to percentage
    int lightPercentage= map(ldrRaw,0,1023,0,100);
    Serial.print("LDR Raw: ");
    Serial.println(ldrRaw);
    Serial.print("Light Percentage: ");
    Serial.println(lightPercentage);
    delay(500);
}
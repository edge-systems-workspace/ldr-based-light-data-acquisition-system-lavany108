#include <Arduino.h>
#define ldrPin A0
void setup() {
    // write your initialization code here
    Serial.begin(9600);
    pinMode(ldrPin,INPUT);
    Serial.println("LDR Test");
}
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
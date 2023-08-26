#include "motors.h"
#include "distance_sensors.h"
#include "controller_IR.h"
#include "contants_declaration"
int flag = 0; 

void setup(){
    Serial.begin(115200);

    motorsInit();
    sensorsInit();
}

void loop(){
    
    controller_IR();

    if(stage == 1) {
        digitalWrite(2, HIGH);
    } else if(stage == 2) {
        distance_Read();
        if (distC < distAtk/3 and (distL < distAtk/3 or distR < distAtk/3)){
            Serial.print(("ATACANDO MAX /t/t"));
        }
    }

}
/**
 * ESP32 zur Steuerung des Pools:
 * - 2 Temperaturfühler
 * - Interner Temperatur-Sensor
 * - 433MHz Sender für Pumpnsteuerung
 *
 * Wird über openHAB gesteuert.
 */

/*
 # This sample code is used to test the pH meter V1.0.
 # Editor : YouYou
 # Ver    : 1.0
 # Product: analog pH meter
 # SKU    : SEN0161
 see: https://wiki.dfrobot.com/PH_meter_SKU__SEN0161_
*/

#include <Arduino.h>
#include <Homie.h>

#ifdef ESP32
const uint8_t SENSOR_PIN = 0; //pH meter Analog output to Analog Input

#elif defined(ESP8266)
const uint8_t SENSOR_PIN = PIN_A0; //pH meter Analog output to Analog Input

#endif

const unsigned long  OFFSET = 0.00; //deviation compensate
const unsigned long  samplingInterval = 20;
const unsigned long  printInterval = 800;
const uint8_t ArrayLenth= 40; //times of collection

int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;


double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){
    //less than 5, calculated directly statistics
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}


/**
 * Startup of controller.
 */
void setup() {
  Serial.begin(SERIAL_SPEED);


  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  Homie_setFirmware("water-quality-monitor", "1.0.0");  // The underscore is not a typo! See Magic bytes
  Homie_setBrand("smart-swimmingpool");


  Homie.setup();

  Homie.getLogger() << F("Free heap: ") << ESP.getFreeHeap() << endl;
}

/**
 * Main loop of ESP.
 */
void loop() {

  Homie.loop();

  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue, voltage;

  if((millis() - samplingTime) > samplingInterval) {

      pHArray[pHArrayIndex++] = analogRead(SENSOR_PIN);

      if(pHArrayIndex==ArrayLenth){
        pHArrayIndex=0;
      }
      voltage = avergearray(pHArray, ArrayLenth) * 5.0/1024;
      pHValue = 3.5 * voltage + OFFSET;
      samplingTime = millis();
  }
  if((millis() - printTime) > printInterval) {
    //Every 800 milliseconds, print a numerical, convert the state of the LED indicator

    Serial.print("Voltage:");
    Serial.print(voltage, 2);
    Serial.print("    pH value: ");
    Serial.println(pHValue, 2);

    printTime=millis();
  }
}

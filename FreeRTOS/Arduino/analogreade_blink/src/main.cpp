#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
/***********************************************************************
 *  freertos_analogread_blink
 *  可変抵抗とLEDを使用したFreeRTOSのマルチタスク実験。
 ***********************************************************************/

void blink_task(void *pvParameters);
void analog_read_task(void *pvParameters);

void setup() {

  xTaskCreate(blink_task, "blink", 128, NULL, 2, NULL);
  xTaskCreate(analog_read_task, "analog_read", 128, NULL, 1, NULL);
}

void loop() {
}

/***********************************************************************
 *  TASKs
 ***********************************************************************/
//- LED点滅
void blink_task(void *pvParameters) {
  (void) pvParameters;

  const uint8_t PIN_LED = 12;

  pinMode(PIN_LED, OUTPUT);
  while(1) {

    // HIGHにして、1秒待つ
    digitalWrite(PIN_LED, HIGH);
    vTaskDelay( 1000 / portTICK_PERIOD_MS);

    // LOWにして、1秒待つ
    digitalWrite(PIN_LED, LOW);
    vTaskDelay( 1000 / portTICK_PERIOD_MS);

  }
}

//- 可変抵抗READ
void analog_read_task(void *pvParameters) {
  (void) pvParameters;

  const uint8_t PIN_AREAD = A0;
  const uint8_t PIN_LED = 11;
  int read_val;

  pinMode(PIN_LED, OUTPUT);
  while(1) {

    // Analog値を読む
    read_val = analogRead(PIN_AREAD);

    if (read_val > 270) {
      digitalWrite(PIN_LED, HIGH);
    } else {
      digitalWrite(PIN_LED, LOW);
    }
    // 15ms待つ
    vTaskDelay(1);
  }

}

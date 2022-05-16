#include <Arduino.h>
#include <SoftwareSerial.h>

#define pinRX 0
#define pinTX 1

#define LED_PIN 13

#define pinR A0

String uart_command = "";
SoftwareSerial softSerial(pinTX, pinRX);
byte skip_bytes = 0;

void setup()
{

  softSerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (softSerial.available() > 0)
  {
    // Serial.println("Что-то приходит");
    while (softSerial.available())
    {

    
      uart_command += char(softSerial.read());
      if (uart_command == "ON")
      {
        skip_bytes = 2;
        digitalWrite(LED_BUILTIN, HIGH);
        uart_command = "";
      }

      if (uart_command == "OFF")
      {
        skip_bytes = 2;
        digitalWrite(LED_BUILTIN, LOW);
        uart_command = "";
      }
      delay(10);
      Serial.println(uart_command); //вывод значений, которые приходят по UART
    }

    // for (uint64_t i = 0; i < uart_command.length();)
    // {

    //   if (memcmp(&uart_command[i], "OFF", 3) == 0)
    //   {
    //     i += 3;
    //     digitalWrite(LED_PIN, HIGH);
    //   }
    // }
  }
}
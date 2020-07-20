/* @author Hilal Merve Hancıoğlu
 * @since 17.07.2020
 * 100'den 0'a Geri Sayım Yapan Program
 * Esp32 modülü bilgisayara bağlanır. Yazılan kod esp32 modülüne yüklenir. Telefon'da serial bluetooth terminal uygulaması üzerinden Esp32'nin bluetooth'una bağlanılır. 
 * Esp32 üzerindeki veriler seri porta yazılır ve bluetooth ile telefondaki serial bluetooth terminal uygulamasına yazılır.*/
#include <Arduino.h>
#include "BluetoothSerial.h"
String BluetoothData; //ANDROİDDEN GELEN DATA
BluetoothSerial ESP_BT;
float batarya = 100;
void setup() 
{
  Serial.begin(115200);
  ESP_BT.begin("ESP32test");
}

void loop() 
{
  if(batarya > 0)
  {
      delay(1000);
      batarya--;
      ESP_BT.print(batarya);
      Serial.print(batarya);
  }
}

#include <dht.h>   //biblioteca do sensor de umidade e temperatura
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define endereco  0x27
#define colunas   16
#define linhas    2
LiquidCrystal_I2C lcd(endereco, colunas, linhas);


#define    dht_pin    5   //pino de sinal do dht11 ligado no digital 5

dht   my_dht;   //objeto para o sensor

int    temperatura = 0x00,   //armazena a temperatura em inteiro
       umidade     = 0x00;   //armazena a umidade em inteiro

void setup() 
{
   lcd.init();
   lcd.backlight();
   lcd.clear();
   Serial.begin(9600);   //serial em 9600 baud rate8
} 
void loop() 
{
   my_dht.read11(dht_pin);
   temperatura = my_dht.temperature;
   umidade     = my_dht.humidity;
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Temperatura: ");
   lcd.print(temperatura);
   lcd.setCursor(0, 1);
   lcd.print("Umidade: ");
   lcd.print(umidade);
   delay(1000);
}

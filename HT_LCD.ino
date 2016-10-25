/*Sensor de Temperatura y Humedad DHT11 en Display LCD
 * Instrucciones:
Recuerda descargar la libreria DHT para poder utilizar este sensor
Conectaremos el Sensor DHT11 a 5v y el pin de señal a la entrada digital 2
*OJO* Utilizaremos un Display LCD controlado mediante un Modulo Serial I2C
*/
#include <Wire.h>                  
#include <LiquidCrystal_I2C.h>     
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//Direccion de LCD
//Si la pantalla se ve con cuadrados en blanco, es porque la I2C Adress no es la correcta
//y tendremos que cambiar 0x3F por 0x27 por ejemplo
#include <DHT.h>
#define DHTPIN 2 //Conectamos el Sensor al pin digital 9
#define DHTTYPE DHT22 // Si el sensor que estamos usando es el DHT 22
//#define DHTTYPE DHT11   // Si el sensor que estamos usando es el DHT 11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
lcd.begin(16,2);// Indicamos medidas de LCD
lcd.print("Leyendo sensores");
dht.begin();
}
void loop() { 
int h = dht.readHumidity();    // Lee la humedad
int t= dht.readTemperature();
/////////////////////////////////////////////////// 
lcd.clear();//Elimina todos los simbolos del LCD
lcd.setCursor(0,0);//Posiciona la primera letra despues del segmento 5 en linea 1              
lcd.print("Humedad Relativa ");
lcd.setCursor(6,1);
lcd.print(h);//Escribe la humedad
lcd.print(" %");                     
delay (2500);
///////////////////////////////////////////////////              
lcd.clear();
lcd.setCursor(3,0);
lcd.print("Temperatura "); 
lcd.setCursor(6,1);
lcd.print(t);//Escribe la temperatura
lcd.print(" C");                   
delay (2500);
///////////////////////////////////////////////////             
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Proyecto GLOBE");                     
  delay (2500);
}



#include "Servo.h"             //подключаем библиотеку для сервомотора
#include "Ultrasonic.h"        //подключаем библиотеку для ультразвукового датчика
#include <Wire.h>              //подключаем библиотеку OLED
#include <Adafruit_GFX.h>      //подключаем библиотеку OLED
#include <Adafruit_SSD1306.h>  //подключаем библиотеку OLED
#include <ESP8266WiFi.h>       //подключаем библиотеку для создания wifi сети
#include <ESP8266WebServer.h>  //подключаем библиотеку для создания web сервера

/* Установка SSID и пароля */
const char* ssid = "NodeMCU";       // SSID
const char* password = "12345678";  // пароль

/* Настройки IP адреса */
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
ESP8266WebServer server(80);
uint8_t LED1pin = D7;  //светодиод сигнализирующий о состоянии работы выключен
bool LED1status = LOW;

constexpr int SCREEN_WIDTH = 128;                                  //Разрешение OLED дисплея по горизонтале, пикселей
constexpr int SCREEN_HEIGHT = 64;                                  //Разрешение OLED дисплея по вертикали, пикселей
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);  //Инициальзируем дисплей SSD1306 подкюченный по I2C шине (SDA, SCL pins)
constexpr int trigPin = 12;                                        // подключаем Trig микроволонового датчика измерения расстояния к пин d6. отправка сигнала
constexpr int echoPin = 14;                                        // подключаем Echo микроволонового датчика измерения расстояния к пин d5. прием ответа

Servo servoneck;             // создаем объект серво-шея
Servo servohead;             // создаем объект серво-голова
int s1, s2, s3, s4, s5, s6;  //создаем переменные для записи расстояний по шести направлениям
long duration;
int distance;

String SendHTML(uint8_t led1stat, uint8_t led2stat)  //функция создания странички Web сервера
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #1abc9c;}\n";
  ptr += ".button-on:active {background-color: #16a085;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP8266 Web Server</h1>\n";
  ptr += "<h3>Using Access Point(AP) Mode</h3>\n";
  if (led1stat)
    ptr += "<p>Server Status: ON</p><a class=\"button button-off\" href=\"/Serveroff\">OFF</a>\n";
  else
    ptr += "<p>Server Status: OFF</p><a class=\"button button-on\" href=\"/Serveron\">ON</a>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}

void handle_OnConnect()  //начальные параметры при запуске Web сервера
{
  server.send(200, "text/html", SendHTML(LED1status, LED1status));
}

void handle_Serveron()  //нажата кнопка ON  на страничке Web сервера
{
  LED1status = HIGH;        //светодиод включен
  Serial.println("Start");  //в монитор порта послана надпись "Start"
  server.send(200, "text/html", SendHTML(true, LED1status));
}

void handle_Serveroff()  //нажата кнопка OFF  на страничке Web сервера
{
  LED1status = LOW;
  Serial.println("Stop");
  server.send(200, "text/html", SendHTML(false, LED1status));
}


//будем замер делать дважды и высчитывать среднюю арифметическую. для исключения ошибок.
//результат измерений будет записываться последовательно в переменные s_1 и s_2

int get_distance() {
  long duration;
  int s_1, s_2, average = 0;
  // запись в s_1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  s_1 = (int)duration / 58.2;
  // запись в s_2
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  s_2 = (int)duration / 58.2;
  // подсчитываем среднее арифметическое s_1 и s_2
  average = (int)(s_1 + s_2) / 2;

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // инициализация дисплея по интерфейсу I2C, адрес 0x3C
  display.clearDisplay();                     // очистка дисплея
  display.setTextSize(5);                     // установка размера шрифта
  display.setTextColor(WHITE);                // установка цвета текста
  display.setCursor(0, 0);                    // установка курсора в позицию X = 0; Y = 0
  display.println(average);                   // записываем в буфер наше значение
  display.display();                          // и её выводим на экран
  return average;
}


int get_distance1(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}


void SW()  //функция сканера периметра и выстрела лазером
{
  s1 = get_distance();  //делаем замер s1 в направлении 30 град.
  if (s1 < 20)          // если меньше заданного то стреляем лазером
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(100);
    servohead.write(30);
    delay(100);
    digitalWrite(2, LOW);  // выключаем светодиод
  } else                   // иначе, поворачиваем шею в положение 60 градусов(вперед)
  {
    servoneck.write(60);
    delay(500);
  }
  s2 = get_distance();  //делаем замер s2 в направлении 60 град.
  if (s2 < 20)          // если меньше заданного то стреляем лазером
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(100);
    servohead.write(30);
    delay(100);
    digitalWrite(2, LOW);  // выключаем светодиод
  } else                   // иначе, поворачиваем шею в положение 90 градусов(вперед)
  {
    servoneck.write(90);
    delay(500);
  }
  s3 = get_distance();  //делаем замер s3 в направлении 120 град.
  if (s3 < 20)        // если меньше заданного то стреляем лазером
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(100);
    servohead.write(30);
    delay(100);
    digitalWrite(2, LOW);  // выключаем светодиод
  } else                   // иначе, поворачиваем шею в положение 120 градусов(вперед)
  {
    servoneck.write(120);
    delay(500);
  }
  s4 = get_distance();  //делаем замер s2 в направлении 120 град.
  if (s4 < 20)          // если меньше заданного то стреляем лазером
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(100);
    servohead.write(30);
    delay(100);
    digitalWrite(2, LOW);  // выключаем светодиод
  } else                   // иначе, поворачиваем шею в положение 150 градусов(налево)
  {
    servoneck.write(150);
    delay(500);
  }
  s5 = get_distance();  //делаем замер s3 в направлении 150 град.
  if (s5 < 20)         // если меньше заданного то стреляем лазером
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(100);
    servohead.write(30);
    delay(100);
    digitalWrite(2, LOW);  // выключаем светодиод
  } else                   // иначе, поворачиваем шею в положение 180 градусов(прямо)
  {
    servoneck.write(180);
    delay(500);
  }
  s6 = get_distance();  //делаем замер s2 в направлении 180 град.
  if (s6 < 20)          // если меньше заданного то стреляем лазером
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(100);
    servohead.write(30);
    delay(100);
    digitalWrite(2, LOW);  // выключаем светодиод
  } else                   // иначе, поворачиваем шею в положение 30 градусов(налево)
  {
    servoneck.write(30);
    delay(500);
  }
}

void SW1()  //функция  2 сканера периметра и выстрела лазером
{
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // инициализация дисплея по интерфейсу I2C, адрес 0x3C
 // поворот на от 15 до 165 градусов
  for(int i=15;i<=165;i++){  
  servoneck.write(i);
  delay(10);
  distance = get_distance1();
  if (distance < 20)          // если меньше заданного в см., то стреляем
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(30);
    servohead.write(30);
    delay(10);
    digitalWrite(2, LOW);  // выключаем светодиод
  }
 
  display.clearDisplay();                     // очистка дисплея
  display.setTextSize(5);                     // установка размера шрифта
  display.setTextColor(WHITE);                // установка цвета текста
  display.setCursor(0, 0);                    // установка курсора в позицию X = 0; Y = 0
  display.println(distance);                   // записываем в буфер наше значение
  display.display();                          // и её выводим на экран
  }
  /// поворот на от 165 до 15 градусов
  for(int i=165;i>15;i--){  
  servoneck.write(i);
  delay(30);
  distance = get_distance1();
  if (distance < 20)          // если меньше заданного в см., то стреляем
  {
    digitalWrite(2, HIGH);  // включаем светодиод
    servohead.write(20);
    delay(10);
    servohead.write(30);
    delay(10);
    digitalWrite(2, LOW);  // выключаем светодиод
  }
  display.clearDisplay();                     // очистка дисплея
  display.setTextSize(5);                     // установка размера шрифта
  display.setTextColor(WHITE);                // установка цвета текста
  display.setCursor(0, 0);                    // установка курсора в позицию X = 0; Y = 0
  display.println(distance);                   // записываем в буфер наше значение
  display.display();                          // и её выводим на экран
  }
}

void setup() {
  Serial.begin(115200);  //монитор порта работает на скорости 115200 baud
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servoneck.attach(16);  // подключаем servoneck к pin d0
  servohead.attach(0);   // подключаем servohead к pin d3
  servoneck.write(0);    // устанавливаем серво-шея в первоначальное положение 0
  servohead.write(30);   // устанавливаем серво-голова в первоначальное положение 30
  pinMode(2, OUTPUT);    // включаем лазерный светодиод d4
  pinMode(LED1pin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", handle_OnConnect);
  server.on("/Serveron", handle_Serveron);
  server.on("/Serveroff", handle_Serveroff);
  server.begin();  //запуск Web сервера
}

void loop() {
  server.handleClient();
  if (LED1status) {
    digitalWrite(LED1pin, HIGH);  //светодиод включен когда работает основная программа
    Serial.println("Work1");       // в монитор порта послана команда печати слова Work1
    SW();                         //выполнение основной программы 1
  }
  if (LED1status) {
    digitalWrite(LED1pin, HIGH);  //светодиод включен когда работает основная программа
    Serial.println("Work2");       // в монитор порта послана команда печати слова Work2
    SW1();                         //выполнение основной программы 2
  } 
  else {
    digitalWrite(LED1pin, LOW);
    Serial.println("NoWork");
  }
}

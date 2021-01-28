#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int photoIn = 1; // photoresistor on Analogue Pin 1
int ledOut = 12; // LED on Digital Pin 7
int aiValue = 0; // input value
double Resistance=0.0;
double Current =0.0;
double Lux=0.0;

void setup()
{
pinMode(ledOut, OUTPUT); // Configure the Digital Pin Direction for the LED
Serial.begin(9600);
lcd.init();   
lcd.backlight(); // backlight of LCD screen 
lcd.setCursor(0,0); 
lcd.print("Test");
}
void loop() {
aiValue = analogRead(photoIn); // Read the analogue input value
Calculate();
Show();
Serial.println(aiValue);
delay(500);
}

void Calculate(){    //Calculate value of resistance of photoresistor
Current= 5-(aiValue*0.0048875);
Resistance =((Current*10000)/(5-Current))/1000;
Lux=Resistance*(-3.363)+833.912;
} 
void Show(){    // Display data on LCD 
  lcd.setCursor(0,0);
  lcd.print("Light Measurment");
  lcd.setCursor(0,1);
  lcd.print(Lux);
  lcd.setCursor(6,1);
  lcd.print("Lux");
}

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int infoCol = 4;
int infoRow = 3;
int i;
int num;
char readData[4];
bool endData;
char rc;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  
  lcd.setCursor(2,0);
  lcd.print("Moisture levels");
  lcd.setCursor(0,0);
  
  zeroCharArray();
}

void zeroCharArray()
{
  for(int counter = 0; counter != 4; counter++)
  {
    readData[counter] = 0;
  }
}

void clearScreen()
{
  lcd.setCursor(infoCol, infoRow);
  lcd.print("                 ");
  lcd.setCursor(infoCol, infoRow);
}

void loop() {
  i = 0;
  zeroCharArray();
  endData = false;
  while(Serial.available() > 0 && !endData)
  {
    rc = Serial.read();
    Serial.print(rc);
    if(rc != '\n')
    {
      if(i < 4){
      readData[i] = rc;
      i++;
      }
    }
    else
    {
      endData = true;
    }
  }
  if(endData)
  {
    lcd.setCursor(7,1);
    lcd.print("     ");
    lcd.setCursor(7,1);
    
    num = atoi(readData);
    lcd.print(num);

    clearScreen();
  
    if(num >= 1000)
    {
      lcd.print("Put in soil");
    }
    else if(num > 800)
    {
      lcd.print("Water Plant");
    }
    else if(num > 700)
    {
      lcd.print("Soil Dry");
    }
    else
    {
      lcd.print("Soil Moist");
    }
  }
  delay(1000);
}


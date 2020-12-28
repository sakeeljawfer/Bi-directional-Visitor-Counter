

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

#define in 14 // Analog pin A0 has a IR Module attached to it.
#define out 15 // Analog pin A1 has a IR Module attached to it.
#define relay 2 // Digital pin D2 has a Relay attached to it.

int count=0;

void IN()
{
    count++; // increment the value
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}

void OUT()
{
  count--; // increment the value
    lcd.clear(); // Clear the LCD Value
    lcd.print("Person In Room:");
    lcd.setCursor(0,1); // set the cursor positon
    lcd.print(count); // Display count value
    delay(1000);
}

void setup()
{
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT); // Assign the IR is Input
  pinMode(out, INPUT);//Assign the IR is Input
  pinMode(relay, OUTPUT);// Assign the Relay is output
  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop()
{  
  
  if(digitalRead(in))
  IN();
  if(digitalRead(out))
  OUT();
  
  if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, LOW); // relay is in ON conditon
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    delay(200);
  }
  
  else
    digitalWrite(relay, HIGH); // relay is OFF condition
  
}

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int c1=0;
int c2=0;
int rellay=3;
int irp1=5,irp2=4;

void setup() {
  pinMode(irp1,INPUT);
  pinMode(irp2,INPUT);
  pinMode(rellay,OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16,2);
}
void loop() {
 int ir1=digitalRead(irp1);
 int ir2=digitalRead(irp2);
       //ENTERS...................
  if(ir1==0)
  {
    while(ir2==1)
       {
       Serial.println("ENTERS");
       c1=c1+1;
       Serial.print("TOTAL PERSON =  ");
       Serial.println(c1+c2);
       
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("ENTERS 1 PERSON");
       lcd.setCursor(0,1);
       lcd.print("TOTAL PERSON= ");
       lcd.setCursor(14,1);
       lcd.print(c1+c2);
       
       delay(3000);
       break;
       }
  } 
      //EXITS.....................
  else if(ir2==0)
    {
      while(ir1==1) 
       {
        Serial.println("EXITS");
        c2=c2-1;
        Serial.print("TOTAL PERSON =  ");
        Serial.println(c1+c2);

        lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("EXITS 1 PERSON");
       lcd.setCursor(0,1);
       lcd.print("TOTAL PERSON= ");
       lcd.setCursor(14,1);
       lcd.print(c1+c2);
        
        delay(3000);
        break;
        }
  }

 if((c1+c2)==0){
       lcd.setCursor(0,0);
       lcd.print("  ! LIGHT OFF !   ");
       digitalWrite(rellay,HIGH);
        }
 else{
       lcd.setCursor(0,0);
       lcd.print("  ! LIGHT ON !   ");
       digitalWrite(rellay,LOW);
        }
}

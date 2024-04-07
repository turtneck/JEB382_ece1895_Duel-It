#include "pitches.h"//tone library
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int buzzer =8;

int score1=5,score2=4;
int winover=3;

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();

  /*delay(2000);
  Tonethr();
  delay(2000);
  Toneone();
  delay(2000);
  Tonetwo();*/
}

void loop() {
  //playerwin(1);
  //delay(1000);
  //playerwin(2);
  //delay(1000);
  fail();
  delay(1000);
}

void Toneone() {
  tone(8, NOTE_G3,0);//G3
  delay(250);
  noTone(8);
  delay(100);

  tone(8, NOTE_G3,0);//G3
  delay(200);
  noTone(8);
  delay(50);

  tone(8, NOTE_C4,0);//C4
  delay(1000);
  noTone(8);
}

void Tonetwo() {
  tone(8, NOTE_C4,0);//C4
  delay(200);
  noTone(8);
  delay(50);
  
  tone(8, NOTE_G3,0);//G3
  delay(250);
  noTone(8);
  delay(50);

  tone(8, NOTE_C4,0);//C4
  delay(200);
  noTone(8);
  delay(50);
  
  tone(8, NOTE_G3,0);//G3
  delay(250);
  noTone(8);
  delay(50);

  tone(8, NOTE_C4,0);//C4
  delay(400);
  noTone(8);
  delay(100);

  tone(8, NOTE_C4,0);//C4
  delay(400);
  noTone(8);
  delay(100);
}

void Tonethr() {
  tone(8, NOTE_D3,0);//D2
  delay(250);
  noTone(8);
  delay(100);

  tone(8, NOTE_D3,0);//D2
  delay(200);
  noTone(8);
  delay(50);

  tone(8, NOTE_C2,0);//C1
  delay(1000);
  noTone(8);
}



void(* resetFunc) (void) = 0;

void playerwin(int player)
{
    lcd.clear();
    lcd.setCursor(0,0);

    tone(buzzer, NOTE_C4,0);//C4
    delay(200);
    noTone(buzzer);
    delay(50);
    if (player == 1){lcd.print("PLAYER 1 WINS");}
    else if (player == 2){lcd.print("PLAYER 2 WINS");}
    
    tone(buzzer, NOTE_G3,0);//G3
    delay(250);
    noTone(buzzer);
    delay(50);
    lcd.clear();

    tone(buzzer, NOTE_C4,0);//C4
    delay(200);
    noTone(buzzer);
    delay(50);
    if (player == 1){lcd.print("PLAYER 1 WINS");}
    else if (player == 2){lcd.print("PLAYER 2 WINS");}
    
    tone(buzzer, NOTE_G3,0);//G3
    delay(250);
    noTone(buzzer);
    delay(50);
    lcd.clear();

    tone(buzzer, NOTE_C4,0);//C4
    delay(400);
    noTone(buzzer);
    delay(100);
    if (player == 1){lcd.print("PLAYER 1 WINS");}
    else if (player == 2){lcd.print("PLAYER 2 WINS");}

    tone(buzzer, NOTE_C4,0);//C4
    delay(400);
    noTone(buzzer);

    delay(3000);
    lcd.clear();
}
void fail()
{
    lcd.clear();
    lcd.setCursor(3,0);

    tone(buzzer, NOTE_D3,0);
    lcd.print("FAIL");
    delay(250);
    noTone(buzzer);
    delay(600);

    tone(buzzer, NOTE_D3,0);
    lcd.print("U");
    delay(200);
    noTone(buzzer);
    delay(50);
    

    tone(buzzer, NOTE_C2,0);
    lcd.print("RE :(");
    delay(2000);
    noTone(buzzer);
    delay(3000);

    if (score1 > score2+winover){playerwin(1);}
    else if (score2 > score1+winover){playerwin(2);}
    else
    {
        lcd.clear();
        lcd.setCursor(5,0);
        lcd.print("PLAYER");
        lcd.setCursor(6,1);
        lcd.print("DRAW");

        tone(buzzer, NOTE_C2,0);
        delay(250);
        noTone(buzzer);
        delay(600);

        tone(buzzer, NOTE_C2,0);
        delay(200);
        noTone(buzzer);
        delay(50);
        

        tone(buzzer, NOTE_D3,0);
        delay(2000);
        noTone(buzzer);
        
        delay(3000);
        resetFunc();
    }
}
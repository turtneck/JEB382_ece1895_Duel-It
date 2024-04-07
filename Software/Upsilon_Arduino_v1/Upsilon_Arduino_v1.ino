#include<pitches.h>//tone library
#include <LiquidCrystal_I2C.h>
#include <time.h>
//Pins
int
OPin1  =  5,
OPin2  =  6,
state1 =  7,
state2 =  8,
buzzer = 12;
LiquidCrystal_I2C lcd(0x27,16,2);
int score1=0,score2=0;
int winover=3;



//Functions
char *strtemp = malloc(16*sizeof(char));
void score_disp()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PLAYER1  PLAYER2");

    lcd.setCursor(0,1);
    itoa(score1,strtemp,10);
    lcd.print(strtemp);

    if (score2<10) {lcd.setCursor(15,1);}
    else {lcd.setCursor(14,1);}
    itoa(score2,strtemp,10);
    lcd.print(strtemp);
}

void playerwin(int player)
{
    /*
    lcd.clear();
    lcd.setCursor(0,0);
    for (int i = 0; i <= 5; i++) {
        if (player = 1){lcd.print("PLAYER 1 WINS");}
        if (player = 2){lcd.print("PLAYER 2 WINS");}
        delay(500);
    }
    buzzer_win();
    lcd.clear();
    reset();*/
    lcd.clear();

    tone(buzzer, NOTE_C4,0);//C4
    delay(200);
    noTone(buzzer);
    delay(50);
    lcd.setCursor(0,0);
    if (player == 1){lcd.print("    PLAYER 1    ");}
    if (player == 2){lcd.print("    PLAYER 2    ");}
    lcd.setCursor(6,1);
    lcd.print("WINS");
    
    tone(buzzer, NOTE_G3,0);//G3
    delay(250);
    noTone(buzzer);
    delay(50);
    lcd.clear();

    tone(buzzer, NOTE_C4,0);//C4
    delay(200);
    noTone(buzzer);
    delay(50);
    lcd.setCursor(0,0);
    if (player == 1){lcd.print("    PLAYER 1    ");}
    if (player == 2){lcd.print("    PLAYER 2    ");}
    lcd.setCursor(6,1);
    lcd.print("WINS");
    
    tone(buzzer, NOTE_G3,0);//G3
    delay(250);
    noTone(buzzer);
    delay(50);
    lcd.clear();

    tone(buzzer, NOTE_C4,0);//C4
    delay(400);
    noTone(buzzer);
    delay(100);
    lcd.setCursor(0,0);
    if (player == 1){lcd.print("    PLAYER 1    ");}
    if (player == 2){lcd.print("    PLAYER 2    ");}
    lcd.setCursor(6,1);
    lcd.print("WINS");

    tone(buzzer, NOTE_C4,0);//C4
    delay(400);
    noTone(buzzer);
        
    while (1){delay(1000);}
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

    if (score1 >= score2+winover){playerwin(1);}
    else
    if (score2 >= score1+winover){playerwin(2);}
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
        
        while (1){delay(1000);}
    }
}

void(* resetFunc) (void) = 0;

void buzzer_start()
{
  tone(buzzer, NOTE_G3,0);//G3
  delay(250);
  noTone(buzzer);
  delay(100);

  tone(buzzer, NOTE_G3,0);//G3
  delay(200);
  noTone(buzzer);
  delay(50);

  tone(buzzer, NOTE_C4,0);//C4
  delay(1000);
  noTone(buzzer);
}
/*
void buzzer_win()
{
  tone(buzzer, NOTE_C4,0);//C4
  delay(200);
  noTone(buzzer);
  delay(50);
  
  tone(buzzer, NOTE_G3,0);//G3
  delay(250);
  noTone(buzzer);
  delay(50);

  tone(buzzer, NOTE_C4,0);//C4
  delay(200);
  noTone(buzzer);
  delay(50);
  
  tone(buzzer, NOTE_G3,0);//G3
  delay(250);
  noTone(buzzer);
  delay(50);

  tone(buzzer, NOTE_C4,0);//C4
  delay(400);
  noTone(buzzer);
  delay(100);

  tone(buzzer, NOTE_C4,0);//C4
  delay(400);
  noTone(buzzer);
  delay(100);
}
void buzzer_fail()
{
  tone(buzzer, NOTE_D3,0);//D2
  delay(250);
  noTone(buzzer);
  delay(100);

  tone(buzzer, NOTE_D3,0);//D2
  delay(200);
  noTone(buzzer);
  delay(50);

  tone(buzzer, NOTE_C2,0);//C1
  delay(1000);
  noTone(buzzer);
}*/

int selection=0;
float curr_time,time_to_complete;
void start_func()
{
    //curr_time = millis();//time modules start
    //time_to_complete *= 0.909; //time to complete gets 10% faster
    //selection = rand()%4; //rand value 0to3 (which module)

    tone(buzzer, NOTE_C4,0);//G3
    delay(250);
    noTone(buzzer);

    curr_time = millis();//time modules start
    time_to_complete *= 0.909; //time to complete gets 10% faster
    selection = rand()%3; //rand value 0to2 (which module)
}






void setup(){
    lcd.init();
    lcd.clear();
    lcd.backlight();
    score_disp();
  
    time_to_complete = 5000;//5sec in ms
    score1=0,score2=0;

    delay(2000);
    buzzer_start();
    delay(2000);
}


bool Player1_prev = false;
bool Player2_prev = false;

void loop() {
    //ROUND STARTS
    start_func();



    //stab
    if (selection == 0)
    {
        //set output pins as 00 (OPin2,OPin1)
        //digitalWrite(OPin1, LOW);
        //digitalWrite(OPin2, LOW);
        digitalWrite(OPin1, HIGH);
        digitalWrite(OPin2, LOW);

        //MODULE STARTS
        //complete if circuit is complete
        while (1)
        {
            if (digitalRead(state1) == HIGH)
            {
                score1++;
                break;
            }
            else if (digitalRead(state2) == HIGH)
            {
                score2++;
                break;
            }
            else if (millis() >= curr_time + time_to_complete)
            {
                fail();
                break;
            }
        }
    }

    //slash
    else if (selection == 1)
    {   //set output pins as 01 (OPin2,OPin1)
        //digitalWrite(OPin1, HIGH);
        //digitalWrite(OPin2, LOW);
        digitalWrite(OPin1, LOW);
        digitalWrite(OPin2, HIGH);

        //MODULE STARTS
        //complete if circuit is complete
        while (1)
        {
            if (digitalRead(state1) == HIGH)
            {
                score1++;
                break;
            }
            else if (digitalRead(state2) == HIGH)
            {
                score2++;
                break;
            }
            else if (millis() >= curr_time + time_to_complete)
            {
                fail();
                break;
            }
        }
    }

    //Grindstone
    else if (selection == 2)
    {
        //getting state of module before round
        //Player1_prev = digitalRead(state1) == HIGH;
        //Player2_prev = digitalRead(state2) == HIGH;

        //set output pins as 10 (OPin2,OPin1)
        //digitalWrite(OPin1, LOW);
        //digitalWrite(OPin2, HIGH);
        digitalWrite(OPin1, HIGH);
        digitalWrite(OPin2, HIGH);
        
        //MODULE STARTS
        //complete if circuit is different then inital
        while (1)
        {
            /*
            //state changed
            if (digitalRead(state1) != Player1_prev)
            {
                digitalWrite(OPin1, LOW);
                digitalWrite(OPin2, LOW);
                score1++;
                break;
            }
            else if (digitalRead(state2) != Player2_prev)
            {
                digitalWrite(OPin1, LOW);
                digitalWrite(OPin2, LOW);
                score2++;
                break;
            }
            else if (millis() >= curr_time + time_to_complete)
            {
                digitalWrite(OPin1, LOW);
                digitalWrite(OPin2, LOW);
                fail();
                break;
            }*/
            if (digitalRead(state1) == HIGH)
            {
                score1++;
                break;
            }
            else if (digitalRead(state2) == HIGH)
            {
                score2++;
                break;
            }
            else if (millis() >= curr_time + time_to_complete)
            {
                fail();
                break;
            }
        }
    }

    /*
    //War Cry
    else if (selection == 3)
    {
        //set output pins as 11 (OPin2,OPin1)
        digitalWrite(OPin1, HIGH);
        digitalWrite(OPin2, HIGH);
        //start_func();
        
        //MODULE STARTS
        //complete if circuit is complete
        while (1)
        {
            if (digitalRead(state1) == HIGH)
            {
                score1++;
                break;
            }
            else if (digitalRead(state2) == HIGH)
            {
                score2++;
                break;
            }
            else if (millis() >= curr_time + time_to_complete)
            {
                fail();
                break;
            }
        }
    }
    */

    //check if players points are at 99 before starting new round
    if (score1 == 99) playerwin(1);
    else if (score2 == 99) playerwin(2);
    digitalWrite(OPin1, LOW);
    digitalWrite(OPin2, LOW);

    score_disp();
    buzzer_start();
    delay(3000);
}

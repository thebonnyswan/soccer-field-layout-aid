// E4 Soccer Field Project

// REFLECTANCE SENSOR CONSTANTS
# define whitethreshold 500

// SENSOR PIN DEFINITIONS
#define REFLECTSENSOR 18
#define PHOTO 19

#define WHEELDIAMETER 10
#define ROTATIONCONSTANT .0873
// use instead of convert to length, value added for every marker tic

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

// __________________________________________BUTTON DEFINITIONS
// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// _____________________________________________________________________ SETUP
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initSensors();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);


  straightlinefunction(100);
  //startpainting();
  //runotherfield();
}





// SENSOR TESTING
void initSensors()
{
  pinMode(REFLECTSENSOR, INPUT);
  pinMode(PHOTO, INPUT);
  int refl = analogRead(REFLECTSENSOR - 14);
  int photo = analogRead(PHOTO - 14);
}

void testSensors()
{
  int refl = analogRead(REFLECTSENSOR - 14);
  int photo = analogRead(PHOTO - 14);

  Serial.print("Refl sensor: ");
  Serial.println(refl);
  //Serial.print("Phototransistor: ");
  //Serial.println(photo);

  Serial.println(" ");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

  //testSensors();

}

// _______________________________________________________FIELD SIZE CALCULATION
void calculatefield(float length, float width)
{
  // all measurements in yards
  float circlediameter = length / 10;
  float penaltyarc = length / 10;
  float penaltymark = penaltyarc + 2;
  float penatlywidth;
  float halfline = length / 2;
  float goalarea = length + width - 30;
  float goallength = 6;
  float goalwidth = goalarea - goallength;
  float penaltyarea = 2 * goallength + 2;
  float penaltylength = width / 2 + 2 - .5 * sqrt(width * width + 8 * width + 16 - 4 * penaltyarea);
}

// __________________________________________________BUTTON READING
// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;

  // For V1.0 comment the other threshold and use the one below:
  /*
    if (adc_key_in < 50)   return btnRIGHT;
    if (adc_key_in < 195)  return btnUP;
    if (adc_key_in < 380)  return btnDOWN;
    if (adc_key_in < 555)  return btnLEFT;
    if (adc_key_in < 790)  return btnSELECT;
  */


  return btnNONE;  // when all others fail, return this...
}

// ________________________________________________________Initial User Interface
void startpainting()
{
  boolean endfunction = false;
  lcd.setCursor(0, 0);
  lcd.print("Choose field by");
  lcd.setCursor(0, 1);
  lcd.print("holding select.");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("U8 Field");
  int timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runU8field();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("U10 Field");
  timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runU10field();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("U12 Field");
  timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runU12field();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("U14 Field");
  timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runU14field();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("U16 Field");
  timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runU16field();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("U19 Field");
  timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runU19field();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);

  lcd.setCursor(0, 0);
  lcd.print("other dimensions");
  timecounter = millis();
  while (millis() < timecounter + 2000);
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      runotherfield();
      endfunction = true;
    }
  }
  if (endfunction == true)
  {
    return;
  }
  delay(1000);
}


// ____________________________________________PRESET FIELD FUNCTIONS
void runU8field()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen U8");
  delay(1000);
  float U8length = 50;
  float U8width = 25;
  U8fielddirections(U8length, U8width);
  return;
}

void runU10field()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen U10");
  delay(1000);
  float U10length = 80;
  float U10width = 40;
  runfullfielddirections(U10length, U10width);
  return;

}

void runU12field()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen U12");
  delay(1000);
  float U12length = 100;
  float U12width = 50;
  runfullfielddirections(U12length, U12width);
  return;

}

void runU14field()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen U14");
  delay(1000);
  float U14length = 100; // INPUT THIS AFTER CLIENT INFO
  float U14width = 50; // INPUT THIS AFTER CLIENT INFO
  runfullfielddirections(U14length, U14width);
  return;
}

void runU16field()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen U16");
  delay(1000);
  float U16length = 100; // INPUT THIS AFTER CLIENT INFO
  float U16width = 50; // INPUT THIS AFTER CLIENT INFO
  runfullfielddirections(U16length, U16width);
  return;
}

void runU19field()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen U19");
  delay(1000);
  float U19length = 100; // INPUT THIS AFTER CLIENT INFO
  float U19width = 50; // INPUT THIS AFTER CLIENT INFO
  runfullfielddirections(U19length, U19width);
  return;
}

void runotherfield()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("chosen other");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("input field");
  lcd.setCursor(0, 1);
  lcd.print("length");
  delay(1000);

  int digitone = 0;
  int digittwo = 0;
  int digitthree = 0;

  // code for first digit

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("choose digit 1");
  lcd.setCursor(7, 1);
  lcd.print(digitone);
  lcd.setCursor(8, 1);
  lcd.print(digittwo);
  lcd.setCursor(9, 1);
  lcd.print(digitthree);

  digitone = digitinput(1);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("choose digit 2");
  lcd.setCursor(7, 1);
  lcd.print(digitone);
  lcd.setCursor(8, 1);
  lcd.print(digittwo);
  lcd.setCursor(9, 1);
  lcd.print(digitthree);

  digittwo = digitinput(2);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("choose digit 3");
  lcd.setCursor(7, 1);
  lcd.print(digitone);
  lcd.setCursor(8, 1);
  lcd.print(digittwo);
  lcd.setCursor(9, 1);
  lcd.print(digitthree);

  digitthree = digitinput(3);
  delay(1000);

  int fieldlength = 100 * digitone + 10 * digittwo + digitthree;

  digitone = 0;
  digittwo = 0;
  digitthree = 0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("input field");
  lcd.setCursor(0, 1);
  lcd.print("length");
  delay(1000);

  // code for first digit

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("choose digit 1");
  lcd.setCursor(7, 1);
  lcd.print(digitone);
  lcd.setCursor(8, 1);
  lcd.print(digittwo);
  lcd.setCursor(9, 1);
  lcd.print(digitthree);

  digitone = digitinput(1);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("choose digit 2");
  lcd.setCursor(7, 1);
  lcd.print(digitone);
  lcd.setCursor(8, 1);
  lcd.print(digittwo);
  lcd.setCursor(9, 1);
  lcd.print(digitthree);

  digittwo = digitinput(2);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("choose digit 3");
  lcd.setCursor(7, 1);
  lcd.print(digitone);
  lcd.setCursor(8, 1);
  lcd.print(digittwo);
  lcd.setCursor(9, 1);
  lcd.print(digitthree);

  digitthree = digitinput(3);
  delay(1000);

  int fieldwidth = 100 * digitone + 10 * digittwo + digitthree;

  runfullfielddirections(fieldlength, fieldwidth);
}

int digitinput(int digitnumber)
{
  int digit = 0;
  int curse = digitnumber+6;

  boolean selectpressed = false;

  while (selectpressed == false)
  {
    if (read_LCD_buttons() == 4)
    {
      selectpressed = true;
    }
    if (read_LCD_buttons() == 1)
    {
      if (digit == 9)
      {
        digit = 9;
      }
      else
      {
        digit += 1;
        lcd.setCursor(curse, 1);
        lcd.print(digit);
      }
      delay(175);
    }
    if (read_LCD_buttons() == 2)
    {
      if (digit == 0)
      {
        digit = 0;
      }
      else
      {
        digit -= 1;
        lcd.setCursor(curse, 1);
        lcd.print(digit);
      }
      delay(175);
    }


  }

  selectpressed = false;

  return digit;
}

// ________________________________________ FULL NONSPECIFIC FIELD INSTRUCTIONS
void runfullfielddirections(int length, int width)
{
  // all measurements in yards
  float circleradius = length / 10;
  float penaltyarc = length / 10;
  float penaltymark = penaltyarc + 2;
  float penaltywidth = penaltymark * 3;
  float halfline = length / 2;
  float goalarea = length + width - 30;
  float goallength = 6;
  float goalwidth = goalarea - goallength;
  float penaltyarea = 2 * goallength + 2;
  float penaltylength = width + 4 - penaltywidth;

  // Instruct the user to paint the outside rectangle.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint field");
  lcd.setCursor(0, 1);
  lcd.print("perimeter:");
  delay(3000);
  lcd.clear();

  // Go to bottom left corner.
  lcd.setCursor(0, 0);
  lcd.print("Go to bottom");
  lcd.setCursor(0, 1);
  lcd.print("left corner.");
  delay(2000);
  lcd.clear();
  pressselecttoconfirm();
  
  // mark the bottom line of the perimeter
  lcd.clear();
  lcd.print("Face along the ");
  lcd.setCursor(0, 1);
  lcd.print("lower field edge");
  lcd.setCursor(0, 0);
  delay(1000);
  straightlinefunction(length);
  delay(1000);


  // mark the right side of the perimeter
  leftturn();
  pressselecttoconfirm();
  delay(1000);
  straightlinefunction(width);

  // mark the top of the perimeter
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(length);

  // mark the left side of the perimeter
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(width);

  // paint penalty box
  // turn around to paint penalty area
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turn around.");
  pressselecttoconfirm();
  float topenalty = (width - goalwidth)/2;
  straightlinenopainting(topenalty);

  // paint right side of penalty box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(penaltylength);

  // mark the outside of the penalty box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(penaltywidth);

  // mark the right side of the penalty box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(penaltylength);

  // move down to goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  float intermediate = (penaltywidth - goalwidth)/2;
  straightlinenopainting(intermediate);

  // paint top of goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(goallength);

  // paint side of goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(goalwidth);

  // paint bottom of goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(goallength);

  // go up to penalty mark line
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(goalwidth/2);

  // go out to penalty mark
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(penaltymark);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hold to paint");
  lcd.setCursor(0,1);
  lcd.print("penalty mark");
  delay(10000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Place stake on");
  lcd.setCursor(0,1);
  lcd.print("penalty mark");
  delay(5000);

  // go to lower left corner
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Go to the lower");
  lcd.setCursor(0, 1);
  lcd.print("left corner.");
  delay(2000);
  pressselecttoconfirm();

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint penalty");
  lcd.setCursor(0, 1);
  lcd.print("arc");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Penalty Arc:");
  lcd.setCursor(0, 1);
  lcd.print("Radius");
  lcd.setCursor(7,1);
  lcd.print(penaltyarc);
  delay(10000);
  pressselectwhendone();

  lcd.clear();
  lcd.print("Face along the ");
  lcd.setCursor(0, 1);
  lcd.print("lower field edge");
  lcd.setCursor(0, 0);
  delay(2000);
  pressselecttoconfirm();

  // go to centerline
  straightlinenopainting(length/2);

  //go to centerpoint
  straightlinefunction(width/2);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Place stake at");
  lcd.setCursor(0, 1);
  lcd.print("end of line.");
  delay(1000);
  pressselecttoconfirm();

  // finish centerline
  straightlinefunction(width/2);
  rightturn();
  delay(1000);
  straightlinenopainting(length/2);

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint center");
  lcd.setCursor(0, 1);
  lcd.print("circle");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Center Circle:");
  lcd.setCursor(0, 1);
  lcd.print("Radius");
  lcd.setCursor(7,1);
  lcd.print(circleradius);
  delay(10000);
  pressselectwhendone();

  // paint rest of field- copied from above
  
  // paint penalty box
  // turn around to paint penalty area
  
  straightlinenopainting(topenalty);

  // paint right side of penalty box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(penaltylength);

  // mark the outside of the penalty box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(penaltywidth);

  // mark the right side of the penalty box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(penaltylength);

  // move down to goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(intermediate);

  // paint top of goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(goallength);

  // paint side of goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(goalwidth);

  // paint bottom of goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(goallength);

  // go up to penalty mark line
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(goalwidth/2);

  // go out to penalty mark
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(penaltymark);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hold to paint");
  lcd.setCursor(0,1);
  lcd.print("penalty mark");
  delay(10000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Place stake on");
  lcd.setCursor(0,1);
  lcd.print("penalty mark");
  delay(5000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint penalty");
  lcd.setCursor(0, 1);
  lcd.print("arc");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Penalty Arc:");
  lcd.setCursor(0, 1);
  lcd.print("Radius");
  lcd.setCursor(7,1);
  lcd.print(penaltyarc);
  delay(10000);
  pressselectwhendone();


  
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint corner");
  lcd.setCursor(0, 1);
  lcd.print("circles");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Corner circles:");
  lcd.setCursor(0, 1);
  lcd.print("Radius 1yd");
  delay(10000);
  pressselectwhendone();
  
  
}

void U8fielddirections(int length, int width)
{
  // length = 50, width = 25
  // all measurements in yards
  float circleradius = 6;
  float halfline = 25;
  float goallength = 6;
  float goalwidth = 12;
  float cornerarc = 1;

  // Instruct the user to paint the outside rectangle.
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint field");
  lcd.setCursor(0, 1);
  lcd.print("perimeter:");
  delay(2000);
  lcd.clear();

  // Go to bottom left corner.
  lcd.setCursor(0, 0);
  lcd.print("Go to bottom");
  lcd.setCursor(0, 1);
  lcd.print("left corner.");
  delay(2000);
  lcd.clear();

  // Replicated at bottom as pressselecttoconfirm();
  //Wait for select input.
  lcd.setCursor(0, 0);
  lcd.print("Press SELECT to");
  lcd.setCursor(0, 1);
  lcd.print("confirm location.");
  delay(2000);
  boolean waitingforselect = true;
  while (waitingforselect == true)
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      break;
    }

  }

  // mark the bottom line of the perimeter
  lcd.clear();
  lcd.print("Face along the ");
  lcd.setCursor(0, 1);
  lcd.print("lower field edge");
  lcd.setCursor(0, 0);
  delay(1000);
  straightlinefunction(length);
  delay(1000);


  // mark the right side of the perimeter
  leftturn();
  pressselecttoconfirm();
  delay(1000);
  straightlinefunction(width);

  // mark the top of the perimeter
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(length);

  // mark the left side of the perimeter
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(width);

  // turn around to paint goal area
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turn around.");
  pressselecttoconfirm();
  straightlinenopainting(6.5);

  // paint right side of goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(6);

  // mark the outside of the goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(12);

  // mark the right side of the goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(6);


  // go to upper left corner
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Go to the upper");
  lcd.setCursor(0, 1);
  lcd.print("left corner.");
  delay(2000);
  rightturn();
  delay(1000);
  straightlinenopainting(6.5);
  pressselecttoconfirm();

  // follow top line
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(25);
  pressselecttoconfirm();


  // mark centerline
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(12.5);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Place stake at");
  lcd.setCursor(0, 1);
  lcd.print("end of line.");
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(12.5);

  // get to other goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinenopainting(25);
  leftturn();
  pressselecttoconfirm();
  straightlinenopainting(6.5);

  // paint right side goal box
  leftturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(6);

  // paint outside goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(12);

  // paint other side goal box
  rightturn();
  delay(1000);
  pressselecttoconfirm();
  straightlinefunction(6);

  // instruct for circle and corner
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Paint center &");
  lcd.setCursor(0, 1);
  lcd.print("corner circles");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Center Circle:");
  lcd.setCursor(0, 1);
  lcd.print("Radius 6yd");
  delay(10000);
  pressselectwhendone();
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Corner arcs:");
  lcd.setCursor(0, 1);
  lcd.print("Radius 1yd");
  delay(10000);
  pressselectwhendone();

}


// ////////////////////////////////////////////////////////////////////////////////////////
// HELPER FUNCTIONS
// ////////////////////////////////////////////////////////////////////////////////////////




void leftturn()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turn 90 degrees");
  lcd.setCursor(0, 1);
  lcd.print("to the left.");
}

void rightturn()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Turn 90 degrees");
  lcd.setCursor(0, 1);
  lcd.print("to the right.");
}


void straightlinefunction(float length)
{
  //int countertotal = converttocounter(length);
  float counternow = 0;

  // input given in yards
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Start painting");
  lcd.setCursor(0, 1);
  lcd.print("& walk forward.");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Keep walking.");
  lcd.setCursor(0, 1);
  lcd.print(counternow);
  lcd.setCursor(6, 1);
  lcd.print("of ");
  lcd.setCursor(12, 1);
  lcd.print(length);

  int ref = analogRead(REFLECTSENSOR - 14);
  int ref2 = analogRead(REFLECTSENSOR - 14);

  while (counternow < length)
  {
    //Serial.print("read_LCD_buttons() hopefully == 3");
    //Serial.println(read_LCD_buttons());
    if (read_LCD_buttons() == 3)
    {

      //Serial.println("it was three");
      delay(1000);
      lcd.clear();
      // Wait for select input.
      lcd.setCursor(0, 0);
      lcd.print("Press SELECT ");
      lcd.setCursor(0, 1);
      lcd.print("when finished.");
      delay(2000);
      boolean waitingforselect = true;
      while (waitingforselect == true)
      {
        delay(50);
        if (read_LCD_buttons() == 4)
        {
          lcd.clear();
          waitingforselect = false;
          break;
        }

      }
      //Serial.println("Escaped while loop.");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Keep walking.");
      lcd.setCursor(0, 1);
      lcd.print(counternow);
      lcd.setCursor(5, 1);
      lcd.print("out of ");
      lcd.setCursor(12, 1);
      lcd.print(length);
    }

    Serial.print("ref1: ");
    Serial.println(ref);
    Serial.print("ref2: ");
    Serial.print(ref2);
    ref2 = ref;
    ref = analogRead(REFLECTSENSOR - 14);
    int diff = ref-ref2;
    if (diff < -300)
    {
      counternow += ROTATIONCONSTANT;
      lcd.setCursor(0, 1);
      Serial.println(counternow);
      lcd.print(counternow); 
    }
    
    delay(100);
  }

  //_________________________________________________________

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stop walking.");
  delay(2000);
}

void straightlinenopainting(float length)
{
  int countertotal = converttocounter(length);
  int counternow = 0;

  // input given in yards
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Walk forward.");
  lcd.setCursor(0, 1);
  lcd.print("Do not paint.");

  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Keep walking.");
  lcd.setCursor(0, 1);
  lcd.print(countertolength(counternow));
  lcd.setCursor(6, 1);
  lcd.print("of ");
  lcd.setCursor(12, 1);
  lcd.print(length);

  int ref = analogRead(REFLECTSENSOR - 14);
  int ref2 = analogRead(REFLECTSENSOR - 14);

  while (counternow < countertotal)
  {
    //Serial.print("read_LCD_buttons() hopefully == 3");
    //Serial.println(read_LCD_buttons());
    if (read_LCD_buttons() == 3)
    {

      //Serial.println("it was three");
      delay(1000);
      lcd.clear();
      // Wait for select input.
      lcd.setCursor(0, 0);
      lcd.print("Press SELECT ");
      lcd.setCursor(0, 1);
      lcd.print("when finished.");
      delay(2000);
      boolean waitingforselect = true;
      while (waitingforselect == true)
      {
        delay(50);
        if (read_LCD_buttons() == 4)
        {
          lcd.clear();
          waitingforselect = false;
          break;
        }

      }
      //Serial.println("Escaped while loop.");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Keep walking.");
      lcd.setCursor(0, 1);
      lcd.print(countertolength(counternow));
      lcd.setCursor(5, 1);
      lcd.print("out of ");
      lcd.setCursor(12, 1);
      lcd.print(length);
    }

    // Serial.println(ref);
    if (ref2 - ref < -350)
    {
      counternow += 1;
      lcd.setCursor(0, 1);
      lcd.print(countertolength(counternow));
    }
    ref2 = ref;
    ref = analogRead(REFLECTSENSOR - 14);
    delay(25);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stop walking.");
  delay(2000);
}

float countertolength(int counter)
{
  float rotations = counter / 10;
  float wheelcircumferenceyd = WHEELDIAMETER * 3.14 / 36;
  float distanceyd = rotations * wheelcircumferenceyd;
  //Serial.println(distanceyd);
  return distanceyd;
}

int converttocounter(float length)
{
  // use global variable WHEELDIAMETER as the diameter of the wheel
  float wheelcircumferencein = WHEELDIAMETER * 3.14;
  float wheelcircumferenceyd = wheelcircumferencein / 36;

  float numberrotations = length / wheelcircumferenceyd;
  int countertotal = numberrotations * 8;

  //Serial.println(countertotal);
  return countertotal;
}

void pressselecttoconfirm()
{
  delay(1000);
  lcd.clear();
  //Wait for select input.
  lcd.setCursor(0, 0);
  lcd.print("Press SELECT to");
  lcd.setCursor(0, 1);
  lcd.print("confirm location.");
  delay(2000);
  boolean waitingforselect = true;
  while (waitingforselect == true)
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      break;
    }

  }

}

void pressselectwhendone()
{
  delay(1000);
  lcd.clear();
  // Wait for select input.
  lcd.setCursor(0, 0);
  lcd.print("Press SELECT ");
  lcd.setCursor(0, 1);
  lcd.print("when finished.");
  delay(2000);
  boolean waitingforselect = true;
  while (waitingforselect == true)
  {
    delay(50);
    if (read_LCD_buttons() == 4)
    {
      break;
    }

  }
}



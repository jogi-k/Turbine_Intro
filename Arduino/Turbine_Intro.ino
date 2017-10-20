/*
 Basic LoL Shield Test
 
 Writen for the LoL Shield, designed by Jimmie Rodgers:
 http://jimmieprodgers.com/kits/lolshield/
 
 This needs the Charliplexing library, which you can get at the
 LoL Shield project page: http://code.google.com/p/lolshield/
 
 Created by Jimmie Rodgers on 12/30/2009.
 Adapted from: http://www.arduino.cc/playground/Code/BitMath
 
 History:
  	December 30, 2009 - V1.0 first version written at 26C3/Berlin

  This is free software; you can redistribute it and/or
  modify it under the terms of the GNU Version 3 General Public
  License as published by the Free Software Foundation; 
  or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

// #include <avr/pgmspace.h>  //AVR library for writing to ROM
#include <Charliplexing.h> //Imports the library, which needs to be
                           //Initialized in setup.

#include "Font.h"

//Sets the time each frame is shown (milliseconds)
const unsigned int blinkdelay = 1000 / 50;

/*
The BitMap array is what contains the frame data. Each line is one full frame.
Since each number is 16 bits, we can easily fit all 14 LEDs per row into it.
The number is calculated y adding up all the bits, starting with lowest on
the left of each row. 18000 was chosen as the kill number, so make sure that
is at the end of the matrix, or the program will continue to read into memory.

Here PROGMEM is called, which stores the array into ROM, which leaves us
with our RAM. You cannot change the array during run-time, only when you
upload to the Arduino. You will need to pull it out of ROM, which is covered
below. If you want it to stay in RAM, just delete PROGMEM
*/
const uint16_t Heli[9] = 
//Diaganal swipe across the screen
{ 8188	,
128	,
4033	,
8162	,
16383	,
8191	,
4090	,
8737	,
8188	};


const uint16_t FishLeft[9] = 

{	384	,
	448	,
	9208	,
	14332	,
	16375	,
	16383	,
	14332	,
	9208	,
	496	};


const uint16_t FishLeftTailUp[9] = 
{	8576	,
	12736	,
	15352	,
	16380	,
	16375	,
	14335	,
	10236	,
	1016	,
	496	};

const uint16_t FishLeftTailDown[9] = 
{	384	,
	448	,
	1016	,
	10236	,
	14327	,
	16383	,
	16380	,
	13304	,
	8688	};


const uint16_t Fish2Left[9] = 


{	0	,
	496	,
	9208	,
	14334	,
	16375	,
	16383	,
	14334	,
	9208	,
	496	};


const uint16_t FishRight[9] = 

{	96	,
	224	,
	2033	,
	4091	,
	15359	,
	16383	,
	4091	,
	2033	,
	992	};

const uint16_t FishRightTailDown[9] = 
{	96	,
	224	,
	2032	,
	4089	,
	15355	,
	16383	,
	4095	,
	2035	,
	993	};

const uint16_t FishRightTailUp[9] = 
{	97	,
	227	,
	2039	,
	4095	,
	15359	,
	16379	,
	4089	,
	2032	,
	992	};



const uint16_t Fish2Right[9] = 

{	0	,
	992	,
	2033	,
	8187	,
	15359	,
	16383	,
	8187	,
	2033	,
	992	};


const uint16_t Fish2RightTailUp[9] = 

{	1	,
	995	,
	2039	,
	8191	,
	15359	,
	16379	,
	8185	,
	2032	,
	992	};

const uint16_t Fish2RightTailDown[9] = 
{	0	,
	992	,
	2032	,
	8185	,
	15355	,
	16383	,
	8191	,
	2035	,
	993	};


const uint16_t Fish2LeftTailUp[9] = 
{	8192	,
	12784	,
	15352	,
	16382	,
	16375	,
	14335	,
	10238	,
	1016	,
	496	};

const uint16_t Fish2LeftTailDown[9] = 
{	0	,
	496	,
	1016	,
	10238	,
	14327	,
	16383	,
	16382	,
	13304	,
	8688	};


const uint16_t zero[9] = 
{	0	,
	0	,
	0	,
	0	,
	0	,
	0	,
	0	,
	0	,
	0	};


static const char welcome[]="Willkommen !!!   ";
static const char turbine[] = "  turbine  - Offene Werkstatt ";

int do_once = 1;


void setup() {
  randomSeed(analogRead(0));
  LedSign::Init(DOUBLE_BUFFER | GRAYSCALE);  //Initializes the screen

}
void loop() 
{
  int what;
  int FlyInTime;
  int FlyOutTime;
  int StayTime;
  LedSign::Init(DOUBLE_BUFFER | GRAYSCALE);  //Initializes the screen

  what = random( 1, 7 );
  FlyInTime = random( 100, 2000 );
  FlyOutTime = random( 100, 2000 );
  StayTime = random( 200, 2000 );
  
  switch ( what )
  {
    case 2:
    case 3:
    case 4: 
      LedSign::Init(DOUBLE_BUFFER | GRAYSCALE);  //Initializes the screen
      LedSign::Init( );  //Initializes the screen
      DisplayText( turbine );
      delay ( 500) ;
      break;
    
    case 1:
      LedSign::Init(DOUBLE_BUFFER | GRAYSCALE);  //Initializes the screen
      AnimateFish2Right(FlyInTime, StayTime, FlyOutTime, Fish2Right, Fish2RightTailDown, Fish2RightTailUp );
      delay (500);
      break;
    case 5:  
      LedSign::Init(DOUBLE_BUFFER | GRAYSCALE);  //Initializes the screen
      AnimateFish2Left(FlyInTime, StayTime, FlyOutTime, FishLeft, FishLeftTailDown, FishLeftTailUp);
      delay (500);
      break;
    case 6:
      LedSign::Init(DOUBLE_BUFFER | GRAYSCALE);  //Initializes the screen
      LedSign::Init( );  //Initializes the screen
      DisplayText( welcome );
      delay ( 500) ;
      break;
  }
}


void DisplayText(const char * whichtext)                     
{
  int8_t x2 = 1;
  int8_t i2 = 0;
  int8_t do_stop = 0;
  for ( int8_t x=DISPLAY_COLS, i=0;; x--) 
  {
    LedSign::Clear();
    for (int8_t x2=x, i2=i; x2<DISPLAY_COLS;) 
    {
      int8_t w = Font::Draw(whichtext[i2], x2, 0);
      x2 += w;
      i2 = (i2+1);
      if ( i2 >= strlen(whichtext))
      { 
        do_stop = 1;
      }
      if (x2 <= 0)	// off the display completely?
      {
        if ( do_stop )
        {
          return;
        }
        x = x2, i = i2;
      }
    }
    delay(80);
  }
}



void AnimateFish2Left( int FlyInTime, int ShowTime, int FlyOutTime, const uint16_t * pBitMapNormal, const uint16_t * pBitMapAnim1, const uint16_t * pBitMapAnim2 )

{
  uint8_t gray = 4;
  int j;
  int max_schleif = random (1,5);

  FlyInBitMapFromRight(pBitMapNormal, gray, FlyInTime );  //Displays the bitmap
  delay( random( 100, 500) );
  for( j = 0 ; j < max_schleif; ++j )
  {
     DisplayBitMap( pBitMapAnim1, gray);
     delay( 150 );
     DisplayBitMap( pBitMapNormal, gray);
     delay( 150 );
     DisplayBitMap( pBitMapAnim2, gray);
     delay( 150 );
     DisplayBitMap( pBitMapNormal, gray);
     delay( 150 );
  }
  if ( ShowTime > 1200 )
  {
    delay( ShowTime - 1200 );
  }
  LedSign::Clear();
  FlyOutBitMapToLeft(Fish2Left, gray, FlyOutTime);  //Displays the bitmap
  LedSign::Clear();
}

void AnimateFish2Right(int FlyInTime, int ShowTime, int FlyOutTime, const uint16_t * pBitMapNormal, const uint16_t * pBitMapAnim1, const uint16_t * pBitMapAnim2 )
{
  uint8_t gray = 4;
  int j;
  int max_schleif = random (1,5);

  FlyInBitMapFromLeft(pBitMapNormal, gray, FlyInTime );  //Displays the bitmap
  delay( random( 100, 500) );
  for( j = 0 ; j < max_schleif; ++j )
  {
     DisplayBitMap( pBitMapAnim1, gray);
     delay( 150 );
     DisplayBitMap( pBitMapNormal, gray);
     delay( 150 );
     DisplayBitMap( pBitMapAnim2, gray);
     delay( 150 );
     DisplayBitMap( pBitMapNormal, gray);
     delay( 150 );
  }
  if ( ShowTime > 1200 )
  {
    delay( ShowTime - 1200 );
  }
  LedSign::Clear();
  FlyOutBitMapToRight(Fish2Right, gray, FlyOutTime);  //Displays the bitmap
  LedSign::Clear();
}


void FlyInBitMapFromRight( const uint16_t * pBitMap, uint8_t grayscale, uint16_t milliseconds)
{
  int line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data
  unsigned int delaytime = milliseconds / 13;
  for ( int animate = 13; animate >= 0; animate-- )
  {
    for( line = 0; line < 9; line++) 
    {
      data = pBitMap[line];
      for ( int led = 0 ;  led < 14 ; ++led ) 
      {
        if (data & (1<<led)) 
        {
          MyLedSignSet(led + animate, line, grayscale);
        }
        else 
        {
          MyLedSignSet(led + animate, line, 0);
        }
      }
    }
    LedSign::Flip(true); 
    delay(delaytime);  
  }
}


void FlyOutBitMapToLeft( const uint16_t * pBitMap, uint8_t grayscale, uint16_t milliseconds)
{
  int line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data
  unsigned int delaytime = milliseconds / 13;

  for ( int animate = 0; animate <= 14; animate++ )
  {
    for( line = 0; line < 9; line++) 
    {
      data = pBitMap[line];
      for ( int led = 0 ;  led < 14 ; ++led ) 
      {
        if (data & (1<<led)) 
        {
          MyLedSignSet(led - animate, line, grayscale);
        }
        else 
        {
          MyLedSignSet(led - animate, line, 0);
        }
      }
      MyLedSignSet(14 - animate, line, 0 );
      MyLedSignSet(15 - animate, line, 0 );
    }
    LedSign::Flip(true); 
    delay(delaytime);  
  }
}

void FlyInBitMapFromLeft( const uint16_t * pBitMap, uint8_t grayscale, uint16_t milliseconds)
{
  int line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data
  unsigned int delaytime = milliseconds / 13;
  for ( int animate = 13; animate >= 0; animate-- )
  {
    for( line = 0; line < 9; line++) 
    {
      data = pBitMap[line];
      for ( int led = 0 ;  led < 14 ; ++led ) 
      {
        if (data & (1<<led)) 
        {
          MyLedSignSet(led - animate, line, grayscale);
        }
        else 
        {
          MyLedSignSet(led - animate, line, 0);
        }
      }
      MyLedSignSet(14 - animate, line, 0 );
      MyLedSignSet(15 - animate, line, 0 );
    }
    LedSign::Flip(true); 
    delay(delaytime);  
  }
}

void FlyOutBitMapToRight( const uint16_t * pBitMap, uint8_t grayscale, uint16_t milliseconds) 
{
  int line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data
  unsigned int delaytime = milliseconds / 13;
  for ( int animate = 0; animate <= 14; animate++ )
  {
    for( line = 0; line < 9; line++) 
    {
      data = pBitMap[line];
      for ( int led = 0 ;  led < 14 ; ++led ) 
      {
        if (data & (1<<led)) 
        {
          MyLedSignSet(led + animate, line, grayscale);
        }
        else 
        {
          MyLedSignSet(led + animate, line, 0);
        }
      }
      MyLedSignSet( animate - 1, line, 0 );
      MyLedSignSet( animate - 2, line, 0 );
    }
    LedSign::Flip(true); 
    delay(delaytime);  
  }
}


void DisplayBitMap( const uint16_t * pBitMap, uint8_t grayscale)
{
  byte line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data

  for( line = 0; line < 9; line++) 
  {
    data = pBitMap[line];
    for ( byte led = 0 ;  led < 14 ; ++led ) 
    {
      if (data & (1<<led)) 
      {
        LedSign::Set(led, line, grayscale);
      }
      else 
      {
         LedSign::Set(led, line, 0);
      }
    }
  }
  LedSign::Flip(true);   
}

void MyLedSignSet( int column, int row, int grayscale)
{
  if(( column >= 0 ) && (column < 14))
  {
    LedSign::Set( column, row, grayscale);
  }
}

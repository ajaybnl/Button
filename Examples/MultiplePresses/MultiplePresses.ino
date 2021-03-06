

#include <Button.h>


/*Valid Pull Values

BUTTON_PULLUP  (Physical Button with a 1k-10k resistor to VCC on GPIO & GND WIRE at second pin)

BUTTON_PULLDOWN (Physical Button with a 1k-10k resistor to ground on GPIO & VCC WIRE at second pin)

Empty : Internal PullUp EG: Button(2)
*/

//Attach a button to Pin 2 and Gnd

Button button = Button(2);

void setup(){
  
  pinMode(13,OUTPUT); //debug to led 13
  
  
  Serial.begin(9600);   

}

void loop(){



//#############################################################################
// Example of using Button Multi Presses

int presses=button.presses();

if(presses>=1){
   // Multi Presses

//Led On
   Led(1);
   
   
	Serial.println("Button Presses ");
	Serial.println(presses);
	Serial.println(" Times");
	

   	
	  
	  //Led Off
    Led(0);
}
//#############################################################################





}

void Led(byte on){
	digitalWrite(13,(on==1?HIGH:LOW));
	delay(10);
}
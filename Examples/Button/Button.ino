

#include <Button.h>


/*Valid Pull Values

BUTTON_PULLUP  (Physical Button with a 1k-10k resistor to VCC on GPIO & GND WIRE at second pin)

BUTTON_PULLDOWN (Physical Button with a 1k-10k resistor to ground on GPIO & VCC WIRE at second pin)

Empty : Internal PullUp EG: Button(12)
*/
Button button = Button(12,BUTTON_PULLDOWN);
Button button1 = Button(11,BUTTON_PULLDOWN);
Button button2 = Button(10,BUTTON_PULLDOWN);

void setup(){
  pinMode(13,OUTPUT); //debug to led 13
  Serial.begin(115200);
  
  

//handler mode (special functions for button events
  button1.pressHandler(onPress);
  button1.releaseHandler(onRelease);
  button1.holdHandler(buttonhold, 100); // must be held for at least 1000 ms to trigger
}

void loop(){

  
	/*Valid Functions: 
	
	bool uniquePress(); // Best for push detection
    
    bool held(unsigned int time=0); // uniquepress must be written in sketch
    
    bool heldFor(unsigned int time); // works without uniquepress
    
	unsigned int holdTime() const; // uniquepress must be written in sketch
 
    int presses() const { return numberOfPresses; }

    bool isPressed();
    bool wasPressed();
    bool stateChanged();
    void setHoldThreshold(unsigned int holdTime);
    
	*/
	




if(button.uniquePress()){
Serial.println("uniquePress()");
} // Best for push detection

	

if(button.stateChanged()){
Serial.print("stateChanged() : ");
Serial.println(button.stateChanged());
}



//Detect Long Press
//but passes after firing uniquePress event
//best for single event for Hold    
//uniquePress must be there in sketch
if(button.held(1000)==true){
Serial.println("Held : 1000");
}


//#############################################################################
// Example of using Button Single Press ,Double Click & Long Press Incremeting

if (button.uniquePress()==true) {
   // Single Click

    
   } else if(button.presses()>=2){
     //double click within 400 miliseconds 
  
  
  }else if(button.held(2000)==true){  
    
    //Held for 2 Secs
    delay(100);
    
    while(button3.isPressed()==true){
      
  //Do while Button hold
  
  delay(100);
    }
}
//#############################################################################












//uniquePress must be there in sketch
if(button.holdTime()>3000){
Serial.println("holdTime : 3000");
}




//Use if you dont need uniquePress event (Button Press Event)
//works without uniquepress in sketch
if(button.heldFor(5000)==true){  
  Serial.println("HeldFor : 5000");
}

//Misc Functions:
/*
if(button.isPressed()){
Serial.print("isPressed() : ");
Serial.println(button.isPressed());

Serial.print("Presses() : ");
Serial.println(button.presses());

}

if(button.wasPressed()){
Serial.print("wasPressed() : ");
Serial.println(button.wasPressed());
}


if(button.holdTime()>10){
Serial.print( "holdTime() : ");
Serial.println(button.holdTime() );
}


*/   
   
    
  
}

// handlers
void onPress(Button& b){
Serial.println( "--------------holdHandler() : press");

}

void onRelease(Button& b){
Serial.println( "--------------holdHandler() : release");

}
void buttonhold(Button& b){
Serial.println( "--------------holdHandler() : hold");

}
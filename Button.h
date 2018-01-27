/* $Id$
||
|| @file 		       Button.cpp
|| @author 		     Alexander Brevig              <alexanderbrevig@gmail.com>        
|| @url            http://alexanderbrevig.com
||
||
|| @contribution
|| | Change by ajay kumar (ajaybnl@gmail.com)
|| #
||
|| @description
|| | Corrected Some Functions to use easily. Also Added Their Use in Examples
|| #
||
||
|| @description
|| | This is a Hardware Abstraction Library for Buttons
|| | It providea an easy way of handling buttons
|| #
||
|| @license LICENSE_REPLACE
||
*/

#ifndef Button_h
#define Button_h

#include <inttypes.h>

#define BUTTON_PULLUP HIGH
#define BUTTON_PULLUP_INTERNAL 2
#define BUTTON_PULLDOWN LOW

class Button;
typedef void (*buttonEventHandler)(Button&);

class Button {
  public:
  
    Button(uint8_t buttonPin, uint8_t buttonMode=BUTTON_PULLUP_INTERNAL);
    
    void pullup(uint8_t buttonMode);
    void pulldown();
    
    bool isPressed();
    bool wasPressed();
    bool stateChanged();
    bool uniquePress();
    
    void setHoldThreshold(unsigned int holdTime);
    bool held(unsigned int time=0);
    bool heldFor(unsigned int time);
    
    void pressHandler(buttonEventHandler handler);
    void releaseHandler(buttonEventHandler handler);
    void clickHandler(buttonEventHandler handler);
    void holdHandler(buttonEventHandler handler, unsigned int holdTime=0);
  
    unsigned int holdTime() const;
    inline unsigned int presses() { 
	unsigned int n=numberOfPresses;
	if(numberOfPresses>0){if ((millis()-pressedStartTime1) > 400){ numberOfPresses=0; pressedStartTime1=0;}}
	return n;
	}
    unsigned long pressedStartTime1=0;
    bool operator==(Button &rhs);
    
  private: 
    uint8_t pin;
    uint8_t mode;
    uint8_t state;
    unsigned int pressedStartTime;
    unsigned int holdEventThreshold;
    buttonEventHandler cb_onPress;
    buttonEventHandler cb_onRelease;
    buttonEventHandler cb_onClick;
    buttonEventHandler cb_onHold;
    unsigned int numberOfPresses;
    bool triggeredHoldEvent;
};

#endif
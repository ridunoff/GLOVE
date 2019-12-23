# GLOVE
Experimenting with alternative interface design using an Arduino and a work glove. I created an interactive demo of how a back-of-hand interface could function. 

![GLOVE Animated Logo](AnimatedLogo.gif)

## LCD Screen Pages

![GLOVE Welcome](images/welcome.jpeg)

For this project, I used the Grove RGB Backlit LCD Screen and an Arduino Uno to alternate through the different example features of the interface. To switch between pages, I needed to clear the screen and re-print all of the text every half second as a refresh rate. The positioning of the LCD screen worked fine for the demo, but in an future iteration, I would want the screen more towards the person when the hand is in a resting state. This would be located on the lower thumb area, where it attaches to the rest of the hand. 

![GLOVE Page Navigation](menu.gif)

### Time and Date

![GLOVE Welcome](images/Time.jpeg)

An additional part would be needed to give an accurate date and time. This part is called an Real Time Calculator and can be added on to the pins of the Arduino. 

### Weather

This feature could easily be implemented with an internet connected Raspberry Pi and the Python weather API as well. For a more complex demo, did experiement a bit with the temperature senesor, but this would be less helpful in determining the outside temperature. 

### Messages

Similar to a smartwatch, it could be useful to have notifications appear on the GLOVE. 

### Calendar

![GLOVE Welcome](images/event.jpeg)

It could also be beneficial to provide access to the user's calendar to remind them of their upcoming events.


## Menu Navigation

![GLOVE Page Navigation](https://media.giphy.com/media/H7lsme6jIfvdvkTIBS/giphy.gif)

To navigate to a different page, the wearer can use their thumb to tap until they get to the page that they are looking for. This feature works well due to the interrupt that I set for the button. 

## Power Button

![GLOVE Page Navigation](https://media.giphy.com/media/mBefXPKR1n9dOyxih0/giphy.gif)

To turn the LCD screen attached to the GLOVE off, one must make a fist and bumb the side of their hand to the table. This presses a button that changes the state of the device.

## Fabrication Method

To adhere the sensors and LCD screen to the glove, I sewed a few loops through the glove and the holes in each board. This method works really well for rapid prototyping as the strings could easily be cut without damaging the glove if I needed to move any of the sensors. I found that sewing through the board at least 3 times was good enough to hold that corner in place.

## Materials List

![Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3)
![Grove Base Shield V2](http://wiki.seeedstudio.com/Base_Shield_V2/)
![Grove Touch Sensor](http://wiki.seeedstudio.com/Grove-Touch_Sensor/)
![Grove Button](http://wiki.seeedstudio.com/Grove-Button/)
![Grove RGB Backlight LCD Screen](http://wiki.seeedstudio.com/Grove-LCD_RGB_Backlight/)

#### Thanks!
Thank you to the Olin College Library for the Grove Arduino kit and the Principles of Engineering course for giving me the confidence to make my own Arduino projects.

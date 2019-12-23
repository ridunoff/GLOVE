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

![GLOVE Page Navigation](menu.gif)

To navigate to a different page, the wearer can use their thumb to tap until they get to the page that they are looking for. This feature works well dur to the interrupt that I set for the button. 

## Power Button

![GLOVE Page Navigation](Power.gif)

To turn the LCD screen attached to the GLOVE off, one must make a fist and bumb the side of their hand to the table. This presses a button that changes the state of the device.

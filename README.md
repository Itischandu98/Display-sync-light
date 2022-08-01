# Programing WS2812B leds to react with the display (Two different codes)

## personal note for future reference

This project is left in the middle (The codes work but needs some more work). Since, it is taking for about 2 seconds for the serial communication with the Arduino Uno. But I am uploading these for reference and for anyone intrested in this project and want to build one for themselves or to develop further.

The idea for this to be possible is to do this with and raspberry pi and a video capture card (Ordered one and the only raspberry pi I got is running octoprint). the video capture card reads the display into a specific pixel size and program the leds to react in that certain way.

## working

### First Code

The "serial_speed.ino" code reads the values from different points on the edges sent it to the arduino and the leds should be mapped accrodingly.

The "serial_speed.py" is the python code which reads the color values at multiple points and send it to the arduino via serial communication. 

### Second Code

The "reactive_led.ino" code reads the most frequent color of the whole screen sent to the arduino and lights up the leds according (same color of the frequent pixel color for entire strip)

The "reactive_led.py" reads the average color of the screen and send it to arduino via serial communication.


## To do
Need to install all the dependent libraries to work

First upload the arduino code with file extension ".ino" to the arduino and change the pins accrodingly. 

Then run the python program by changing the com port accordingly (it doesn't work simultaniously. so make sure you close the serial port in each one before starting with other one else you can just unplug and plug it back in).

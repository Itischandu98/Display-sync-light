import serial
import numpy as np
import time
from PIL import ImageGrab

## Connect to the arduino serial port
ser=serial.Serial('com4',9600)
time.sleep(3)
step = 50

## returns the most repeated pixel along the screen
def mostFrequent(List):
    counter = 0
    num = List[0] 
      
    for i in List: 
        curr_frequency = List.count(i) 
        if(curr_frequency> counter): 
            counter = curr_frequency 
            num = i 
  
    return num 

while 1:
    time.sleep(2)

    ## This takes a screen shot and takes pixels all over the screen and gets the most frequent pixel
    img = ImageGrab.grab()
    imgNP = np.array(img)
    im_arr = np.frombuffer(img.tobytes(), dtype=np.uint8)
    im_arr = im_arr.reshape((img.size[1], img.size[0], 3))
    r = g = b = 0
    pixelArray = []
    for y in range(0, 1080, step):
        for x in range(0, 1920, step):
            px = im_arr[y][x]
            pixelArray.append([px[0], px[1], px[2]])
    color = mostFrequent(pixelArray)

    ## Sending value ot the arduino
    val=str("{},{},{}".format(color[0],color[1],color[2]))
    print(val)
    ser.write(val.encode())
ser.close()
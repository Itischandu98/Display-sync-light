import serial
import time
import numpy as np
from PIL import ImageGrab

## Communicate with the arduino using the com port
ser=serial.Serial('com4',115200)

time.sleep(3)
mty=np.array([])
# to debug the code test and change it to "while 1:"
for i in range(1):
    ## Reads RGB values at different points along the top edge 
    ## change according to the screen resolution you can use pyautogui library to find the position of a particular spot
    y=15
    for x in range (15,1855,80):
        px = ImageGrab.grab().load()
        color = px[x, y]
        mty=np.append(mty,color)
    len_for_shape=((1855-15)//80)

    ## reshape based on number of points
    test=mty.reshape(len_for_shape,3).astype(int)

    ## Editing the values to send it to the arduino
    t1=(' '.join(map(str,test[:,0])))
    t2=(' '.join(map(str,test[:,1])))
    t3=(' '.join(map(str,test[:,2])))
    stringer=str("{},{},{}".format(t1,t2,t3))
    ser.write(stringer.encode())
    time.sleep(5)
    print(ser.readline().decode())
ser.close()
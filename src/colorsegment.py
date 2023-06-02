import numpy as np
import cv2

def on_trackbar(val):
    pass

cap = cv2.VideoCapture(0)
#ini buat window trackbar nya
cv2.namedWindow('Trackbars')

# nilai maximal dan minimal dari trackbar
# h = hue, s = saturation, v = value
#kalo mau tau hsv buat apa aja cari di gugel
h_min, s_min, v_min = 0, 0, 0
h_max, s_max, v_max = 255, 255, 255

# buat trackbar dari hsv range nya buat cari warna
cv2.createTrackbar('H Min', 'Trackbars', h_min, 255, on_trackbar)
cv2.createTrackbar('S Min', 'Trackbars', s_min, 255, on_trackbar)
cv2.createTrackbar('V Min', 'Trackbars', v_min, 255, on_trackbar)
cv2.createTrackbar('H Max', 'Trackbars', h_max, 255, on_trackbar)
cv2.createTrackbar('S Max', 'Trackbars', s_max, 255, on_trackbar)
cv2.createTrackbar('V Max', 'Trackbars', v_max, 255, on_trackbar)

while True:
    _, frame = cap.read()

    #rubah color frame jadi frame hsv
    hsvframe = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)

    #ini buat ngeset hsv ke trackbar dan biar hmin,hmax dan seterusnya bisa dipake kedepannya
    h_min = cv2.getTrackbarPos('H Min', 'Trackbars')
    s_min = cv2.getTrackbarPos('S Min', 'Trackbars')
    v_min = cv2.getTrackbarPos('V Min', 'Trackbars')
    h_max = cv2.getTrackbarPos('H Max', 'Trackbars')
    s_max = cv2.getTrackbarPos('S Max', 'Trackbars')
    v_max = cv2.getTrackbarPos('V Max', 'Trackbars')

    # masukin hasil segmentasi ke dua variabel,lower sama upper
    lower_color = np.array([h_min, s_min, v_min])
    upper_color = np.array([h_max, s_max, v_max])

    #masukin hasil segmentasi nya kesini
    mask = cv2.inRange(hsvframe , lower_color, upper_color)
        
    print(h_min,",",s_min,",",v_min,",",h_max,",",s_max,",",v_max)
    
    cv2.imshow("frame",frame)
    cv2.imshow("mask",mask)
    cv2.waitKey(1)

    

cap.release()
cv2.destroyAllWindows()




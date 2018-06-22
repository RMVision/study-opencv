# -*- coding: utf-8 -*-
"""
霍夫圆变换：
1.cv2.HoughCircles()
"""

import cv2
import numpy as np

img = cv2.imread('task11.jpg', 0)
img = cv2.medianBlur(img, 5)  # 中值滤波
cimg = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)

circles = cv2.HoughCircles(img, cv2.HOUGH_GRADIENT, 1, 20, param1=50, param2=30, minRadius=20, maxRadius=40)

circles = np.uint16(np.around(circles))

print('circles', circles)
for i in circles[0]:
    # 绘制外接圆
    cv2.circle(cimg, (i[0], i[1]), i[2], (0, 255, 0), 2)
    # 绘制中心的圆
    cv2.circle(cimg, (i[0], i[1]), 2, (0, 0, 255), 3)

cv2.imshow('res', cimg)
cv2.waitKey(0) & 0xFF
cv2.destroyAllWindows()

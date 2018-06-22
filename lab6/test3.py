# -*- coding: utf-8 -*-
"""
霍夫圆变换：
1.cv2.HoughCircles()
"""

import cv2 as cv
import numpy as np

img = cv.imread('task13.jpg', 0)
img = cv.medianBlur(img, 5)  # 中值滤波
cimg = cv.cvtColor(img, cv.COLOR_GRAY2BGR)  # 转化为灰度图像

circles = cv.HoughCircles(img, cv.HOUGH_GRADIENT, 1, 20, param1=50, param2=30, minRadius=20, maxRadius=30)

circles = np.uint16(np.around(circles))

print('circles', circles)
for i in circles[0]:
    # 绘制外接圆
    cv.circle(cimg, (i[0], i[1]), i[2], (0, 255, 0), 2)
    # 绘制中心的圆
    cv.circle(cimg, (i[0], i[1]), 2, (0, 0, 255), 3)

cv.imwrite('houghcircle3.png', cimg)
cv.imshow('res', cimg)
cv.waitKey(0) & 0xFF
cv.destroyAllWindows()

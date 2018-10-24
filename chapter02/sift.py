import numpy as np
import cv2 as cv

img = cv.imread('../img/266679.png')
cv.namedWindow("image", cv.WINDOW_AUTOSIZE)  # 定义窗口的大小
cv.imshow("image", img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.namedWindow("gray", cv.WINDOW_AUTOSIZE)  # 定义窗口的大小
cv.imshow("gray", gray)

sift = cv.xfeatures2d.SIFT_create()
kp = sift.detect(gray, None)

sift_keypoints = cv.drawKeypoints(gray, kp, img)
cv.namedWindow("sift_keypoints", cv.WINDOW_AUTOSIZE)  # 定义窗口的大小
cv.imshow("sift_keypoints", sift_keypoints)

cv.imwrite('sift_keypoints.jpg', img)

cv.waitKey(0)

# video_demo()

cv.destroyAllWindows()

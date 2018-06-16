import cv2 as cv

src = cv.imread("./img/266679.png") #读取图片

# 新建一个窗口并展示
cv.namedWindow("input image", cv.WINDOW_AUTOSIZE)
cv.imshow("input image", src)
cv.waitKey(0)
cv.destroyAllWindows()

print("hello")
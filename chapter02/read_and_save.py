import cv2 as cv


# 这个， 由于没有摄像头，暂时用不了
def video_demo():
    capture = cv.VideoCapture(0)
    while (True):
        ret, frame = capture.read()
        frame = cv.flip(frame, 1)  # 将图片颠倒
        cv.imshow("video", frame)
        c = cv.waitKey(0)
        if c == 27:
            break


def get_img_info(img):
    """获取图像信息"""
    print(type(img))
    print(img.shape)
    print(img.size)
    print(img.dtype)


src = cv.imread("../img/266679.png")  # 读取图片

# 新建一个窗口并展示
cv.namedWindow("image", cv.WINDOW_AUTOSIZE)  # 定义窗口的大小
cv.imshow("image", src)
get_img_info(src)
gray = cv.cvtColor(src, cv.COLOR_BGRA2GRAY)  # 转化为灰度图片
cv.imwrite("girl.jpg", gray)  # 存储
cv.waitKey(0)

# video_demo()

cv.destroyAllWindows()

print("hello")

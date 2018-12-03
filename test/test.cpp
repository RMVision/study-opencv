//
// Created by niracler on 18-10-20.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
    cout << "请输入 a, b and c (-200<=A、B、C<=200):";
    cin >> a >> b >> c;
    discriminant = b * b - 4 * a * c;

    if (a < -200 || a > 200 || b < -200 || b > 200 || c < -200 || c > 200) {
        cout << "错误：注意ABC范围-200<=A、B、C<=200" << endl;
        exit(0);
    }

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "有两个不同的实数根。" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else if (discriminant == 0) {
        cout << "有两个相同的实数根。" << endl;
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
    } else {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "有两个不同的复数根。" << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }

    return 0;
}


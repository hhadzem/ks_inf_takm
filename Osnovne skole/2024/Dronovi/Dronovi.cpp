#include<iostream>
#include<math.h>
using namespace std;

void parse(string dir, double &x_sign, double &y_sign) {
    if(dir == "S") { x_sign = 0; y_sign = 1; }
    else if(dir == "J") { x_sign = 0; y_sign = -1; }
    else if(dir == "I") { x_sign = 1; y_sign = 0;  }
    else if(dir == "Z") { x_sign = -1; y_sign = 0; }
    else if(dir == "SI") { x_sign = 1./sqrt(2); y_sign = 1./sqrt(2); }
    else if(dir == "SZ") { x_sign = -1./sqrt(2); y_sign = 1./sqrt(2); }
    else if(dir == "JI") { x_sign = 1./sqrt(2); y_sign = -1./sqrt(2); }
    else if(dir == "JZ") { x_sign = -1./sqrt(2); y_sign = -1./sqrt(2); }
}

int main() {
    int M, H;
    double xm = 0, ym = 0;
    double xh = 1, yh = 0;

    cin >> M;
    for(int i = 0 ; i < M; i++) {
        string dir; float value;
        cin >> dir >> value;
        double x_sign, y_sign;
        parse(dir, x_sign, y_sign);
        xm += x_sign * value; 
        ym += y_sign * value;
    }

    cin >> H;
    for(int i = 0 ; i < H; i++) {
        string dir; float value; 
        cin >> dir >> value;
        double x_sign, y_sign;
        parse(dir, x_sign, y_sign);
        xh += x_sign * value;
        yh += y_sign * value;
    }

    double diff = sqrt((xm - xh) * (xm - xh) + (ym - yh) * (ym - yh));
    cout << diff << endl;
    return 0;
}
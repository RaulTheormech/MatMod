#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string line;
    ifstream file("in.txt");
    double x0;
    double y0;
    file >> A >> B;
    double x_left = 0; 
    double y_left = 0; 
    double x_right = 0;
    double y_right = 0;
    double x_left_m = 0; 
    double y_left_m = 0;
    double x_right_m = 0;
    double y_right_m = 0;
    double h_right_0 = fabs((B * x_right - A * y_right) / sqrt(A * A + B * B));
    double h_left_0 = fabs((B * x_left - A * y_left) / sqrt(A * A + B * B));
    double x;
    double y;
    double h_left_1;
    double h_right_1;
    double y_right_m_0;
    double x_right_m_0;

    while (file >> x >> y) {
        if ((A >= 0 and B > 0) or (A > 0 and B <= 0)) {
            if (B * x - A * y < 0) {
                x_left = x;
                y_left = y;
                h_left_1 = fabs((B * x_left - A * y_left) / sqrt(A * A + B * B));
                if (h_left_1 >= h_left_0) {
                    h_left_0 = h_left_1;
                    x_left_m = x;
                    y_left_m = y;
                }
            } else {
                x_right = x;
                y_right = y;
                h_right_1 = fabs((B * x_right - A * y_right) / sqrt(A * A + B * B));
                if (h_right_1 >= h_right_0) {
                    h_right_0 = h_right_1;
                    x_right_m = x;
                    y_right_m = y;
                }
                if (h_right_1 == 0){
                    x_right_m_0 = x;
                    y_right_m_0 = y;
                }}
        }
        if ((A <= 0 and B < 0) or (A < 0 and B >= 0)) {
            if (B * x - A * y < 0) {
                x_left = x;
                y_left = y;
                h_left_1 = fabs((B * x_left - A * y_left) / sqrt(A * A + B * B))
                if (h_left_1 >= h_left_0) {
                    h_left_0 = h_left_1;
                    x_left_m = x;
                    y_left_m = y;
                }
} else {
                x_right = x;
                y_right = y;

            h_right_1 = fabs((B * x_right - A * y_right) / sqrt(A * A + B * B));
                
                if (h_right_1 >= h_right_0) {
                    h_right_0 = h_right_1;
                    x_right_m = x;
                    y_right_m = y;
                }
                if (h_right_1 == 0){
                    x_right_m_0 = x;
                    y_right_m_0 = y;
                }
            }
        }
    }
    file.close();
    if (h_right_1 == 0){
        cout << "\nLeftmost: " << x_left_m << " " << y_left_m;
        cout << "\nRightmost: " << x_right_m_0 << " " << y_right_m_0;
    }
    else {
        cout << "\nLeftmost: " << x_left_m << " " << y_left_m;
        cout << "\nRightmost: " << x_right_m << " " << y_right_m;
    }
}


#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string line;
    ifstream file("in.txt");
    double X_0;
    double Y_0;
    file >> X_0 >> Y_0;
    double x_left = 0; 
    double y_left = 0; 
    double x_right = 0;
    double y_right = 0;
    double x_left_m = 0; 
    double y_left_m = 0;
    double x_right_m = 0;
    double y_right_m = 0;
    double h_right_0 = fabs((Y_0 * x_right - X_0 * y_right) / sqrt(X_0 * X_0 + Y_0 * Y_0));
    double h_left_0 = fabs((Y_0 * x_left - X_0 * y_left) / sqrt(X_0 * X_0 + Y_0 * Y_0));
    double x;
    double y;
    double h_left_1;
    double h_right_1;
    double y_right_m_0;
    double x_right_m_0;
    while (file >> x >> y) {
                   if (Y_0 * x - X_0 * y < 0) {
                x_left = x;
                y_left = y;
                h_left_1 = fabs((Y_0 * x_left - X_0 * y_left) / sqrt(X_0 * X_0 + Y_0 * Y_0));
                if (h_left_1 >= h_left_0) {
                    h_left_0 = h_left_1;
                    x_left_m = x;
                    y_left_m = y;
                }
            } else {
                x_right = x;
                y_right = y;
                h_right_1 = fabs((Y_0 * x_right - X_0 * y_right) / sqrt(X_0 * X_0 + Y_0 * Y_0));
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

    file.close();
    if (h_right_1 == 0){
        cout << "Leftmost: " << x_left_m << " " << y_left_m<<"\n";
        cout << "Rightmost: " << x_right_m_0 << " " << y_right_m_0<<"\n";
    }
    else {
        cout << "Leftmost: " << x_left_m << " " << y_left_m<<"\n";
        cout << "Rightmost: " << x_right_m << " " << y_right_m<<"\n";
    }
}

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string line;
    ifstream input_data("in.tXt");

    double X0;
    double Y0;
    input_data >> X0 >> Y0;

    double X_0 = X0, Y_0 = Y0;

    double X_left = 0, Y_left = 0, X_right = 0, Y_right = 0;
    double X_left_m = 0, Y_left_m = 0, X_right_m = 0, Y_right_m = 0;

    double h_r_start = fabs((X_0 * X_right - X_0 * Y_right) / sqrt(X_0 * X_0 + Y_0 * Y_0));
    double h_left_0 = fabs((Y_0 * X_left - X_0 * Y_left) / sqrt(X_0 * X_0 + Y_0* Y_0));

    double X;
    double Y;
    double h_left_1;
    double h_right_1;
    double Y_r_start;
    double X_r_start;

    while (input_data >> X >> Y) {
        if ((X_0>= 0 and Y_0 > 0) or (X_0 > 0 and Y_0 <= 0)) {
            if (-Y_0 * X + X_0 * Y > 0) {
                X_left = X;
                Y_left = Y;

                h_left_1 = fabs((Y_0 * X_left - X_0 * Y_left) / sqrt(X_0 * X_0 + Y_0 * Y_0));
                if (h_left_1 >= h_left_0) {
                    
                    X_left_m = X;
                    Y_left_m = Y;
					h_left_0 = h_left_1;
                }
            } 
			else {
                X_right = X;
                Y_right = Y;
                h_right_1 = fabs((Y_0 * X_right - X_0 * Y_right) / sqrt(X_0 * X_0 + Y_0 * X_0));
                 if (h_right_1 >= h_r_start) {
                    h_r_start = h_right_1;
                    X_right_m = X;
                    Y_right_m = Y;
                }
                if (h_right_1 == 0){
                    X_r_start = X;
                    Y_r_start = Y;
                }
				}
				}
        if ((X_0 <= 0 and Y_0 < 0) or (X_0 < 0 and Y_0 >= 0)) {
            if (-Y_0 * X + X_0 * Y > 0) {
                X_left = X;
                Y_left = Y;
         h_left_1 = fabs((Y_0 * X_left - X_0 * Y_left) / sqrt(X_0 * X_0 + Y_0 * Y_0));
                if (h_left_1 >= h_left_0) {
                    h_left_0 = h_left_1;
                    X_left_m = X;
                    Y_left_m = Y;
                }

            } else {
                X_right = X;
                Y_right = Y;
				h_right_1 = fabs((Y_0 * X_right - X_0 * Y_right) / sqrt(X_0 * X_0 + Y_0 * Y_0));
       if (h_right_1 >= h_r_start) {
                    h_r_start = h_right_1;
                    X_right_m = X;
                    Y_right_m = Y;
                }
                if (h_right_1 == 0){
                    X_r_start = X;
                    Y_r_start = Y;
                }} }}
    input_data.close();
    if (h_right_1 == 0){
        cout << "\nLeftmost: " << X_left_m << " " << Y_left_m;
        cout << "\nRightmost: " << X_r_start << " " << Y_r_start;
    }
    else {
        cout << "\nLeftmost: " << X_left_m << " " << Y_left_m;
        cout << "\nRightmost: " << X_right_m << " " << Y_right_m;
    }
}

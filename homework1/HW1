#include <iostream>
#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
#include <stdlib.h>
using namespace std;
int main() {
    string line;
    ifstream Input_data("in.txt");
    double X_0;
    double Y_0;
    Input_data >> X_0 >> Y_0;
    double X_L = 0; 
    double Y_L = 0; 
    double X_R = 0;
    double Y_R = 0;
    double X_Lm = 0; 
    double Y_Lm = 0;
    double X_Rmax = 0;
    double Y_Lmax = 0;
    double H_Rstart = fabs((Y_0 * X_R - X_0 * Y_R) / sqrt(X_0 * X_0 + Y_0 * Y_0));
    double H_Lstart = fabs((Y_0 * X_L - X_0 * Y_L) / sqrt(X_0 * X_0 + Y_0 * Y_0));
    double x;
    double y;
    double H_L1;
    double H_R1;
    double Y_Rms;
    double X_Rms;
    while (Input_data >> x >> y) {
                   if (Y_0 * x - X_0 * y < 0) {
                X_L = x;
                Y_L = y;
                H_L1 = fabs((Y_0 * X_L - X_0 * Y_L) / sqrt(X_0 * X_0 + Y_0 * Y_0));
                if (H_L1 >= H_Lstart) {
                    H_Lstart = H_L1;
                    X_Lm = x;
                    Y_Lm = y;
                }
            } else {
                X_R = x;
                Y_R = y;
                H_R1 = fabs((Y_0 * X_R - X_0 * Y_R) / sqrt(X_0 * X_0 + Y_0 * Y_0));
                if (H_R1 >= H_Rstart) {
                    H_Rstart = H_R1;
                    X_Rmax = x;
                    Y_Lmax = y;
                }
                if (H_R1 == 0){
                    X_Rms = x;
                    Y_Rms = y;
                }}
        }
Input_data.close();
    if (H_R1 == 0){
        cout << "Leftmost: " << X_Lm << " " << Y_Lm<<"\n";
        cout << "Rightmost: " << X_Rms << " " << Y_Rms<<"\n";
    }
    else {
        cout << "Leftmost: " << X_Lm << " " << Y_Lm<<"\n";
        cout << "Rightmost: " << X_Rmax << " " << Y_Lmax<<"\n";
    }
}

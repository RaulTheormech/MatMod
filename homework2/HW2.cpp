#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//globals.cpp
double g = 9.81;

double time(double x0, double x, double v_x, int j)
{
    return (x - x0) / (j * v_x);
}

double vy_func(double v_y0, double t)
{
    return v_y0 - g * t;
}

double y_func(double h0, double v_y, double t)
{
    return h0 + v_y * t - (g *pow(t, 2))/2;
}

double get_h0(ifstream& input_file)
{
    string first;
    double h0;
    input_file >> first;
    h0 = stod(first);
    return h0;
}

double get_v0(ifstream& input_file, double& v_x, double& v_y) 
{
    string v1;
    string v2;
    input_file >> v1 >> ws >> v2;
    v_x = stod(v1);
    v_y = stod(v2);
    return v_x, v_y;
}

void get_coords(ifstream& input_file, vector<double>& X, vector<double>& H) 
{
    string x;
    string h;
    input_file >> x >> ws >> h;
    X.push_back(stod(x));
    H.push_back(stod(h));
}
void help(double x0, double h0, double v_x, double v_y, vector<double>& X, vector<double>& H, int& result, int j)
{
    double y;
    double t;
    for (int i = result; (i > -1 && i < X.size()); i = i + j)
    {
        t = time(x0, X[i + j], v_x, j);
        y = y_func(h0, v_y, t);
        if (H[i + j] < y)
        {
            result += j;
        }
        else
        {
            double v_yt = vy_func(v_y, t);
            j = j*(-1);
            help(X[i], y, v_x, v_yt, X, H, result, j);
            return;
        }
    }
}


void calculate(ifstream& input_file, double& h0, double& v_x, double& v_y, vector<double>& X, vector<double>& H, int& result)
{
    string line;
    double t;
    double y;
    while (getline(input_file, line))
    {
        get_coords(input_file, X, H);
        t = time(0, X.back(), v_x, 1);
        y = y_func(h0, v_y, t);
        if (H.back() < y)
        {
            result++;
        }
     
        else if ((y < 0) || (result == 0))
        {
            return;
        }
        else
        {
            double v_yt = vy_func(v_y, t);
            help(X.back(), y, v_x, v_yt, X, H, result, -1);
            return;
        }
    }
}



int main(int argc, char** argv)
{
    string file;

    if (argc == 2)
    {
        file = argv[1];
        cout << "1st argument: " << argv[1] << endl;
    }
    else {
        file = "in.txt";
    }
    ifstream input_file(file);

    double h0;
    double v_x;
    double v_y;

    int result = 0;

    string line;

    vector <double> X;
    vector <double> H;
 
    h0= get_h0(input_file);
    v_x, v_y=get_v0(input_file, v_x, v_y);

    calculate(input_file, h0, v_x, v_y, X, H, result);

    cout << result;
    
    return 0;
}


#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include <stdio.h>
using namespace std;

int hand(double a_x, double a_y, double x, double y) {
	if ((a_x * y - a_y * x) > 0) {
		//влево
		return 1;
	}
	else if (a_y == 0 && a_x == 0) {
		//вправо
		return 0;
	}
	else {
		//вправо
		return 0;
	}

}

double get_x(ifstream& input_file) 
{
	string coord1;
	double x;
	input_file >> coord1;
	x = stod(coord1);
	return x;
}

double get_y(ifstream& input_file)  
{
	string coord2;
	double y;
	input_file >> ws >> coord2;
	y = stod(coord2);
	return y;
}

int main() {
	const char filename[] = "in.txt";

	FILE* f = fopen(filename, "rb");
	if (!f)
	{
		cout << "File is not exists" << endl;
		return 0;
	}

	char a;
	size_t readed = fread(&a, 1, 1, f);

	if (readed) {
	
	double a_x;
	double a_y;
	
	double x;
	double y;

	double x_left = 0;
	double y_left = 0;

	double x_right = 0;
	double y_right = 0;

	double start_dist_left = -1;
	double start_dist_right = -1;

	double leftmost_x = 0;
	double leftmost_y = 0;

	double rightmost_x = 0;
	double rightmost_y = 0;

	
	
	string line;

	ifstream input_file("in.txt");
	
	a_x = get_x(input_file);
	a_y = get_y(input_file);

	while (getline(input_file, line))
	{
		x = get_x(input_file);
		y = get_y(input_file);
		int help = hand(double(a_x), double(a_y), double(x), double(y));
		
		if (help == 1) {
			double dist_left = abs((-(a_x)*y + (a_y)*x)) / sqrt(pow(a_x, 2) + pow(a_y, 2));
			if (dist_left >= start_dist_left) {
				leftmost_x = x;
				leftmost_y = y;
				start_dist_left = dist_left;
				
			}
		}
		else if (help == 0) {
			double dist_right = abs((-(a_x)*y + (a_y)*x)) / sqrt(pow(a_x, 2) + pow(a_y, 2));
			if (dist_right >= start_dist_right) {
				rightmost_x = x;
				rightmost_y = y;
				start_dist_right = dist_right;
			}
             }

	}
	cout << "Leftmost: " << leftmost_x <<" " << leftmost_y << endl;

	cout << "Rightmost: " << rightmost_x <<" " << rightmost_y << endl;
	}
	else {
//		cout << "Leftmost: " << 0 << " " << 0 << endl;
cout << "(0,0)"<< endl;
//		cout << "Rightmost: " <<0 << " " << 0 << endl;
	}
	return 0;
}



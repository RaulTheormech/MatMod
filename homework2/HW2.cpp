#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
void calc(vector<vector<double>> &wall, vector<double> &V);
void new_wall(vector<vector<double>> &wall, vector<double> &V);
double solution(vector<vector<double>> wall, vector<double> V);
double g;
int main(int argc, char** argv) {
    if(argc < 2 || argc > 2){
        cout << "аргументов нет или их больше чем мы ожидаем"<< endl;
    }
    g=9.81;
vector<double> V(2); 
    vector<vector<double>> wall; 
    ifstream input_data;
    input_data.open(argv[1]);
    double h;
    input_data >> h;
    input_data >> V[0]; input_data >> V[1];
    double current = 0; 
    double x;   
    double y;  
    double h_curwall;
    wall.push_back({0, h, current}); 
    while (!input_data.eof() && input_data >> x && input_data >> y) {
        current += 1;
        h_curwall = h + V[1] / V[0] * x - g * 0.5 / (V[0]*V[0]) * x * x;
        wall.push_back({x, y, current});
        if (y >= h_curwall) {
            wall[current][1] = h_curwall;
            break;}}
    input_data.close();
    if (y < h_curwall) { 
        cout << int(current) << endl;
        return 0; }
    if (wall.size() <= 2) { 
        cout << 0 << endl;
        return 0;}
cout << int(solution(wall, V)) << endl;
 return 0;}
void calc(vector<vector<double>> &wall, vector<double> &V) {
  reverse(wall.begin(), wall.end()); 
    V[1] = V[1] - g * wall[0][0] / V[0];
double x_0 = wall[0][0];
    wall[0][0] = 0;
    for (size_t i = 1; i < wall.size(); i++) {
        wall[i][0] = x_0 - wall[i][0];}
}
void new_wall(vector<vector<double>> &wall, vector<double> &V) {
    vector<vector<double>> tem_wall = {wall[0]};
    double h_curwall;
    for (size_t i = 1; i < wall.size(); i++) {
        h_curwall = wall[0][1] + V[1] / V[0] * wall[i][0] - g * 0.5 / (V[0]*V[0]) * wall[i][0] * wall[i][0];
        tem_wall.push_back({wall[i][0], wall[i][1], wall[i][2]});
        if (wall[i][1] >= h_curwall) {
            tem_wall[i][1] = h_curwall; 
            break;}}
    wall.swap(tem_wall);}
double solution(vector<vector<double>> wall, vector<double> V) {
    while (true) {
        calc(wall, V);
        if (wall.size() == 2) {
            if (wall[0][2] > wall[1][2]) {
                return wall[1][2];
            } else {
                return wall[0][2];}}
        if (wall[0][2] == 0) {
            return 0;}
        new_wall(wall, V);}
}


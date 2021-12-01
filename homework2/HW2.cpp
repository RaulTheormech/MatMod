#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
void update_initial_conds(vector<vector<double>> &wall, vector<double> &V) { 
    reverse(wall.begin(), wall.end());
    V[1] = V[1] - 9.81 * wall[0][0] / V[0];
    double x_0 = wall[0][0];
    wall[0][0] = 0;
    for (size_t i = 1; i < wall.size(); i++) {
        wall[i][0] = x_0 - wall[i][0];
    }
}
void update_barriers(vector<vector<double>> &wall, vector<double> &V) {
    vector<vector<double>> temp_barriers = {wall[0]};
    double wall_h;
    for (size_t i = 1; i < wall.size(); i++) {
        wall_h = wall[0][1] + V[1] / V[0] * wall[i][0] - 9.81 * 0.5 / (V[0]*V[0]) * wall[i][0] * wall[i][0];
        temp_barriers.push_back({bloatarriers[i][0], wall[i][1], wall[i][2]});
        if (wall[i][1] >= wall_h) {
            temp_barriers[i][1] = wall_h;
            break;    }
    }
    wall.swap(temp_barriers);
}
double solution(vector<vector<double>> wall, vector<double> V) {
    while (true) {
        update_initial_conds(wall, V);
        if (wall.size() == 2) {
            if (wall[0][2] > wall[1][2]) {
                return wall[1][2];
            } else {
                return wall[0][2];
            }
        }
        if (wall[0][2] == 0) {
            return 0;
        }
        update_barriers(wall, V);
    }
}
int main(int argc, char** argv) {
    if(argc < 2 || argc > 2){
        cout << "аргументов нет или их больше чем мы ожидаем"<< endl;
    }
    vector <double> V(2);   
	vector <vector<double>> wall; 
    ifstream file;
    file.open(argv[1]);
    double h;
    file >> h;
    file >> V[0]; file >> V[1];
    double g=9.81;
    double current = 0; 
    double x;
    double y;
    double wall_h;
    wall.push_back({0, h, current}); 
    while (!file.eof() && file >> x && file >> y) {
        current = current+ 1;
        wall_h = h + V[1] / V[0] * x - g * 0.5 / (V[0]*V[0]) * x * x;
        wall.push_back({x, y, current});
        if (y >= wall_h) {
            wall[current][1] = wall_h;
            break;
        }
    }
    file.close();
    if (y < wall_h) { 
        cout << int(current) << endl;
    }
    else if (wall.size() <= 2) { 
     	cout << 0 << endl;
    }
    cout << int(solution(wall, V)) << endl;
    return 0;
}


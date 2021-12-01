#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void update_initial_conds(vector<vector<float>> &barriers, vector<float> &velocity);
void update_barriers(vector<vector<float>> &barriers, vector<float> &velocity);
float find_sector(vector<vector<float>> barriers, vector<float> velocity);

int main(int argc, char** argv) {
    if(argc < 2 || argc > 2){
        cout << "аргументов нет или их больше чем мы ожидаем"<< endl;
    }
    // остальной код программы
    vector<float> velocity(2); // вектор для скорости
    vector<vector<float>> barriers; // вектор для барьеров

    // считывание до первого столкновения
    ifstream file;
    file.open(argv[1]);
    float h;
    file >> h;
    file >> velocity[0]; file >> velocity[1];

    float index = 0; // индекс текущего барьера
    float x;   // положение текущего
    float y;   // барьера
    float height_on_cur_barrier;
    barriers.push_back({0, h, index}); // добавляем начальный мнимый барьер
    while (!file.eof() && file >> x && file >> y) {
        index += 1;
        height_on_cur_barrier = h + velocity[1] / velocity[0] * x - 9.81 * 0.5 / (velocity[0]*velocity[0]) * x * x;
        barriers.push_back({x, y, index});
        if (y >= height_on_cur_barrier) {
            barriers[index][1] = height_on_cur_barrier; // обновим высоту начала полета
            break;
        }
    }
    file.close();

    // особые случаи задачи
    if (y < height_on_cur_barrier) { // когда мяч перелетел через все барьеры
        cout << int(index) << endl;
        return 0;
    }
    if (barriers.size() <= 2) { // когда мяч столкнулся с первым барьером или барьеров вообще не было
        cout << 0 << endl;
        return 0;
    }

    cout << int(find_sector(barriers, velocity)) << endl;
    return 0;
}

//функция для пересчета иксов в массиве (отражение массива барьеров относительно последнего)
void update_initial_conds(vector<vector<float>> &barriers, vector<float> &velocity) {
    // развернем массив барьеров
    reverse(barriers.begin(), barriers.end());

    // пересчет скорости
    velocity[1] = velocity[1] - 9.81 * barriers[0][0] / velocity[0];

    float x_0 = barriers[0][0];
    barriers[0][0] = 0;
    for (size_t i = 1; i < barriers.size(); i++) {
        barriers[i][0] = x_0 - barriers[i][0];
    }
}

// функция определения нового массива барьеров
void update_barriers(vector<vector<float>> &barriers, vector<float> &velocity) {
    vector<vector<float>> temp_barriers = {barriers[0]};
    float height_on_cur_barrier;
    for (size_t i = 1; i < barriers.size(); i++) {
        height_on_cur_barrier = barriers[0][1] + velocity[1] / velocity[0] * barriers[i][0] - 9.81 * 0.5 / (velocity[0]*velocity[0]) * barriers[i][0] * barriers[i][0];
        temp_barriers.push_back({barriers[i][0], barriers[i][1], barriers[i][2]});
        if (barriers[i][1] >= height_on_cur_barrier) {
            temp_barriers[i][1] = height_on_cur_barrier; // обновим высоту начала полета
            break;
        }
    }
    barriers.swap(temp_barriers);
}

// функция посика конечной области куда попадет мяч
float find_sector(vector<vector<float>> barriers, vector<float> velocity) {
    while (true) {
        update_initial_conds(barriers, velocity);
        if (barriers.size() == 2) {
            if (barriers[0][2] > barriers[1][2]) {
                return barriers[1][2];
            } else {
                return barriers[0][2];
            }
        }
        if (barriers[0][2] == 0) {
            return 0;
        }
        update_barriers(barriers, velocity);
    }
}

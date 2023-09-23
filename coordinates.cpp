#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("coordinates.txt");
    if (!inputFile) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        double latitude, longitude;
        ss.ignore(1);  // skip '('
        ss >> latitude;
        ss.ignore(2);  // skip ", "
        ss >> longitude;

        // Округляем координаты до целых чисел
        int intLatitude = static_cast<int>(latitude);
        int intLongitude = static_cast<int>(longitude);

        // Проверяем, что округленные координаты находятся в заданных пределах
        if (intLatitude >= 50 && intLatitude <= 80 && intLongitude >= 20 && intLongitude <= 45) {
            cout << "Найдены координаты в квадрате: (" << latitude << ", " << longitude << ")" << endl;
        }
    }

    inputFile.close();
    return 0;
}

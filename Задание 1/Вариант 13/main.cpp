#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    int counter = 0;

    string vowels = "ауэоыиюя";

    while (true) {
        getline(cin, line);
        if (line.empty()) {
            break;
        }

        char first = line[0];
        char last = line[line.length() - 1];

        if (vowels.find(first) != string::npos && vowels.find(last) != string::npos) {
            counter++;
        }
    }

    cout << "В тексте " << counter << " строк начинаются и заканчиваются глассными русскими буквами" << endl;
    return 0;
}
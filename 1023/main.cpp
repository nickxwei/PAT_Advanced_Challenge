#include <iostream>
#include <vector>

using namespace std;

vector<int> input;
int number_counts[9] = {0};

int main(void)
{
    char tmp;
    while ((tmp = cin.get()) != '\n') {
        input.push_back(tmp - '0');
        number_counts[tmp - '0' - 1]++;
    }

    int in = 0;
    bool is_fun = true;
    int last_in = 0;
    for (int i = input.size() - 1; i >= 0; i--) {
        int mult = (input[i] * 2) + in;
        in = mult / 10;
        int spare = mult % 10;
        if (spare != 0 && --number_counts[spare - 1] < 0) {
            is_fun = false;
        }
        input[i] = spare;
        if (i == 0 && in > 0) {
            last_in = 1;
            is_fun = false;
        }
    }   

    if (is_fun == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    if (last_in == 1) {
        cout << 1;
    }

    for (int i = 0; i < input.size(); i++) {
        cout << input[i];
    }

    cout << endl;

    return 0;
}
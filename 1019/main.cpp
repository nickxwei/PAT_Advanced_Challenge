#include <iostream>
#include <vector>

using namespace std;

vector<int> out;

int main(void)
{
    int n, b;
    cin >> n >> b;

    if (n == 0) {
        cout << "Yes" << endl;
        cout << 0 << endl;
        return 0;
    }

    while (n != 0) {
        out.push_back(n % b);
        n = n / b;
    }

    int len = out.size();
    bool is_palindromic = true;

    for (int i = 0; i < len / 2; i++) {
        if (out[i] != out[len - i - 1]) {
            is_palindromic = false;
            break;
        }
    }

    if (is_palindromic == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    for (int i = len - 1; i > 0; i--) {
        cout << out[i] << ' ';
    }
    cout << out[0] << endl;

    return 0;
}
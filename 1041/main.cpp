#include <iostream>

using namespace std;

int n;
int a[100001], m[100000];

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;

        m[temp]++;
    }

    for (int i = 0; i < n; i++) {
        if (m[a[i]] == 1) {
            cout << a[i] << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}
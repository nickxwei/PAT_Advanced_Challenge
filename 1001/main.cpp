#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void) {
    int a, b;
    ostringstream os;
    cin >> a >> b;
    os << a + b;
    string s = os.str();
    int len = s.length();

    for(int i = 0; i < len; i++) {
        cout << s[i];
        if(s[i] == '-')
            continue;
        if((i + 1) % 3 == len % 3 && i != len - 1) {
            cout << ',';
        }
    }

    return 0;
}
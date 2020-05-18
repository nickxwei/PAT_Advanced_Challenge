#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> v;

int main(void)
{
    int n, min_len = 256;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s, '\n');
        min_len = min_len > s.length() ? s.length() : min_len;
        v.push_back(s);
    }

    string out;
    bool flag = 0;

    for (int i = 0; i < min_len; i++) {
        char ch;
        string::iterator it = v[0].end();
        flag = 0;
        
        ch = *(it - i - 1);
        for (int j = 1; j < v.size(); j++) {
            string::iterator it = v[j].end();
            if (ch != *(it - i - 1)) {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
            break;
        else 
            out += ch;
    }

    int len = out.length();
    if (len == 0) {
        cout << "nai" << endl;
    } else {
        for (int i = len - 1; i >= 0; i--) {
            cout << out[i];
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
char port1[100000], port2[100000];

int main(void) 
{
    int ch = ' ';
    unsigned int sta = 0, i = 0;
    bool negative = true;

    string s;
    cin >> s;
    unsigned int j = 0;
    while (j < s.length()) {
        switch (sta) {
            case 0:
                if (s[j] == '-')
                    cout << s[j];
                sta++;
                i = 0;
                break;
            case 1:
                if (s[j] != 'E') 
                    port1[i++] = s[j];
                else {
                    port1[i++] = '\0';
                    sta++;
                    i = 0;
                }
                break;
            case 2:
                if (s[j] == '+') {
                    negative = true;
                } else {
                    negative = false;
                }
                sta++;
                break;
            case 3:
                port2[i++] = s[j];
                break;
            default:
                break;
        }
        j++;
    }
    
    port2[i++] = '\0';
    int cnt = atoi(port2);
    int len = strlen(port1);
    if (negative == true) {
        cout << port1[0];
        for ( i = 2; i < len; i++) {
            if (cnt == 0) {
                cout << ".";
                break;
            }
            cout << port1[i];
            cnt--;
        }

        if (i != len) {
            while (i < len) {
                cout << port1[i];
                i++;
            }
        } else {
            while (cnt) {
                cout << '0';
                cnt--;
            }
        }
    } else {
        if (cnt == 0) {
            cout << port1;
        } else {
            cnt--;
            cout << "0.";
            while (cnt) {
                cout << "0";
                cnt--;
            }

            for (i = 0; i < len; i++) {
                if (port1[i] != '.')
                    cout << port1[i];
            }
        }
    }

    cout << endl;
    return 0;
}
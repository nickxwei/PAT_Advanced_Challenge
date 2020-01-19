#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _Info{
    string account;
    string password;
}Info_Type;

unsigned int n;
string account, password;
bool flag = 0;
vector<Info_Type> info_v;
Info_Type info_e;

int main(void)
{
    cin >> n;

    for (unsigned int i = 0; i < n; i++) {
        flag = 0;
        cin >> account;
        cin >> password;
        
        for (unsigned int j = 0; j < password.length(); j++) {
            switch (password[j]) {
                case '1':
                    password[j] = '@';
                    flag = 1;
                    break;
                case '0':
                    password[j] = '%';
                    flag = 1;
                    break;
                case 'l':
                    password[j] = 'L';
                    flag = 1;
                    break;
                case 'O':
                    password[j] = 'o';
                    flag = 1;
                    break;
                default:
                    break;
            }
        }

        if (flag == 1) {
            info_e.account = account;
            info_e.password = password;
            info_v.push_back(info_e);
        }
    }

    if (info_v.size() == 0) {
        if (n == 1)
            cout << "There is " << n << " account and no account is modified" << endl;
        else 
            cout << "There are " << n << " accounts and no account is modified" << endl;
    } else {
        cout << info_v.size() << endl;
        for (unsigned int j = 0; j < info_v.size(); j++) {
            cout << info_v[j].account << ' ' << info_v[j].password << endl;
        }
    }

    return 0;
}
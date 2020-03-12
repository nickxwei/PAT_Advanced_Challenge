#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void)
{
    int n;
    char s[100], s1[100], s2[100];
    string out_str = "";
    cin >> n;
    for (unsigned int i = 0; i < n; i++) {
        scanf("%s", s);
        int k = strlen(s) / 2;
        memcpy(s1, s, k);
        s1[k] = '\0';
        memcpy(s2, s + k, k);
        s2[k] = '\0';

        int a = atoi(s1);
        int b = atoi(s2);
        if (a * b == 0) {
            out_str += "No\n";
        } else {
            if (atoi(s) % (a * b) == 0) {
                out_str += "Yes\n";
            } else {
                out_str += "No\n";
            }
        }
    }

    cout << out_str;

    return 0;
}
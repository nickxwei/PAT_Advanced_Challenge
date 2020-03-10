#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

string week_str[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void)
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    unsigned int w, h, m;

    int cnt = 0;
    unsigned int i = 0;

    while (i < s1.length() && i < s2.length()) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            w = s1[i] - 'A';
            break;
        }
        i++;
    }

    i += 1;
    while (i < s1.length() && i < s2.length()) {
        if (s1[i] == s2[i]) {
            if (s1[i] >= '0' && s1[i] <= '9') {
                h = s1[i] - '0';
                break;
            } else if (s1[i] >= 'A' && s1[i] <= 'N') {
                h = s1[i] - 'A' + 10;
                break;
            }
        }
        i++;
    }

    for (unsigned int i = 0; i < s3.length() && i < s4.length(); i++) {
        if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
            m = i;
            break;
        }
    }

    printf("%s %02d:%02d", week_str[w].c_str(), h, m);
    return 0;
}
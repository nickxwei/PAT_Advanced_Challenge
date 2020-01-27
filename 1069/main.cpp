#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp1(char c1, char c2)
{
    return c1 > c2;
}

bool cmp2(char c1, char c2)
{
    return c1 < c2;
}

int Kaprekar(string s)
{
    char a1[5], a2[5];

    strcpy(a1, s.c_str());
    strcpy(a2, s.c_str());

    sort(a1, a1 + s.size(), cmp1);
    sort(a2, a2 + s.size(), cmp2);

    int num1, num2, result;
    num1 = atoi(a1);
    num2 = atoi(a2);

    result = num1 - num2;

    printf("%04d - %04d = %04d\n", num1, num2, result);

    return result; 
}

int main(void)
{
    string s;
    cin >> s;

    s.insert(0, 4 - s.length(), '0');

    int num = -1;
    while (num != 6174 && num != 0) {
        num = Kaprekar(s);
        ostringstream os;
        os << num;
        s = os.str();
        s.insert(0, 4 - s.length(), '0');
    }
    

    return 0;
}
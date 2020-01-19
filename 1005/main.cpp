#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a;
    int sum = 0;
    string engArr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    cin >> a;
    for (auto x : a)
        sum += (x - '0');
    string b = to_string(sum);
    cout << engArr[b[0] - '0'];
    for (auto it = b.begin() + 1; it < b.end(); it++)
        cout << " " + engArr[*it - '0'];
    return 0;
}
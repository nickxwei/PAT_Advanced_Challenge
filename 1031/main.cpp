#include <iostream>

using namespace std;

unsigned char input_str[80];

int main(void)
{
    unsigned char c;
    unsigned int i = 0, n1, n2, len;

    while ((c =  cin.get()) != '\n') 
        input_str[i++] = c;
    len = i;
    n1 = (len + 2) / 3;
    n2 = n1 + (len + 2) % 3;
    
    for (i = 0; i < n1 - 1; i++) {
        cout << input_str[i];
        for (int j = 0; j < n2 - 2; j++) {
            cout << ' ';
        }
        cout << input_str[len - i - 1] << endl;
    }

    for (int j = 0; j < n2; j++) {
        cout << input_str[n1 - 1 + j];
    }

    return 0;
}
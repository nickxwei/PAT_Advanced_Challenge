#include <iostream>

using namespace std;

int main(void) 
{
    int from = 0, to, sum = 0;
    int n;

    cin >> n;
    
    while(n--) {
        cin >> to;
        if(to > from) {
            sum += 6 * (to - from);
        } else if(to < from) {
            sum += 4 * (from - to);
        }
        from = to;
        sum += 5;
    }

    cout << sum;
    return 0;
}
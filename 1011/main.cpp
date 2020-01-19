#include <iostream>
#include <iomanip>

using namespace std;

float game_odd_array[3][3];
char game_result_array[3] = {'W', 'T', 'L'};
int max_ratio[3];

int main(void)
{
    int i,j;
    float max = -1.0;
    float result = 1.0;
    for (i = 0; i < 3; i++) {
        max = -1.0;
        for (j = 0; j < 3; j++) {
            float temp;
            cin >> temp;
            game_odd_array[i][j] = temp;
            if (temp >= max) {
                max = temp;
                max_ratio[i] = j;
            }
        }
    }
    
    for (i = 0; i < 3; i++) {
        cout << game_result_array[max_ratio[i]] << ' ';
        result *= game_odd_array[i][max_ratio[i]];
    }
    result = (result * 0.65 - 1) * 2;
    cout << fixed << setprecision(2) <<  result << endl;
    return 0;
}
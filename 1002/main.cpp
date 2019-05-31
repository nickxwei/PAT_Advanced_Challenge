#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    vector<pair<int, float> > input1, input2;
    ostringstream os;

    int len;
    cin >> len;
    for(int i = 0; i < len; i++) {
        pair<int, float> temp;
        cin >> temp.first >> temp.second;
        if(temp.second != 0)
            input1.push_back(temp);
    }

    cin >> len;
    for(int i = 0; i < len; i++) {
        pair<int, float> temp;
        cin >> temp.first >> temp.second;
        if(temp.second != 0)
            input2.push_back(temp);
    }

    int i, j, num = 0;
    os << fixed << setprecision(1);
    for(i = 0, j = 0; i < input1.size() && j <input2.size(); ) {
        if(input1[i].first > input2[j].first) {
            os << ' ' << input1[i].first << ' ' << input1[i].second;
            i++;
            num++;
        } else if(input1[i].first == input2[j].first) {
            float temp_sum = input1[i].second + input2[j].second;
            if(temp_sum != 0) {
                os << ' ' << input1[i].first << ' ' << temp_sum;
                num++;
            }
            i++;
            j++;
        } else {
            os << ' ' << input2[j].first << ' ' << input2[j].second;
            j++;
            num++;
        }
    }

    while (i < input1.size()) {
        os << ' ' << input1[i].first << ' ' << input1[i].second;
        i++;
        num++;
    }

    while (j < input2.size()) {
        os << ' ' << input2[j].first << ' ' << input2[j].second;
        j++;
        num++;
    }
    
    cout << num << os.str() << endl;
    return 0;
}

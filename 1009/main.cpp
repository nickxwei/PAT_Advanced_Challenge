#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <iomanip>

using namespace std;

float test_array[2001] = {0};
ostringstream os;

int main(int argc, char** argv) {
	vector<pair<int, float> > input1, input2;
	int n;
	cin >> n;
	while(n--) {
		pair<int, float> temp;
		int a;
		float b;
		cin >> a >> b;
		temp.first = a;
		temp.second = b;
		input1.push_back(temp);
	}

	cin >> n;
	while (n--) {
		pair<int, float> temp;
		int a;
		float b;
		cin >> a >> b;
		temp.first = a;
		temp.second = b;
		input2.push_back(temp);
	}
	
	for(int i = 0; i < input1.size(); i++) {
		for(int j = 0; j < input2.size(); j++) {
			int sum = input1[i].first + input2[j].first;
			test_array[sum] += input1[i].second * input2[j].second;
		}
	}
	os << fixed << setprecision(1);
	int sum = 0;
	for(int i = 2000; i >= 0; i--) {
		if(test_array[i] != 0) {
			os << ' ' << i << ' ' <<test_array[i];
			sum++;
		}
	}
	cout << sum << os.str() << endl;

	return 0;
}

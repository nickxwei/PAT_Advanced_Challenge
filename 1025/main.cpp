#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 

using namespace std;

typedef struct _List_Info {
		string registerId;
		int score;
		int final_rank;
		int location_number;
		int local_rank;
	} List_Info;

bool cmp(List_Info a, List_Info b) {
	if (a.score != b.score) {
		return a.score > b.score;
	} else {
		if ( strcmp(a.registerId.c_str(), b.registerId.c_str()) > 0) {
			return false;
		} else {
			return true;
		}
	}
}

int main(int argc, char** argv) 
{

	int n;
	vector<List_Info> total_data;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		vector<List_Info> temp_data;
		cin >> k;

		for (int j = 0; j < k; j++) {
			string temp_id;
			int temp_score;
			List_Info temp_info;

			cin >> temp_id >> temp_score;
			
			temp_info.registerId = temp_id;
			temp_info.score = temp_score;
			temp_info.location_number = i + 1;

			temp_data.push_back(temp_info);
		}

		sort(temp_data.begin(), temp_data.end(), cmp);
		temp_data[0].local_rank = 1;
		total_data.push_back(temp_data[0]);
		for (int j = 1; j < temp_data.size(); j++) {
			if (temp_data[j].score == temp_data[j - 1].score) {
				temp_data[j].local_rank = temp_data[j - 1].local_rank;
			} else {
				temp_data[j].local_rank = j + 1;
			}

			total_data.push_back(temp_data[j]);
		}
	}

	sort(total_data.begin(), total_data.end(), cmp);
	cout << total_data.size() << endl;

	total_data[0].final_rank = 1;
	
	cout << total_data[0].registerId << ' ' << total_data[0].final_rank << ' ' << total_data[0].location_number << ' ' << total_data[0].local_rank << endl;

	for (int i = 1; i < total_data.size(); i++) {
		if (total_data[i].score == total_data[i - 1].score) {
			total_data[i].final_rank = total_data[i - 1].final_rank;
		} else {
			total_data[i].final_rank = i + 1;
		}

		cout << total_data[i].registerId << ' ' << total_data[i].final_rank << ' ' << total_data[i].location_number << ' ' << total_data[i].local_rank << endl;
	}

	return 0;
}

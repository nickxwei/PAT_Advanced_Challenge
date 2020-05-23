#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
#define MAXN 100

vector<int> arr[MAXN];
queue<pair<int, int>> q;

int main(void)
{
    int n, m;
    cin >> n >> m;
    if (n == 0)
        return -1;

    for (int i = 0; i < m; i++) {
        int num, cout;
        cin >> num >> cout;
        for (int j = 0; j < cout; j++) {
            int tmp;
            cin >> tmp;
            arr[num].push_back(tmp);
        }
    }

    int i = 0;
    for (i = 0; i < arr[1].size(); i++) {
        pair<int, int> tmp;
        tmp.first = arr[1][i];
        tmp.second = 1;
        q.push(tmp);
    }

    if (i == 0) {
        cout << "1" << endl;
        return 0;
    } else 
        cout << "0" << " ";

    int last_layer = 1, leaf_num = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        if (p.second != last_layer) {
            last_layer = p.second;
            cout << leaf_num << " ";
            leaf_num = 0;
        }

        for (i = 0; i < arr[p.first].size(); i++) {
            pair<int, int> tmp;
            tmp.first = arr[p.first][i];
            tmp.second = p.second + 1;
            q.push(tmp);
        }

        if (i == 0)
            leaf_num++;
    }

    cout << leaf_num << endl;
    return 0;
}
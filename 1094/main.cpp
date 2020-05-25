#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define MAXN 105

struct node_t {
    int data;
    vector<int> children;
};

node_t nodes[MAXN];
int n, m;
int largest_gener_cnt = -1, largest_gener_level;

void bfs(int root)
{
    queue<pair<int, int>> q;
    pair<int, int> tmp_p;
    tmp_p.first = root;
    tmp_p.second = 1;
    q.push(tmp_p);

    int last_level = -1, cnt = 1;

    while (!q.empty()) {
        pair<int, int> tmp;
        tmp = q.front();
        q.pop();
        int data = tmp.first;
        int level = tmp.second;

        if (level != last_level) {
            cnt = 1;
            last_level = level;
        } else {
            cnt++;
        }

        if (cnt > largest_gener_cnt) {
            largest_gener_cnt = cnt;
            largest_gener_level = level;
        }

        for (vector<int>::iterator it = nodes[data].children.begin(); it != nodes[data].children.end(); it++) {
            tmp.first = *it;
            tmp.second = last_level + 1;
            q.push(tmp);
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int data, len;
        cin >> data >> len;
        for (int j = 0; j < len; j++) {
            int child;
            cin >> child;
            nodes[data].children.push_back(child);
        }
    }

    bfs(1);

    cout << largest_gener_cnt << " " << largest_gener_level << endl;
    return 0;
}
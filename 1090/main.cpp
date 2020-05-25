#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iomanip>

using namespace std;

#define MAXN 100005

struct node_t {
    vector<int> children;
};

node_t nodes[MAXN];

int n;
double price, r, highest_price = -1.0;
int last_level = -1;
int cnt = 0;

void bfs(int root)
{
    queue<pair<int, int>> q;
    pair<int, int> p;
    p.first = root;
    p.second = 0;
    q.push(p);

    while (!q.empty()) {
        pair<int, int> tmp;
        tmp = q.front();
        q.pop();

        int data = tmp.first;
        int level = tmp.second;

        if (level != last_level) {
            last_level = level;
            cnt = 1;
            if (highest_price < 0) 
                highest_price = price;
            else 
                highest_price *= (1 + r);
        } else {
            cnt++;
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
    int root;
    cin >> n >> price >> r;
    r /= 100;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (data == -1) {
            root = i;
            continue;
        }
        nodes[data].children.push_back(i);
    }

    bfs(root);


    cout.precision(2);
    cout << fixed << highest_price << " " << cnt << endl;

    return 0;
}
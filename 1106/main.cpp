#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

struct node_t {
    vector<int> children;
};
#define MAXN 100005

node_t nodes[MAXN];
int n;
double price, rate, lowest_price;

int last_level = -1, cnt = 0;
bool is_get = false;

void bfs(void)
{
    queue<pair<int, int>> q;
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    q.push(p);

    while (!q.empty()) {
        pair<int, int> p;
        p = q.front();
        q.pop();

        int data = p.first;
        int level = p.second;

        if (level != last_level) {
            if (is_get == true)
                return;
            last_level = level;
            cnt = 0;
        }

        int len = nodes[data].children.size();
        if (len == 0) {            
            is_get = true;
            cnt++;
        } else {
            for (int i = 0; i < len; i++) {
                p.first = nodes[data].children[i];
                p.second = level + 1;
                q.push(p);
            }
        }
    }

}

int main(void)
{
    cin >> n >> price >> rate;
    rate /= 100;
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int data;
            cin >> data;
            nodes[i].children.push_back(data);
        }
    }

    bfs();

    lowest_price = price * pow((1 + rate), last_level);

    cout.precision(4);
    cout << fixed << lowest_price << " " << cnt << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MAXN    100005

struct node_t {
    int data;
    vector<int> children;
};

node_t nodes[MAXN];
int cnt_arr[MAXN];

int n;
double p, r, sum = 0.0;

void dfs(int root, double price)
{
    int len = nodes[root].children.size();
    if (len == 0) 
        sum += price * cnt_arr[root];        
    else {
        for (int i = 0; i < len; i++) 
            dfs(nodes[root].children[i], price * (1 + r));
    }
}

int main(void)
{
    cin >> n >> p >> r;
    r /=  100;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        if (len == 0) {
            cin >> cnt_arr[i];
            continue;
        } else {
            for (int j = 0; j < len; j++) {
                int data;
                cin >> data;
                nodes[i].children.push_back(data);
            }
        }
    }

    dfs(0, p);
    cout.precision(1);
    cout << fixed << sum << endl;
    return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 101

struct tree_node_t {
    int weight;
    vector<int> children;
};

tree_node_t node[MAXN];
int n, m, s;
int path[MAXN];

bool cmp(int i, int j)
{
    return node[i].weight > node[j].weight;
}

void dfs(int root, int depth, int sum)
{
    sum += node[root].weight;
    path[depth] = node[root].weight;

    if (sum > s) 
        return;
    else if (sum == s) {
        if (node[root].children.size() != 0)
            return;
        for (int i = 0; i <= depth; i++) {
            printf("%d", path[i]);
            if (i == depth)
                printf("\n");
            else 
                printf(" ");
        }
    } else {
        for (int i = 0; i < node[root].children.size(); i++)
            dfs(node[root].children[i], depth + 1, sum);
    }
}

int main(void)
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        node[i].weight = w;
    }

    for (int i = 0; i < m; i++) {
        int data, num;
        scanf("%d%d", &data, &num);
        for (int j = 0; j < num; j++) {
            int child;
            scanf("%d", &child);
            node[data].children.push_back(child);
        }
        sort(node[data].children.begin(), node[data].children.end(), cmp);
    }

    dfs(0, 0, 0);
    return 0;
}
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAXN  12

struct node_t {
    int lchild;
    int rchild;
    int parent;
};

node_t nodes[MAXN];
vector<int> order;

int find_root(int num)
{
    while (nodes[num].parent != -1)
        num = nodes[num].parent;
    return num;
}

void levelorder_traversal(int root)
{
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        
        if (nodes[node].lchild != -1)
            q.push(nodes[node].lchild);
        
        if (nodes[node].rchild != -1)
            q.push(nodes[node].rchild);
    }
}

void inorder_traversal(int root)
{
    if (nodes[root].lchild != -1)
        inorder_traversal(nodes[root].lchild);
    order.push_back(root);
    if (nodes[root].rchild != -1)
        inorder_traversal(nodes[root].rchild);
}

void printf_order(void)
{
    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i == order.size() - 1)
            cout << endl;
        else 
            cout << " ";
    }
}

int main(void)
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
        nodes[i].parent = -1;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s[0] == '-')
            nodes[i].rchild = -1;
        else {
            nodes[i].rchild = s[0] - '0';
            nodes[s[0] - '0'].parent = i;
        }

        if (s[2] == '-')
            nodes[i].lchild = -1;
        else {
            nodes[i].lchild = s[2] - '0';
            nodes[s[2] - '0'].parent = i;
        }
    }

    int root = 0;
    root = find_root(0);

    order.clear();
    levelorder_traversal(root);
    printf_order();
    order.clear();
    inorder_traversal(root);
    printf_order();

    return 0;
}
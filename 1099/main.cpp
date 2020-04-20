#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct bst_node {
    int number;
    int value;
    bst_node* lchild;
    bst_node* rchild;
};

const int maxn = 100;
int input[maxn] = {0}, index = 0;
vector<pair<int, int>> child;
vector<int> level_order;
queue<bst_node *> q;

bst_node* new_bst_node(int number, int value)
{
    bst_node* node = new bst_node;
    node->number = number;
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;
}

void levelorder_traverse(bst_node* root)
{
    queue<bst_node*> q;
    if (root == NULL)
        return;
    
    q.push(root);

    while (!q.empty()) {
        bst_node* node = q.front();
        q.pop();
        level_order.push_back(node->value);
        if (node->lchild != NULL)
            q.push(node->lchild);
        
        if (node->rchild != NULL)
            q.push(node->rchild);
    }
}

void inorder_create_bst(bst_node* root)
{
    if (root == NULL)
        return;
    
    inorder_create_bst(root->lchild);
    root->value = *(input + index++);
    inorder_create_bst(root->rchild);
}

bool cmp(int a, int b)
{
    return a < b;
}

int main(void)
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        pair<int, int> p;
        int l, r;
        cin >> l >> r;
        p.first = l;
        p.second = r;
        child.push_back(p);
    }

    for (int i = 0; i < cnt; i++) {
        cin >> input[i];
    }
    sort(input, input + cnt, cmp);

    bst_node* root = new_bst_node(0, 0);
    q.push(root);
    while (!q.empty()) {
        bst_node* node = q.front();
        q.pop();
        if (child[node->number].first != -1) {
            node->lchild = new_bst_node(child[node->number].first, 0);
            q.push(node->lchild);
        }

        if (child[node->number].second != -1) {
            node->rchild = new_bst_node(child[node->number].second, 0);
            q.push(node->rchild);
        }
    }

    inorder_create_bst(root);
    levelorder_traverse(root);

    for (int i = 0; i < level_order.size(); i++) {
        cout << level_order[i];
        if (i != level_order.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}
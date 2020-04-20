#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct bt_node {
    int value;
    bt_node* lchild;
    bt_node* rchild;
};

const int maxn = 1000;
int input[maxn];
int cnt;
int index = 0;
vector<int> level_order;

bt_node* new_bt_node(int value)
{
    bt_node* node = new bt_node;
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

bt_node* create_cbt(int num) 
{
    queue<bt_node*> q;
    if (num <= 0)
        return NULL;

    bt_node* root = new_bt_node(0);
    q.push(root);
    num--;

    while (1) {
        bt_node* node = q.front();
        q.pop();

        if (num > 0) {
            num--;
            node->lchild = new_bt_node(0);
            q.push(node->lchild);
        } else {
            break;
        }

        if (num > 0) {
            num--;
            node->rchild = new_bt_node(0);
            q.push(node->rchild);
        } else {
            break;
        }
    }

    return root;
}

bool cmp(int a, int b)
{
    return a < b;
}

void inorder_init(bt_node* root)
{
    if (root == NULL)
        return;
    inorder_init(root->lchild);
    root->value = input[index++];
    inorder_init(root->rchild);
}

void levelorder_traverse(bt_node* root)
{
    queue<bt_node*> q;
    if (root == NULL)
        return;
    
    q.push(root);
    
    while (!q.empty()) {
        bt_node* node = q.front();
        q.pop();
        level_order.push_back(node->value);
        if (node->lchild != NULL) {
            q.push(node->lchild);
        }

        if (node->rchild != NULL) {
            q.push(node->rchild);
        }
    }

}

int main(void)
{
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
        cin >> input[i];
    sort(input, input + cnt, cmp);

    bt_node *root = NULL;
    root = create_cbt(cnt);
    inorder_init(root);
    levelorder_traverse(root);
    for (int i = 0; i < level_order.size(); i++) {
        cout << level_order[i];
        if (i != level_order.size() - 1)
            cout << " ";
    }

    return 0;
}
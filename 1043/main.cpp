#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN    1000

struct bt_node {
    int data;
    bt_node* lchild;
    bt_node* rchild;
};

vector<int> postorder;
bool is_failed = false;

bt_node* new_bt_node(int value)
{
    bt_node* node = new bt_node;
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void postorder_traverse(bt_node* root)
{
    if (root == NULL)
        return;

    postorder_traverse(root->lchild);
    postorder_traverse(root->rchild);
    postorder.push_back(root->data);
}

bool cmp_increase(int a, int b)
{
    return a < b;
}

bool cmp_decrease(int a, int b)
{
    return a > b;
}

bt_node* create_btree(int* pre, int* in, int len, bool is_bst)
{
    if (is_failed == true || len <= 0)
        return NULL;

    int pos = -1, value;
    value = *pre;
    for (int i = 0; i < len; i++) {
        if (*(in + i) == value) {
            pos = i;
            if (is_bst)
                break;
        }
    }

    if (pos == -1) {
        is_failed = true;
        return NULL;
    }

    int l_len = pos;
    int r_len = len - pos - 1;
    bt_node* node = new_bt_node(value);
    node->lchild = create_btree(pre + 1, in, l_len, is_bst);
    node->rchild = create_btree(pre + 1 + l_len, in + pos + 1, r_len, is_bst);
    return node;
}

int main(void)
{
    int pre[MAXN], in[MAXN];
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int data;
        cin >> data;
        pre[i] = data;
        in[i] = data;
    }

    bt_node* root;
    is_failed = false;
    sort(in, in + cnt, cmp_increase);
    root = create_btree(pre, in, cnt, true);
    if (is_failed) {
        is_failed = false;
        sort(in, in + cnt, cmp_decrease);
        root = create_btree(pre, in, cnt, false);
        if (is_failed) {
            goto failed;
        } else {
            goto success;
        }
    } else {
        goto success;
    }

failed:
    cout << "NO" << endl;
    return 0;
    
success:
    cout << "YES" << endl;
    postorder_traverse(root);
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i];
        if (i != postorder.size() - 1)
            cout << ' ';
    }
    return 0;
}
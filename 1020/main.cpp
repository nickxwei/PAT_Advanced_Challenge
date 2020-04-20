#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 30;
int postorder[maxn], inorder[maxn];
vector<int> levelorder;
bool failed = false;

struct bt_node {
    int value;
    bt_node* lchild;
    bt_node* rchild;
};

bt_node* new_bt_node(int value)
{
    bt_node* node = new bt_node;
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
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
        levelorder.push_back(node->value);
        
        if (node->lchild != NULL) {
            q.push(node->lchild);
        }

        if (node->rchild != NULL) {
            q.push(node->rchild);
        }
    }
}

bt_node* create_bt_from_post_and_in(int *post, int *in, int len)
{
    if (failed == true || len <= 0)
        return NULL;
    
    int pos = -1, value;
    value = *(post + len - 1);
    for (int i = 0; i < len; i++) {
        if (*(in + i) == value) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        failed = true;
        return NULL;
    }

    bt_node* node = new_bt_node(value);
    int l_len = pos;
    int r_len = len - pos - 1;
    node->lchild = create_bt_from_post_and_in(post, in, l_len);
    node->rchild = create_bt_from_post_and_in(post + l_len, in + pos + 1, r_len);
    return node;
}

int main(void)
{
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) 
        cin >> postorder[i];
    for (int i = 0; i < cnt; i++)
        cin >> inorder[i];

    bt_node* root = NULL;
    root = create_bt_from_post_and_in(postorder, inorder, cnt);
    levelorder_traverse(root);

    for (int i = 0; i < levelorder.size(); i++) {
        cout << levelorder[i];
        if (i != levelorder.size() - 1)
            cout << ' ';
    }
    
    return 0;
}
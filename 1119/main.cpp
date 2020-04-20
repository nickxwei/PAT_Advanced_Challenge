#include <iostream>
#include <vector>

using namespace std;

struct bt_node {
    int value;
    bt_node* lchild;
    bt_node* rchild;
};

const int maxn = 30;
int postorder[maxn], preorder[maxn];
vector<int> inorder;
bool is_unique = true, failed = false;

bt_node* new_bt_node(int value)
{
    bt_node* node = new bt_node;
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void inorder_traverse(bt_node* root)
{
    if (root == NULL)
        return;
    
    inorder_traverse(root->lchild);
    inorder.push_back(root->value);
    inorder_traverse(root->rchild);
}

bt_node* create_bt_from_post_and_pre(int *post, int* pre, int len)
{
    if (failed == true || len <= 0)
        return NULL;

    int pos, value;
    value = *pre;
    if (*(post + len - 1) != value)
        failed = true;
    
    bt_node* node = new_bt_node(value);
    if (len > 1) {
        value = *(pre + 1);

        for (int i = len - 1; i >= 0; i--) {
            if (*(post + i) == value) {
                pos = i;
                break;
            }
        }

        int l_len = pos + 1;
        int r_len = len - l_len - 1;
        if (r_len == 0) 
            is_unique = false;

        node->lchild = create_bt_from_post_and_pre(post, pre + 1, l_len);
        node->rchild = create_bt_from_post_and_pre(post + l_len, pre + l_len + 1, r_len);
        return node;
    } else {
        node->lchild = NULL;
        node->rchild = NULL;
        return node;
    }
    
}

int main(void)
{
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) 
        cin >> preorder[i];

    for (int i = 0; i < cnt; i++)
        cin >> postorder[i];

    bt_node* root = NULL;
    root = create_bt_from_post_and_pre(postorder, preorder, cnt);
    inorder_traverse(root);

    if (is_unique == true)
        cout << "Yes" << endl;  
    else 
        cout << "No" << endl;

    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i];
        if (i != inorder.size() - 1)
            cout << ' ';
        else 
            cout << endl;
    }

    return 0;
}
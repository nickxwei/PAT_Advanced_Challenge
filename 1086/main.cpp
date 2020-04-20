#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct bt_node {
    int value;
    bt_node* lchild;
    bt_node* rchild;
};

vector<int> postorder;

bt_node* new_bt_node(int value)
{
    bt_node* node = new bt_node;
    node->value = value;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void postorder_traverse(bt_node *root)
{   
    if (root == NULL)
        return;

    postorder_traverse(root->lchild);
    postorder_traverse(root->rchild);
    postorder.push_back(root->value);
}

int main(void)
{
    stack<bt_node*> inorder_s;
    int cnt;
    cin >> cnt;
    cnt = 2 * cnt;

    bt_node* root = NULL;
    bt_node* last_node = NULL;
    bt_node* node = NULL;
    bool is_push = false;

    while (cnt > 0) {
        string s;
        int value;
        cin >> s;
        cnt--;

        if (s == "Push") {
            cin >> value;
            if (last_node == NULL) {
                root = new_bt_node(value);
                inorder_s.push(root);
                last_node = root;
                is_push = true;
            } else {
                node = new_bt_node(value);
                inorder_s.push(node);

                if (is_push == true) { 
                    last_node->lchild = node;
                } else {
                    last_node->rchild = node;
                }

                is_push = true;
                last_node = node;
            }
        } else if (s == "Pop") {
            is_push = false;
            node = inorder_s.top();
            inorder_s.pop();
            last_node = node;
        }
    }

    postorder_traverse(root);

    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i];
        if (i != postorder.size() - 1)
            cout << " ";
    }

    return 0;
}
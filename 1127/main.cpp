#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define MAXN    32

struct node_t {
    int data;
    node_t* lchild;
    node_t* rchild;
};

int inorder_arr[MAXN];
int postorder_arr[MAXN];
int order[MAXN] = {0};
int level_cnt_arr[MAXN] = {0};
int highest_level = 0;

node_t* create_new_node(int data)
{
    node_t* node = new node_t;
    if (node == NULL)
        return NULL;
    
    node->data = data;
    node->lchild = node->rchild = NULL;
    return node;
}

node_t* create_from_in_and_post_order(int* in, int in_l, int in_r, 
                                      int *post, int post_l, int post_r)
{
    node_t* root = NULL;

    if (post_l >= post_r)
        return NULL;
    
    int data = * (post + post_r - 1);
    int pos = -1;
    for (int i = in_l; i < in_r; i++) {
        if (*(in + i) == data) {
            pos = i;
            break;
        }      
    }

    int l_len = pos - in_l;
    int r_len = in_r - pos - 1;
    root = create_new_node(data);
    root->lchild = create_from_in_and_post_order(in, in_l,    pos,  post, post_l,         post_l + l_len);
    root->rchild = create_from_in_and_post_order(in, pos + 1, in_r, post, post_l + l_len, post_r - 1);

    return root;
}

void reverse(int* a, int l, int r)
{
    int len = r - l;
    int cnt = len / 2;
    for (int i = 0; i < cnt; i++) {
        int data = *(a + l + i);
        *(a + l + i) = *(a + r - 1 -i);
        *(a + r - 1 -i) = data;
    }
}

void levelorder_traversal(node_t* root)
{
    queue<pair<node_t*, int>> q;
    int index = 0;

    if (root == NULL)
        return;
    
    pair<node_t*, int> p;
    p.first = root;
    p.second = 0;
    q.push(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        node_t* node = p.first;
        int level = p.second;
        highest_level = level;

        order[index++] = node->data;
        level_cnt_arr[level]++;

        if (node->lchild) {
            p.first = node->lchild;
            p.second = level + 1;
            q.push(p);
        }

        if (node->rchild) {
            p.first = node->rchild;
            p.second = level + 1;
            q.push(p);
        }
    }

}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inorder_arr[i];

    for (int i = 0; i < n; i++)
        cin >> postorder_arr[i];

    node_t* root = NULL;
    root = create_from_in_and_post_order(inorder_arr, 0, n, postorder_arr, 0, n);
    
    levelorder_traversal(root);

    int start = 0, end = n;
    for (int i = 0; i <= highest_level; i++) {
        if (i % 2 == 0) {
            reverse(order, start, start + level_cnt_arr[i]);
        }
        start += level_cnt_arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << order[i];
        if (i == n - 1)
            cout << endl;
        else 
            cout << " ";
    }
    return 0;
}
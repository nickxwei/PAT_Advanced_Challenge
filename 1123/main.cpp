#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node_t {
    int data;
    int height;
    node_t *lchild;
    node_t *rchild;
};

#define MAXN    21
#define HEIGHT(p) ((p == NULL) ? -1 : ((node_t *) p)->height)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

node_t nodes[MAXN];
int arr[MAXN];
vector<int> order;

node_t* create_new_node(int data)
{
    node_t* node = new node_t;
    if (node == NULL)
        return NULL;

    node->data = data;
    node->height = 0;
    node->lchild = node->rchild = NULL;

    return node;
}

node_t* left_left_rotate(node_t* k2)
{
    node_t* k1 = k2->lchild;
    k2->lchild = k1->rchild;
    k1->rchild = k2;

    k2->height = MAX(HEIGHT(k2->lchild), HEIGHT(k2->rchild)) + 1;
    k1->height = MAX(HEIGHT(k1->lchild), k2->height) + 1;
    return k1;
}

node_t* right_right_rotate(node_t* k1)
{
    node_t* k2 = k1->rchild;
    k1->rchild = k2->lchild;
    k2->lchild = k1;

    k1->height = MAX(HEIGHT(k1->lchild), HEIGHT(k1->rchild)) + 1;
    k2->height = MAX(HEIGHT(k2->rchild), k1->height) + 1;
    return k2;
}

node_t* left_right_rotate(node_t* k3)
{
    k3->lchild = right_right_rotate(k3->lchild);
    return left_left_rotate(k3);
}

node_t* right_left_rotate(node_t* k1)
{
    k1->rchild = left_left_rotate(k1->rchild);
    return right_right_rotate(k1);
}

node_t* insert_node(node_t* root, int data)
{
    if (root == NULL) {
        root = create_new_node(data);
        return root;
    }

    if (root->data == data)
        return NULL;
    else if (root->data > data) {
        root->lchild = insert_node(root->lchild, data);
        if (HEIGHT(root->lchild) - HEIGHT(root->rchild) == 2) {
            if (root->lchild->data > data)
                root = left_left_rotate(root);
            else 
                root = left_right_rotate(root);
        }
    } else {
        root->rchild = insert_node(root->rchild, data);
        if (HEIGHT(root->rchild) - HEIGHT(root->lchild) == 2) {
            if (root->rchild->data < data)
                root = right_right_rotate(root);
            else 
                root = right_left_rotate(root);
        }
    }

    root->height = MAX(HEIGHT(root->lchild), HEIGHT(root->rchild)) + 1;
    return root;
}

node_t* create_avl_tree(int* a, int len)
{
    node_t* root = NULL;
    for (int i = 0; i < len; i++)
        root = insert_node(root, *(a + i));
    return root;
}

bool last_node_flag = false, is_complete = true;

void levelorder_traversal(node_t* root)
{
    queue<node_t*> q;
    if (root == NULL)
        return;
    
    q.push(root);

    while (!q.empty()) {
        node_t* node = q.front();
        q.pop();
        order.push_back(node->data);

        if (node->lchild == NULL) {
            if (last_node_flag == false)
                last_node_flag = true;
        } else {
            q.push(node->lchild);
            if (last_node_flag == true)
                is_complete = false;
        }

        if (node->rchild == NULL) {
            if (last_node_flag == false)
                last_node_flag = true;
        } else {
            q.push(node->rchild);
            if (last_node_flag == true)
                is_complete = false;
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    node_t* root = create_avl_tree(arr, n);
    levelorder_traversal(root);

    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i == order.size() - 1)
            cout << endl;
        else 
            cout << " ";
    }

    if (is_complete)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;

    return 0;
}
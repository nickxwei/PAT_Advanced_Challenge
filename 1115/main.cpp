#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAXN    1000

struct bst_node {
    int data;
    int layer;
    bst_node* l_child;
    bst_node* r_child;
};

vector<pair<int, int>> levelorder;

bst_node* new_bst_node(int value)
{
    bst_node* node = new bst_node;
    node->data = value;
    node->l_child = NULL;
    node->r_child = NULL;
    node->layer = 0;
    return node;
}

bst_node* insert_bst(bst_node* &root, int value)
{
    if (root == NULL) {
        root = new_bst_node(value);
        return root;
    }

    if (value <= root->data) {
        return insert_bst(root->l_child, value);
    } else {
        return insert_bst(root->r_child, value);
    }
}

bst_node* create_bst(int* a, int len)
{
    bst_node* root = NULL;
    for (int i = 0; i < len; i++) {
        insert_bst(root, *(a + i));
    }
    return root;
}

void levelorder_traverse(bst_node* root)
{
    if (root == NULL)
        return;
    
    queue<bst_node*> q;
    root->layer = 1;
    q.push(root);

    while (!q.empty()) {
        bst_node* node = q.front();
        q.pop();

        pair<int, int> p;
        p.first = node->data;
        p.second = node->layer;
        levelorder.push_back(p);

        if (node->l_child != NULL) {
            node->l_child->layer = node->layer + 1;
            q.push(node->l_child);
        } 

        if (node->r_child != NULL) {
            node->r_child->layer = node->layer + 1;
            q.push(node->r_child);
        }
    }
    
}

int main(void)
{
    int cnt, input[MAXN];
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int data;
        cin >> data;
        input[i] = data;
    }

    bst_node* root = create_bst(input, cnt);
    levelorder_traverse(root);
    int lowest_layer_nodes = 0, second_lowest_layer_nodes = 0;
    int lowerst_layer = levelorder[levelorder.size() - 1].second;

    for (int i = levelorder.size() - 1; i >= 0; i--) {
        if (levelorder[i].second == lowerst_layer) {
            lowest_layer_nodes++;
        } else if (levelorder[i].second == lowerst_layer - 1) {
            second_lowest_layer_nodes++;
        } else {
            break;
        }
    }

    cout << lowest_layer_nodes << " + " << second_lowest_layer_nodes << " = " <<  second_lowest_layer_nodes + lowest_layer_nodes << endl;
    return 0;
}
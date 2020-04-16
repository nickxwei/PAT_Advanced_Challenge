#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder, inorder;

int postorder_from_pre_in_order(vector<int>::iterator pre_iter, vector<int>::iterator in_iter, int len)
{

    int value = *pre_iter;
    int pos = 0;
    int l_len, r_len;

    for (int i = 0; i < len; i++) {
        if (*(in_iter + i) == value) {
            pos = i;
            break;
        }
    }

    l_len = pos;
    r_len = len - pos - 1;

    if (l_len > 0) {
        return postorder_from_pre_in_order(pre_iter + 1, in_iter, l_len);
    } else {
        if (r_len == 0) {
            return value;
        }
        return postorder_from_pre_in_order(pre_iter + 1, in_iter + 1, r_len);
    }
}

int main(void) 
{
    int cnt;
    cin >> cnt;

    preorder.resize(cnt);
    inorder.resize(cnt);

    for (int i = 0; i < cnt; i++) {
        cin >> preorder[i];
    }

    for (int i = 0; i < cnt; i++) {

        cin >> inorder[i];
    }

    cout << postorder_from_pre_in_order(preorder.begin(), inorder.begin(), cnt) << endl;

    return 0;
}

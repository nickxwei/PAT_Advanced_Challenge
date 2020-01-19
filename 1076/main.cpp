#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_MEMBERS 1010
vector<int> graph_table[MAX_MEMBERS];
vector<int> query_members;
bool is_travesed[MAX_MEMBERS] = {false};
struct vertex_type {
    int index;
    int layer;
};

int input_numbers, input_level;

int bfs(int i)
{
    queue<vertex_type> q;
    int count = 0;

    is_travesed[i] = true;
    vertex_type v;
    v.index = i;
    v.layer = 1;
    q.push(v);

    while (!q.empty()) {
        vertex_type current_v = q.front();
        int current_index = current_v.index;
        int current_layer = current_v.layer;
        q.pop();
        count++;

        if (current_v.layer < input_level + 1) {
            for (int i = 0; i < graph_table[current_index].size(); i++) {
                if (is_travesed[graph_table[current_index][i]] == false) {
                    is_travesed[graph_table[current_index][i]] = true;
                    vertex_type tmp;
                    tmp.index = graph_table[current_index][i];
                    tmp.layer = current_layer + 1;
                    q.push(tmp);
                }
            }
        }
        
    }

    return count - 1;
    
}

int main()
{

    cin >> input_numbers >> input_level;

    for (int i = 1; i <= input_numbers; i++) {
        int follow_count;
        cin >> follow_count;
        for (int j = 0; j < follow_count; j++) {
            int member;
            cin >> member;
            graph_table[member].push_back(i);
        }
    }

    int query_counts;
    cin >> query_counts;
    for (int i = 0; i < query_counts; i++) {
        int member;
        cin >> member;
        query_members.push_back(member);
    }

    for (int i = 0; i < query_counts; i++) {
        int count = 0;
        for (int j = 0; j < MAX_MEMBERS; j++) {
            is_travesed[j] = false;
        }
        count = bfs(query_members[i]);
        cout << count << endl;
    }

    return 0;
}
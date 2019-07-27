#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> heap;
vector<bool> is_traversed;
stack<int> traverse_index_stack;
vector<int> traverse_key_container;

int type = 0;     // 1 max 2 min 3 no
int last_key = 0;

void printf_vector(vector<int> v)
{
	last_key = v[0];
	cout << v[0];

	for(int i = 1; i < v.size(); i++) { 
		if(type == 0) {
			if(last_key > v[i]) {
				type = 1;
			} else if(last_key == v[i]) {
				type = 0;
			} else {
				type = 2;
			}
		} else if(type == 1) {
			if(last_key < v[i]) {
				type = 3;
			}
		} else if(type == 2) {
			if(last_key > v[i]) {
				type = 3;
			}
		}

		last_key = v[i];
		cout << ' ' << v[i];
	}
	cout << endl;
}

void DFS(vector<int>)
{
	int i = 0;
	while(i <= heap.size() - 1) {
		int tmp = i;
		traverse_index_stack.push(i);
		traverse_key_container.push_back(heap[i]);
		i = i * 2 + 2;
		if(i - 1 == heap.size() - 1) {
			i = i - 1;
			is_traversed[tmp] = 1;
		}
	}

	printf_vector(traverse_key_container);

	while(!traverse_index_stack.empty()) {
		int current = traverse_index_stack.top();
		if(is_traversed[current] == 1) {
			traverse_index_stack.pop();
			traverse_key_container.pop_back();
		} else {
			is_traversed[current] = 1;
			current = current * 2 + 1;
			if(current <= heap.size() - 1) {
				while(current <= heap.size() - 1) {
					int tmp = current;
					traverse_index_stack.push(current);
					traverse_key_container.push_back(heap[current]);
					current = current * 2 + 2;
					if(current - 1 == heap.size() - 1) {
						current = current - 1;
						is_traversed[tmp] = 1;
					}
				}

				printf_vector(traverse_key_container);
			}
			
		}
	}
}

int len; 

int main(void)
{
    cin >> len;
	for(int i = 0; i < len; i++) {
		int tmp;
		cin >> tmp;
		is_traversed.push_back(0);
		heap.push_back(tmp);
	}

	DFS(heap);
	
	switch(type) {
		case 1:
			cout << "Max Heap" << endl;
			break;
		case 2:
			cout << "Min Heap" << endl;
			break;
		case 3:
			cout << "Not Heap" << endl;
		break;
		default:
			break;
	}
}
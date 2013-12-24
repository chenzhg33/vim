#include <iostream>
#include <fstream>
#include <queue>
#define MAX 15
using namespace std;
struct node {
	int layer;
	int perm[16];
	node(int layer) : layer(layer) {
		for (int i = 1; i < 16; i++)
			perm[i] = 0;
	}
	void insert(int a) {
		perm[layer++] = a;
	}
	node() {
		for (int i = 1; i < 16; i++)
			perm[i] = 0;
	}
	bool isIn(int a) {
		for (int i = 1; i < layer; i++)
			if (a == perm[i])
				return false;
		return true;
	}
};
node node_matrix[MAX];
int m[MAX][MAX];
int count = 0;
int N2, N;
void  breathFirstSort() {
	queue<node> que;
	for (int i = 1; i <= N2; i++) {
		node node_temp(1);
		node_temp.insert(i);
		que.push(node_temp);
	}
	while (!que.empty()) {
		node temp = que.front();
		que.pop();
		if (temp.layer >= N)
			node_matrix[count++] = temp;
		for (int i = 1; i <= N2; i++) {
		//	cout << temp.isIn(i) << endl;
			if (temp.isIn(i))
				continue;
			node temp2(temp.layer);
			temp2.insert(i);
			cout << "layer is" << temp2.layer << endl;
		//	for (int i = 1; i < temp2.layer; i++)
		//		cout << temp2.perm[i];
		//	cout << endl;
		}
	}
}
int main() {
	int value[MAX];
	fstream cin("input.txt");
	while (cin >> N2 >> N) {
		count = 0;
		if (N2 == 0 && N == 0)
			break;
		for (int i = 0; i < N2; i++)
			cin >> value[i];
		for (int i = 0; i < N2; i++)
			for (int j = 0; j < N2; j++)
				cin >> m[i][j];
		breathFirstSort();
		cout << count << endl;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < node_matrix[i].layer; i++)
				cout << node_matrix[i].perm[j];
			cout << endl;
		}
	}
	return 0;
}

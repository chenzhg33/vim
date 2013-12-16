#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;
struct method {
	string str;
	int count;
	method() : str(""), count(0) {}
};
method start;
method end;
bool isOk(const method m1, const method m2) {
	return m1.str == m2.str;
}
void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
int convertToNumber(string str) {
	int a[9] = {1, 2, 3, 5, 7, 13, 17, 19, 31};
	int num = 0;
	for (int i = 0; i < 9; i++)
		num += (str[i] - '0')*a[i];
	return num-240;
}
class Hash {
	public:
		Hash() {
		}
		void insert(string str) {
			int temp = convertToNumber(str);
			int i = temp;
			while (array[i++] != 0) {
				array[i] = temp;
			}
		}
		bool isInHash(string str) {
			int temp = convertToNumber(str);
			int i = temp;
			while (1) {
				if (array[i] == temp)
					return true;
				else if (array[i] == 0)
					return false;
				else {
					i++;
					i %= 400000;
				}
			}
		}
	private:
		int array[400000];
};
Hash hash;
string operation(int flag, string str) {
	if (flag == 1) {
		swap(str[0], str[2]);
		swap(str[3], str[5]);
		swap(str[6], str[8]);
	} else if (flag == 2) {
		swap(str[0], str[8]);
		swap(str[1], str[5]);
		swap(str[3], str[7]);
	} else {
		swap(str[1], str[3]);
		swap(str[2], str[6]);
		swap(str[5], str[7]);
	}
	return str;
}
void breadth_deep_search() {
	if (!isOk(start, end)) {
		queue<method> que;
		que.push(start);
		while (!que.empty()) {
			method temp = que.front();
			if (isOk(temp, end) && temp.count <= 10) {
				cout << temp.count << endl;
				return;
			}
			if (temp.count > 10) {
				cout << "It is too hard!" << endl;
				return;
			}
			cout << "----" << temp.count << "----" << endl;
			que.pop();
			for (int i = 1; i <= 3; i++) {
				method temp2;
				string str_temp = operation(i, temp.str);
				if (hash.isInHash(str_temp))
					continue;
				temp2.str = str_temp;
				temp2.count = temp.count+1;
				que.push(temp2);
				hash.insert(str_temp);
			}
		}
	} else {
		cout << 0 << endl;
	}
}
int main() {
	int n;
	fstream fin("input.txt");
	fin >> n;
	while (n--) {
		string str1, str2;
		for (int i = 0; i < 9; i++) {
			char ch;
			fin >> ch;
			str1 += ch;
		}
		for (int i = 0; i < 9; i++) {
			char ch;
			fin >> ch;
			str2 += ch;
		}
	//	cout << str1 << endl << str2 << endl;
		start.count = 0;
		start.str = str1;
		end.count = 0;
		end.str = str2;
		breadth_deep_search();
		cout << "********************" << endl;
	}
	return 0;
}

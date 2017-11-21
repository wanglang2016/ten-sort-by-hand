#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100;
int n;
int a[maxn];

void bubble_sort_improve_1() {
	int pos = n;
	while(pos) {
		int index = 0;
		for(int i = 0; i < pos-1; i++) {
			if(a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				index = i+1;
			}
		}
		pos = index;
	}	
}

int main() {
	freopen("in.txt", "r", stdin);	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];	
	}
	bubble_sort_improve_1();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;	
}

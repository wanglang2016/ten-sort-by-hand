#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 100;
int n;
int a[maxn];

void bubble_sort() {
	int offset = n;
	while(offset) {
		for(int i = 0; i < offset-1; i++) {
			if(a[i] >  a[i+1]) {
				swap(a[i], a[i+1]);
			}
		}
		offset--;
	}
}

int main() {
	freopen("in.txt", "r", stdin);	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];	
	}
	bubble_sort();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;	
}

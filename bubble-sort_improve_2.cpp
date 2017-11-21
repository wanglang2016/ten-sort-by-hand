#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 100;
int n;
int a[maxn];

void bubble_sort_improve_2() {
	int pos_end = n-1;
	int pos_beg = 0;
	while(abs(pos_end-pos_beg)>1) {
		int index_end = 0;
		int index_beg = n-1;
		for(int i = pos_beg; i < pos_end-1; i++) {
			if(a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				index_end = i+1;
			}
		}
		for(int i = pos_end-1; i >= pos_beg; i--) {
			if(a[i+1] < a[i]) {
				swap(a[i], a[i+1]);
				index_beg = i+1;
			}
		}
		pos_end = index_end;
		pos_beg = index_beg;
	}	
}

int main() {
	freopen("in.txt", "r", stdin);	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];	
	}
	bubble_sort_improve_2();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;	
}

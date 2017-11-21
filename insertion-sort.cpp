#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;
int a[maxn];

void insertion_sort() {
	if(n == 1) return;
	for(int i = 1; i < n; i++) {
		int j = i-1;
		int temp = a[i];
		for(j = i-1; j >= 0; j--) {
			if(a[j] <= a[i]) break;
		}
		if(i == j+1) continue;
		for(int k = i-1; k > j; k--) {
			a[k+1] = a[k];
		}
		a[j+1] = temp; 
	} 
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	insertion_sort();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

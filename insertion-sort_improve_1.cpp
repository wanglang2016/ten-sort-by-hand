#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;
int a[maxn];

int my_binary_search(int i) {
	int low = 0, high = i;
	while(abs(high-low)>1) {
		int mid = (low+high)>>1;
		if(a[mid]>a[i]) high = mid;
		else low = mid;
	}
	if(low == 0) {
		if(a[low] > a[i]) low = -1; 	
	}
	return low;
}
void insertion_sort_improve_1() {
	if(n == 1) return;
	for(int i = 1; i < n; i++) {
		int j = i-1;
		int temp = a[i];
		j = my_binary_search(i);
		cout << j << endl;
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
	insertion_sort_improve_1();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

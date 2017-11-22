#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;
int a[maxn];

int partition(int l, int r) {
	int temp = a[l];
	int len = r-l+1;
	int * arr = new int(len);
	int pos = 0;	
	for(int i = l+1; i <= r; i++) {
		if(a[i] < temp) arr[pos++] = a[i];
	}
	int ret = l + pos;
	arr[pos++] = temp; 
	for(int i = l+1; i <= r; i++) {
		if(a[i] >= temp) arr[pos++] = a[i];
	}
	int id = 0;
	for(int i = l; i <= r; i++) {
		a[i] = arr[id++];
	}
	delete []arr;
	return ret;
}

void quick_sort(int l, int r) {
	if(l < r) {
		int par_id = partition(l, r);
		if(par_id == l) {
			quick_sort(l+1, r);
		}		
		else if(par_id == r) {
			quick_sort(l, r-1);
		}
		else {
			quick_sort(l, par_id-1);
			quick_sort(par_id+1, r);
		}
	}   
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quick_sort(0, n-1);	
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	} 
	cout << endl;
	return 0;
}

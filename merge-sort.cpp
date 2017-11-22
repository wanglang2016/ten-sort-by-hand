#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;
int a[maxn];
const int INF = 0x3fffffff;

void merge(int p, int q, int r) {
	int n1 = q-p+1;
	int n2 = r-q;
	int * L = new int(n1);
	int * R = new int(n2);
	for(int i = 0; i < n1; i++) {
		L[i] = a[p+i];
	}
	for(int i = 0; i < n2; i++) {
		R[i] = a[q+1+i];
	}
	L[n1] = R[n2] = INF;
	int id_l = 0;
	int id_r = 0;
	for(int i = p; i <= r; i++) {
		if(L[id_l] < R[id_r] && L[id_l] != INF) {
			a[i] = L[id_l];
			id_l++;
		}
		else if(R[id_r] < L[id_l] && R[id_r] != INF) {
			a[i] = R[id_r];
			id_r++;
		}
	}
	delete []L;
	delete []R;
}

void merge_sort(int l, int r) {
	if(l < r) {
		int mid = (l+r) >> 1;
		merge_sort(l, mid);
		merge_sort(mid+1, r);
		merge(l, mid, r);	
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(0, n-1);	
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

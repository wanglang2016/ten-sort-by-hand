#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;
int a[maxn];

void adjust(int len, int index) {
	int lson = (index<<1) + 1;
	int rson = (index<<1) + 2;
	int max_id = index;
	if(lson < len && a[lson] > a[max_id]) max_id = lson;
	if(rson < len && a[rson] > a[max_id]) max_id = rson;
	if(index != max_id) {
		swap(a[max_id], a[index]);
		adjust(len, max_id);
	}
}

void heap_sort() {
	for(int i = n/2-1; i >= 0; i--) {
		adjust(n, i);
	}
	for(int i = n-1; i >= 1; i--) {
		swap(a[0], a[i]);
		adjust(i, 0);		
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	heap_sort();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 100;
const int INF = 0x3fffffff;
int n;
int a[maxn];

void selection_sort() {
	for(int i = 0; i < n; i++) {
		int pos = i;
		int min_value = INF;
		for(int j = i; j < n; j++) {
			if(a[j] < min_value) {
				min_value = a[j];
				pos = j;
			}
		}
		if(i != pos) swap(a[i], a[pos]);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	selection_sort();
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

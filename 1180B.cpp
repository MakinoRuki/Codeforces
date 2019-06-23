#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
int n;
int a[N];
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	int maxv = 1;
	int idx = -1;
	int cnt = n;
	for (int i = 0; i < n; ++i) {
		int v = max(abs(a[i]), abs(-a[i] - 1));
		if (v > maxv) {
			maxv = v;
			idx = i;
		}
	}
	if (idx >= 0) {
		for (int i = 0; i < n; ++i) {
			if (a[i] == 0) a[i] = -1;
			else if (a[i] > 0) {
				if (idx != i || (cnt%2==0)) a[i] = -a[i]-1;
			} else if (a[i] < -1) {
				if ((idx == i) && (cnt%2)) a[i] = -a[i] -1;
			}
		}
	} else {
		if (cnt%2) {
			for (int i = 0; i < n; ++i) {
				a[i] = 0;
			}
		} else {
			for (int i = 0; i < n; ++i) {
				a[i] = -1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout<<a[i];
		if (i < n - 1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 300005
using namespace std;
int n;
int c[N];
int cl[N], cr[N];
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>c[i];
	}
	int ans = 0;
	int cr = -1, cl = -1;
	for (int i = n - 2; i >= 0; --i) {
		if (c[i] != c[n-1]) ans = max(ans, n-1-i);
		else {
			if (cr >= 0) ans = max(ans, cr-i);
		}
		if (c[i] != c[n-1]) cr=i;
	}
	for (int i = 1; i < n; ++i) {
		if (c[i] != c[0]) ans = max(ans, i);
		else {
			if (cl >= 0) ans = max(ans, i-cl);
		}
		if (c[i] != c[0]) cl = i;
	}
	cout<<ans<<endl;
	return 0;
}

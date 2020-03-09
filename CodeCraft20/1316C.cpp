#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define N 1000005
using namespace std;
typedef long long ll;
int n, m, p;
int a[N], b[N];
int main() {
	cin>>n>>m>>p;
	int l=0, r=0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] % p) l = i; 
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		if (b[i] % p) r = i;
	}
	cout<<l+r<<endl;
	return 0;
}

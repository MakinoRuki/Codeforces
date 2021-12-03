#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
int par[N];
int find(int x) {
	return x== par[x] ? x : par[x] = find(par[x]);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		par[i] = i;
	}
	cin>>s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			int px = find(i+1);
			int py = find(i+2);
			if (px != py) {
				par[px] = py;
			}
		}
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != i) {
			int px = find(i);
			int py = find(a[i]);
			if (px != py) {
				ok=false;
				break;
			}
		}
	}
	if (ok) puts("YES");
	else puts("NO");
  return 0;
}


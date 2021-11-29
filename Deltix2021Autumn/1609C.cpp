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
int idx[N];
int idx2[N];
int id[N], id2[N];
bool pm[M];
int main() {
	memset(pm, true, sizeof(pm));
	for (int i =2; i < M; ++i) {
		if (pm[i]) {
			for (int j = 2*i; j < M; j += i) {
				pm[j]=false;
			}
		}
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &e);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < e; ++i) {
			idx[i] = n+1;
			idx2[i] = n+1;
		}
		int cur=n+1;
		for (int i = n; i >= 1; --i) {
			if (i == n) {
				id[i] = n+1;
				id2[i] = n+1;
			} else {
				id[i] = idx[i%e];
				id2[i] = idx2[i%e];
			}
			if (a[i] > 1) {
				idx2[i%e] = i;
				if (pm[a[i]]) idx[i%e] = i;
				else idx[i%e] = n+1;
			}
		}
		ll tot=0LL;
		for (int i = 1; i <= n; ++i) {
			int l, r;
			if (a[i] > 1) {
				if (!pm[a[i]]) continue;
				l = i;
			} else {
				l = id[i];
			}
			if (l > n) continue;
			r = id2[l]-1;
			if (l <= r) {
				l = max(1, (l-i+e-1)/e);
				r = (r-i)/e;
				if (l <= r) {
					tot += (r-l+1);
				}
			}
		}
		printf("%lld\n", tot);
	}
  return 0;
}


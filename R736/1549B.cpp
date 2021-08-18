#pragma GCC optimize(2)
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
#include <cmath>
#include <queue>
#include <time.h>
#define eps 1e-7
#define M 22
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
bool vis[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			vis[i] = false;
		}
		string s1, s2;
		cin>>s1>>s2;
		int ans=0;
		for (int i = 0; i < n; ++i) {
			if (s2[i] == '1') {
				if (s1[i] == '0') {
					ans++;
				} else {
					if (i-1>=0 && s1[i-1]=='1' && !vis[i-1]) {
						vis[i-1] = true;
						ans++;
					} else if (i + 1 < n && s1[i+1] == '1' && !vis[i+1]) {
						vis[i+1] = true;
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
  return 0;
}

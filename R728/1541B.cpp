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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int a[N];
int idx[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= 2*n; ++i) {
			idx[i] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			idx[a[i]] = i;
		}
		ll ans= 0LL;
		for (int i = 1; i <= 2*n; ++i) {
			for (int j = 1; j * j <= i; ++j) {
				if (i%j == 0) {
					if (j!= i/j && idx[j]>=1 && idx[i/j]>=1 && idx[j] + idx[i/j] == i) {
					//	cout<<i<<" "<<j<<" "<<idx[j]<<" "<<idx[i/j]<<endl;
						ans++;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}

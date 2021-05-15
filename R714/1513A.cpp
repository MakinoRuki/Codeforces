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
#define eps 1e-7
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			a[i] = i;
		}
		for (int i = 2; i +1 <= n; i += 2) {
			if (k == 0) break;
			swap(a[i], a[i+1]);
			k--;
		}
		if (k > 0) {
			puts("-1");
		} else {
			for (int i = 1; i <= n; ++i) {
				printf("%d", a[i]);
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}

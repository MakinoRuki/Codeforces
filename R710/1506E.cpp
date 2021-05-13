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
#define M 25
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int q[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &q[i]);
		}
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= q[1]; ++i) {
			ss.insert(i);
		}
		for (int i = 1; i <= n; ++i) {
			if (i == 1 || q[i] > q[i-1]) {
				printf("%d", q[i]);
				if (i>1) {
					for (int j = q[i-1]+1; j <= q[i]; ++j) {
						ss.insert(j);
					}
				}
				ss.erase(q[i]);
			} else {
				int x = (*ss.begin());
				printf("%d", x);
				ss.erase(x);
			}
			if (i < n) cout<<" ";
			else cout<<endl;
		}
		ss.clear();
		for (int i = 1; i <= q[1]; ++i) {
			ss.insert(i);
		}
		for (int i = 1; i <= n; ++i) {
			if (i == 1 || q[i] > q[i-1]) {
				printf("%d", q[i]);
				if (i>1) {
					for (int j = q[i-1]+1; j <= q[i]; ++j) {
						ss.insert(j);
					}
				}
				ss.erase(q[i]);
			} else {
				int x = (*ss.rbegin());
				printf("%d", x);
				ss.erase(x);
			}
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}

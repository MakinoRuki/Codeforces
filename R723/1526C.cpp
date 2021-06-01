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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	multiset<int> ss;
	ss.clear();
	int ans=0;
	ll cur = 0LL;
	for (int i = 1; i <= n; ++i) {
		cur += a[i];
		ss.insert(a[i]);
		ans++;
		while(cur < 0 && !ss.empty()) {
			cur -= *(ss.begin());
			ss.erase(ss.begin());
			ans--;
		}
	}
	cout<<ans<<endl;
  return 0;
}

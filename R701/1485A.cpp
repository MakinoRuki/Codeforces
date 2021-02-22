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
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int a,b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &a, &b);
		int lb = (b == 1 ? 1 : 0);
		int ans=-1;
		for (int d = lb; d <= 32; ++d) {
			int cnt=d;
			int y = a;
			while(y) {
				y /= (d+b);
				cnt++;
			}
			ans = (ans < 0 ? cnt : min(ans, cnt));
		}
		printf("%d\n", ans);
	}
  return 0;
}

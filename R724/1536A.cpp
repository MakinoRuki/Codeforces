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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
int a[N];
int getgcd(int x, int y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		bool found=false;
		int g=-1;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] < 0) found=true;
			else {
				if (g < 0) g = a[i];
				else g = getgcd(g, a[i]);
			}
		}
		if (found) puts("NO");
		else {
			puts("YES");
			found=false;
			int maxv = -1;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 0) {
					found=true;
				}
				maxv = max(maxv, a[i]);
			}
			vector<int> ans;
			ans.clear();
			if (found) {
				ans.push_back(0);
			}
			for (int i = g; i <= maxv; i += g) {
				ans.push_back(i);
			}
			printf("%d\n", (int)ans.size());
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d", ans[i]);
				if (i < ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}

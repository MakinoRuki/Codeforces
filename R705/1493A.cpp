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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		int l = 1, r= k-1;
		vector<int> ans;
		ans.clear();
		while(l < r) {
			ans.push_back(r);
			l++;
			r--;
		}
		if (l == r && r != k) {
			ans.push_back(l);
		}
		for (int i = k+1; i <= n; ++i) {
			ans.push_back(i);
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}

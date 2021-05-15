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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int idx[30];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i) {
		idx[i] = (i+1)%k;
	}
	string res = "";
	for (int i = 0; i < k; ++i) {
		res.push_back('a'+i);
		res.push_back('a'+i);
		idx[i] = (idx[i]+1) % k;
	}
	int cur=0;
	while(true) {
		res.push_back('a'+cur);
		int nxt = idx[cur];
		if (nxt==cur) break;
		idx[cur] = (idx[cur]+1) % k;
		cur = nxt;
	}
	string ans="";
	if (res.size() >= n) {
		ans = res.substr(0, n);
	} else {
		ans = res;
		while(ans.size() < n) {
			for (int i = 1; i < res.size(); ++i) {
				if (ans.size()==n) break;
				ans.push_back(res[i]);
			}
		}
	}
	cout<<ans<<endl;
  return 0;
}

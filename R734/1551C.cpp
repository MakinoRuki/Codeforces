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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<string> ss;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			string s;
			cin>>s;
			ss.push_back(s);
		}
		int ans=0;
		for (char c = 'a'; c <= 'e'; ++c) {
			vector<int> rk;
			rk.clear();
			for (int i = 0; i < n; ++i) {
				int cnt=0;
				for (int j = 0; j < ss[i].size(); ++j) {
					if (ss[i][j] == c) cnt++;
					else cnt--;
				}
				rk.push_back(cnt);
			}
			sort(rk.begin(), rk.end());
			int sum = 0;
			int num = 0;
			for (int i = rk.size()-1; i >= 0; --i) {
				if (sum + rk[i] > 0) {
					sum += rk[i];
					num++;
				} else {
					break;
				}
			}
			ans = max(ans, num);
		}
		printf("%d\n", ans);
	}
  return 0;
}

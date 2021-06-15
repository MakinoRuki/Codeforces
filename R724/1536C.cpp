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
#define M 10005
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
int getgcd(int x, int y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		map<pair<int,int>,int> dp;
		dp.clear();
		int d = 0, k = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'D') {
				d++;
			} else {
				k++;
			}
			int g = getgcd(d, k);
			if (dp.find(make_pair(d/g, k/g)) != dp.end()) {
				printf("%d", dp[make_pair(d/g, k/g)]+1);
			} else {
				printf("%d", 1);
			}
			if (i < n-1) cout<<" ";
			else cout<<endl;
			dp[make_pair(d/g, k/g)] += 1;
		}
	}
  return 0;
}

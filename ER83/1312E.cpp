#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 502
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
int dp[N][N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j =i; j <= n; ++j) {
			dp[i][j] = j-i+1;
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i + 1; j <= n; ++j) {
			vector<int> stk;
			stk.clear();
			for (int k = i; k <= j; ++k) {
				if (stk.empty() || stk.back() != a[k]) {
					stk.push_back(a[k]);
				} else {
					int x = a[k];
					while(!stk.empty() && stk.back() == x) {
						stk.pop_back();
						x++;
					}
					stk.push_back(x);
				}
			}
			if (stk.size() == 1) {
				dp[i][j] = 1;
			}
			for (int k = i; k < j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
			//cout<<"i="<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}

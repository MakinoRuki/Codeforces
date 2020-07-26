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
#define N 2002
#define M 20010
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int p[N*2];
bool dp[N*2][N*2];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= 2*n; ++i) {
			scanf("%d", &p[i]);
		}
		int x = p[1];
		int len = 1;
		vector<int> lens;
		lens.clear();
		for (int i = 2; i <= 2*n; ++i) {
			if (p[i] > x) {
				lens.push_back(len);
				x = p[i];
				len = 1;
			} else {
				len++;
			}
		}
		for (int i = 0; i <= 2*n; ++i) {
			for (int j= 0; j <= 2*n; ++j) {
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		for (int i = 0; i < lens.size(); ++i) {
			for (int j = 0; j <= n; ++j) {
				if (dp[i][j]) {
					dp[i+1][j] = true;
					if (j+lens[i] <= n) {
						dp[i+1][j+lens[i]] = true;
					}
				}
			}
		}
		int sz = lens.size();
		if (dp[sz][n]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
  return 0;
}

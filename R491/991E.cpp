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
#define N 205
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
int cnt[20];
ll dp[30][30][10];
ll comb[19][19];
int main() {
	cin>>n;
	memset(cnt, 0, sizeof(cnt));
	int pos=0;
	ll m=n;
	while(m) {
		pos++;
		cnt[m%10]++;
		m/=10;
	}
	int num=0;
	for (int i = 0; i <= 9; ++i) {
		if (cnt[i]>0) {
			num++;
		}
	}
	memset(comb, 0LL, sizeof(comb));
	for (int i = 0; i <= pos; ++i) {
		comb[i][0]=1LL;
		for (int j =1; j <= i; ++j) {
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
		}
	}
	ll ans=0LL;
	for (int i = num; i <= pos; ++i) {
		for (int d=1; d <= 9; ++d) {
			if (cnt[d]==0) continue;
			memset(dp, 0, sizeof(dp));
			cnt[d]--;
			vector<int> ds;
			ds.clear();
			for (int j = 0; j <= 9; ++j) {
				if (cnt[j]>0) {
					ds.push_back(j);
				}
			}
			dp[0][i-1][1] = 1LL;
			for (int j = 0; j < ds.size(); ++j) {
				for (int j1=0; j1<=i-1; ++j1) {
					for (int j2=1; j2<=num; ++j2) {
						int d2=ds[j];
						dp[j+1][j1][j2] += dp[j][j1][j2];
						for (int k1=1; k1<= cnt[d2]; ++k1) {
							if (j1>=k1) {
								int k2=(d2==d ? j2 : j2+1);
								dp[j+1][j1-k1][k2] += dp[j][j1][j2] * comb[j1][k1];
							}
						}
					}
				}
			}
			cnt[d]++;
			ans += dp[ds.size()][0][num];
		//	cout<<i<<" "<<d<<" "<<dp[ds.size()][0][num]<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

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
#define N 1000005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int ds[N];
int dp[N][9];
bool check(int* ds2) {
	for (int i= 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int l = 2; l <= 4; l+=2) {
				if (i + l <= n && j + l <= m) {
					int cnt=0;
					for (int i2 = i; i2 < i+l; ++i2) {
						for (int j2 = j; j2 < j+l; ++j2) {
							if (ds2[i2*m+j2]) cnt++;
						}
					}
					if (cnt%2==0) return false;
				}
			}
		}
	}
	return true;
}
int main() {
	cin>>n>>m;
	if (n>=4 && m >=4) {
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
		}
		cout<<-1<<endl;
	} else if (n*m<=12) {
		memset(ds, 0, sizeof(ds));
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			for (int j = 0; j < m; ++j) {
				ds[i*m+j] = s[j]-'0';
			}
		}
		int ans=n*m+2;
		int c = n*m;
		for (int i = 0; i < (1<<c); ++i) {
			int ds2[15];
			int cnt=0;
			for (int j = 0; j < c; ++j) {
				ds2[j] = ds[j];
			}
			for (int j = 0; j < c; ++j) {
				if ((1<<j)&i) {
					ds2[j] ^= 1;
					cnt++;
				}
			}
			if (check(ds2)) {
			//	cout<<"i="<<i<<endl;
				ans = min(ans, cnt);
			}
		}
		cout<<ans<<endl;
	} else {
		memset(ds, 0, sizeof(ds));
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			for (int j = 0; j < m; ++j) {
				ds[i*m+j] = s[j]-'0';
			}
		}
		int ds2[N];
		if (n > m) {
			for (int j = 0; j < m; ++j) {
				for (int i = 0; i < n; ++i) {
					ds2[j*n+i] = ds[i*m+j];
				}
			}
			swap(n, m);
		} else {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					ds2[i*m+j] = ds[i*m+j];
				}
			}
		}
		if (n == 1) {
			cout<<0<<endl;
			return 0;
		}
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < (1<<n); ++i) {
			int cnt=0;
			for (int j = 0; j < n; ++j) {
				if (((1<<j) & i) && ds2[j*m] == 0) {
					cnt++;
				} else if (!((1<<j)&i) && ds2[j*m]) {
					cnt++;
				}
			}
			dp[0][i] = cnt;
		}
		for (int j = 0; j < m-1; ++j) {
			for (int x = 0; x < (1<<n); ++x) {
				if (dp[j][x] >= 0) {
					for (int x2 = 0; x2 < (1<<n); ++x2) {
						int c1 = 0;
						int c2=0;
						if (x&1) c1++;
						if (x&2) c1++;
						if (x2&1) c2++;
						if (x2&2) c2++;
						if ((c1+c2)%2==0) continue;
						if (n > 2) {
							c1=0;c2=0;
							if (x&2) c1++;
							if (x&4) c1++;
							if (x2&2) c2++;
							if (x2&4) c2++;
							if ((c1+c2)%2==0) continue;
						}
						int cnt=0;
						for (int i = 0; i < n; ++i) {
							if (((1<<i) & x2) && ds2[i*m+j+1] == 0) {
								cnt++;
							} else if (!((1<<i)&x2) && ds2[i*m+j+1]) {
								cnt++;
							}
						}
						// if (dp[j][x]+cnt == 2) {
						// 	cout<<"j="<<j<<" "<<x<<" "<<x2<<endl;
						// }
						dp[j+1][x2] = (dp[j+1][x2] < 0 ? cnt+dp[j][x] : min(dp[j+1][x2], cnt+dp[j][x]));
					}
				}
			}
		}
		int ans = inf;
		for (int i = 0; i < (1<<n); ++i) {
			if (dp[m-1][i]>=0) ans=min(ans, dp[m-1][i]);
		}
		if (ans >= inf) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

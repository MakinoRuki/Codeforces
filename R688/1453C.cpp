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
#define M 20005
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
vector<string> mat;
int r[10][N][2];
int c[10][N][2];
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d", &n);
		mat.clear();
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
		}
		for (int d = 0; d < 10; ++d) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < 2; ++j) {
					r[d][i][j]=-1;
					c[d][i][j]=-1;
				}
			}
		}
		for (int d = 0; d < 10; ++d) {
			for (int i = 0; i < n; ++i) {
				int pre=-1;
				for (int j = 0; j < n; ++j) {
					if ((mat[i][j]-'0')==d) {
						r[d][i][0] = max(r[d][i][0], max(j, n-1-j));
						if (pre>=0) {
							r[d][i][1] = max(r[d][i][1], j-pre);
						}
						pre=j;
					}
				}
			}
		}
		for (int d = 0; d < 10; ++d) {
			for (int j = 0; j < n; ++j) {
				int pre=-1;
				for (int i = 0; i < n; ++i) {
				//	if (d==1 && j==0) cout<<"v="<<mat[i][j]<<endl;
					if ((mat[i][j]-'0')==d) {
					//	if (d==1 && j==0) cout<<"v2="<<i<<endl;
						c[d][j][0] = max(c[d][j][0], max(i, n-1-i));
						if (pre>=0) {
							c[d][j][1] = max(c[d][j][1], i-pre);
						}
						pre=i;
					}
				}
			}
		}
	//	cout<<r[9][1][0]<<endl;
		for (int d = 0; d < 10; ++d) {
			int ans=0;
			for (int i = 0; i < n; ++i) {
				if (r[d][i][1]>=0) {
					for (int i2 = 0; i2 < n; ++i2) {
						if (r[d][i2][0] >= 0) {
							ans = max(ans, r[d][i][1]*abs(i2-i));
						}
					}
					ans = max(ans, r[d][i][1]*max(i, n-1-i));
			//		if (d==2) cout<<"r1="<<i<<" "<<ans<<endl;
				}
				if (r[d][i][0]>=0) {
					for (int i2 = 0; i2 < n; ++i2) {
						if (r[d][i2][0]>=0) {
							ans = max(ans, r[d][i][0]*abs(i2-i));
						}
					}
				//	if (d==2) cout<<"r2="<<i<<" "<<ans<<endl;
				}
			}

			for (int i = 0; i < n; ++i) {
			//	if ( d==1 && i == 2) cout<<"x="<<c[1][0][0]<<endl;
				if (c[d][i][1]>=0) {
					for (int i2 = 0; i2 < n; ++i2) {
						if (c[d][i2][0] >= 0) {
							ans = max(ans, c[d][i][1]*abs(i2-i));
						}
					}
					ans = max(ans, c[d][i][1]*max(i, n-1-i));
				//	if (d==2) cout<<"r3="<<i<<" "<<ans<<endl;
				}
				if (c[d][i][0]>=0) {
			//		if (d==1 && i==2) cout<<c[d][i][0]<<endl;
					for (int i2 = 0; i2 < n; ++i2) {
						if (c[d][i2][0]>=0) {
				//			if (d==1 && i==2) cout<<"i2="<<i2<<endl;
							ans = max(ans, c[d][i][0]*abs(i2-i));
						//	if (d==2 && ans==2) cout<<"i2="<<i<<" "<<i2<<" "<<c[d][i][0]<<" "<<c[d][i2][0]<<endl;
						}
					}
				//	if (d==2) cout<<"r4="<<i<<" "<<ans<<endl;
				}
			}
			printf("%d", ans);
			if (d < 9) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

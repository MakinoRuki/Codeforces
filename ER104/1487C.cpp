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
#define M 21
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int res[N][N];
int c0[N], c1[N], c2[N];
bool res2[N][N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		memset(c0,0 ,sizeof(c0));
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(res, 0, sizeof(res));
		memset(res2, false, sizeof(res2));
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i += 2) {
				res[i][i+1] = 0;
				res[i+1][i] = 0;
				c0[i]++;
				c0[i+1]++;
				res2[i][i+1]=true;
				res2[i+1][i]=true;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (i==j) continue;
					if (i%2 && j==i+1) continue;
					if (i%2==0 && j==i-1) continue;
					if (!res[i][j] && c1[i] < (n-2)/2 && c2[j]<(n-2)/2) {
						res[i][j] = 1;
						res[j][i] = -1;
						res2[i][j]=res2[j][i]=true;
						c1[i]++;
						c2[j]++;
					}
				}
			}
		} else {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (i==j) continue;
				//	if (i==3 && j==1) cout<<res[i][j]<<" "<<c1[i]<<" "<<c2[j]<<endl;
					if (!res[i][j] && c1[i] < n/2 && c2[j]<n/2) {
						res[i][j]=1;
						res[j][i]=-1;
						res2[i][j]=res2[j][i]=true;
						c1[i]++;
						c2[j]++;
					}
				}
			}
		}
		int cnt=0;
		for (int i = 1; i < n; ++i) {
			for (int j = i+1; j <= n; ++j) {
				printf("%d", res[i][j]);
				cnt++;
				if (cnt < n*(n-1)/2) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}

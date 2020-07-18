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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
string s;
int sum[26][N];
int dp[N][20];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		cin>>s;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j< 26; ++j) {
				sum[j][i] = 0;
			}
		}
		for (int i = 0; i < 26; ++i) {
			for (int j = 1; j <= n; ++j) {
				sum[i][j] = sum[i][j-1] + (s[j-1]=='a'+i);
			}
		}
		int pw = 0;
		while((1<<pw) < n) pw++;
		for (int i = 0; i <= pw; ++i) {
			for (int j = 1; j <= n; j += (1<<i)) {
				int c = pw-i;
				if (i == 0) {
					dp[j][i] = (s[j-1]=='a'+c ? 0 : 1);
				} else {
					int x = sum[c][j+(1<<(i-1))-1]-sum[c][j-1];
					int y = sum[c][j+(1<<i)-1]-sum[c][j+(1<<(i-1))-1];

					x = (1<<(i-1))-x;
					y = (1<<(i-1))-y;
				//	if (i==1&&j==3) cout<<"x="<<x<<" "<<"y="<<y<<endl;
					dp[j][i] = min(x+dp[j+(1<<(i-1))][i-1], y+dp[j][i-1]);
				}
				//if (i==1 && j==3) cout<<dp[j][i]<<endl;
			}
		}
		cout<<dp[1][pw]<<endl;
	}
  return 0;
}

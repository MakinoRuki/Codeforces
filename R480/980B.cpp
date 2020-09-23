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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
vector<string> mat;
// void calc1() {
// 	int dp[4][100];
// 	memset(dp, 0, sizeof(dp));
// 	dp[0][0]=1;
// 	for (int i = 0; i < 4; ++i) {
// 		for (int j = 0; j < n; ++j) {
// 			if (mat[i][j]=='#') continue;
// 			if (i-1>=0) {
// 				dp[i][j]+=dp[i-1][j];
// 			}
// 			if (j-1>=0) {
// 				dp[i][j]+=dp[i][j-1];
// 			}
// 		}
// 	}
// 	cout<<"dp1="<<dp[3][n-1]<<endl;
// }
// void calc2() {
// 	int dp[4][100];
// 	memset(dp, 0, sizeof(dp));
// 	dp[3][0]=1;
// 	for (int i = 3; i >=0; --i) {
// 		for (int j = 0; j < n; ++j) {
// 			if (mat[i][j]=='#') continue;
// 			if (i+1<4) {
// 				dp[i][j]+=dp[i+1][j];
// 			}
// 			if (j-1>=0) {
// 				dp[i][j]+=dp[i][j-1];
// 			}
// 		}
// 	}
// 	cout<<"dp2="<<dp[0][n-1]<<endl;
// }
int main() {
	cin>>n>>k;
	mat.clear();
	for (int i = 0; i < 4; ++i) {
		string s(n, '.');
		mat.push_back(s);
	}
	if (k%2==0) {
		for (int i = 1; i <= k/2; ++i) {
			mat[1][i] = '#';
			mat[2][i] = '#';
		}
	} else {
		mat[1][n/2] = '#';
		k--;
		for (int i = 1; i <= n/2; ++i) {
			if (k==0) {
				break;
			}
			if (k>0) {
				mat[1][n/2-i]='#';
				mat[1][n/2+i]='#';
				k-=2;
			}
			if (k>0) {
				mat[2][n/2-i]='#';
				mat[2][n/2+i]='#';
				k-=2;
			}
		}
	}
	cout<<"YES"<<endl;
	for (int i = 0; i < 4; ++i) {
		cout<<mat[i]<<endl;
	}
	return 0;
}

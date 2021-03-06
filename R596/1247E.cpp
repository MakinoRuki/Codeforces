#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <deque>
#define N 2005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<string> mat;
ll dp[N][N][2];
int sumr[N][N];
int sumc[N][N];
deque<pair<int, ll>> dq[N];
ll tot[N];
int main() {
	cin>>n>>m;
	mat.clear();
	memset(sumr, 0, sizeof(sumr));
	memset(sumc, 0, sizeof(sumc));
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	if (n == 1 && m == 1) {
		cout<<1<<endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = m-1; j >= 0; --j) {
			sumr[i][j] = sumr[i][j+1] + (mat[i][j] == 'R');
		}
	}
	for (int j = 0; j < m; ++j) {
		for (int i = n-1; i >= 0; --i) {
			sumc[j][i] = sumc[j][i+1] + (mat[i][j] == 'R');
		}
	}
	for (int j = 0; j < m; ++j) {
		dq[j].clear();
	}
	memset(tot, 0, sizeof(tot));
	memset(dp, 0, sizeof(dp));
	// if (1 < m && sumr[0][1] < m-1) {
	// 	dp[0][1][0] = 1;
	// }
	// if (1 < n && sumc[0][1] < n-1) {
	// 	dp[1][0][1] = 1;
	// }
	dp[0][0][0] = dp[0][0][1] = 1;
	deque<pair<int, ll>> cdq;
	cdq.clear();
	ll csum = 0;
	for (int i = 0; i < n; ++i) {
		csum = 0;
		cdq.clear();
		for (int j = 0; j < m; ++j) {
			if (i == 0 && j == 0) {
				dq[j].push_back(make_pair(i, dp[i][j][0]));
				tot[j] = (tot[j] + dp[i][j][0]) % mod;
				cdq.push_back(make_pair(j, dp[i][j][1]));
				csum = (csum + dp[i][j][1]) % mod;
			} else {
				while(!dq[j].empty()) {
					auto p = dq[j].front();
					int id = p.first;
					if (sumc[j][id + 1] > n-1-i) {
						dq[j].pop_front();
						tot[j] = (tot[j] - p.second + mod) % mod;
					} else {
						break;
					}
				}
				dp[i][j][1] = (dp[i][j][1] + tot[j]) % mod;
				while(!cdq.empty()) {
					auto p = cdq.front();
					int id = p.first;
					if (sumr[i][id+1] > m-1-j) {
						cdq.pop_front();
						csum = (csum - p.second + mod) % mod;
					} else {
						break;
					}
				}
				//if (i == 0 && j == 2) cout<<"csum="<<csum<<" "<<cdq.size()<<endl;
				dp[i][j][0] = (dp[i][j][0] + csum) % mod;
				cdq.push_back(make_pair(j, dp[i][j][1]));
				csum = (csum + dp[i][j][1]) % mod;
				dq[j].push_back(make_pair(i, dp[i][j][0]));
				tot[j] = (tot[j] + dp[i][j][0]) % mod;
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cout<<dp[i][j][0]<<","<<dp[i][j][1];
	// 		if (j < m-1) cout<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout << (dp[n-1][m-1][0] + dp[n-1][m-1][1]) % mod<<endl;
	return 0;
}

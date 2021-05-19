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
#include <time.h>
#define eps 1e-7
#define M 52
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
vector<int> v0, v1;
int dp[N][N];
int main() {
	cin>>n;
	v0.clear();
	v1.clear();
//	memset(b, -1, sizeof(b));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i]) v1.push_back(i);
		else v0.push_back(i);
		// if (a[i] == 0) b[i] = i;
		// else b[i] = b[i-1];
	}
	int ans = INT_MAX;
	for (int i = 0; i <= v0.size(); ++i) {
		for (int j = 0; j <= v1.size(); ++j) {
			dp[i][j] = inf;
		}
	}
	for (int i = 0; i <= v0.size(); ++i) {
		dp[i][0] = 0;
	}
	for (int i = 0; i < v0.size(); ++i) {
		for (int j = 0; j <= v1.size(); ++j) {
			if (dp[i][j] < inf) {
				dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
				if (j+1<=v1.size()) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+abs(v0[i]-v1[j]));
			}
		}
	}
	ans = dp[v0.size()][v1.size()];
	// for (int i = 0; i < v0.size(); ++i) {
	// 	int cur = v0[i];
	// 	int i2 = i;
	// 	int sum = 0;
	// 	for (int j = 0; j < v1.size(); ++j) {
	// 		if (i == 0 && j == 0) {
	// 			sum += abs(v1[j]-cur);
	// 			i2++;
	// 		} else {
	// 		//	if (j == 1) cout<<"x="<<j<<" "<<v1[j]<<" "<<i2<<endl;
	// 			while(i2 < v0.size()) {
	// 				int det1 = v1.size()-1-j;
	// 				int det0 = v0.size()-1-i2;
	// 				if (det0 <= det1) {
	// 					break;
	// 				}
	// 				if (i2 + 1 >= v0.size() || abs(v1[j]-v0[i2+1]) > abs(v1[j]-v0[i2])) {
	// 					break;
	// 				}
	// 				i2++;
	// 			}
	// 			if (i2 >= v0.size()) {
	// 				sum=-1;
	// 				break;
	// 			}
	// 		//	if (i==0) cout<<"x="<<j<<" "<<v1[j]<<" "<<i2<<" "<<v0[i2]<<endl;
	// 			cur = v0[i2];
	// 			sum += abs(v1[j]-cur);
	// 			i2++;
	// 		//	if (i==0) cout<<"y="<<sum<<endl;
	// 		}
	// 	}
	// //	cout<<i<<" "<<sum<<endl;
	// 	if (sum >= 0) {
	// 	//	cout<<i<<" "<<v0[i]<<" "<<sum<<endl;
	// 		ans = min(ans, sum);
	// 	}
	// }
	cout<<ans<<endl;
  return 0;
}

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
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int h[N];
int dp[N];
int main() {
	cin>>n;
	vector<int> stk1, stk2;
	stk1.clear();
	stk2.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h[i]);
	}
	dp[n] = 0;
	stk1.push_back(n);
	stk2.push_back(n);
	for (int i = n-1; i >= 1; --i) {
		dp[i]=dp[i+1]+1;
		//if (i==2) cout<<"i="<<i<<" "<<"sz1="<<stk1.size()<<" "<<"sz2="<<stk2.size()<<endl;
		if (h[i+1] > h[i]) {
			while(!stk1.empty() && h[stk1.back()]>h[i]) {
				if (h[stk1.back()]<h[i+1]) {
					dp[i]=min(dp[i], dp[stk1.back()]+1);
				}
				stk1.pop_back();
			}
			if (!stk1.empty() && h[stk1.back()] < h[i+1]) {
				dp[i]=min(dp[i], dp[stk1.back()]+1);
			}
			while(!stk1.empty() && h[i]<=h[stk1.back()]) {
				stk1.pop_back();
			}
			stk1.push_back(i);
			while(!stk2.empty() && h[i]>=h[stk2.back()]) {
				stk2.pop_back();
			}
			stk2.push_back(i);
		} else if (h[i+1] < h[i]) {
			while(!stk2.empty() && h[stk2.back()]<h[i]) {
				if (h[stk2.back()]>h[i+1]) {
					dp[i]=min(dp[i], dp[stk2.back()]+1);
				}
				stk2.pop_back();
			}
			if (!stk2.empty() && h[stk2.back()]>h[i+1]) {
				dp[i]=min(dp[i], dp[stk2.back()]+1);
			}
			while(!stk2.empty() && h[i]>=h[stk2.back()]) {
				stk2.pop_back();
			}
			stk2.push_back(i);
			while(!stk1.empty() && h[i]<=h[stk1.back()]) {
				stk1.pop_back();
			}
			stk1.push_back(i);
		} else {
			while(!stk1.empty() && h[i]<=h[stk1.back()]) {
				stk1.pop_back();
			}
			stk1.push_back(i);
			while(!stk2.empty() && h[i]>=h[stk2.back()]) {
				stk2.pop_back();
			}
			stk2.push_back(i);
		}
	//	cout<<i<<" "<<dp[i]<<endl;
		// cout<<i<<" "<<"sz="<<stk2.size()<<endl;
	}
	cout<<dp[1]<<endl;
	return 0;
}

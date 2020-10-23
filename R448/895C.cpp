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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,x,k;
int a[N];
bool pr[100];
int cnt[100], st[100];
int dp[71][(1<<19)];
int pw[N];
int main() {
	memset(pr, true, sizeof(pr));
	vector<int> ps;
	ps.clear();
	for (int i = 2; i <= 70; ++i) {
		if (pr[i]) {
			ps.push_back(i);
			for (int j = 2*i; j <= 70; j += i) {
				pr[j]=false;
			}
		}
	}
	memset(cnt, 0, sizeof(cnt));
	memset(st, 0, sizeof(st));
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	pw[0]=1;
	for (int i = 1; i <= n; ++i) {
		pw[i]=(int)((ll)pw[i-1]*2LL%mod);
	}
	for (int i = 1; i <= 70; ++i) {
		int x=i;
		for (int j = 0; j < ps.size(); ++j) {
			int num=0;
			while(x%ps[j]==0) {
				num++;
				x/=ps[j];
			}
			if (num%2) st[i] |= (1<<j);
		}
	}
	dp[0][0]=1;
	int sz=(int)ps.size();
	for (int i = 0; i < 70; ++i) {
		for (int j = 0; j < (1<<sz); ++j) {
			if (cnt[i+1]>0) {
				dp[i+1][j] = (int)((dp[i+1][j] + (ll)dp[i][j]*(ll)pw[cnt[i+1]-1]%mod)%mod);
				dp[i+1][j^st[i+1]] = (int)((dp[i+1][j^st[i+1]] + (ll)dp[i][j]*(ll)pw[cnt[i+1]-1]%mod)%mod);
			} else {
				dp[i+1][j] = (int)((dp[i+1][j] + dp[i][j])%mod);
			}
		}
	}
	cout<<(dp[70][0]-1+mod)%mod<<endl;
	return 0;
}

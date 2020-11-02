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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
int a[N];
int b[N];
int getres(vector<int>& ids) {
	int dp[N];
	if (ids.empty()) {
		return 0;
	}
	dp[1]=a[ids[0]];
	int len=1;
	for (int i = 1; i < ids.size(); ++i) {
		int id = ids[i];
		int l = 1, r= len+1;
		while(l<r) {
			int mid=(l+r)/2;
			if (dp[mid]>a[id]) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		if (r<=len) {
			dp[r]=a[id];
		} else {
			dp[++len]=a[id];
		}
	}
	return len;
}
int main() {
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &b[i]);
	}
	bool ok=true;
	for (int i = 2; i <= k; ++i) {
		if (a[b[i]] < a[b[i-1]]) {
			ok=false;
			break;
		}
	}
	if (!ok) {
		cout<<-1<<endl;
		return 0;
	}
	int ans=0;
	for (int i = 2; i <= k; ++i) {
		int l = b[i-1];
		int r=b[i];
		vector<int> ids;
		ids.clear();
		for (int j = l; j <= r; ++j) {
			if (a[j]<a[l] || a[j]>a[r]) {
				ans++;
			} else {
				ids.push_back(j);
			}
		}
		int res=getres(ids);
		ans += (int)ids.size()-res;
	}
	if (k==0) {
		vector<int> ids;
		ids.clear();
		for (int i = 1; i <= n; ++i) {
			ids.push_back(i);
		}
		int res=getres(ids);
		ans += (int)ids.size()-res;
	} else {
		if (b[1]>1) {
			vector<int> ids;
			ids.clear();
			for (int i = 1; i <= b[1]; ++i) {
				if (a[i]>a[b[1]]) {
					ans++;
				} else {
					ids.push_back(i);
				}
			}
			int res=getres(ids);
			ans += (int)ids.size()-res;
		}
		if (b[k]<n) {
			vector<int> ids;
			ids.clear();
			for (int i = b[k]; i <= n; ++i) {
				if (a[i]<a[b[k]]) {
					ans++;
				} else {
					ids.push_back(i);
				}
			}
			int res=getres(ids);
			ans += (int)ids.size()-res;
		}
	}
	cout<<ans<<endl;
	return 0;
}

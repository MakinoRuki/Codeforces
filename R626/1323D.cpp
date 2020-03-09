#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define N 400005
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int n;
int a[N];
int sum[N];
int getid(vector<pair<int,int>>& rk, int val) {
	int l = 0, r = n;
	while(l < r) {
		int mid = (l+r)/2;
		if (rk[mid].first > val) {
			r = mid;
		} else {
			l = mid+1;
		}
	}
	return r-1;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	ll ans=0;
	for (int i = 30; i >= 0; --i) {
		ll tot=0;
		vector<pair<int, int>> rk;
		rk.clear();
		for (int j = 1; j <= n; ++j) {
			rk.push_back(make_pair((((1<<i)-1)&a[j]), ((1<<i)&a[j]) > 0));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i <= n; ++i) {
			sum[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1] + rk[i-1].second;
		}
		for (int j = 0; j < n; ++j) {
			int rev = ((1<<i)-1) ^ rk[j].first;
			int id = getid(rk, rev);
			id++;
			int cnt1=0;
			int cnt2=0;
			if (rk[j].second) {
				cnt1 = id - sum[id];
				cnt2 = sum[n] - sum[id];
				if (j > id-1) {
					cnt2--;
				}
			} else {
				cnt1 = sum[id];
				cnt2 = (n-id) - (sum[n] - sum[id]);
				if (j > id-1) {
					cnt2--;
				}
			}
			tot += cnt1+cnt2;
		}
		tot /= 2;
		if (tot % 2) ans |= (1<<i);
		//cout<<i<<" "<<tot<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

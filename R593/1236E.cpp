#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
int main() {
	unordered_map<int, ll> cnt1;
	unordered_map<int, ll> cnt2;
	cnt1.clear();
	cnt2.clear();
	cin>>n>>m;
	bool isone = false;
	for (int i = 1; i <= m; ++i) {
		cin>>a[i];
		if (a[i] == 1) isone = true;
	}
	if (n == 1) {
		if (isone) cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	// wrong solution : 
	// example : 
	// 10 10
    // 1 9 7 6 2 4 7 8 1 3
    // when calculate position=10, should not take 3+7 same as 4+6
    // cnt2[3+7] should replace cnt2[4+6], adding with cnt2[3+7+1]
	// int num = 0;
	// for (int i = m; i >= 1; --i) {
	// 	if (i == m || a[i] != a[i+1]) num=1;
	// 	else num++;
	// 	cnt2[a[i]+i] += num;
	// 	cnt1[a[i]-i] += num;
	// }
	for (int i = m; i >= 1; --i) {
		cnt1[a[i]-i] = cnt1[a[i]-i-1] + 1;
		cnt2[a[i]+i] = cnt2[a[i]+i+1] + 1;
	}
	ll tot=0LL;
	for (int i= 1; i <= n; ++i) {
		ll rn = min((ll)(n-i), max((ll)m+1-cnt1[i], 0LL));
		ll ln = min((ll)(i-1), max((ll)m+1-cnt2[i], 0LL));
		tot += ln+rn+1;
	}
	cout<<tot<<endl;
	return 0;
}

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
int n,k;
int a[N];
int cnt[N];
ll getsum(int i, int num) {
	ll x=a[i]/num;
	ll r=a[i]%num;
	return r*(x+1)*(x+1)+(num-r)*x*x;
}
int main() {
	cin>>n>>k;
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		tot += (ll)a[i]*(ll)a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cnt[i]=1;
	}
	k -= n;
	priority_queue<pair<ll,int>> pq;
	for (int i = 1; i <= n; ++i) {
		if (a[i]>1) {
			ll cost = abs(getsum(i, cnt[i]) - getsum(i, cnt[i]+1));
			pq.push(make_pair(cost, i));
		}
	}
	for (int i = 1; i <= k; ++i) {
		auto top=pq.top();
		pq.pop();
		tot -= top.first;
		int id=top.second;
		cnt[id]++;
		if (cnt[id]<a[id]) {
			ll cost = abs(getsum(id, cnt[id]) - getsum(id, cnt[id]+1));
			pq.push(make_pair(cost, id));
		}
	}
	cout<<tot<<endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int n;
int p[N];
int bit[N];
int query(int x) {
	int sum=0;
	while(x > 0) {
		sum += bit[x];
		x -= x&(-x);
	}
	return sum;
}
void update(int x) {
	while(x <= n) {
		bit[x] += 1;
		x += x&(-x);
	}
}
int main() {
	cin>>n;
	for (int i =1; i<=n; ++i) {
		int x;
		cin>>x;
		p[x] = i;
	}
	memset(bit, 0, sizeof(bit));
	ll lsum = 0;
	ll rsum = 0;
	set<int> ls;
	set<int> rs;
	ls.clear();
	rs.clear();
  // 答案是逆序对累积和+到online median的距离和。
	ll inv =0;
	for (int i =1; i <= n; ++i) {
		inv += (ll)(i-1-query(p[i]));
		update(p[i]);
		if (ls.size() == rs.size()) {
			if (ls.empty()) {
				ls.insert(-p[i]);
				lsum += p[i];
			} else {
				if (p[i] < (*rs.begin())) {
					ls.insert(-p[i]);
					lsum += p[i];
				} else {
					int pos = (*rs.begin());
					rsum -= pos;
					rs.erase(pos);
					lsum += pos;
					ls.insert(-pos);
					rs.insert(p[i]);
					rsum += p[i];
				}
			}
		} else {
			if (p[i] > -(*ls.begin())) {
				rs.insert(p[i]);
				rsum += p[i];
			} else {
				int pos = -(*ls.begin());
				ls.erase(-pos);
				lsum -= pos;
				rs.insert(pos);
				rsum += pos;
				ls.insert(-p[i]);
				lsum += p[i];
			}
		}
		int mid = -(*ls.begin());
		int lnum = ls.size();
		int rnum = rs.size();
		ll ans = inv + (ll)mid*(ll)(lnum-1)-(ll)(lsum-mid)-(ll)lnum*(ll)(lnum-1)/2;
		ans += (ll)rsum - (ll)mid*(ll)rnum-(ll)rnum*(ll)(rnum+1)/2;
		cout<<ans;
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int n;
int x[N], v[N];
ll cBIT[N], sBIT[N];
int lowbit(int x) {
	return x&(-x);
}
ll query(ll* BIT, int pos) {
	ll res=0;
	while(pos) {
		res+=BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
void update(ll* BIT, int pos, ll val, int cur) {
	while(pos <= cur) {
	//	cout<<pos<<" "<<cur<<endl;
		BIT[pos] += val;
		pos += lowbit(pos);
	}
}
void calc(vector<pair<int, int>>& v, ll& tot) {
	int id[N];
	vector<pair<int, int>> vr;
	vr.clear();
	for (int i= 0; i < v.size(); ++i) {
		vr.push_back(make_pair(v[i].second, i));
	}
	sort(vr.begin(), vr.end());
	int cur=0;
	for (int i = 0; i < vr.size(); ++i) {
		if (i == 0 || vr[i] != vr[i-1]) {
			cur++;
		}
		id[vr[i].second] = cur;
	}
	memset(cBIT, 0, sizeof(cBIT));
	memset(sBIT, 0, sizeof(sBIT));
	for (int i = 0; i < v.size(); ++i) {
	//	cout<<"i="<<i<<endl;
		int x= id[i];
		tot += v[i].first * query(cBIT, x) - query(sBIT, x);
	//	cout<<"i1="<<cur<<endl;
		update(cBIT, x, 1, cur);
		update(sBIT, x, v[i].first, cur);
	//	cout<<"i2="<<i<<endl;
	}
}
int main() {
	cin>>n;
	vector<pair<int, int>> rks;
	rks.clear();
	for (int i = 1; i <= n; ++i) {
		cin>>x[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin>>v[i];
	}
	for (int i = 1; i <= n; ++i) {
		rks.push_back(make_pair(x[i], v[i]));
	}
	sort(rks.begin(), rks.end());
	ll tot=0LL;
	int cnt=0;
	ll sum=0;
	ll acc = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0) acc += rks[i].first - rks[i-1].first;
		if (rks[i].second < 0) {
			sum += (ll)cnt * acc;
			acc = 0;
			cnt++;
		} else {
			tot += sum + (ll)cnt * acc;
		}
	}
//	cout<<"tot="<<tot<<endl;
	vector<pair<int, int>> r1;
	vector<pair<int, int>> r2;
	for (int i = 0; i < n; ++i) {
		if (rks[i].second < 0) r1.push_back(rks[i]);
		else r2.push_back(rks[i]);
	}
//	cout<<"b="<<lowbit(1)<<endl;
	calc(r1, tot);
//	cout<<"tot2="<<tot<<endl;
	calc(r2, tot);
	cout<<tot<<endl;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define N 500005
using namespace std;
typedef long long ll;
int n;
int m[N];
ll ls[N], rs[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>m[i];
	}
	vector<int> stk;
	stk.clear();
	for (int i = 1; i <= n; ++i) {
		while(!stk.empty() && m[stk.back()] > m[i]) {
			stk.pop_back();
		}
		ll cur;
		if (!stk.empty()) {
			cur = (ll)(i-stk.back()) * (ll)m[i] + ls[stk.back()];
		} else {
			cur = (ll)i * (ll)m[i];
		}
		ls[i] = cur;
		stk.push_back(i);
	}
	stk.clear();
	for (int i = n; i >= 1; --i) {
		while(!stk.empty() && m[stk.back()] > m[i]) {
			stk.pop_back();
		}
		ll cur;
		if (!stk.empty()) {
			cur = (ll)(stk.back()-i) * (ll)m[i] + rs[stk.back()];
		} else {
			cur = (ll)(n+1-i) * (ll)m[i];
		}
		rs[i] = cur;
		stk.push_back(i);
	}
	ll ans = 0LL;
	int id = -1;
	for (int i =1; i <= n; ++i) {
		if (ls[i] + rs[i] - m[i] > ans) {
			ans = ls[i] + rs[i] - m[i];
			id = i;
		}
	}
	for (int i = id-1; i >= 1; --i) {
		m[i] = min(m[i], m[i+1]);
	}
	for (int i = id+1; i <= n; ++i) {
		m[i] = min(m[i], m[i-1]);
	}
	for (int i = 1; i <= n; ++i) {
		cout<<m[i];
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}

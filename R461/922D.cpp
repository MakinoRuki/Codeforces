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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<pair<string,pair<ll,ll>>> ts;
void calc(string& t) {
	ll sn=0,tn=0;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i]=='s') sn++;
		else tn++;
	}
	ts.push_back(make_pair(t, make_pair(sn,tn)));
}
int main() {
	cin>>n;
	ts.clear();
	for (int i = 1; i<= n; ++i) {
		string t;
		cin>>t;
		calc(t);
	}
	sort(ts.begin(), ts.end(), [](const pair<string,pair<ll,ll>> a, const pair<string,pair<ll,ll>> b) {
		return a.second.first*b.second.second > b.second.first*a.second.second;
	});
	string res="";
	for (int i = 0; i < ts.size(); ++i) {
		res += ts[i].first;
	}
	ll ans=0LL;
	ll sum=0LL;
	for (int i = res.size()-1; i>=0; --i) {
		if (res[i]=='s') {
			ans += sum;
		} else {
			sum++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

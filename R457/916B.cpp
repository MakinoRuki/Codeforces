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
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
int k;
int main() {
	cin>>n>>k;
	vector<int> ans;
	ans.clear();
	for (int ub=0; ub<=60; ++ub) {
		// cout<<"ub="<<ub<<endl;
		if ((n+(1LL<<ub)-1)/(1LL<<ub)>k) continue;
		int pw=ub;
		ll v=1;
		ll x=n;
		for (int i = 1; i <= pw; ++i) {
			v=v*2;
		}
		vector<int> res;
		res.clear();
		while(x) {
			while(v>x) {
				pw--;
				v/=2;
			}
			x-=v;
			res.push_back(pw);
		}
		if (res.size()>k) {
			continue;
		}
		unordered_map<int,int> cnt;
		cnt.clear();
		deque<int> dq;
		for (int i = 0; i < res.size(); ++i) {
			cnt[res[i]]++;
			dq.push_back(res[i]);
		}
		while(dq.size()<k) {
			int x=dq.front();
			int num=cnt[x];
			if (dq.size()+num<=k) {
				for (int i = 1; i <= num; ++i) {
					dq.pop_front();
				}
				for (int i = 1; i <= 2*num; ++i) {
					dq.push_front(x-1);
				}
				cnt.erase(x);
				cnt[x-1]+=2*num;
			} else {
				int y=dq.back();
				dq.pop_back();
				dq.push_back(y-1);
				dq.push_back(y-1);
			}
		}
		if (ans.empty() || dq.front() < ans[0]) {
			ans.clear();
			while(!dq.empty()) {
				ans.push_back(dq.front());
				dq.pop_front();
			}
		}
	}
	if (ans.empty()) {
		cout<<"No"<<endl;
	} else {
		cout<<"Yes"<<endl;
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i<ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

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
#define N 5005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<pair<int, pair<int,int>>> hs;
vector<pair<int, pair<int,int>>> vs;
int BIT[N*3];
int lowbit(int x) {
	return x&(-x);
}
void update(int pos, int val) {
	while(pos <= 10002) {
		BIT[pos] += val;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos>0) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>n;
	hs.clear();
	vs.clear();
	for (int i = 0; i < n; ++i) {
		int a,b,c,d;
		scanf("%d%d%d%d", &a,&b,&c,&d);
		if (a==c) {
			vs.push_back(make_pair(a, make_pair(max(b,d), min(b,d))));
		} else {
			hs.push_back(make_pair(b, make_pair(min(a,c), max(a,c))));
		}
	}
	sort(vs.begin(), vs.end());
	sort(hs.begin(), hs.end());
	ll ans=0LL;
	reverse(hs.begin(), hs.end());
	for (int i = 0; i < hs.size(); ++i) {
	//	cout<<"i="<<i<<" "<<hs[i].first<<" "<<hs[i].second.first<<" "<<hs[i].second.second<<endl;
		memset(BIT, 0, sizeof(BIT));
		vector<pair<int,int>> cdd;
		for (int j = 0; j < vs.size(); ++j) {
			int a=vs[j].second.first;
			int b=vs[j].second.second;
			if (a>=hs[i].first && b<=hs[i].first) {
				cdd.push_back(make_pair(b, vs[j].first));
			}
		}
		sort(cdd.begin(), cdd.end());
		reverse(cdd.begin(), cdd.end());
		for (int j = 0; j < cdd.size(); ++j) {
			update(cdd[j].second+5000+1, 1);
		//	cout<<"j="<<j<<" "<<cdd[j].second+5000+1<<endl;
		}
		int k=0;
		for (int j = i+1; j < hs.size(); ++j) {
			if (hs[j].first==hs[i].first) {
				continue;
			}
			int a=max(hs[i].second.first, hs[j].second.first);
			int b=min(hs[i].second.second, hs[j].second.second);
		//	cout<<"j2="<<j<<" "<<a<<" "<<b<<endl;
			if (a>=b) continue;
			while(k < cdd.size() && cdd[k].first > hs[j].first) {
			//	cout<<"k="<<k<<" "<<cdd[k].first<<endl;
				update(cdd[k].second+5000+1, -1);
				k++;
			}
			int tot=query(b+5000+1)-query(a+5000);
			if (tot>=1) {
				ans += (ll)tot*(ll)(tot-1)/2;
			}
		//	cout<<"res="<<i<<" "<<j<<" "<<ans<<endl;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n;
bool vis[N];
ll ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &n);
		vector<ll> ps;
		vector<ll> ds;
		ps.clear();
		ds.clear();
		ll m= n;
		for (ll i = 2; i*i <= m; ++i) {
			if (m%i==0) {
				ps.push_back(i);
				while(m%i==0) {
					m/=i;
				}
			}
		}
		if (m>1) ps.push_back(m);
		m=n;
		for (ll i = 2; i * i <= m; ++i) {
			if (m%i==0) {
				ds.push_back(i);
				if (m/i != i) {
					ds.push_back(m/i);
				}
			}
		}
		ds.push_back(m);
		if (ps.size()==1) {
			for (int i = 0; i < ds.size(); ++i) {
				printf("%lld", ds[i]);
				if (i<ds.size()-1) cout<<" ";
				else cout<<endl;
			}
			cout<<0<<endl;
			continue;
		}
		if (ps.size()==2) {
			if (ps[0]*ps[1] == n) {
				cout<<ps[0]<<" "<<n<<" "<<ps[1]<<endl;
				cout<<1<<endl;
			} else {
				for (int i = 0; i < ds.size(); ++i) {
					vis[i]=false;
					if (ds[i] == ps[0] || ds[i] == ps[1] || ds[i] == ps[0]*ps[1] || ds[i]==n) {
						vis[i]=true;
					}
				}
				int id=1;
				ans[id++] = ps[0];
				for (int i = 0; i < ds.size(); ++i) {
					if (!vis[i] && (ds[i]%ps[0]==0)) {
						ans[id++] = ds[i];
						vis[i]=true;
					}
				}
				ans[id++] = ps[0]*ps[1];
				ans[id++]=ps[1];
				for (int i = 0; i < ds.size(); ++i) {
					if (!vis[i] && (ds[i]%ps[1]==0)) {
						ans[id++]=ds[i];
						vis[i]=true;
					}
				}
				ans[id++] = n;
				for (int i = 1; i < id; ++i) {
					printf("%lld", ans[i]);
					if (i<id-1) cout<<" ";
					else cout<<endl;
				}
				cout<<0<<endl;
			}
			continue;
		}
		for (int i = 0; i < ds.size(); ++i) {
			vis[i]=false;
		}
		int id=1;
		int sz=ps.size();
		for (int i = 0; i < ps.size(); ++i) {
			ll p = ps[i];
			ll p1=ps[(i+1)%sz];
			for (int j=0;j<ds.size(); ++j) {
				if (ds[j] == p || ds[j]==p*p1) {
					vis[j]=true;
				}
			}
		}
		for (int i = 0; i < ps.size(); ++i) {
			ll p = ps[i];
			ll p1=ps[(i+1)%sz];
			ans[id++] = p;
			for (int j = 0; j < ds.size(); ++j) {
				if (!vis[j] && ds[j]%p==0) {
					ans[id++] = ds[j];
					vis[j]=true;
				}
			}
			ans[id++] = p*p1;
		}
		for (int i = 1; i < id; ++i) {
			printf("%lld", ans[i]);
			if (i < id-1) cout<<" ";
			else cout<<endl;
		}
		if (ps.size()==2 && ps[0]*ps[1]==n) {
			cout<<1<<endl;
		} else {
			cout<<0<<endl;
		}
	}
	return 0;
}

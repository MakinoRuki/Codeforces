#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int q;
int p[N];
int x,y,a,b;
ll k;
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			cin>>p[i];
		}
		cin>>x>>a>>y>>b;
		cin>>k;
		ll l = 0, r = n+1;
		sort(p+1, p+n+1);
		reverse(p+1, p+n+1);
		while(l < r) {
			ll mid = (l+r)/2;
			vector<int> ws;
			ws.clear();
			for (int i = 1; i <= mid; ++i) {
				int w = 0;
				if (i % a == 0) {
					w += x;
				}
				if (i % b == 0) {
					w += y;
				}
				ws.push_back(w);
			}
			sort(ws.begin(), ws.end());
			reverse(ws.begin(), ws.end());
			ll tot=0;
			for (int i = 0; i < ws.size(); ++i) {
				tot += p[i+1]/100LL * ws[i];
			}
		//	cout<<l<<" "<<r<<" "<<mid<<" "<<tot<<endl;
			if (tot >= k) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (r == n+1) {
			cout<<-1<<endl;
		} else {
			cout<<r<<endl;
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 5002
using namespace std;
typedef long long ll;
int t,n,d;
int par[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>d;
		ll maxv = (ll)n*(ll)(n-1)/2;
		ll minv = 0LL;
		int lev = 0;
		int tot=1;
		int cur=1;
		while(true) {
			cur *= 2;
			lev++;
			if (tot + cur <=n) {
				tot += cur;
				minv += cur * lev;
			} else {
				break;
			}
		}
		minv += (n-tot) * lev;
	//	cout<<minv<<" "<<maxv<<endl;
		if (d < minv || d > maxv) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
			unordered_map<int, vector<int>> pts;
			pts.clear();
			for (int i = 1; i <= n; ++i) {
				pts[i-1].push_back(i);
				if (i > 1) par[i] = i-1;
			}
			int tot=maxv;
			int cl = n-1;
			int canl = 0;
			int canp = 0;
			while(tot > d) {
				int x = pts[cl][0];
				int det = tot-d;
				if (det >= cl-canl-1) {
					tot -= cl-canl-1;
					pts[cl].pop_back();
					pts[canl+1].push_back(x);
					par[x] = pts[canl][canp];
					if (pts[canl+1].size() == (1<<(canl+1))) {
						canl++;
						canp = 0;
					} else {
						canp = (pts[canl+1].size())/2;
					}
				} else {
					pts[cl].pop_back();
					pts[cl-det].push_back(x);
					par[x] = pts[cl-det-1][0];
					break;
				}
				cl--;
			}
			for (int i = 2; i <= n; ++i) {
				cout<<par[i];
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}

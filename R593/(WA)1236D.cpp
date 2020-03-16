#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,m,k;
vector<int> robs[N];
vector<int> cobs[N];
int getid(vector<int>& v, int x, int f, int bd) {
	if (f) {
		int l = -1;
		int r = v.size()-1;
		while(l < r) {
			int mid=(l+r+1)/2;
			if (v[mid] < x) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		if (r == -1) return 0;
		return v[r];
	} else {
		int l = 0, r = v.size();
		while(l<r) {
			int mid=(l+r)/2;
			if (v[mid]>x) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (r == v.size()) return bd;
		return v[r];
	}
}
int main() {
	cin>>n>>m>>k;
	for (int i = 0; i< k; ++i) {
		int x,y;
		cin>>x>>y;
		robs[x].push_back(y);
		cobs[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		sort(robs[i].begin(), robs[i].end());
	}
	for (int i = 1; i <= m; ++i) {
		sort(cobs[i].begin(), cobs[i].end());
	}
	int d = 1;
	int x = 1;
	int y = 1;
	ll tot=1;
	int ub = 0, db = n+1;
	int lb = 0, rb = m+1;
	while(true) {
		if (d == 1) {
			int id = getid(robs[x], y, 0, m+1);
			rb = min(rb, id);
			if (rb == y+1) {
				if (x==1 && y==1) {
					d = 2;
					int id2 = getid(cobs[y], x, 0, n+1);
					db = min(db, id2);
					if (db == x+1) break;
					tot += db-x-1;
					x = db-1;
					rb--;
				} else {
					break;
				}
			} else {
				tot += rb-y-1;
				y = rb-1;
				d = 2;
			}
			ub--;
		} else if (d == 2) {
			int id = getid(cobs[y], x, 0, n+1);
			db = min(db, id);
			if (db == x+1) break;
			tot += db - x-1;
			x = db-1;
			rb--;
			d = 3;
		} else if (d == 3) {
			int id = getid(robs[x], y, 1, m+1);
			lb = max(lb, id);
			if (lb== y-1) break;
			tot += y-lb-1;
			y = lb+1;
			db--;
			d = 4;
		} else {
			int id = getid(cobs[y], x, 1, n+1);
			ub = max(ub, id);
			if (ub == x-1) break;
			tot += x-ub-1;
			x= ub+1;
			lb++;
			d = 1;
		}
	}
	if (tot == (ll)n*(ll)m-k) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

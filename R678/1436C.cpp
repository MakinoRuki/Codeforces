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
#include <queue>
#define eps 1e-7
#define M 20005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,x,pos;
int main() {
	cin>>n>>x>>pos;
	int l=0,r=n;
	vector<int> id1, id2;
	id1.clear();
	id2.clear();
	while(l<r) {
		int mid=(l+r)/2;
		if (mid>pos) {
			id2.push_back(mid);
			r=mid;
		} else {
			if (mid<pos) {
				id1.push_back(mid);
			}
			l=mid+1;
		}
	}
	int v2=n-x;
	int v1=x-1;
	int sz1=(int)id1.size();
	int sz2=(int)id2.size();
	int det=n-1-sz1-sz2;
	ll res=1LL;
	if (v2>=sz2) {
		for (int i = v2; i > v2-sz2; --i) {
			res=res*(ll)i%mod;
		}
	} else {
			res=0LL;
	}
	if (v1>=sz1) {
		for (int i = v1; i > v1-sz1; --i) {
			res=res*(ll)i%mod;
		}
	} else {
			res=0LL;
		}
	if (det>=0) {
		for (int i = 1; i <= det; ++i) {
			res=res*(ll)i%mod;
		}
	} else {
		res=0LL;
	}
	cout<<res<<endl;
	return 0;
}

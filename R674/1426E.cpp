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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a1,a2,a3;
int b1,b2,b3;
vector<vector<int>> rk = {{0,2},{0,1},{1,2}};
ll getres(int i, int j, int k, vector<int>as, vector<int> bs) {
	ll res=n;
	for (int i2=0;i2<2;++i2) {
		for (int j2=0;j2<2;++j2) {
			for (int k2=0;k2<2;++k2) {
				vector<int> as2=as;
				vector<int> bs2=bs;
				ll tot=0;
				if (i2==0) {
					ll det=min(as2[i],bs2[rk[i][0]]);
					as2[i]-=det;
					bs2[rk[i][0]]-=det;
					tot+=det;
					det=min(as2[i],bs2[rk[i][1]]);
					as2[i]-=det;
					bs2[rk[i][1]]-=det;
					tot+=det;
				} else {
					ll det=min(as2[i],bs2[rk[i][1]]);
					as2[i]-=det;
					bs2[rk[i][1]]-=det;
					tot+=det;
					det=min(as2[i],bs2[rk[i][0]]);
					as2[i]-=det;
					bs2[rk[i][0]]-=det;
					tot+=det;
				}
				if (j2==0) {
					ll det=min(as2[j],bs2[rk[j][0]]);
					as2[j]-=det;
					bs2[rk[j][0]]-=det;
					tot+=det;
					det=min(as2[j],bs2[rk[j][1]]);
					as2[j]-=det;
					bs2[rk[j][1]]-=det;
					tot+=det;
				} else {
					ll det=min(as2[j],bs2[rk[j][1]]);
					as2[j]-=det;
					bs2[rk[j][1]]-=det;
					tot+=det;
					det=min(as2[j],bs2[rk[j][0]]);
					as2[j]-=det;
					bs2[rk[j][0]]-=det;
					tot+=det;
				}
				if (k2==0) {
					ll det=min(as2[k],bs2[rk[k][0]]);
					as2[k]-=det;
					bs2[rk[k][0]]-=det;
					tot+=det;
					det=min(as2[k],bs2[rk[k][1]]);
					as2[k]-=det;
					bs2[rk[k][1]]-=det;
					tot+=det;
				} else {
					ll det=min(as2[k],bs2[rk[k][1]]);
					as2[k]-=det;
					bs2[rk[k][1]]-=det;
					tot+=det;
					det=min(as2[k],bs2[rk[k][0]]);
					as2[k]-=det;
					bs2[rk[k][0]]-=det;
					tot+=det;
				}
				res=min(res, n-tot);
			}
		}
	}
	return res;
}
int main() {
	cin>>n;
	cin>>a1>>a2>>a3;
	cin>>b1>>b2>>b3;
	ll maxv=min(a1,b2)+min(a2,b3)+min(a3,b1);
	ll minv=n;
	vector<int> as = {a1,a2,a3};
	vector<int> bs = {b1,b2,b3};
	minv=min(minv, getres(0,1,2,as,bs));
	minv=min(minv, getres(0,2,1,as,bs));
	minv=min(minv, getres(1,0,2,as,bs));
	minv=min(minv, getres(1,2,0,as,bs));
	minv=min(minv, getres(2,0,1,as,bs));
	minv=min(minv, getres(2,1,0,as,bs));
	cout<<minv<<" "<<maxv<<endl;
	return 0;
}

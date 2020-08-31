#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
ll n, m;
int main() {
	cin>>n>>m;
	if (n>m) swap(n, m);
	if (n==1) {
		ll res=m/6*6;
		if (m%6==4) res+=2;
		else if (m%6==5) res+=4;
		cout<<res<<endl;
	} else if (n==2) {
		if (m<=2) cout<<0<<endl;
		else if (m==3||m==7) {
			cout<<n*m-2<<endl;
		} else {
			cout<<n*m<<endl;
		}
	} else {
		if ((n*m)%2) cout<<n*m-1<<endl;
		else cout<<n*m<<endl;
	}
	return 0;
}

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
#define N 2002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
ll n, m, k;
ll getgcd(ll a, ll b) {
	return b==0 ? a: getgcd(b, a%b);
}
int main() {
	cin>>n>>m>>k;
	if ((n*m)%k==0) {
		ll g1=getgcd(n,k);
		k/=g1;
		ll g2=k;
		ll d1=n/g1;
		ll d2=m/g2;
		if (g1>=2) {
			cout<<"YES"<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<d1<<" "<<d2<<endl;
			cout<<2*d1<<" "<<0<<endl;
		} else {
			cout<<"YES"<<endl;
			cout<<0<<" "<<0<<endl;
			cout<<d1<<" "<<d2<<endl;
			cout<<0<<" "<<2*d2<<endl;
		}
	} else {
		ll g1=getgcd(n, k);
		k/=g1;
		ll g2=getgcd(m, k);
		k/=g2;
		if (k!=2) {
			cout<<"NO"<<endl;
			return 0;
		}
		ll d1=n/g1;
		ll d2=m/g2;
		cout<<"YES"<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<d1<<" "<<0<<endl;
		cout<<d1<<" "<<d2<<endl;
	}
	return 0;
}

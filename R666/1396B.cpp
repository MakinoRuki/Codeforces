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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
ll a[N];
inline ll gcd(ll a,ll b){
    if(b==0)
        return a;
    else{
        while(ll i=a%b){
            a=b;
            b=i;
        }
        return b;
    }
}

ll ex_gcd(ll a,ll b,ll& x,ll& y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll d=ex_gcd(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-a/b*y;
    return d;
}
bool calc(ll a, ll b, ll c, ll &x0, ll &y0) {
    ll x,y;
    ll d=ex_gcd(a,b,x,y);
    if(c%d!=0){
        //无解
        return 0;
    }
    //ax0 + by0 = gcd(a,b)
    ll k=c/d;
    x0=x*k;
    y0=y*k;
    //(x0,y0)是一组解
    //x=x0+bt,y=y0+at，是方程的所有解，对所有整数t成立
    return 1;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	if (n==1) {
		cout<<1<<" "<<1<<endl;
		cout<<-a[1]<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
	} else {
		int len1=n-1;
		int len2=n;
		cout<<1<<" "<<len1<<endl;
		for (int i = 1; i <= len1; ++i) {
			if (a[i]%len2==0) {
				cout<<0;
			} else {
				ll x, y;
				calc(len1, -len2, -a[i], x, y);
				a[i] += x*len1;
				printf("%lld", x*len1);
			}
			if (i<len1) cout<<" ";
			else cout<<endl;
		}
		cout<<n<<" "<<n<<endl;
		ll det = len2-a[n];
		a[n] = len2;
		printf("%lld\n", det);
		cout<<1<<" "<<n<<endl;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) {
				cout<<0;
			} else {
				printf("%lld", -a[i]);
			}
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

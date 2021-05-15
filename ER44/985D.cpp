#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <time.h>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
ll n, h;
int main() {
	cin>>n>>h;
	ll l = 1, r = n;
	while(l < r) {
		ll mid = (l+r)/2;
		if (mid <= h) {
		//	cout<<"ok1"<<endl;
			if (mid >= 2000000000LL) {
				r = mid;
				continue;
			}
			if (mid+1>=(2*n+mid-1)/mid) {
				r = mid;
			} else {
				l = mid+1;
			}
		} else {
			if (2*mid-h+1 >= 2000000000LL && h >= 2000000000LL) {
				r = mid;
				continue;
			}
			if (2*mid-h+1>=(2*n+h-1)/h) {
			//	cout<<"ok2"<<endl;
				r = mid;
			} else {
			//	if (mid == 6) cout<<"ok"<<endl;
				ll n2 = n-(2*mid-h+1)*h/2;
				//if (mid == 6) cout<<"n2="<<n2<<endl;
				ll cur = mid - h+1-2;
				//cout<<"ok6"<<endl;
				if (cur > 0) {
				//	cout<<"ok3"<<endl;
					ll x = (cur+1)/2;
					ll lb = (cur%2 ? 1 : 2);
					//if (mid == 6) cout<<cur<<" "<<lb<<" "<<x<<endl;
					if (x-1 >= (n2-lb*x+x-1)/x) {
						r = mid;
					} else {
						l = mid+1;
					}
				} else {
				//	cout<<"ok4"<<endl;
					l = mid+1;
				}
			}
		}
	}
	cout<<r<<endl;
	return 0;
}

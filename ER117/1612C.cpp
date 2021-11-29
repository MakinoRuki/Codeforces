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
#define M 1000005
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll k, x;
		scanf("%lld%lld", &k, &x);
		if ((k+1)*k/2 >= x) {
			ll y1 = 1, y2 = k;
			while(y1 < y2) {
				ll mid = (y1+y2)/2;
				if (mid+1 >= (2*x+mid-1)/mid) {
					y2 = mid;
				} else {
					y1 = mid+1;
				}
			}
			printf("%lld\n", y2);
		} else if (x-k*(k+1)/2 >= k*(k-1)/2) {
			printf("%lld\n", 2*k-1);
		}	else {
			ll r = x-k*(k+1)/2;
			ll y1 = 1, y2 = k-1;
			while(y1<y2) {
				ll mid=(y1+y2)/2;
			//	cout<<y1<<" "<<y2<<" "<<mid<<" "<<mid+1<<" "<<2LL*(k*mid-r)/mid<<endl;
				if (k*mid-r >= 0 && (mid+1 <= 2LL*(k*mid-r)/mid)) {
					y2 = mid;
				} else {
					y1 = mid+1;
				}
			}
			printf("%lld\n", k+y2);
		}
	}
  return 0;
}


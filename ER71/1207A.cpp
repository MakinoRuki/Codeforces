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
//const ll mod2 = 999999937LL;
int t, n;
int b,p,f;
int h,c;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>b>>p>>f;
		cin>>h>>c;
		int ans=0;
		for (int i = 0; i <= p; ++i) {
			for (int j = 0; j <= f; ++j) {
				if (2*i+2*j<=b) {
					ans = max(ans, i*h+c*j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,d,k;
string a,b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &d, &k);
		ll x = 0;
		while(true) {
			if (2LL*(x+k)*(x+k)<=(ll)d*(ll)d) {
				x += k;
			} else {
				break;
			}
		}
		if ((x+k)*(x+k)+x*x <= (ll)d*(ll)d) {
			cout<<"Ashish"<<endl;
		} else {
			cout<<"Utkarsh"<<endl;
		}
	}
	return 0;
}

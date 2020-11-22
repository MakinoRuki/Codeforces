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
int t,n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		if (n == 1) cout<<0<<endl;
		else if (n==2) cout<<1<<endl;
		else if (n==3) cout<<2<<endl;
		else {
			if (n%2==0) {
				cout<<2<<endl;
			} else {
				cout<<3<<endl;
			}
		}
	}
	return 0;
}

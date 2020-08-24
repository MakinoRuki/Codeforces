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
int t;
int a, b, c;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &a, &b, &c);
		int x = (b+c-a);
		int res;
		if (x<0) {
			res = c+1;
		} else {
			x/=2;
			res = x+1;
			if (res <= c) {
				res = c-res+1;
			} else {
				res = 0;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

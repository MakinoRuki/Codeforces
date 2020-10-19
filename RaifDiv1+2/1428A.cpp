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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,a,b,c,d;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d%d", &a,&b,&c,&d);
		if (a==c || b==d) {
			int res=abs(a-c)+abs(b-d);
			printf("%d\n", res);
		} else {
			int res=abs(a-c)+abs(b-d)+2;
			printf("%d\n", res);
		}
	}
	return 0;
}

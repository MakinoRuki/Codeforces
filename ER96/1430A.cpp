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
		int x=-1,y=-1,z=-1;
		for (x=0;x<=n; ++x) {
			if (3*x<=n) {
				int det=n-3*x;
				int w=det/5;
				int r=det-5*w;
				if (r >= 0 && r%2==0 && r/2<=w) {
					y=w-r/2;
					z=r/2;
					break;
				}
			}
		}
		if (x<0 || y <0 || z < 0) {
			cout<<-1<<endl;
		} else {
			printf("%d %d %d\n", x, y, z);
		}
	}
	return 0;
}

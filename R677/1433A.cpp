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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int x;
		scanf("%d", &x);
		int tot=0;
		for (int i = 1; i <= 9; ++i) {
			if (i>x%10) break;
			int cur=i;
			int cnt=1;
			int ub=10000;
			if (i==x%10) {
				ub=x;
			}
			while(cur<=ub) {
				tot += cnt;
				cur = cur*10 + i;
				cnt++;
			}
			//cout<<i<<" "<<tot<<endl;
		}
		printf("%d\n", tot);
	}
	return 0;
}

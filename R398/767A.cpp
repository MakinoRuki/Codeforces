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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 510
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
int main() {
	cin>>n;
	set<int> ss;
	ss.clear();
	int cur = n;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		ss.insert(x);
		if (ss.find(cur) != ss.end()) {
			for (; cur > 0; --cur) {
				if (ss.find(cur) != ss.end()) {
					printf("%d ", cur);
				} else {
					break;
				}
			}
		}
		cout<<endl;
	}
  return 0;
}

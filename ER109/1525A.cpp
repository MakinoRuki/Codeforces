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
#define M 52
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,k;
int getgcd(int x, int y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &k);
		if (k == 100) {
			puts("1");
		} else {
			int g = getgcd(100-k, k);
			int x = (100-k)/g;
			int y = k/g;
			printf("%d\n", x+y);
		}
	}
  return 0;
}

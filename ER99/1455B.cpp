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
int t;
int x;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &x);
		int i;
		int sum=0;
		for (i = 1; i <= x; ++i) {
			sum += i;
			if (sum >= x) {
				break;
			}
		}
		if (sum==x) {
			printf("%d\n", i);
		} else {
			if (sum-x==1) {
				printf("%d\n", i+1);
			} else {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}

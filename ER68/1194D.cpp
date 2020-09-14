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
#define N 500005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		if (k > n) {
			if (n%3==0) puts("Bob");
			else puts("Alice");
		} else {
			if (k%3==0) {
				n%=(k+1);
				if (n%3==0 && n!=k) {
					puts("Bob");
				} else {
					puts("Alice");
				}
			} else {
				if (n%3==0) puts("Bob");
				else puts("Alice");
			}
		}
	}
	return 0;
}

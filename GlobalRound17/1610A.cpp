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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (n == 1 && m == 1) {
			puts("0");
			continue;
		}
		if (n == 1 || m == 1) {
			puts("1");
		} else {
			puts("2");
		}
	}
  return 0;
}


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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		string s;
		cin>>s;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); ++i) {
			cnt[s[i]-'a']++;
		}
		int tot=0;
		for (int i = 0; i < 26; ++i) {
			tot += min(2, cnt[i]);
		}
		printf("%d\n", tot/2);
	}
  return 0;
}

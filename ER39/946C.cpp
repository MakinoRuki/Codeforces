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
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
string s;
int main() {
	cin>>s;
	int n = s.size();
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (cur >= 26) break;
		if (cur >= s[i]-'a') {
			s[i] = cur+'a';
			cur++;
		}
	}
	if (cur >= 26) {
		cout<<s<<endl;
	} else {
		puts("-1");
	}
  return 0;
}

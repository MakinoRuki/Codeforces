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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, k;
string s;
int main() {
	cin>>n>>k>>s;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		cnt[s[i]-'A']++;
	}
	int minv=n;
	for (int i = 0; i < k; ++i) {
		minv=min(minv, cnt[i]);
	}
	cout<<minv*k<<endl;
	return 0;
}

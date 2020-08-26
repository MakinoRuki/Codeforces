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
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t, n;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>s;
		string ans(n, s[n-1]);
		cout<<ans<<endl;
	}
	return 0;
}

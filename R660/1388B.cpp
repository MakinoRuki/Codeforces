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
#define N 300005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		int x = (3*n)/4;
		string ans="";
		for (int i = 1; i <= x; ++i) {
			ans += "9";
		}
		for (int i = x+1; i <= n; ++i) {
			ans += "8";
		}
		cout<<ans<<endl;
	}
  return 0;
}

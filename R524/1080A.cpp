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
#define N 500005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, k;
int main() {
	cin>>n>>k;
	int res = (2*n+k-1)/k;
	res += (5*n+k-1)/k;
	res += (8*n+k-1)/k;
	cout<<res<<endl;
	return 0;
}

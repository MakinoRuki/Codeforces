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
#define M 20005
#define N 1000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll k,n,s,p;
int main() {
	cin>>k>>n>>s>>p;
	ll res1=(n+s-1)/s;
	ll res2=(res1*k+p-1)/p;
	cout<<res2<<endl;
	return 0;
}

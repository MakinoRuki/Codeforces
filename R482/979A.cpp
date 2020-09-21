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
#define N 200005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int a,b,c,d;
ll n;
int main() {
	cin>>n;
	n++;
	if (n==1) {
		cout<<0<<endl;
		return 0;
	}
	if (n%2) {
		cout<<n<<endl;
	} else {
		cout<<n/2<<endl;
	}
	return 0;
}

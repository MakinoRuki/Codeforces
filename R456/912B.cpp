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
#define eps 1e-7
#define M 20005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n,k;
int main() {
	cin>>n>>k;
	if (k==1) {
		cout<<n<<endl;
	} else {
		int pw=0;
		while((1LL<<pw)<=n) {
			pw++;
		}
		pw--;
		cout<<(1LL<<(pw+1))-1<<endl;
	}
	return 0;
}

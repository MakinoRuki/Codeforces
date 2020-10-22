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
#define M 20005
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m,k;
int a,b,c;
int main() {
	cin>>a>>b>>c;
	int i;
	int cur=a;
	for (i = 1; i <= 2*b; ++i) {
		if (cur*10/b==c) {
			break;
		}
		cur*=10;
		cur=cur%b;
	}
	if (i<=2*b) cout<<i<<endl;
	else cout<<-1<<endl;
	return 0;
}

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
#define N 100005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll l, r;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld",&l, &r);
		if (2*l<=r) {
			printf("%lld %lld\n", l, 2*l);
		} else {
			cout<<-1<<" "<<-1<<endl;
		}
	}
  return 0;
}

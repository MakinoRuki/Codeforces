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
#include <queue>
#define N 202
using namespace std;
typedef long long ll;
ll x, y, z;
int main() {
	cin>>x>>y>>z;
	ll tot = x/z + y/z;
	x %= z;
	y %= z;
	if (x + y < z) {
		cout<<tot<<" "<<0<<endl;
	} else {
		cout<<tot+1<<" ";
		if (x>y) cout<<z-x<<endl;
		else cout<<z-y<<endl;
	}
	return 0;
}

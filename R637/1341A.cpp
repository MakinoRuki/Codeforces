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
#define N 1000005
using namespace std;
typedef long long ll;
int n, m;
int t,a,b,c,d;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>a>>b>>c>>d;
		ll l1 = n*(a-b);
		ll r1 = n*(a+b);
		ll l2 = c-d;
		ll r2 = c+d;
		if (l2 <= r1 && r2 >= l1) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}

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
#define N 100005
using namespace std;
typedef long long ll;
int t, n;
ll u, v;
int main() {
	cin>>u>>v;
	if (u > v) {
		cout<<-1<<endl;
		return 0;
	}
	ll d = (v-u);
	if (d%2) {
		cout<<-1<<endl;
		return 0;
	}
	if (u ==v) {
		if (u==0) cout<<0<<endl;
		else {
			cout<<1<<endl;
			cout<<u<<endl;
		}
		return 0;
	}
	d /= 2;
	if ((d&u) == 0) {
		cout<<2<<endl;
		cout<<d<<" "<<(d^u)<<endl;
	} else {
		cout<<3<<endl;
		cout<<u<<" "<<d<<" "<<d<<endl;
	}
	return 0;
}

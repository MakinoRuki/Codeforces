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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string a, b;
int main() {
	cin>>a>>b;
	int ans=0;
	int cnt=0;
	int n = a.size();
	int m = b.size();
	int num=0;
	for (int i = 0; i < m-1; ++i) {
		if (b[i] != b[i+1]) num++;
	}
	num %= 2;
	for (int i = 0; i < m; ++i) {
		if (a[i] != b[i]) cnt++;
	}
	if (cnt%2==0) ans++;
	cnt %= 2;
	for (int i = m; i < n; ++i) {
		if (a[i-m] != b[0]) cnt ^= 1;
		cnt ^= num;
		if (a[i] != b.back()) cnt ^= 1;
		if (!cnt) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

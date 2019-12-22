#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 300005
using namespace std;
typedef long long ll;
int n;
ll a[N];
int main() {
	cin>>n;
	ll w = 0, b = 0;
	// 把格子黑白染色？？
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		if (i%2==0) {
			b += (a[i]+1)/2;
			w += a[i]/2;
		} else {
			w += (a[i]+1)/2;
			b += a[i]/2;
		}
	}
	cout<<min(b, w)<<endl;
	return 0;
}

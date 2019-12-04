#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 1000005
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n;
		int l, r;
		int minr = INT_MAX;
		int maxl = INT_MIN;
		for (int i = 0; i < n; ++i) {
			cin>>l>>r;
			minr = min(minr, r);
			maxl = max(maxl, l);
		}
		cout<<(maxl >= minr ? maxl-minr : 0)<<endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
int t, n, a, b;
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cin>>n>>a>>b;
		int res1;
		int res2;
		if (b-n+a+1 > b) {
			res1 = n-min(n, (b+1));
		} else {
			res1 = n-max(1, min(n, b-n+a+1));
		}
		res1= n-res1;
		res2 = min(a+b-1, n);
		cout<<res1<<" "<<res2<<endl;
	}
	return 0;
}

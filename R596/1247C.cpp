#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
int n, p;
bool check(int m, int i) {
	int cnt=0;
	int sum=0;
	while(m) {
		int i = 0;
		while((1LL<<i) <= (ll)m) {
			i++;
		}
		i--;
		sum += i+1;
		m -= (1LL<<i);
		cnt++;
	}
	if (cnt > i) return false;
	return sum >= i;
}
int main() {
	cin>>n>>p;
	int ans=-1;
	for (int i = 0; i <= 31; ++i) {
		//cout<<"i="<<i<<endl;
		int m = n-i*p;
		if (m < 0) continue;
		if (check(m, i)) {
			ans = (ans < 0 ? i : min(ans, i));
		}
	}
	cout<<ans<<endl;
	return 0;
}

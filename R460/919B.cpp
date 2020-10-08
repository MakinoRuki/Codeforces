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
#include <cmath>
#define N 5002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int k;
bool check(int x) {
	int res=0;
	while(x) {
		res+=x%10;
		x/=10;
	}
	return res==10;
}
int main() {
	cin>>k;
	vector<int> res;
	res.clear();
	for (int i = 1; i <= 11000000; ++i) {
		if (check(i)) {
			res.push_back(i);
		}
	}
	//cout<<res.size()<<endl;
	printf("%d\n", res[k-1]);
	return 0;
}

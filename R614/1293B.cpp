#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int main() {
	cin>>n;
	double ans=0.0;
	for (int i =1; i <=n; ++i) {
		ans += 1.0/(double)i;
	}
	printf("%.6lf\n", ans);
	return 0;
}

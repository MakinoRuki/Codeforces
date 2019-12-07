#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;
int t;
ll r,b,k;
ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x%y);
}
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		cin>>r>>b>>k;
		if (r>b) swap(r,b);
		if (r==b) cout<<"OBEY"<<endl;
		else {
			// 当gcd(r,b)=1,假设两个b之间存在最多的r，那么会有一个r*x-b*y=1。
			// 也就是r在某个b的pos+1的位置。这时需要1+(k-1)*r>=b。
			// 当gcd(r,b)>1,我们以gcd(r,b)为单位去看，也可以转化为gcd(r,b)=1的情况。
			int d = gcd(r,b);
			if (d+(k-1)*r>=b) {
				cout<<"OBEY"<<endl;
			} else {
				cout<<"REBEL"<<endl;
			}
		}
	}
	return 0;
}

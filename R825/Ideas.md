A. 0的个数差和不想等的位置数是否相等。

B. gcd(b1,b2)=a1,gcd(b2,b3)=a2,那么求出b2=lcm(a1,a2),b3=lcm(a2,a3)。然后如果gcd(b2,b3)!=a2则无解。后面的依此类推。

C. 两指针。如果区间左端点是l，那么a[i]-i+l-1>=0。当l增大的时候，可以作为右端点的i也会增大。

***D. 首先1的个数必须是偶数个才有解。然后就看相邻两个位置，如果都是0或者都是1，正好可以分到两串里，如果是01或者10，那么奇数对位置拿出1偶数对位置拿出0，使用shift操作就会变成00和11。***

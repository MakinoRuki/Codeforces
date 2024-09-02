A. 前k个字母重复n次。

C. n次重复，每次要k个字母都出现。如果答案是NO，那么每次重复找最后出现的字母。

***D. 纯组合数学题。对每个pair单独考虑，它被选择0到k次的期望。用到的组合数公式：i*C(k,i)=k*C(k-1, i-1); sum([i=0...k],C(k,i)*p^(k-i))=(p+1)^k.*** 

***E. 当在l和r的harbour之间的x位置加个新的harbour时，相当于是[l+1,x]之间的位置都减少v[l]xDIS[x,r]，而[x,r-1]之间的位置都加上(-v[l]+v[x])xSUMDIS[x,r]。所以用线段树维护det(v)和det(dis)。但同时要维护sum(v)和sum(dis)以及区间res。***

D. 如果k次之后，原来n=2^p*3^q*5^w最后剩下的结果是x=2^a*3^b*5^c诸如此类，那么概率就是2从p->a，3从q->b，5从w->c的概率。

   因此对于每个素因子d，dp出k步从p1到某个p2的概率，然后跟d^p2乘起来，再把每个次幂的结果相加得到sum{dp[k][p1->p2]*d^p2}，然后每个d的这个sum乘起来。

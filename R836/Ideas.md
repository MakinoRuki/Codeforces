B. n是奇数全1，n是偶数就1+3+(n-1)\*2。

C. 当x!=n时，n如果不放在x的位置放在之后的y，那么y%x=0,n%y=0,因此必然n%x=0。又因为字典序最小，因此从前往后找n能往后放的最靠后位置。

***D. 假设最小为x最大为y，强行假设y-x=n。这样S=n^2，相当于每个数都是n，要互不相同就前后两两匹配成2n，因此x+y=2n。这样x和y未必为整数，因此假设y-x=2n，则y+x=8n。求出x=3n，y=5n。*** 

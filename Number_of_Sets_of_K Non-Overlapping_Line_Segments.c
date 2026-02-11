Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly
k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. 
The k line segments do not have to cover all n points, and they are allowed to share endpoints.
Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

#define MOD 1000000007

long long modPow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int numberOfSets(int n,int k){
    long long res=1;
    int N=n+k-1;
    int K=2*k;
    if(K>N) return 0;
    for(int i=0;i<K;i++) 
       res=res*(N-i)%MOD;
    long long denom=1;
    for(int i=1;i<=K;i++) 
      denom=denom*i%MOD;
    res=res*modPow(denom,MOD-2)%MOD;
    return (int)res;
}

 

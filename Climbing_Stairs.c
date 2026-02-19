Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

int climbStairs(int n) {
    if(n<4)
     return n;
    int p1=1,p2=2,p3;
    for(int i=3;i<=n;i++){
        p3=p1+p2;
        p1=p2;
        p2=p3;
    }
    return p2;
}

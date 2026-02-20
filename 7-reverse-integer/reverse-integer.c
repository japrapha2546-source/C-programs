int reverse(int x){
    int rev=0;
    while(x){
        if(rev>214748364 || rev<-214748364) return 0; // overflow check
        rev = rev*10 + x%10;
        x /= 10;
    }
    return rev;
}
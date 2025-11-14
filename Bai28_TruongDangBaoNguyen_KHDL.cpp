#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 1000006
char A[max + 1];
long long B[max + 1];
long long GCD(long long a, long long b){        
    while(b != 0){
        long long temp;
        temp = a;
        a = b;
        b = temp % b;
    }
    return llabs(a);
}
long long LCM(long long a, long long b){            
    long long ans = GCD(a, b);
    return llabs(a/ans) * llabs(b);
}
int solve(){
    long long UCLN = 0;
    long long BCNN = 0;
    long long n = 0;
    long long t;
    fgets(A, sizeof(A), stdin);
    char *tmp = A;
    long long c = 0;
    while (sscanf(tmp,"%lld%n", &t, &n) == 1){                   
        if(t == 0) {                                
            printf("Day so khong co UCLN va BCNN.");
            return 0;
        }
        B[c] = t;
        c++;
        tmp += n;
    }
    if(c == 0){
        printf("Khong co UCLN va BCNN");
        return 0;
    }
    else{
        UCLN = B[0];
        BCNN = B[0];
        for(int i = 1; i < c; i++){
            printf("%lld\n", B[i]);
            UCLN = GCD(UCLN, B[i]);
            BCNN = LCM(BCNN, B[i]);
        }
        printf("UCLN:%lld\nBCNN:%lld", UCLN, BCNN);
        return 0;
    }
}
int main(){
    solve();
    return 0;
}


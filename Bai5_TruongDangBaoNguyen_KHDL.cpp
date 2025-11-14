#include <stdio.h>
#include <math.h>
#define max 1000006
char A[max + 1];
long long B[max +1];
int UCLN(int a, int b){       
    while(b != 0){
        int temp;
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int solve(){        
    fgets(A, sizeof(A), stdin);
    long long c = 0, t, n;
    char *tmp = A;
    while(sscanf(tmp, "%lld%n", &t, &n) == 1){
        if(t == 0) {
            printf("Khong co UCLN");
            return 0;
        }
        B[c++] = t;
        tmp += n;
        
    }
    if(c == 0){
        printf("Khong co UCLN");
        return 0;
    }
    long long ans = llabs(B[0]);
    for(int i = 1; i < c; i++){
        ans = UCLN(ans, llabs(B[i]));
    }
    printf("%lld", ans);
    return 0;
}
int main(){
    solve();
    return 0;
}

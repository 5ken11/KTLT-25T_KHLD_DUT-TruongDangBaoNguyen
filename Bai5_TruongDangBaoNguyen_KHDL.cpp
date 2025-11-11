#include <stdio.h>
#include <math.h>
int t1, t2;
int UCLN(int a, int b){
    if (b == 0) return a;
    return UCLN(b, a % b);
}
int solve(int a, int b){
    int ans = UCLN(a, b);
    int t3;
    while (scanf("%d", &t3) == 1){
        if(t3 == 0){
            printf("Không có UCLN");
            return;
        }
        ans = UCLN(ans, t3);
    }
    return ans;
}
int main(){
    scanf("%d %d", &t1, &t2);
    if(t1 == 0 || t2 == 0){
        printf("Không có UCLN");
        return 0;
    }
    else printf("%d", solve(t1, t2));
}

#include <stdio.h>
#include <math.h>
int t1, t2;
int UCLN(int a, int b){
    while (a != b){
        if (a > b) a -= b;
        else if (b > a) b -= a;
    }
    return a;
}
int solve(int a, int b){
    int ans = UCLN(a, b);
    int t3;
    scanf("%d", &t3);
    if(t3 != 0){
        return UCLN(ans, t3);
    }
    else return ans;
}
int main(){
    scanf("%d %d", &t1, &t2);
    printf("%d", solve(t1, t2));
}
#include <stdio.h>
#include <math.h>
#define max 100005
int GCD(int a, int b){
    while (a != b){
        if (a > b) a -= b;
        else if (b > a) b -= a;
    }
    return a;
}
int LCM(int a, int b){
    int ans = GCD(a, b);
    return (a * b)/ans;
}
int n;
int A[max + 1];
int main(){
    printf("Nhập só số hạng muốn tìm UCLN và BCNN:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int UCLN = GCD(A[0], A[1]);
    int BCNN = LCM(A[0], A[1]);
    for(int i = 2; i < n; i++){
        UCLN = GCD(UCLN, A[i]);
        BCNN = LCM(BCNN, A[i]);
    }
    printf("Uoc chung lon nhat cua day so la: %d\n", UCLN);
    printf("Boi chung nho nhat cua day so la: %d\n", BCNN);
    
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long GCD(long long a, long long b){            //Tính UCLN của 2 số.
    if (b == 0) return llabs(a);
    return GCD(b, a % b);
}
long long LCM(long long a, long long b){            // Tính BCNN của 2 số.
    long long ans = GCD(a, b);
    return llabs(a/ans) * llabs(b);
}
int solve(){
    long long UCLN = 0;
    long long BCNN = 0;
    long long n = 0;
    long long t;
    while (scanf("%lld", &t) == 1){                   //Đọc số trong dãy cho đến khi hết dữ liệu.
        if(t == 0) {                                //Nếu đọc được 0 -> Không có UCLN và BCNN
            printf("Day so khong co UCLN va BCNN.");
            return 0;
        }
        else{
            t = llabs(t);                           //Lấy giá trị tuyệt đối(Cho trường hợp số âm).
            if(n == 0){
                UCLN = t;                           //Khi chỉ đọc giá trị đầu tiên, UCLN và BCNN = chính giá trị đó.
                BCNN = t;
            }
            else{
                UCLN = GCD(UCLN, t);                //Tính UCLN của n số.
                BCNN = LCM(BCNN, t);                //Tính BCNN của n số
            }
            n++;
        }
    }
    if (n == 0) printf("Day so khong co UCLN va BCNN.");               //In kết quả.
    else{
        printf("Uoc chung lon nhat cua day so la: %lld\n", UCLN);
        printf("Boi chung nho nhat cua day so la: %lld\n", BCNN);
    }
    return 0;
}
int main(){
    solve();
    return 0;
}

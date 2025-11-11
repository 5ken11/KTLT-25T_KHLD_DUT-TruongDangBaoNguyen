#include <stdio.h>
#include <math.h>
int t1, t2;
int UCLN(int a, int b){                             //Tính UCLN của 2 số theo thuật toán Euclid.
    while(b != 0){
        int temp;
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int solve(int a, int b){                               
    int ans = UCLN(a, b);       
    int t3;
    while (scanf("%d", &t3) == 1){                 //Đọc giá trị của dữ liệu cho tới khi hết dữ liệu.
        if(t3 == 0){                               //Nếu giá trị đọc được bằng 0 thì không có UCLN.
            printf("Không có UCLN");
            return;
        }
        ans = UCLN(ans, t3);                       //Tính UCLN theo công thức UCLN(a1, a2, a3, ..., an) = UCLN(UCLN(a1, a2, a3, ..., an-1), an);
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


#include <stdio.h>
#include <math.h>

int n;
bool check(int n){
    int ans = n*n;                              //Tính bình phương của số cho trước.
    int result = 0;
    while(n > 0){
        int temp = n % 10;                      //Lấy từng chữ số của số cho trước.
        n = n / 10;
        result += temp*temp*temp;               //Tổng của các chữ số của số cho trước.
    }
    if(ans == result) return true;              //So sánh và trả về kết quả.
    else return false;                          
}
int main(){
    scanf("%d", &n);
    if(check(n)) printf("n^2 bằng tổng các lập phương các chữ số của n");           //In kết quả.
    else printf("n^2 không bằng tổng các lập phương các chữ số của n");

}

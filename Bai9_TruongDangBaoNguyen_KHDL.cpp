#include <stdio.h>
#include <math.h>

int main(){
    double ansa = 1; double ansb = -1.0/10000.0;
    for(int i = 1; i < 10000; i++){
        if((i + 1) % 2 == 0) ansa-= (1.0/(i + 1));             // Tính giá trị biểu thức 1 - 1/2 + 1/3 ...... + 1/9999 - 1/10000 theo chiều từ trái sang phải.
        else ansa += (1.0/(i + 1));                                         
        if ((10000 - i) % 2 == 0) ansb -= (1.0/(10000-i));     // Tính giá trị biểu thức 1 - 1/2 + 1/3 ...... + 1/9999 - 1/10000 theo chiều từ phải sang trái.
        else ansa += (1.0/(i + 1));
        else ansb += (1.0/(10000-i));                       
    }
    printf("Giá trị của biểu thức 1 - 1/2 + 1/3 - ... + 1/9999 - 1/10000 từ trái sang phải là: %lf\n", ansa);
    printf("Giá trị của biểu thức 1 - 1/2 + 1/3 - ... + 1/9999 - 1/10000 từ phải sang trái là: %lf\n", ansb);
    double s1 = 1; double s2 = 1.0/2;
    for(int i = 3; i < 10000; i += 2){
        s1 += 1.0/i;                              // Tính tổng 1 + 1/3 + ... + 1/9999
        s2 += 1.0/(i + 1);                        // Tính tổng 1/2 + 1/4 + ... + 1/10000
    }
    printf("s1 = %lf \ns2 = %lf\n", s1 , s2);     // So sánh.
    printf("s1 - s2 = %lf\n", s1 - s2);           
    printf("Từ kết quả câu b và câu c, ta thấy s = s1 - s2. Có sự khác nhau về kết quả giữa câu b và câu c là do s = s1 - s2.");

}

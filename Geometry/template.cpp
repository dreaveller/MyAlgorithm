/*
 * 计算几何模板
 */

#include <iostream>
#include <math.h>
using namespace std;

const double pi = acos(-1.0);
const double inf = 1e100;
const double eps = 1e-9;

int sgn(double d){
    if(fabs(d) < eps)
        return 0;
    if(d > 0)
        return 1;
    return -1;
}
int dcmp(double x, double y){
    if(fabs(x - y) < eps)
        return 0;
    if(x > y)
        return 1;
    return -1;
}
int main() {
    double x = 1.49999;
    int fx = floor(x);
    int cx = ceil(x);
    int rx = round(x);
    printf("%f %d %d %d\n", x, fx, cx, rx);
    //输出结果 1.499990 1 2 1
    return  0 ;
}
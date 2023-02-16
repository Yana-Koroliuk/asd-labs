#include <stdio.h>
#include <math.h>

float func4(float x);
float func2(float x, float i);


float result = 1;

int main() {
    printf("%f\n", func4(2));

    func2(2, 5);
    printf("%f \n", result);

    printf("%f", cos(2));
    return 0;

}

float func2(float x, float i) {
    if (i == 0) {
        return 1;
    }
    float fi = -func2(x, i-1)*x*x/(4*i*i-2*i);
    result += fi;
    return fi;
}

float func4(float x) {
    int n = 5;
    float res = 1;
    float fi = 1;
    for (int i = 1; i < n; i++) {
        float fi1 = (-fi*x*x)/(4*(float)i*(float)i-2*(float)i);
        fi = fi1;
        res += fi1;
    }
    return res;
}

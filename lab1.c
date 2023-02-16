#include <stdio.h>
#include <math.h>

float func1(float x, float n, float i, float fi);
struct Str func2(float x, float i);
float func4(float x);

struct Str {
    float fi;
    float sum;
};

int main() {
    printf("Recursion_1 result: %f\n", func1(2, 5, 1, 1));
    struct Str res2 = func2(2, 5);
    printf("Recursion_2 result: %f\n", res2.sum);
    printf("Iteration result: %f\n", func4(2));
    printf("Correct result: %f", cos(2));
    return 0;

}
float func1(float x, float n, float i, float fi) {
    if (n < i) {
        return 0;
    }
    if (i == 1) {
        float f1 = 1;
        return f1 + func1(x, n, i + 1, f1);
    }
    float fiNext = (-fi) * (x*x/(4*(i-1)*(i-1) - 2*(i-1)));
    return fiNext + func1(x, n, i + 1, fiNext);

}

struct Str func2(float x, float i) {
    static struct Str result = {1, 1};
    if (i == 0) {
        return result;
    }
    float fi = -func2(x, i-1).fi*x*x/(4*i*i-2*i);
    result.fi = fi;
    result.sum += fi;
    return result;
}

float func4(float x) {
    int n = 10;
    float res = 0;
    float fi = 1;
    for (int i = 1; i < n; i++) {
        res += fi;
        float fi1 = (-fi*x*x)/(4*(float)i*(float)i-2*(float)i);
        fi = fi1;
    }
    return res;
}
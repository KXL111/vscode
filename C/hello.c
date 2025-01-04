#include <stdio.h>

// 定义分数结构
typedef struct {
    int numerator;   // 分子
    int denominator; // 分母
} Fraction;

// 求最大公约数（用于约分）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 约分函数
Fraction simplify(Fraction f) {
    int common_divisor = gcd(f.numerator, f.denominator);
    f.numerator /= common_divisor;
    f.denominator /= common_divisor;
    return f;
}

// 分数加法
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return simplify(result);
}

int main() {
    Fraction fractions[100];  // 存储 1/1 到 1/100 的分数
    Fraction sum = {0, 1};    // 初始化和为 0/1

    // 初始化分数数组
    for (int i = 1; i <= 100; i++) {
        fractions[i - 1].numerator = 1;
        fractions[i - 1].denominator = i;
        fractions[i - 1] = simplify(fractions[i - 1]);
    }

    // 计算和
    for (int i = 0; i < 100; i++) {
        sum = add(sum, fractions[i]);
    }

    // 输出结果
    printf("The sum of the series is: %d/%d\n", sum.numerator, sum.denominator);
    return 0;
}

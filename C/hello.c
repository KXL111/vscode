#include <stdio.h>

// ��������ṹ
typedef struct {
    int numerator;   // ����
    int denominator; // ��ĸ
} Fraction;

// �����Լ��������Լ�֣�
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Լ�ֺ���
Fraction simplify(Fraction f) {
    int common_divisor = gcd(f.numerator, f.denominator);
    f.numerator /= common_divisor;
    f.denominator /= common_divisor;
    return f;
}

// �����ӷ�
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return simplify(result);
}

int main() {
    Fraction fractions[100];  // �洢 1/1 �� 1/100 �ķ���
    Fraction sum = {0, 1};    // ��ʼ����Ϊ 0/1

    // ��ʼ����������
    for (int i = 1; i <= 100; i++) {
        fractions[i - 1].numerator = 1;
        fractions[i - 1].denominator = i;
        fractions[i - 1] = simplify(fractions[i - 1]);
    }

    // �����
    for (int i = 0; i < 100; i++) {
        sum = add(sum, fractions[i]);
    }

    // ������
    printf("The sum of the series is: %d/%d\n", sum.numerator, sum.denominator);
    return 0;
}

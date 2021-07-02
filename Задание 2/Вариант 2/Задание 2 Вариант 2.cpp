#include <stdio.h>

struct Decimal {
	int a;
	int b;
};

int nod(int a, int b) {

	if (a == b) {
		return a;
	}
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	return nod(a, b - a);
}

struct Decimal multiply(struct Decimal d1, struct Decimal d2) {
	struct Decimal result;
	result.a = d1.a * d2.a;
	result.b = d1.b * d2.b;

	int c = nod(result.a, result.b);

	result.a /= c;
	result.b /= c;

	return result;
}

int main() {
	struct Decimal d1, d2, result;

	scanf("%d/%d", &d1.a, &d1.b);
	scanf("%d/%d", &d2.a, &d2.b);

	result = multiply(d1, d2);

	printf("%d/%d\n", result.a, result.b);

	return 0;
}

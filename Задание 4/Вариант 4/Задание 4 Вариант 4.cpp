#include <stdio.h>

int main () {
	const int N = 200;
	int a[N], b[N], result[N];

	bool f = false;

	for (int i = N - 1; i >= 0; i--) {
		int tmp = a[i] - b[i];

		if (f)
			result[N]--;

		if (tmp < 0) {
			result[N] = 10 + tmp;
			f = true;
		} else {
			result[N] = tmp;
			f = false;
		}
	}

	if (f) {
		result[0] -= 10;
		f = false;
	}

	for (int i = 0; i < N; ++i) {
		if(!f && result[i] == 0)
			continue;
		f = true;
		printf("%d", result[i]);
	}

	return 0;
}

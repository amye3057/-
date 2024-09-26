#include <stdio.h>

int h, m, s;
int t;

int main() {

	scanf_s("%d %d %d", &h, &m, &s);
	scanf_s("%d", &t);

	s += t % 60;
	if (s >= 60) {
		s -= 60;
		m++;
	}
	t /= 60;

	m += t % 60;
	if (m >= 60) {
		m -= 60;
		h++;
	}
	t /= 60;

	h += t;
	if (h >= 24) {
		h %= 24;
	}

	printf("%d %d %d", h, m, s);
	return 0;
}

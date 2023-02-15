int gcd1(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd1(y, x % y);
	}
}

int gcd2(int x, int y) {
	int temp;
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
	int rest;

	while (y != 0) {
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

#include <stdio.h>

void HanoiTower(int n, char from, char mid, char to) {

	if (n == 1) {
		printf("원반 %d를 %c에서 %c로 이동\n", n, from, to);
		return;
	}
	HanoiTower(n - 1, from, to, mid);
	printf("원반 %d를 %c에서 %c로 이동\n",n ,from, to);
	HanoiTower(n - 1, mid, from, to);

}

int main() {
		

	HanoiTower(3, 'A', 'B', 'C');

	return 0;
} 

#include <stdio.h>

int dow(int y, int m, int d) {
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {

    int myDoW = dow(1974, 10, 22);
	char str[10];

	printf("%i", myDoW);
	scanf("%s", str);
	
    // printf("Hello World!\n");
    
    return 0;   
}

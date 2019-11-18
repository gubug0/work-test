#include <stdio.h>

void octfunc(int* x, int minus);
void hexafunc(int* x, int minus);

char hexArray[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
	int input = 0;
	int mask; // 비교용 변수 mask 선언  
	int binary[33] = {0}; //2진수 값을 저장할 binary배열 선언
	int i, minus;

	printf("10진수 값을 입력하시오.: ");
	scanf("%d", &input);  //사용자의 입력을 input 변수에 담는다.
	if (input == 0) {
		return 0;
	}
	minus = input < 0;
	input = input < 0 ? -input : input;

	if (minus) {
		printf("-");
	}
	for (i = 31; i >= 0; i--) //i는 31~0까지 반복(32비트)
	{
		mask = 1 << i; // i만큼 왼쪽으로 이동한 것을 mask변수에 저장 
		binary[i] = input & mask ? 1 : 0;  // mask와 정수 input을 &연산해서 참이면 1, 거짓이면 0을 binary배열에 저장
		printf("%d", binary[i]); //2진수 값 하나씩 출력
		if (i % 8 == 0) {
			printf(" ");
		}
	}
	printf("\n");

	octfunc(binary, minus); //2진수를 8진수로 변환하는 함수
	hexafunc(binary, minus);  //2진수를 16진수로 변환하는 함수

	return 0;

}

void octfunc(int* x, int minus) {
	int i;
	if (minus) {
		printf("-");
	}
	for (i = 32; i >= 0; i -= 3) {
		printf("%c", hexArray[x[i] * 4 + x[i - 1] * 2 + x[i - 2]]);
	}

	printf("\n");
}
	
void hexafunc(int* x, int minus) {
	int i;

	if (minus) {
		printf("-");
	}
	for (i = 31; i >= 0; i -= 4) {
		printf("%c", hexArray[x[i] * 8 + x[i - 1] * 4 + x[i - 2] * 2 + x[i - 3] * 1]);
	}

	printf("\n");
}



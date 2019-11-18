#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int octfunc(int x);
int hexafunc(int y);

int main()
{
	int input = 0;
	int mask; // 비교용 변수 mask 선언  
	int binary[32]; //2진수 값을 저장할 binary배열 선언
	int rbinary; //최종 2진수 값
	int r=1;
	int i,j;

	printf("10진수 값을 입력하시오.: ");
	scanf("%d", &input);  //사용자의 입력을 input 변수에 담는다.
	if (input == 0) {
		return 0;
	}
	for (i = 31; i >= 0; i--) //i는 31~0까지 반복(32비트)
	{
		mask = 1 << i; // i만큼 왼쪽으로 이동한 것을 mask변수에 저장 
		binary[i] = input & mask ? 1 : 0;  // mask와 정수 input을 &연산해서 참이면 1, 거짓이면 0을 binary배열에 저장

	}
	for (j = 31; j >= 0; j--) {
		
		printf("%d", binary[j]); //2진수 값 하나씩 출력
		if (j % 8 == 0) printf(" ");
		r = r * 10;
		rbinary += binary[j] * r; // 2진수를 rbinary 변수에 저장
	}

	printf("\n");


	octfunc(rbinary); //2진수를 8진수로 변환하는 함수
	hexafunc(rbinary);  //2진수를 16진수로 변환하는 함수

}

int octfunc(int x) {
		int octalConstant[] = { 0, 1, 10, 11, 100, 101, 110, 111 };

		int octal, tempBinary;
		int digit, place, p;

		octal = 0;
		place = 1;



		tempBinary = x;  // 이진수 값을 tempBinary 변수에 복사한다.


		while (tempBinary != 0)
		{

			digit = tempBinary % 1000; //이진수의 끝에 있는 세자리를 추출한다.

			/* 3자리 이진수를 8진수로 변환한다. */
			for (p = 0; p < 8; p++)
			{
				if (octalConstant[p] == digit)
				{

					octal = (p * place) + octal;
					break;
				}
			}

			tempBinary /= 1000; //이진수의 끝에 있는 세자리를 제거한다.


			place *= 10; //place값을 증가시킨다.
		}


		printf("%d", octal); //8진수 출력

}
	
int hexafunc(int y) {
		int hexaConstant[] = { 0, 1, 10, 11, 100, 101, 110, 111,1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111 };

		char hexa;
		int tempBinary_2;
		int digit_2, place_2, q;

		place_2 = 1;

		char hexaArray[16];
		hexaArray[0] = '0';
		hexaArray[1] = '1';
		hexaArray[2] = '2';
		hexaArray[3] = '3';
		hexaArray[4] = '4';
		hexaArray[5] = '5';
		hexaArray[6] = '6';
		hexaArray[7] = '7';
		hexaArray[8] = '8';
		hexaArray[9] = '9';
		hexaArray[10] = 'A';
		hexaArray[11] = 'B';
		hexaArray[12] = 'C';
		hexaArray[13] = 'D';
		hexaArray[14] = 'E';
		hexaArray[15] = 'F';


		tempBinary_2 = y; //이진수 값을 tempBianry_2에 복사한다.


		while (tempBinary_2 != 0)
		{

			digit_2 = tempBinary_2 % 10000; //이진수의 끝에 있는 네자리를 추출한다.

			/* 네자리의 이진수와 동일한 16진수를 찾는다.  */
			for (q = 0; q < 16; q++)
			{
				if (hexaConstant[q] == digit_2)
				{

					switch (hexaConstant[q]) {

						hexa += hexaArray[q]*place_2;
						break;
					}
				}


				tempBinary_2 /= 10000; //이진수의 끝에 있는 네자리를 제거한다.


				place_2 *= 10; //place_2 값을 증가시킨다.
			}

			printf("%d", hexa); //16진수 출력
		}	
}



/* 월드 전자는 노트북을 제조하고 판매하는 회사이다. 노트북 판매 대수에 상관없이 매년 임대료, 재산세,	*/
/* 보험료, 급여 등 A만원의 고정 비용이 들며, 한 대의 노트북을 생산하는 데에는 재료비와 인건비 등 		*/
/* 총 B만원의 가변 비용이 든다고 한다. 예를 들어 A=1,000, B=70 이라고 하자. 이 경우 노트북을 한 대 	*/
/* 생산하는 데는 총 1,070만원이 들며, 열 대 생산하는 데는 총 1,700만원이 든다.						*/
/*																							*/ 
/* 노트북 가격이 C만원으로 책정되었다고 한다. 일반적으로 생간 대수를 늘려 가다 보면 어느 순간 			*/
/* 총 수입( =판매비용 )이 총 비용(=고정비용 + 가변비용) 보다 많아지게 된다. 최초로 총 수입이 총 비용보다*/
/* 많아져 이익이 발생하는 지점은 손익 분기점(BREAK-EVEN POINT)라고 한다.							*/

/* 입력 : 첫 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A,B,C < 2,100,000,000 인 자연수	*/
/* 출력 : 첫 번째 줄에 손익분기점 즉 최초로 이익이 발생하는 판매량을 출력한다. 손익분기점이 없을경우 -1 출력 */

#include<stdio.h>

int main() {
	// n > A/(B-C) 를 만족하는 가장 작은 n을 출력하는 것이고
	// 손익분기점이 발생하지 않는 경우는 b == c 인 경우이다.
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	if( c > b )	printf("%d\n", a/(c-b) + 1);
	else		printf("-1\n");
	
	return 0;
}
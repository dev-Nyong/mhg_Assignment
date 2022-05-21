#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compression(char* s) {
	//문자열길이를 변수 len에 저장
	//ex)s가 aaabccd일 때 len은 7
	int len = strlen(s);
	int i;
	int j = 0;
	// e는 뒤의 문자와 같은지 다른지 비교할 문자
	char e = s[0];
	//ss는 출력 문자열 ex)3ab2cd 
	char ss[1000] = { 0 };
	int count = 0;
	for (i = 0; i <= len; i++) {
		//len만큼 돌리는데 e하고 같으면 count 1 증가
		if (s[i] == e) {
			count++;
		}
		else {
			//count가 1일때 출력을 1a처럼 하지 않으므로 
			//count가 1이 아닐 때와 나눠주어야함
			if (count != 1) {
				ss[j] = count + '0';
				j++;
			}
			ss[j] = e;
			//e에게 다음 토스
			e = s[i];
			j++;
			//aaabccd에서 a중 b랑 다름을 알기 위해서는 
			//i = 3까지 가야함. 그래야 e인 a와 i[3]인 b를 비교해서 else로 넘어가는거
			//그래서 i가 문자열의 끝이 아닐 때 하나 감소시켜야 b부터 시작 할 수 있음
			//감소시키지 않는 순간 b는 고려되지 않고 c로 그냥 넘어감
			if (i != len) {
				i--;
			}
			//새로 시작할 때는 count를 0으로 초기화 해줘야함.
			count = 0;
		}
	}
	printf("%d", strlen(ss));
}
int main(void) {
	//s의 길이는 1 이상 1000 미만이니까 배열크기를 1000으로 둔다.
	char s[1000] = { 0 };
	scanf("%s", s);
	compression(s);
}
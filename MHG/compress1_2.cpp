#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compression(char* s) {
	//문자열길이를 변수 len에 저장
	//ex)s가 ab/ab/ab/cd일 때 len은 8
	int len = strlen(s);
	int i;
	int j = 0;
	int h = 0;
	//ss는 출력 문자열 ex)3abcd 
	char ss[1000] = { 0 };
	//ss = (char*)(malloc(sizeof(char*) * len));
	int count = 0;
	//2개씩 묶어서 보는거니까 길이가 7개일때 반번만 돌면 됨. 2+2+2
	for (i = 0; i < (len - 1) / 2; i++) {
		if (s[2 * i] == s[2 * (i + 1)] && s[2 * i + 1] == s[2 * (i + 1) + 1]) {
			//s[2*0]==s[2*(0 + 1)] &&s[2 * 0 + 1]==s[2 * (0 + 1) + 1
			//즉 s[0]와 s[2]가 같고 s[1]과 s[3]이 같을 때
			count++;
			//aaaa일 때 //마지막 문자열까지 비교를 다 했을 때
			if (i == (len - 1) / 2 - 1) {
				ss[j] = (count + 1) + '0';
				j++;
				ss[j] = s[2 * i];
				j++;
				ss[j] = s[2 * i + 1];
				j++;
			}
		}
		//abababxyz에서 x,y차례일 때
		else {
			//xy는 한번만 있으니까 1을 안써주기 위해서
			if (count == 0) {
				j == j;
			}
			else {
				ss[j] = (count + 1) + '0';
				j++;
			}
			ss[j] = s[2 * i];
			j++;
			ss[j] = s[2 * i + 1];
			j++;
			//i가 반을 다 돌았을 때 마지막 배열 2개 넣어주기
			if (i == ((len - 1) / 2) - 1) {
				ss[j] = s[2 * (i + 1)];
				j++;
				ss[j] = s[2 * (i + 1) + 1];
			}
			count = 0;
		}
	}
	printf("%s", ss);
	printf("\n");
	printf("%d", strlen(ss));
}
int main(void) {
	char s[1000] = { 0 };
	scanf("%s", s);
	compression(s);
}
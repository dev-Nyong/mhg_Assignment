#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int solution(char* s) {
	int i, j, index = 0;
	int len, shortest = 1000;
	char temp[1000] = "";
	char num[4];
	char str1[1000];
	char str2[1000];

	for (i = 1; i <= strlen(s) / 2; i++) {
		//strncpy 문자열 복사
		strncpy(str1, s, i);//str1 문자열에 s 문자열의 값을 i개의 인덱스(자를 문자의 단위 수)만큼 복사 
		str1[i] = '\0';
		len = 1;
		for (j = i; j < strlen(s); j += i) {
			index = 0;
			while (index < i)//str2 문자열에는 자를 문자의 단위 수만큼 저장
				str2[index++] = s[j + index];
			str2[index] = '\0';
			//strcmp 문자열 비교 같으면 0 str1<str2이면 음수 str1>str2이면 양수
			if (strcmp(str1, str2) == 0)//str1과 str2 문자열이 같으면 len에 1을 더함
				len++;
			else {//아니면 len의 값을 문자열로 변환하여 num문자열에 저장하고 temp 문자열에 붙여줌(len > 1)
				if (len > 1) {
					sprintf(num, "%d", len);
					//strcat num을 temp에 연결
					strcat(temp, num);
				}
				strcat(temp, str1);//temp 문자열에 str1 문자열을 붙여줌
				//str2를 str1에 복사
				strcpy(str1, str2);
				len = 1;
			}
		}
		if (len > 1) {//반복문이 끝나고 나서 남은 len값과 temp 문자열의 값을 temp 배열에 붙여줌
			sprintf(num, "%d", len);
			strcat(temp, num);
		}
		strcat(temp, str1);

		shortest = shortest <= strlen(temp) ? shortest : strlen(temp);//그동안의 temp 배열 중 가장 짧은 길이를 shortest에 저장
		temp[0] = '\0';
	}
	return shortest;//반복문이 끝나고 가장 짧은 길이를 반환
}

int main() {
	char str[1000];

	scanf("%s", str);
	printf("%d", solution(str));
}
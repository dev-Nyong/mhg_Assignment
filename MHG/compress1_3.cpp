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
		//strncpy ���ڿ� ����
		strncpy(str1, s, i);//str1 ���ڿ��� s ���ڿ��� ���� i���� �ε���(�ڸ� ������ ���� ��)��ŭ ���� 
		str1[i] = '\0';
		len = 1;
		for (j = i; j < strlen(s); j += i) {
			index = 0;
			while (index < i)//str2 ���ڿ����� �ڸ� ������ ���� ����ŭ ����
				str2[index++] = s[j + index];
			str2[index] = '\0';
			//strcmp ���ڿ� �� ������ 0 str1<str2�̸� ���� str1>str2�̸� ���
			if (strcmp(str1, str2) == 0)//str1�� str2 ���ڿ��� ������ len�� 1�� ����
				len++;
			else {//�ƴϸ� len�� ���� ���ڿ��� ��ȯ�Ͽ� num���ڿ��� �����ϰ� temp ���ڿ��� �ٿ���(len > 1)
				if (len > 1) {
					sprintf(num, "%d", len);
					//strcat num�� temp�� ����
					strcat(temp, num);
				}
				strcat(temp, str1);//temp ���ڿ��� str1 ���ڿ��� �ٿ���
				//str2�� str1�� ����
				strcpy(str1, str2);
				len = 1;
			}
		}
		if (len > 1) {//�ݺ����� ������ ���� ���� len���� temp ���ڿ��� ���� temp �迭�� �ٿ���
			sprintf(num, "%d", len);
			strcat(temp, num);
		}
		strcat(temp, str1);

		shortest = shortest <= strlen(temp) ? shortest : strlen(temp);//�׵����� temp �迭 �� ���� ª�� ���̸� shortest�� ����
		temp[0] = '\0';
	}
	return shortest;//�ݺ����� ������ ���� ª�� ���̸� ��ȯ
}

int main() {
	char str[1000];

	scanf("%s", str);
	printf("%d", solution(str));
}
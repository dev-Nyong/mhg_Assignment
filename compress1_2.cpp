#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compression(char* s) {
	//���ڿ����̸� ���� len�� ����
	//ex)s�� ab/ab/ab/cd�� �� len�� 8
	int len = strlen(s);
	int i;
	int j = 0;
	int h = 0;
	//ss�� ��� ���ڿ� ex)3abcd 
	char ss[1000] = { 0 };
	//ss = (char*)(malloc(sizeof(char*) * len));
	int count = 0;
	//2���� ��� ���°Ŵϱ� ���̰� 7���϶� �ݹ��� ���� ��. 2+2+2
	for (i = 0; i < (len - 1) / 2; i++) {
		if (s[2 * i] == s[2 * (i + 1)] && s[2 * i + 1] == s[2 * (i + 1) + 1]) {
			//s[2*0]==s[2*(0 + 1)] &&s[2 * 0 + 1]==s[2 * (0 + 1) + 1
			//�� s[0]�� s[2]�� ���� s[1]�� s[3]�� ���� ��
			count++;
			//aaaa�� �� //������ ���ڿ����� �񱳸� �� ���� ��
			if (i == (len - 1) / 2 - 1) {
				ss[j] = (count + 1) + '0';
				j++;
				ss[j] = s[2 * i];
				j++;
				ss[j] = s[2 * i + 1];
				j++;
			}
		}
		//abababxyz���� x,y������ ��
		else {
			//xy�� �ѹ��� �����ϱ� 1�� �Ƚ��ֱ� ���ؼ�
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
			//i�� ���� �� ������ �� ������ �迭 2�� �־��ֱ�
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
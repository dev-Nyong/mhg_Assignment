#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compression(char* s) {
	//���ڿ����̸� ���� len�� ����
	//ex)s�� aaabccd�� �� len�� 7
	int len = strlen(s);
	int i;
	int j = 0;
	// e�� ���� ���ڿ� ������ �ٸ��� ���� ����
	char e = s[0];
	//ss�� ��� ���ڿ� ex)3ab2cd 
	char ss[1000] = { 0 };
	int count = 0;
	for (i = 0; i <= len; i++) {
		//len��ŭ �����µ� e�ϰ� ������ count 1 ����
		if (s[i] == e) {
			count++;
		}
		else {
			//count�� 1�϶� ����� 1aó�� ���� �����Ƿ� 
			//count�� 1�� �ƴ� ���� �����־����
			if (count != 1) {
				ss[j] = count + '0';
				j++;
			}
			ss[j] = e;
			//e���� ���� �佺
			e = s[i];
			j++;
			//aaabccd���� a�� b�� �ٸ��� �˱� ���ؼ��� 
			//i = 3���� ������. �׷��� e�� a�� i[3]�� b�� ���ؼ� else�� �Ѿ�°�
			//�׷��� i�� ���ڿ��� ���� �ƴ� �� �ϳ� ���ҽ��Ѿ� b���� ���� �� �� ����
			//���ҽ�Ű�� �ʴ� ���� b�� ������� �ʰ� c�� �׳� �Ѿ
			if (i != len) {
				i--;
			}
			//���� ������ ���� count�� 0���� �ʱ�ȭ �������.
			count = 0;
		}
	}
	printf("%d", strlen(ss));
}
int main(void) {
	//s�� ���̴� 1 �̻� 1000 �̸��̴ϱ� �迭ũ�⸦ 1000���� �д�.
	char s[1000] = { 0 };
	scanf("%s", s);
	compression(s);
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void compression(char* s) {
	int len = strlen(s);
	int i;
	int j = 0;
	int h = 0;
	char ss[1000] = { 0 };
	//ss = (char*)(malloc(sizeof(char*) * len));
	int count = 0;
	//2���� ��� ���°Ŵϱ� ���̰� 7���϶� �ݹ��� ���� ��. 2+2+2
	for (i = 0; i < (len - 1) / 2; i++) {
		if (s[2 * i] == s[2 * (i + 1)] && s[2 * i + 1] == s[2 * (i + 1) + 1]) {
			count++;
			//aaaa�� ��
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
				//count�� 10�̻��� �Ǵ� ���� �ݺ��Ǵ� ���ڸ� ���� ĭ�� ��ĭ �� �ð� ��
				//count�� 9�̻��� �� (aaaa�� �������� ���� 1���� ���ϸ� �Ǳ⶧���� count�� 1�� �ǰ�
				//�����δ� aa�� �ι� �ݺ��ǹǷ� count+1 �� ����������
				if (count >= 9) {
					while (count >= 9) {
						ss[j] = ((count + 1) / 10) + '0';
						count = ((count + 1) % 10);
						j++;
					}
					if (count == 0) {
						ss[j] = 0 + '0';
						j++;
					}
					else {
						ss[j] = count + '0';
						j++;
					}
				}
				else {
					ss[j] = (count + 1) + '0';
					j++;
				}
			}
			ss[j] = s[2 * i];
			j++;
			ss[j] = s[2 * i + 1];
			j++;
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
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
	//2개씩 묶어서 보는거니까 길이가 7개일때 반번만 돌면 됨. 2+2+2
	for (i = 0; i < (len - 1) / 2; i++) {
		if (s[2 * i] == s[2 * (i + 1)] && s[2 * i + 1] == s[2 * (i + 1) + 1]) {
			count++;
			//aaaa일 때
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
				//count가 10이상이 되는 순간 반복되는 숫자를 적는 칸이 한칸 더 늘게 됨
				//count가 9이상일 때 (aaaa를 기준으로 보면 1번만 비교하면 되기때문에 count가 1이 되고
				//실제로는 aa가 두번 반복되므로 count+1 을 출력해줘야함
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
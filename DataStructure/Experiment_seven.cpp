/*ʵ���� ���Ĳ���ʵ��
һ��ʵ��Ŀ��
  1���ܹ��ø߼������������Ĵ洢�ṹ��
  2���ܹ��ø߼����Ա�д���Ļ����������㷨��ͨ�������������ȷ�ԣ�
  3. �ܹ����ô��Ļ�������������ĸ����ӵĲ������⡣
����ʵ������
  ������ô��Ƚϡ��󴮳��ͽ��Ӵ��Ȳ�����ʵ���Ӵ��Ķ�λ����Index(S,T,pos)��
����ʵ��Ҫ��
  1. ���ô��Ķ���˳��洢�򴮵Ķѷ���洢�ṹ�������������Ĵ���S����T����������������ĸ�Ԫ��ֵ��
  2. ��д�󴮵ĳ���StrLength(S)�����Ӵ�SubString(&sub,S,pos,len)�Ͷ����������бȽ�StrCompare(S, T)�Ĳ����㷨 ��
  3. ��д����������ɵĲ���ʵ���Ӵ��Ķ�λ����Index(S,T,pos)���㷨��
  4. ��д�������������������㷨����ȷ�ԡ�
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char *ch;
	int length;
}HString;
//�󳤶�
int StrLength(HString &S){
	int i;
	for(i = 0; S.ch[i] != '\0'; i++) ;
	S.length = i;
	return 1;
}
//���Ӵ�
int SubString(HString &sub, HString S, int pos, int len){
	sub.ch = (char *)malloc(len * sizeof(char));
	for(int i = 0; i < len; i++){
		sub.ch[i] = S.ch[pos-1];
		pos++;
	}
	return 1;
}
//���Ƚ�
int StrCompare(HString S, HString T){
	for(int i = 0; i < S.length && i < T.length; i++){
		if(S.ch[i] != T.ch[i])
			return 0;
	}
	return 1;
}
//�Ӵ���λ
int Index(HString S, HString T, int &pos){
	HString temp;
	int i; 
	for(i = 1; i <= S.length - T.length; i++){
		SubString(temp, S, i, T.length);
		StrLength(temp);
		if(StrCompare(temp,T)){
					pos = i;
					return 1;
		}
	}
	return 0;
}
int main(){
	HString S,T;
	int pos = -1;
	S.ch = (char *)malloc(25 * sizeof(char));
	printf("����������:");
	scanf("%s", S.ch);
	StrLength(S);
	printf("�������Ӵ�:");
	T.ch = (char *)malloc(25 * sizeof(char)); 
	scanf("%s", T.ch);
	StrLength(T);
	Index(S, T, pos);
	printf("�Ӵ��������е�λ���ǣ�%d\n", pos);
	return 0;
} 

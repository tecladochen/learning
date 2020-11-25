/*实验七 串的操作实验
一、实验目的
  1．能够用高级语言描述串的存储结构；
  2．能够用高级语言编写串的基本操作的算法并通过程序测试其正确性；
  3. 能够运用串的基本操作解决串的更复杂的操作问题。
二、实验内容
  编程利用串比较、求串长和截子串等操作来实现子串的定位操作Index(S,T,pos)。
三、实验要求
  1. 利用串的定长顺序存储或串的堆分配存储结构创建两个给定的串（S串和T串），并输出两串的各元素值。
  2. 编写求串的长度StrLength(S)、截子串SubString(&sub,S,pos,len)和对两个串进行比较StrCompare(S, T)的操作算法 。
  3. 编写利用上述完成的操作实现子串的定位操作Index(S,T,pos)的算法。
  4. 编写主函数测试上述操作算法的正确性。
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char *ch;
	int length;
}HString;
//求长度
int StrLength(HString &S){
	int i;
	for(i = 0; S.ch[i] != '\0'; i++) ;
	S.length = i;
	return 1;
}
//截子串
int SubString(HString &sub, HString S, int pos, int len){
	sub.ch = (char *)malloc(len * sizeof(char));
	for(int i = 0; i < len; i++){
		sub.ch[i] = S.ch[pos-1];
		pos++;
	}
	return 1;
}
//串比较
int StrCompare(HString S, HString T){
	for(int i = 0; i < S.length && i < T.length; i++){
		if(S.ch[i] != T.ch[i])
			return 0;
	}
	return 1;
}
//子串定位
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
	printf("请输入主串:");
	scanf("%s", S.ch);
	StrLength(S);
	printf("请输入子串:");
	T.ch = (char *)malloc(25 * sizeof(char)); 
	scanf("%s", T.ch);
	StrLength(T);
	Index(S, T, pos);
	printf("子串在主串中的位置是：%d\n", pos);
	return 0;
} 

//�ַ�����ʵ��
/*����ѡ�õ������Է���洢���ַ�����ʽ����Ҫ��Ϊ�˿��Բ��޶��ַ�������*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAXSTRELEN 255
typedef struct  {
	char ch[MAXSTRELEN];
	int length;
}SString;

//�ַ�����ʼ��,ͬʱҲ����ͨ����ʼ�������ַ������٣����¸�ֵ
InitStr(SString* string) {
	for (int i = 0; i < MAXSTRELEN; i++) {
		(*string).ch[i] = '\0';
	}
	(*string).length = 0;
}
//�ַ����������Ƶõ��ַ���
CreateString(SString *string, char *ch) {
	
	unsigned int i = 0;
	int length = StrLength(*string);
	while (i<strlen(ch))
	{		
		(*string).ch[i+length] = ch[i];
		(*string).length++;
		i++;
	}
}
//�ǳ�ʼ�������ַ���
CreateString2(SString *string, char *ch,int pos,int n) {

	unsigned int i = 0;
	int length = StrLength(*string);
	while (i< n)
	{
		(*string).ch[i+length] = ch[i+pos];
		(*string).length++;
		i++;
	}
}
//�ַ���S�ĵ�pos��λ�ÿ�ʼ����n���Ը����ַ���string
StrCat(SString *string, SString S, int pos ,int n) {
	CreateString2(string, S.ch, pos, n);
}

//�ַ�������
StrTraversal(SString string) {
	printf("%s\n", string.ch);
}

//�ַ�������
int StrLength(SString string) {
	return string.length;
}

//�ַ���Ϊ��
int StrEmpty(SString string) {
	return string.length ? string.length :0 ;
}

//���string>s�򷵻�������С�ڷ��ظ�������ȷ���0
int StrCompare(SString string, SString s) {
	int length_a = StrLength(string);
	int length_b = StrLength(s);
	int length = max(length_a, length_b);
	for (int i = 0; i <length; i++) {
		if (string.ch[i] != s.ch[i]) {
			return string.ch[i]- s.ch[i];
			break;
		}
	}
	return 0;
}

//�����ַ������ӳ�һ���ַ���
Concat(SString *string, SString S1, SString S2) {
	int length = S1.length + S2.length;
	StrCat(string, S1,0,S1.length);
	(*string).length = length;
	for (int i = 0; i < S2.length; i++) {
		(*string).ch[S1.length + i] = S2.ch[i];
	}
}

//��Sub����S�ĵ�pos���Է��𳤶�Ϊlen���Ӵ�
SubString(SString *Sub, SString string, int pos, int len) {
	for (int i = 0; i < len; i++) {
		(*Sub).ch[i] = string.ch[i + pos];
		(*Sub).length = len;
	}
}

//���Ӵ�λ�õĶ�λ����
/*
pos��ʾƥ�䴮��posλ֮��pos�ͷ���ֵ����0����
*/
int SubIndex(SString string, SString Sub, int pos) {
	int i = pos, j = 0;
	for (; i < StrLength(string) && j < StrLength(Sub);) {
		if (Sub.ch[j] == string.ch[i]) {
			j++;
			i++;
		}
		else {
			i++;
			j = 0;
		}
	}
	//return i;
		if (j == StrLength(Sub))
			return i-StrLength(Sub);
		else return -1;
}

//��V�滻S��������T��ȵĲ��ص����Ӵ�
StrReplace(SString*S, SString T, SString V,SString*D,int pi) {
	//���ӣ�  S:HELLOWORLD T:LLOW V:HELL
	//���Ȼ�ȡ�ַ���S��T������
	//SString D;
	//InitStr(&D);
	int slength = StrLength(*S);
	// ���㱻�滻�����滻���ĳ���.
	int nsrclen = StrLength(T);
	int nDstLen = StrLength(V);
	int nLen ;
	//S�ĺϲ���ʼ���ַ
	//int pi = 0;
	int p = SubIndex(*S, T, pi);
	if (p)
	{
		//����ҵ�
			//���㱻�滻��ǰ���ַ����ĳ���.
			nLen = (p - pi);
			StrCat(D,*S,pi,nLen);
			StrCat(D, V, 0, nDstLen);
			//StrCat(&D, T, p + nsrclen,nsrclen-p-pi);
			pi = p+nsrclen;
			StrReplace(S,T,V,D,pi);
	}
	else {
		StrCat(D, *S, pi, slength - pi);
	}
	StrTraversal(*D);
}

/*���ַ�����S�ĵ�pos��λ�ò����ַ���T������S���ز������ַ���*/
StrInsert(SString*S, SString T, int pos) {
	SString tmp;
	InitStr(&tmp);
	StrCat(&tmp, *S, 0, pos);
	StrCat(&tmp, T, 0, StrLength(T));
	StrCat(&tmp,*S,pos,StrLength(*S)-pos);
	//�Ƚ���S���٣�Ȼ���ٽ���tmp���Ƶ���S
	InitStr(S);
	StrCat(S, tmp, 0, StrLength(tmp));
}

//ɾ��pos��λ�ÿ�ʼ��len���ȵ��ַ����������ص�S��
StrRemove(SString*S, int pos, int len) {
	SString tmp;
	InitStr(&tmp);
	StrCat(&tmp, *S, 0, pos);
	StrCat(&tmp, *S, pos+len, StrLength(*S) - pos);
	//�Ƚ���S���٣�Ȼ���ٽ���tmp���Ƶ���S
	InitStr(S);
	StrCat(S, tmp, 0, StrLength(tmp));
}

//�����ַ�������Ӵ�,srcΪԴ�ַ�����stringΪƥ���ַ�����max_length_substringΪ���ص�����ַ���
int MaxLengthSubString(SString src,SString string,SString *maxsubstring) {
	int index;
	for (int j = StrLength(string); j > 0; j--) {
		for (int i = 0; i < j; i++) {
			SString sub;
			InitStr(&sub);
			SubString(&sub, string, i, j - i);
			index = SubIndex(src,sub,0);
			if (index >=0) {
				StrCat(maxsubstring, sub, 0, StrLength(sub));
				//StrTraversal(sub);
				return 0;//����0��ʾ�ҵ�
			}
		}
	}
	return -1;//����-1��ʾΪƥ��
}

int main(void) {
	SString string,s,slast,LAST;

	//��ʼ������
	InitStr(&string);
	//�ַ�����ʼ����������ڴ�ռ䣻������char[],����ֱ�ӱ�����ջ������malloc�ڴ�ռ�
	char ch[MAXSTRELEN];
	scanf("%s", ch);
	CreateString(&string, ch);
	
	//��ʼ������
	InitStr(&s);
	//�ַ�����ʼ����������ڴ�ռ䣻������char[],����ֱ�ӱ�����ջ������malloc�ڴ�ռ�
	char character[MAXSTRELEN];
	scanf("%s", character);
	CreateString(&s, character);


	//���ַ���������Ӵ�
	SString maxsubstring;
	InitStr(&maxsubstring);
	int tmps =MaxLengthSubString(string, s, &maxsubstring);
	if (tmps == 0) {
		StrTraversal(maxsubstring);
	}
	else {
		printf("no common str");
	}
	

	////��ʼ������
	//InitStr(&slast);
	////�ַ�����ʼ����������ڴ�ռ䣻������char[],����ֱ�ӱ�����ջ������malloc�ڴ�ռ�
	//char character2[MAXSTRELEN];
	//scanf("%s", character2);
	//CreateString(&slast, character2);

	//InitStr(&LAST);

	SString tmp;
	InitStr(&tmp);

	////�ַ�����ɾ��
	//StrRemove(&string, 2, 3);
	//StrTraversal(string);
	//�ַ����Ĳ���
	//StrInsert(&string, s, 2);
	//StrTraversal(string);

////��ȡ�Ӵ�
	//SString sub;
	//InitStr(&sub);
	////��ȡ�Ӵ�
	//SubString(&sub, string, 0, 3);
	//

	////�ַ�������
	//StrTraversal(string);
	//StrTraversal(sub);

	///*���ַ����ϲ�������slast��*/
	//Concat(&slast, string,s);
	//StrTraversal(slast);

	///*�ַ���������string��*/
	//StrCat(&string, s,0,s.length);
	//printf("%s\n", string.ch);
	//printf("%d\n", string.length);


	///*�ַ����Ƚ�*/
	//int tmp=StrCompare(string, s);

	/*�ַ����滻*/
	//StrReplace(&string, s, slast, &LAST,0);

	//�Ӵ�����λ��
	/*int tmp = SubIndex(string, s,0);
	printf("%d\n", tmp);*/
}
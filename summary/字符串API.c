//字符串的实现
/*这里选用的是线性分配存储的字符串形式，主要是为了可以不限定字符串长度*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAXSTRELEN 255
typedef struct  {
	char ch[MAXSTRELEN];
	int length;
}SString;

//字符串初始化,同时也可以通过初始化来将字符串销毁，重新赋值
InitStr(SString* string) {
	for (int i = 0; i < MAXSTRELEN; i++) {
		(*string).ch[i] = '\0';
	}
	(*string).length = 0;
}
//字符串常量复制得到字符串
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
//非初始化创建字符串
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
//字符串S的第pos个位置开始复制n个自负到字符串string
StrCat(SString *string, SString S, int pos ,int n) {
	CreateString2(string, S.ch, pos, n);
}

//字符串遍历
StrTraversal(SString string) {
	printf("%s\n", string.ch);
}

//字符串长度
int StrLength(SString string) {
	return string.length;
}

//字符串为空
int StrEmpty(SString string) {
	return string.length ? string.length :0 ;
}

//如果string>s则返回正数，小于返回负数，相等返回0
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

//两个字符串连接成一个字符串
Concat(SString *string, SString S1, SString S2) {
	int length = S1.length + S2.length;
	StrCat(string, S1,0,S1.length);
	(*string).length = length;
	for (int i = 0; i < S2.length; i++) {
		(*string).ch[S1.length + i] = S2.ch[i];
	}
}

//用Sub返回S的第pos字自符起长度为len的子串
SubString(SString *Sub, SString string, int pos, int len) {
	for (int i = 0; i < len; i++) {
		(*Sub).ch[i] = string.ch[i + pos];
		(*Sub).length = len;
	}
}

//求子串位置的定位函数
/*
pos表示匹配串第pos位之后，pos和返回值均从0计数
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

//用V替换S中所有与T相等的不重叠的子串
StrReplace(SString*S, SString T, SString V,SString*D,int pi) {
	//例子：  S:HELLOWORLD T:LLOW V:HELL
	//首先获取字符串S中T的索引
	//SString D;
	//InitStr(&D);
	int slength = StrLength(*S);
	// 计算被替换串和替换串的长度.
	int nsrclen = StrLength(T);
	int nDstLen = StrLength(V);
	int nLen ;
	//S的合并起始点地址
	//int pi = 0;
	int p = SubIndex(*S, T, pi);
	if (p)
	{
		//如果找到
			//计算被替换串前边字符串的长度.
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

/*在字符串的S的第pos个位置插入字符串T，并用S返回插入后的字符串*/
StrInsert(SString*S, SString T, int pos) {
	SString tmp;
	InitStr(&tmp);
	StrCat(&tmp, *S, 0, pos);
	StrCat(&tmp, T, 0, StrLength(T));
	StrCat(&tmp,*S,pos,StrLength(*S)-pos);
	//先将串S销毁，然后再将串tmp复制到串S
	InitStr(S);
	StrCat(S, tmp, 0, StrLength(tmp));
}

//删除pos个位置开始的len长度的字符串，并返回到S中
StrRemove(SString*S, int pos, int len) {
	SString tmp;
	InitStr(&tmp);
	StrCat(&tmp, *S, 0, pos);
	StrCat(&tmp, *S, pos+len, StrLength(*S) - pos);
	//先将串S销毁，然后再将串tmp复制到串S
	InitStr(S);
	StrCat(S, tmp, 0, StrLength(tmp));
}

//两个字符串的最长子串,src为源字符串，string为匹配字符串，max_length_substring为返回的最长子字符串
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
				return 0;//返回0表示找到
			}
		}
	}
	return -1;//返回-1表示为匹配
}

int main(void) {
	SString string,s,slast,LAST;

	//初始化部分
	InitStr(&string);
	//字符串初始化必须分配内存空间；或者用char[],这样直接保存在栈区不用malloc内存空间
	char ch[MAXSTRELEN];
	scanf("%s", ch);
	CreateString(&string, ch);
	
	//初始化部分
	InitStr(&s);
	//字符串初始化必须分配内存空间；或者用char[],这样直接保存在栈区不用malloc内存空间
	char character[MAXSTRELEN];
	scanf("%s", character);
	CreateString(&s, character);


	//两字符串最长公共子串
	SString maxsubstring;
	InitStr(&maxsubstring);
	int tmps =MaxLengthSubString(string, s, &maxsubstring);
	if (tmps == 0) {
		StrTraversal(maxsubstring);
	}
	else {
		printf("no common str");
	}
	

	////初始化部分
	//InitStr(&slast);
	////字符串初始化必须分配内存空间；或者用char[],这样直接保存在栈区不用malloc内存空间
	//char character2[MAXSTRELEN];
	//scanf("%s", character2);
	//CreateString(&slast, character2);

	//InitStr(&LAST);

	SString tmp;
	InitStr(&tmp);

	////字符串的删除
	//StrRemove(&string, 2, 3);
	//StrTraversal(string);
	//字符串的插入
	//StrInsert(&string, s, 2);
	//StrTraversal(string);

////获取子串
	//SString sub;
	//InitStr(&sub);
	////获取子串
	//SubString(&sub, string, 0, 3);
	//

	////字符串遍历
	//StrTraversal(string);
	//StrTraversal(sub);

	///*两字符串合并保存在slast中*/
	//Concat(&slast, string,s);
	//StrTraversal(slast);

	///*字符串拷贝到string中*/
	//StrCat(&string, s,0,s.length);
	//printf("%s\n", string.ch);
	//printf("%d\n", string.length);


	///*字符串比较*/
	//int tmp=StrCompare(string, s);

	/*字符串替换*/
	//StrReplace(&string, s, slast, &LAST,0);

	//子串索引位置
	/*int tmp = SubIndex(string, s,0);
	printf("%d\n", tmp);*/
}
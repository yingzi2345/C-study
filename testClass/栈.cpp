//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//#define MAXSIZE 100
//
//// 栈的定义
//typedef struct {
//	char data[MAXSIZE];
//	int top;
//} Stack;
//
//// 初始化栈
//void InitStack(Stack* S) {
//	if (S == NULL) return;
//	S->top = -1;
//	// 初始化栈数据为0
//	memset(S->data, 0, sizeof(S->data));
//}
//
//// 判断栈是否为空
//int StackEmpty(Stack* S) {
//	if (S == NULL) return 1;
//	return S->top == -1;
//}
//
//// 判断栈是否已满
//int StackFull(Stack* S) {
//	if (S == NULL) return 1;
//	return S->top == MAXSIZE - 1;
//}
//
//// 获得栈顶元素
//char GetTop(Stack* S) {
//	if (StackEmpty(S)) {
//		return '\0';
//	}
//	return S->data[S->top];
//}
//
//// 进栈
//int Push(Stack* S, char ch) {
//	if (S == NULL || StackFull(S)) {
//		return 0;
//	}
//	S->top++;
//	S->data[S->top] = ch;
//	return 1;
//}
//
//// 出栈
//int Pop(Stack* S, char* ch) {
//	if (S == NULL || StackEmpty(S) || ch == NULL) {
//		return 0;
//	}
//	*ch = S->data[S->top];
//	S->top--;
//	return 1;
//}
//
//// 安全的字符串输入函数
//void SafeInput(char* buffer, int maxSize) {
//	if (buffer == NULL) return;
//
//	printf("请输入字符串: ");
//
//	// 清空输入缓冲区
//	int c;
//	while ((c = getchar()) != '\n' && c != EOF);
//
//	// 安全的输入方式
//	if (fgets(buffer, maxSize, stdin) != NULL) {
//		// 移除换行符
//		size_t len = strlen(buffer);
//		if (len > 0 && buffer[len - 1] == '\n') {
//			buffer[len - 1] = '\0';
//		}
//	}
//	else {
//		buffer[0] = '\0';
//	}
//}
//
//// 判断是否为回文（简化版本）
//int IsPalindromeSimple(char* str) {
//	if (str == NULL || str[0] == '\0') {
//		return 1;
//	}
//
//	int len = strlen(str);
//	if (len >= MAXSIZE) {
//		printf("字符串过长，请缩短字符串\n");
//		return 0;
//	}
//
//	// 直接使用数组而不是动态内存
//	char stack[MAXSIZE];
//	int top = -1;
//
//	// 入栈
//	for (int i = 0; i < len; i++) {
//		if (top >= MAXSIZE - 1) {
//			break;
//		}
//		stack[++top] = str[i];
//	}
//
//	// 出栈比较
//	for (int i = 0; i < len; i++) {
//		if (top < 0) break;
//		if (stack[top--] != str[i]) {
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
//// 测试基本栈操作
//void TestBasicStack() {
//	printf("=== 测试基本栈操作 ===\n");
//
//	Stack s;
//	InitStack(&s);
//
//	// 测试进栈
//	printf("1. 测试进栈: ");
//	for (char c = 'A'; c <= 'C'; c++) {
//		if (Push(&s, c)) {
//			printf("%c ", c);
//		}
//	}
//	printf("\n");
//
//	// 测试栈顶
//	printf("2. 栈顶元素: %c\n", GetTop(&s));
//
//	// 测试出栈
//	printf("3. 测试出栈: ");
//	char ch;
//	while (Pop(&s, &ch)) {
//		printf("%c ", ch);
//	}
//	printf("\n");
//
//	// 测试空栈
//	printf("4. 空栈测试: ");
//	if (!Pop(&s, &ch)) {
//		printf("空栈出栈正确返回失败\n");
//	}
//	printf("栈顶元素: %c\n", GetTop(&s));
//}
//
//// 主函数
//int main() {
//	printf("=== 回文判断程序 ===\n");
//
//	// 先测试基本栈操作
//	TestBasicStack();
//
//	printf("\n=== 回文判断测试 ===\n");
//
//	char input[MAXSIZE] = { 0 };
//
//	// 安全输入
//	SafeInput(input, sizeof(input));
//
//	printf("您输入的字符串: \"%s\"\n", input);
//	printf("字符串长度: %zu\n", strlen(input));
//
//	if (strlen(input) == 0) {
//		printf("输入为空字符串\n");
//		return 0;
//	}
//
//	// 使用简化版本判断回文
//	if (IsPalindromeSimple(input)) {
//		printf("结果: 是回文\n");
//	}
//	else {
//		printf("结果: 不是回文\n");
//	}
//	printf("\n程序正常结束\n");
//	return 0;
//}
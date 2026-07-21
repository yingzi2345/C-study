//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// 单链表结点定义
//typedef struct LNode {
//	int data;           // 数据域
//	struct LNode* next; // 指针域
//} LNode, * LinkList;
//
//// 1. 初始化单链表（带头结点）
//int InitList(LinkList* L) {
//	*L = (LNode*)malloc(sizeof(LNode));
//	if (*L == NULL) {
//		return 0; // 内存分配失败
//	}
//	(*L)->data = 0;  // 头结点数据域初始化为0（用于存储长度）
//	(*L)->next = NULL;
//	return 1;
//}
//
//// 2. 尾插法创建单链表
//void CreateList_Tail(LinkList L, int arr[], int n) {
//	LNode* r = L; // 尾指针指向头结点
//	for (int i = 0; i < n; i++) {
//		LNode* p = (LNode*)malloc(sizeof(LNode));
//		p->data = arr[i];
//		p->next = NULL;
//		r->next = p;
//		r = p;
//		L->data++; // 长度加1
//	}
//}
//
//// 3. 在指定位置插入元素
//int ListInsert(LinkList L, int i, int e) {
//	if (i < 1) return 0; // 位置不合法
//
//	LNode* p = L;
//	int j = 0;
//
//	// 寻找第i-1个结点
//	while (p != NULL && j < i - 1) {
//		p = p->next;
//		j++;
//	}
//
//	if (p == NULL) return 0; // 位置不合法
//
//	LNode* s = (LNode*)malloc(sizeof(LNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	L->data++; // 长度加1
//	return 1;
//}
//
//// 4. 删除指定位置的元素
//int ListDelete(LinkList L, int i, int* e) {
//	if (i < 1) return 0; // 位置不合法
//
//	LNode* p = L;
//	int j = 0;
//
//	// 寻找第i-1个结点
//	while (p != NULL && j < i - 1) {
//		p = p->next;
//		j++;
//	}
//
//	if (p == NULL || p->next == NULL) return 0; // 位置不合法
//
//	LNode* q = p->next;
//	*e = q->data;
//	p->next = q->next;
//	free(q);
//	L->data--; // 长度减1
//	return 1;
//}
//
//// 5. 按值查找
//LNode* LocateElem(LinkList L, int e) {
//	LNode* p = L->next; // 从第一个元素结点开始
//	while (p != NULL) {
//		if (p->data == e) {
//			return p;
//		}
//		p = p->next;
//	}
//	return NULL; // 未找到
//}
//
//// 6. 按位置查找
//int GetElem(LinkList L, int i, int* e) {
//	if (i < 1) return 0; // 位置不合法
//
//	LNode* p = L->next; // 从第一个元素结点开始
//	int j = 1;
//
//	while (p != NULL && j < i) {
//		p = p->next;
//		j++;
//	}
//
//	if (p == NULL) return 0; // 位置不合法
//
//	*e = p->data;
//	return 1;
//}
//
//// 7. 按值删除（删除第一个遇到的指定值）
//int DeleteByValue(LinkList L, int e) {
//	LNode* p = L;
//
//	while (p->next != NULL) {
//		if (p->next->data == e) {
//			LNode* q = p->next;
//			p->next = q->next;
//			free(q);
//			L->data--; // 长度减1
//			return 1;
//		}
//		p = p->next;
//	}
//	return 0; // 未找到
//}
//
//// 8. 输出单链表（包含头结点）
//void PrintList(LinkList L) {
//	LNode* p = L; // 从头结点开始
//	printf("单链表元素序列（长度=%d）: ", L->data);
//	while (p != NULL) {
//		printf("%d", p->data);
//		if (p->next != NULL) {
//			printf(" -> ");
//		}
//		p = p->next;
//	}
//	printf("\n");
//}
//
//// 9. 输出单链表（不包含头结点，仅数据元素）
//void PrintListData(LinkList L) {
//	LNode* p = L->next; // 从第一个元素结点开始
//	printf("数据元素序列: ");
//	while (p != NULL) {
//		printf("%d", p->data);
//		if (p->next != NULL) {
//			printf(" -> ");
//		}
//		p = p->next;
//	}
//	printf("\n");
//}
//
//int main() {
//	LinkList link1, link2;
//	int i, value, result;
//
//	// 初始化随机数种子
//	srand((int)time(0));
//
//	printf("========== 单链表基本操作演示 ==========\n\n");
//
//	// (1) 定义单链表link1，用尾插入法创建link1
//	printf("(1) 创建单链表link1\n");
//	InitList(&link1);
//
//	int arr1[] = { 10, 20, 30, 40, 50, 60 };
//	int n1 = sizeof(arr1) / sizeof(arr1[0]);
//
//	CreateList_Tail(link1, arr1, n1);
//	printf("创建后的link1: ");
//	PrintListData(link1);
//	printf("\n");
//
//	// (2) 计算link1的长度并输出（包含头结点）
//	printf("(2) 计算link1长度并输出完整链表\n");
//	printf("link1的长度为: %d\n", link1->data);
//	PrintList(link1);
//	printf("\n");
//
//	// (3) 定义单链表link2，插入10个随机数
//	printf("(3) 创建单链表link2（插入10个随机数）\n");
//	InitList(&link2);
//
//	for (i = 0; i < 10; i++) {
//		int random_num = rand() % 200 + 1;
//		ListInsert(link2, i + 1, random_num);
//	}
//
//	printf("插入后的link2: ");
//	PrintListData(link2);
//	printf("\n");
//
//	// (4) 查找link1中第i个元素
//	printf("(4) 查找link1中第i个元素\n");
//	printf("请输入要查找的位置i: ");
//	scanf_s("%d", &i);
//
//	if (GetElem(link1, i, &value)) {
//		printf("第%d个元素的值是: %d\n", i, value);
//	}
//	else {
//		printf("位置%d不合法或不存在！\n", i);
//	}
//	printf("\n");
//
//	// (5) 在link1中查找并删除指定值
//	printf("(5) 在link1中查找并删除指定值\n");
//	printf("请输入要查找并删除的数: ");
//	scanf_s("%d", &value);
//
//	if (LocateElem(link1, value) != NULL) {
//		if (DeleteByValue(link1, value)) {
//			printf("删除成功！删除后的link1: ");
//			PrintListData(link1);
//		}
//		else {
//			printf("删除失败！\n");
//		}
//	}
//	else {
//		printf("找不到数值%d！\n", value);
//	}
//	printf("\n");
//
//	// (6) 删除link2中第i个元素
//	printf("(6) 删除link2中第i个元素\n");
//	printf("请输入要删除的位置i: ");
//	scanf_s("%d", &i);
//
//	if (ListDelete(link2, i, &value)) {
//		printf("删除成功！删除的元素值是: %d\n", value);
//		printf("删除后的link2: ");
//		PrintListData(link2);
//	}
//	else {
//		printf("删除失败！位置%d不存在！\n", i);
//	}
//	printf("\n");
//
//	// 释放内存
//	LNode* p = link1;
//	while (p != NULL) {
//		LNode* temp = p;
//		p = p->next;
//		free(temp);
//	}
//
//	p = link2;
//	while (p != NULL) {
//		LNode* temp = p;
//		p = p->next;
//		free(temp);
//	}
//
//	printf("程序执行完毕！\n");
//
//	return 0;
//}
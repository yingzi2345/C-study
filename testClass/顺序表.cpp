//#include<stdio.h>
//#include<stdlib.h>
//
//typedef int Datatype;
//
//struct list
//{
//	int Max;//顺序表的最大元素个数
//	int n;//实际元素个数
//	Datatype* elem;//首地址
//};
//typedef struct list* X;//X表示struct list *
//
////顺序表初始化：构建一个最大的元素个数为m的空的顺序表
//X SetNull_List(int m) {
//	X A;  //X是顺序表类型  A是变量名
//	A = (X)malloc(sizeof(struct list));
//	if (A != NULL) {
//		A->elem = (Datatype*)malloc(sizeof(Datatype) * m);
//		if (A->elem != NULL) {
//			A->Max = m;
//			A->n = 0;
//			return A;
//		}
//		else {
//			free(A);
//		}
//	}
//	printf("空间不足");
//	return NULL;
//}
//
////顺序表的插入  插入成功返回1  失败返回0
//int Insert_List(X A, Datatype value, int i) {
//	if (A->n >= A->Max) {  //顺序表满
//		printf("溢出");
//		return 0;   //插入失败
//	}
//
//	if (i < 0 || i > A->n) {
//		printf("下标不合法");
//		return 0;   //插入失败
//	}
//	//移动数据元素
//	for (int j = A->n - 1; j >= i; j--)
//	{
//		A->elem[j + 1] = A->elem[j];
//	}
//	A->elem[i] = value;//在i位置中插入值value
//	A->n = A->n + 1;
//	return 1;    //插入成功
//}
//
////删除顺序表中第i个元素
//int Delete_List(X A, int i) {
//	if (i < 0 || i >= A->n) {
//		printf("下标不合法");
//		return 0;   //删除失败
//	}
//
//	//移动数据元素
//	for (int j = i; j < A->n - 1; j++)
//	{
//		A->elem[j] = A->elem[j + 1];
//	}
//	A->n = A->n - 1;
//	return 1;    //删除成功
//}
//
////定位函数：查找元素value在顺序表中的位置，找到返回位置，找不到返回-1
//int Locate_List(X A, Datatype value) {
//	for (int i = 0; i < A->n; i++) {
//		if (A->elem[i] == value) {
//			return i; // 找到，返回位置
//		}
//	}
//	return -1; // 没找到
//}
//
////合并两个有序顺序表（假设都是升序）
//X Merge_List(X La, X Lb) {
//	X Lc = SetNull_List(La->n + Lb->n);
//	if (Lc == NULL) {
//		return NULL;
//	}
//
//	int i = 0, j = 0, k = 0;
//
//	// 合并两个有序表
//	while (i < La->n && j < Lb->n) {
//		if (La->elem[i] <= Lb->elem[j]) {
//			Insert_List(Lc, La->elem[i], k++);
//			i++;
//		}
//		else {
//			Insert_List(Lc, Lb->elem[j], k++);
//			j++;
//		}
//	}
//
//	// 将La剩余元素插入
//	while (i < La->n) {
//		Insert_List(Lc, La->elem[i], k++);
//		i++;
//	}
//
//	// 将Lb剩余元素插入
//	while (j < Lb->n) {
//		Insert_List(Lc, Lb->elem[j], k++);
//		j++;
//	}
//
//	return Lc;
//}
////打印函数
//void dayin(X A) {
//	int i;
//	for (i = 0; i < A->n; i++)
//	{
//		printf("%3d", A->elem[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	X La, Lb, Lc;
//	int i;
//	La = SetNull_List(10);
//	Lb = SetNull_List(10);
//
//	//La的个数：
//	for (i = 0; i < 5; i++)
//	{
//		Insert_List(La, 2 * i + 1, i);
//	}
//	printf("La中的元素有：");
//	dayin(La);
//
//	//Lb的个数：
//	for (i = 0; i < 5; i++)
//	{
//		Insert_List(Lb, 2 * i + 2, i);
//	}
//	printf("Lb中的元素有：");
//	dayin(Lb);
//
//	// (5) 调用删除函数删除La的第1个元素并输出删除后的La
//	printf("\n(5) 删除La的第一个元素后：");
//	Delete_List(La, 0);
//	dayin(La);
//
//	// (6) 由用户输入一个数，查找是否在Lb中，如果在则删除
//	Datatype num;
//	printf("\n(6) 请输入要查找的数字：");
//	scanf_s("%d", &num);
//
//	int pos = Locate_List(Lb, num);
//	if (pos != -1) {
//		printf("数字 %d 在Lb中，位置为 %d，正在删除...\n", num, pos);
//		Delete_List(Lb, pos);
//		printf("删除后的Lb：");
//		dayin(Lb);
//	}
//	else {
//		printf("数字 %d 不在Lb中\n", num);
//		printf("Lb保持不变：");
//		dayin(Lb);
//	}
//
//	// (7) 调用合并函数将La和Lb合并成Lc
//	printf("\n(7) 合并La和Lb：\n");
//	Lc = Merge_List(La, Lb);
//	printf("合并后的Lc：");
//	dayin(Lc);
//
//	// 释放内存
//	free(La->elem);
//	free(La);
//	free(Lb->elem);
//	free(Lb);
//	free(Lc->elem);
//	free(Lc);
//
//	return 0;
//}
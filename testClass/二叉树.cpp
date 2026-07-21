//#include<stdio.h>
//#include<stdlib.h>
//
////二叉树的二叉链表  类型定义
//struct node {
//	char data;//数据域
//	struct node* lchild;//左孩子指针域
//	struct node* rchild;//右孩子指针域
//};
//typedef struct node* BNode;//二叉树的结点别名
//typedef struct node* BTree;//二叉树别名
//
////创建二叉树   用扩展的先序序列创建  空结点用@表示
////先序序列  根节点\遍历左子树\遍历右子树
//BTree Create_BTree() {
//	char ch; //定义字符变量
//	BTree bt;  //定义二叉树类型的变量
//	scanf_s("%c", &ch);
//	if (ch == '@') {
//		bt = NULL;
//	}
//	else {
//		bt = (BTree)malloc(sizeof(struct node));//申请结点空间
//		bt->data = ch; //数据域赋值
//		bt->lchild = Create_BTree();//递归创建左子树
//		bt->rchild = Create_BTree();//递归创建右子树
//	}
//	return bt;
//}
//
////先序遍历  递归方式
//void Prepost_BTree(BTree bt) {
//	if (bt == NULL) {  //空树、空结点
//		return;
//		//修改函数类型 int 空的时候返回0   不空返回1
//	}
//	printf("%c", bt->data);  //访问根节点  打印结点的数据域
//	Prepost_BTree(bt->lchild);//先序遍历左子树
//	Prepost_BTree(bt->rchild);//先序遍历右子树
//}
//
////中序遍历  
//int Inpost_BTree(BTree bt) {
//	if (bt == NULL) {  //空树、空结点
//		return 0;
//		//修改函数类型 int 空的时候返回0   不空返回1
//	}
//	Inpost_BTree(bt->lchild);//先序遍历左子树
//	printf("%c", bt->data);  //访问根节点  打印结点的数据域
//	Inpost_BTree(bt->rchild);//先序遍历右子树
//	return 1;
//}
//
////后序遍历  
//int post_BTree(BTree bt) {
//	if (bt == NULL) {  //空树、空结点
//		return 0;
//		//修改函数类型 int 空的时候返回0   不空返回1
//	}
//	post_BTree(bt->lchild);//先序遍历左子树
//	post_BTree(bt->rchild);//先序遍历右子树
//	printf("%c", bt->data);  //访问根节点  打印结点的数据域
//	return 1;
//}
//
////统计二叉树的叶子结点数
//int CountLeafNode(BTree bt) {
//	if (bt == NULL) {
//		return 0;   //递归调用的结束条件
//	}
//	else {     //左、右子树都为空，是叶子
//		if ((bt->lchild == NULL) && (bt->rchild == NULL)) {
//			return 1;
//		}
//		else {    //递归遍历左子树和右子数
//			return(CountLeafNode(bt->lchild) + CountLeafNode(bt->rchild));
//		}
//	}
//}
//
////计算二叉树的深度
//int CountLevel(BTree bt) {
//	if (bt ==NULL) {
//		return 0;   //如果空则返回0
//	}
//	else {
//		int i = CountLevel(bt->lchild);   //递归计算左子树的深度
//		int j = CountLevel(bt->rchild);   //递归计算右子树的深度
//		return(i>j?i:j)+1;                //返回两个子树中高的深度+1
//	}
//}
//
//int main() {
//	BTree T;    //主函数中二叉树类型的变量T声明
//	T = Create_BTree();   //二叉树的创建
//	if (T != NULL) {
//		printf("\n二叉树创建完成");
//	}
//	printf("\n二叉树先序遍历的结果是：");
//	Prepost_BTree(T);
//	printf("\n二叉树中序遍历的结果是：");
//	Inpost_BTree(T);
//	printf("\n二叉树后序遍历的结果是：");
//	post_BTree(T);
//	printf("\n二叉树的叶子结点数为：%d", CountLeafNode(T));
//	printf("\n二叉树的深度为:%d",CountLevel(T));
//	return 0;
//}
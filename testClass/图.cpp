#include<stdio.h>

#include<stdlib.h>



// 邻接矩阵   二维数组   二维数组的大小  与图的顶点数相关 

struct GraphMatrix {

	int n;        //图中顶点数  n=6

	int** graph;  //二维数组  申请空间 n*n 

	// 存顶点信息  不限于 整数 / 字符  char * vex; vex[]={0,1,2,3,4,5}  vex[]={A,B,C,D,E,F} 

	// 申请空间大小 n 

};

typedef struct GraphMatrix* GM;  // 取别名

void DFS(GM g, int* visited, int i);  // 函数声明 



// 创建图 存储形式是邻接矩阵   size*size方阵 

GM  create_GraphMatrix(int size) {

	int i, j;

	GM g = (GM)malloc(sizeof(struct GraphMatrix));

	if (g != NULL) {

		g->n = size;  // 图的顶点数赋初值

		g->graph = (int**)malloc(sizeof(int*) * g->n);   //注意

		for (i = 0;i < g->n;i++) {

			g->graph[i] = (int*)malloc(sizeof(int) * g->n);   // 完成二维数组的空间申请 

		}

		//对图的邻接矩阵进行初始化  赋值 全部0 

		for (i = 0;i < g->n;i++) {

			for (j = 0;j < g->n;j++) {

				g->graph[i][j] = 0;

			}

		}

	}

	return g;

}



// 创建一个图  输入 图中存在的边的信息  <0,1>  <1,2>

// 边是<0,1>  输入 v1=0,v2=1  // 如果没有权值信息  g->graph[0][1]=1 

// 为了有权值信息的共同使用  <0,1> 默认权重1

// 输入 v1=0  v2=1  weight=1  /w 

void Create_Graph(GM g) {

	int v1, v2, weight;

	printf("请输入图中边的信息,若存在<0,1>输入格式 0 1 1(表示权重),权重为-1时结束\n");

	scanf_s("%d %d %d", &v1, &v2, &weight);  // 错误 "%d","%d","%d" 

	while (weight != -1) {

		g->graph[v1][v2] = weight;   // 修改初始化邻接矩阵中的aij值

		scanf_s("%d %d %d", &v1, &v2, &weight);  // 重复录入边的信息 直到weight=-1结束 

	}

}



// 打印二维数据  邻接矩阵的信息 

void Print_GraphMatrix(GM g) {

	int i, j;

	for (i = 0;i < g->n;i++)
	{
		for (j = 0;j < g->n;j++)
		{
			printf("%5d", g->graph[i][j]);
		}
		printf("\n");  // 换行 

	}

}



// 深度优先遍历图g  遍历的过程就是打印顶点 

// 遍历要求:所有顶点打印有且仅有一次  如何保证 visited[i]=0未遍历 =1遍历 

void DFS_Graph(GM g) {

	int i;

	int* visited = (int*)malloc(sizeof(int) * g->n); //作用记录图中顶点是否被遍历    

	for (i = 0;i < g->n;i++) {

		visited[i] = 0;   // 初始的情况下 所有顶点都没有遍历

	}

	for (i = 0;i < g->n;i++)
	{
		if (visited[i] == 0)
		{
			DFS(g, visited, i);  //调用一个函数  从顶点i开始对图进行深度遍历   
			// DFS函数写在后面  可以到文件开始部分进行声明
		}   // 图是连通图  DFS调用一次   图是非连通图 DFS 调用多次
	}
}

void DFS(GM g, int* visited, int i) {

	int j;
	visited[i] = 1;  // 标记顶点i被访问/遍历
	printf("顶点%d   ", i);   // 打印 /访问   // 若前面增加了vex数组 printf("%c",g->vex[i]); 
	// 找与i相邻且未被访问的顶点j  g->graph[i][j]==1 visited[j]==0 
	for (j = 0;j < g->n;j++)
	{
		if (g->graph[i][j] == 1 && visited[j] == 0)
		{
			DFS(g, visited, j);  // 从顶点j开始做深度优先搜索 
		}
	}
}


// 在图g中插入一个顶点

GM Add_Vex(GM g) {    // 图中增加一个顶点 

	int i, j;

	GM newg = (GM)malloc(sizeof(struct GraphMatrix));

	newg->n = g->n + 1;  // 新图的顶点数比旧图的多1

	newg->graph = (int**)malloc(sizeof(int*) * newg->n);

	for (i = 0;i < newg->n;i++)
	{
		newg->graph[i] = (int*)malloc(sizeof(int) * newg->n);
	}

	for (i = 0;i < newg->n;i++)
	{
		for (j = 0;j < newg->n;j++)
		{
			if (i < g->n && j < g->n)
			{
				newg->graph[i][j] = g->graph[i][j];  // 原来的邻接矩阵直接复制到新的邻接矩阵 
			}
			else {
				newg->graph[i][j] = 0;
			}
		}
	}
	printf("\n");  //换行 
	Print_GraphMatrix(newg);  // 打印邻接矩阵 
	return newg;  // 新图返回 

}

// 剩下的时间继续完成剩余的实验内容  
// 增加一条边  <v0,v1>  scanf("%d %d",&v0,&v1)  g->graph[v0][v1]=1
void Add_Edge(GM g) {
	int v0, v1, weight;
	printf("\n请输入要添加的边（格式：v0 v1 权重）:");
	scanf_s("%d %d %d", &v0, &v1, &weight);

	// 检查顶点是否合法
	if (v0 < 0 || v0 >= g->n || v1 < 0 || v1 >= g->n) {
		printf("顶点编号不合法！\n");
		return;
	}

	g->graph[v0][v1] = weight;
	printf("添加边后的邻接矩阵:\n");
	Print_GraphMatrix(g);
}

// 删除一条边  <v0,v1>  scanf("%d %d",&v0,&v1)  g->graph[v0][v1]=0 
void Delete_Edge(GM g) {
	int v0, v1;
	printf("\n请输入要删除的边（格式：v0 v1）:");
	scanf_s("%d %d", &v0, &v1);

	// 检查顶点是否合法
	if (v0 < 0 || v0 >= g->n || v1 < 0 || v1 >= g->n) {
		printf("顶点编号不合法！\n");
		return;
	}

	g->graph[v0][v1] = 0;
	printf("删除边后的邻接矩阵:\n");
	Print_GraphMatrix(g);
}
// 删除一个顶点  把这个顶点在邻接矩阵中所在的行和列删掉   对新图的邻接矩阵进行调整 
GM Delete_Vex(GM g) {
	int del_vex, i, j;
	printf("\n请输入要删除的顶点编号:");
	scanf_s("%d", &del_vex);

	// 检查顶点是否合法
	if (del_vex < 0 || del_vex >= g->n) {
		printf("顶点编号不合法！\n");
		return g;
	}

	// 创建新图
	GM newg = create_GraphMatrix(g->n - 1);

	// 复制原矩阵数据（跳过要删除的行和列）
	int row = 0, col = 0;
	for (i = 0; i < g->n; i++) {
		if (i == del_vex) continue;  // 跳过要删除的行
		col = 0;
		for (j = 0; j < g->n; j++) {
			if (j == del_vex) continue;  // 跳过要删除的列
			newg->graph[row][col] = g->graph[i][j];
			col++;
		}
		row++;
	}

	// 释放原图的内存
	for (i = 0; i < g->n; i++) {
		free(g->graph[i]);
	}
	free(g->graph);
	free(g);

	printf("删除顶点后的邻接矩阵:\n");
	Print_GraphMatrix(newg);
	return newg;
}


int main() {
	GM G1 = create_GraphMatrix(6);  // 创建的图的顶点数为6 
	Create_Graph(G1);   //输入边的信息  调用修改邻接矩阵函数 
	Print_GraphMatrix(G1);  // 打印邻接矩阵 
	printf("深度优先搜索遍历序列:");
	DFS_Graph(G1);
	G1 = Add_Vex(G1);
	printf("\n深度优先搜索遍历序列:");
	DFS_Graph(G1);

	Add_Edge(G1);  // 添加一条边
	printf("深度优先搜索遍历序列:");
	DFS_Graph(G1);

	Delete_Edge(G1);  // 删除一条边
	printf("深度优先搜索遍历序列:");
	DFS_Graph(G1);

	G1 = Delete_Vex(G1);  // 删除一个顶点
	printf("深度优先搜索遍历序列:");
	DFS_Graph(G1);

	// 释放最后图形的内存
	for (int i = 0; i < G1->n; i++) {
		free(G1->graph[i]);
	}
	free(G1->graph);
	free(G1);

	return 0;

}
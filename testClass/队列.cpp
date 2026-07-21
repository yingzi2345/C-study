//#include <stdio.h>
//#include <stdlib.h>
//
//// 链式队列的节点定义
//typedef struct QNode {
//    int data;
//    struct QNode* next;
//} QNode;
//
//// 链式队列定义
//typedef struct {
//    QNode* front; // 队头指针
//    QNode* rear;  // 队尾指针
//} LinkQueue;
//
//// 1. 队列初始化
//void InitQueue(LinkQueue* Q) {
//    Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
//    if (!Q->front) {
//        printf("内存分配失败！\n");
//        exit(1);
//    }
//    Q->front->next = NULL;
//    printf("队列初始化成功！\n");
//}
//
//// 2. 取队头元素
//int GetHead(LinkQueue* Q) {
//    if (Q->front == Q->rear) {
//        printf("队列为空，无法取队头元素！\n");
//        return -1;
//    }
//    return Q->front->next->data;
//}
//
//// 3. 入队操作
//void EnQueue(LinkQueue* Q, int e) {
//    QNode* p = (QNode*)malloc(sizeof(QNode));
//    if (!p) {
//        printf("内存分配失败！\n");
//        exit(1);
//    }
//    p->data = e;
//    p->next = NULL;
//    Q->rear->next = p;
//    Q->rear = p;
//}
//
//// 4. 出队操作
//int DeQueue(LinkQueue* Q) {
//    if (Q->front == Q->rear) {
//        printf("队列为空，无法出队！\n");
//        return -1;
//    }
//    QNode* p = Q->front->next;
//    int e = p->data;
//    Q->front->next = p->next;
//
//    if (Q->rear == p) {
//        Q->rear = Q->front;
//    }
//
//    free(p);
//    return e;
//}
//
//// 5. 判断队列是否为空
//int IsEmpty(LinkQueue* Q) {
//    return Q->front == Q->rear;
//}
//
//// 6. 输出队列元素（从队头开始）
//void PrintQueue(LinkQueue* Q) {
//    if (IsEmpty(Q)) {
//        printf("队列为空！");
//        return;
//    }
//
//    QNode* p = Q->front->next;
//    printf("队列元素：");
//    while (p) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//}
//
//// 7. 打印杨辉三角形（附加题）
//void PrintPascalTriangle(int n) {
//    printf("\n=== 杨辉三角形（前%d行）===\n", n);
//
//    LinkQueue Q;
//    InitQueue(&Q);
//
//    // 第一行
//    printf("%*d\n", n * 3, 1);
//
//    // 第二行
//    EnQueue(&Q, 1);
//    EnQueue(&Q, 1);
//    printf("%*d", (n - 1) * 3, 1);
//    printf("%6d\n", 1);
//
//    // 第三行开始
//    for (int i = 3; i <= n; i++) {
//        EnQueue(&Q, 1); // 每行开头都是1
//
//        printf("%*d", (n - i + 1) * 3, 1);
//
//        // 计算中间的数
//        int pre = 1;
//        for (int j = 1; j <= i - 2; j++) {
//            int current = DeQueue(&Q);
//            int sum = pre + current;
//            printf("%6d", sum);
//            EnQueue(&Q, sum);
//            pre = current;
//        }
//
//        EnQueue(&Q, 1); // 每行结尾都是1
//        printf("%6d\n", 1);
//    }
//
//    // 释放队列内存
//    while (!IsEmpty(&Q)) {
//        DeQueue(&Q);
//    }
//    free(Q.front);
//}
//
//int main() {
//    LinkQueue Q;
//    int num;
//
//    printf("========== 链式队列操作 ==========\n");
//    printf("操作规则：\n");
//    printf("  - 输入偶数：入队\n");
//    printf("  - 输入奇数：出队\n");
//    printf("  - 输入0：结束程序\n");
//    printf("==================================\n");
//
//    // 初始化队列
//    InitQueue(&Q);
//
//    while (1) {
//        printf("\n请输入一个整数：");
//        scanf_s("%d", &num);
//
//        if (num == 0) {
//            printf("程序结束！\n");
//            break;
//        }
//
//        if (num % 2 == 0) { // 偶数入队
//            EnQueue(&Q, num);
//            printf("元素 %d 已入队\n", num);
//        }
//        else { // 奇数出队
//            if (!IsEmpty(&Q)) {
//                int dequeued = DeQueue(&Q);
//                printf("元素 %d 已出队\n", dequeued);
//            }
//            else {
//                printf("队列为空，无法出队！\n");
//            }
//        }
//
//        // 显示当前队列状态
//        PrintQueue(&Q);
//        printf("\n");
//    }
//
//    // 释放队列内存
//    while (!IsEmpty(&Q)) {
//        DeQueue(&Q);
//    }
//    free(Q.front);
//
//    // 打印杨辉三角形（附加题）
//    printf("\n");
//    PrintPascalTriangle(8);
//
//    return 0;
//}
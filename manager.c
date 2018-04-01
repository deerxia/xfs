#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "message.h"
int number = 1;
char judge1;
manager_Hand *makeNode(){
    manager_Hand *newNode = (manager_Hand *)malloc(sizeof(manager_Hand));
    if(NULL == newNode){
        manager_Hand *newNode = (manager_Hand *)malloc(sizeof(manager_Hand));
    }
    newNode->pNext = NULL;
    return newNode;
}
manager_Hand *createList(){  
    char lotteryType1[20];
    int idCode1;
    char issueTime1[15];//发布时间
    char beginTime1[15];//开奖时间
    char beginStatue1[10];//开奖状态
    int money;
    manager_Hand *pHead = makeNode();
    manager_Hand *temp = makeNode(); 
    number++; 
    temp->manager.id = number;

    printf("彩票类型\n");
    scanf("%s",lotteryType1);
    strcpy(temp->manager.lotteryType,lotteryType1);

    printf("彩票编号\n");
    temp->manager.idCode = 12367813;

    printf("发布时间\n");
    scanf("%s",lotteryType1);
    strcpy(temp->manager.issueTime,issueTime1);

    printf("开奖时间\n");
    scanf("%s",beginTime1);
    strcpy(temp->manager.issueTime,beginTime1);

    printf("开奖状态\n");
    scanf("%s",beginStatue1);
    strcpy(temp->manager.issueTime,beginStatue1);

    printf("金额\n");
    scanf("%s",money);
    temp->manager.money = money;

    temp->pNext =  pHead->pNext;
    pHead->pNext = temp;
    FILE *four = fopen("out.txt","w");
    if(NULL == four){
        printf("create file error\n");
        exit(-1);
    }
    fwrite(&temp->manager,sizeof(temp->manager),1,four);
    if(fwrite(&temp->manager,sizeof(temp->manager),1,four)>0){
        printf("存入成功\n");
    }else{
        printf("存入失败\n");
    }
    printf("是否还添加彩票 Y或N\n");
    judge1 = getchar();
    getchar();
    if(judge1=='y'){
        createList();
    }else if(judge1=='Y'){
        createList();
    }
}
manager_Hand *Exhibition(){
    manager_Hand *pHead = makeNode();
    manager_Hand *temp = makeNode(); 
    FILE *four = fopen("out.txt","r");
    fread(&temp->manager,sizeof(temp->manager),1,four);
    printf("id\t彩票类型\t彩票编号\t发布时间\t开奖时间\t开奖状态\t金额\n");
    printf("%d\t %s\t %d\t %s\t %s\t %s\t %d\n",temp->manager.id,temp->manager.lotteryType,temp->manager.idCode,temp->manager.issueTime,temp->manager.beginTime,temp->manager.beginStatue,temp->manager.money);
    temp->pNext =  pHead->pNext;
    pHead->pNext = temp;
}
int main(void){
    int choose;
    printf("彩票-管理员端\n");
    printf("1.添加彩票\n");
    printf("2.删除彩票\n");
    printf("3.查询彩票\n");
    printf("4.彩票排序\n");
    scanf("%d",&choose); 
    getchar();
 //   while(judge){
        switch(choose){
            case 1:
                createList();
            //   addLottery();
                break;
            case 2:
            //   deleteLottery();
                break;
            case 3:
               Exhibition();
                break;
            case 4:
            //   sortLottery();
                break;
            default :
                printf("输入有误");
                break;
        }
//    }
    return 0;
}
# ifndef _MESSAGE_H_
# define _MESSAGE_H_
typedef struct managerType{//管理员
    int id;
    char lotteryType[20];
    int idCode;
    char issueTime[15];//发布时间
    char beginTime[15];//开奖时间
    char beginStatue[5];//开奖状态
    int money;
}manager_Type;
typedef struct managerHand{
    struct managerType manager;
    struct managerHand *pNext;
}manager_Hand;
#endif
/*
manager_Hand *Exhibition(){
    manager_Hand *pHead = makeNode();
    manager_Hand *temp = makeNode(); 
    FILE *four = fopen("out.txt","r");
    fread(&temp->manager,sizeof(temp->manager),1,four);
    printf("%d\n",temp->manager.id);
    printf("%s\n",temp->manager.lotteryType);
    printf("%d\n",temp->manager.idCode);
    printf("%s\n",temp->manager.issueTime);
    printf("%s\n",temp->manager.beginTime);
    printf("%s\n",temp->manager.beginStatue);
    printf("%d\n",temp->manager.money);
    temp->pNext =  pHead->pNext;
    pHead->pNext = temp;
}
*/
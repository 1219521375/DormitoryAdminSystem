#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student{
    char name[10];   //姓名
    int number;      //学号
    int dorm_num;    //宿舍号
    int calss;       //班级
    char sex[4];     //性别

    struct student *next;
}stu;

void interface();  //主页面

stu *create();     //创建列表

void addstu(stu* head);     //添加数据记录

stu *delstu(stu* head);     //删除数据记录

void show(stu *head); //显示当前数据记录

void modifystu(stu *head);  //编辑数据记录

void seekstu(stu *head);    //查询记录    未完成利用二分查找实现住宿信息查询（A、按姓名；B、按学号；C、按宿舍号）

stu *sortstu(stu *head);    //选择排序并输出

void outputstu(stu *head);  //生成文件输出


int main()
{
    stu *head;
    interface();//主页面
    head = create();
    int choice;
    while(1){
        printf("输入操作1-7:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addstu(head);
                break;
            case 2:
                head = delstu(head);
                break;
            case 3:
                modifystu(head);
                break;
            case 4:
                seekstu(head);
                break;
            case 5:
                head = sortstu(head);
                break;
            case 6:
                outputstu(head);
                break;
            case 7:
                show(head);
                break;
            default :
                printf("输入错误，请重新输入！\n");
                break;
        }

    }


    return 0;
}


void interface()//主界面
{
	printf("\n\n");
	printf("\t---------------------------------------------------------\n");
	printf("\t|\t\t欢迎使用宿舍信息管理系统\t\t|\n");
	printf("\t---------------------------------------------------------\n");

	/*
		数据增删改查
	*/
	printf("\t|\t\t\t1-数据添加\t\t\t|\n");
	printf("\t|\t\t\t2-数据删除\t\t\t|\n");
	printf("\t|\t\t\t3-数据修改\t\t\t|\n");
	printf("\t|\t\t\t4-数据查询\t\t\t|\n");
	/*
		数据排序
	*/
	printf("\t|\t\t\t5-数据排序\t\t\t|\n");
	/*
		输出
	*/
	printf("\t|\t\t\t6-数据文件输出\t\t\t|\n");
	printf("\t|\t\t\t7-当前数据展示\t\t\t|\n");
	printf("\t---------------------------------------------------------\n");
}

stu* create()   //初始化链表，从文件中获取数据
{
    FILE *fp;
    stu *head,*end,*p;
    char name[10];
    int number,dorm_num,calss;
    char sex[4];

    head = (stu*)malloc(sizeof(stu));
    head->next = NULL;
    p = head;
    end = head;
    int i = 0;
    if((fp = fopen("studentData.txt","r")) == NULL){
        printf("文件不存在！已创建新文件。\n");
        fopen("studentData.txt","w");
        fp = fopen("studentData.txt","r");
        addstu(head);
    }else{
        printf("成功读取文件！\n");
        while(fscanf(fp,"%s %d %d %d %s\n",&p->name,&p->number,&p->dorm_num,&p->calss,p->sex)>0){
                end = p;
                p->next = (stu*)malloc(sizeof(stu));
                p = p->next;

        }
    }
    free(end->next);
    end->next = NULL;
    p = head;
    fclose(fp);
    return head;
}

void addstu(stu *head) //添加学生数据
{
    stu* end,*p;
    int i=0;
    p = head;
    while(p->next != NULL){
        p = p->next;
    }
    end = p;
    p->next = (stu*)malloc(sizeof(stu));
    p=p->next;
    printf("开始添加学生数据：\n");
    while(1){
            printf("输入姓名：\n");
            scanf("%s",&p->name);
            printf("输入学号：\n");
            scanf("%d",&p->number);
            printf("输入宿舍；\n");
            scanf("%d",&p->dorm_num);
            printf("输入班级：\n");
            scanf("%d",&p->calss);
            printf("输入性别：\n");
            scanf("%s",&p->sex);
            end = p;
            p->next = NULL;

            printf("按数字1继续输入,按其余数字退出：\n");
            scanf("%d",&i);
            if(i!=1) break;
            p->next = (stu*)malloc(sizeof(stu));
            p = p->next;
    }
    printf("结束输入。\n");
}

stu *delstu(stu *head)  //删除学生数据 根据学号
{
    stu *p,*pre;
    pre = head;
    p = head;
    int num;
    int i = 0;
    printf("输入你要删除的学生学号：\n");
    scanf("%d",&num);
    while(p){
        if(p->number == num){
            break;
        }
        i++;
        pre = p;
        p = p->next;

    }
    if(p == NULL){
        printf("未找到该学生！\n");
    }
    else
    {
        if(i==0){
            head = p->next;
        }
        else
        {
            pre->next = p->next;


        }


    }
    return head;
}

void show(stu *head)
{
    stu *p;
    p = head;
    while(p){
        printf("%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        p = p->next;
    }
}

void modifystu(stu *head)
{
    stu *p;
    int num;
    printf("请输入修改学生的学号：\n");
    scanf("%d",&num);
    while(p){
        if(num == p->number){
            break;
        }
        p = p->next;
    }
    if(p == NULL){
        printf("未找到该学生的数据记录！\n");
    }
    else
    {
        printf("%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        printf("请输入修改后数据：\n");
        printf("输入姓名：\n");
        scanf("%s",&p->name);
        printf("输入学号：\n");
        scanf("%d",&p->number);
        printf("输入宿舍；\n");
        scanf("%d",&p->dorm_num);
        printf("输入班级：\n");
        scanf("%d",&p->calss);
        printf("输入性别：\n");
        scanf("%s",&p->sex);
        printf("修改成功！");
    }
}

void seekstu(stu *head)
{
    stu *p = sortstu(head);
    int num;
    printf("请输入查询学生的学号：\n");
    scanf("%d",&num);
    while(p){
        if(num == p->number){
            break;
        }
        p = p->next;
    }
    if(p == NULL){
        printf("未找到该学生的数据记录！\n");
    }
    else
    {
        printf("%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        printf("查询成功！");
    }
}

stu *sortstu(stu *head)   //对所有住宿信息按关键字（A、按姓名；B、按学号；C、按宿舍号）排序
{
    stu *p,*pmin,*pminpre,*newhead,*newp;
    p = head;
    pmin = head;
    newhead = NULL;
    newp = NULL;
    char sort_way;
    printf("请输入排序方式，A 按姓名，B 按学号，C 按宿舍号\n");
    getchar();
    scanf("%c",&sort_way);
    switch(sort_way)
    {
        case 'A':
            pminpre = NULL;
            while(head!=NULL)
            {
                //找到最小值
                p = head;
                pmin = head;
                while(p->next!=NULL)
                {
                    if(p->next->name[0] < pmin->name[0]){
                        pminpre = p;
                        pmin = p->next;
                    }
                    else if(p->next->name[0] == pmin->name[0]){
                        if(p->next->name[2] < pmin->name[2]){
                            pminpre = p;
                            pmin = p->next;
                        }
                    }
                     p = p->next;
                }
                //存入新链表
                if(newhead == NULL)
                {
                    newhead = pmin;
                    newp = newhead;

                }
                else
                {
                    newp->next = pmin;
                    newp = newp->next;
                }
                //离开原来链表
                if(pmin == head)
                {
                    head = head->next;
                }
                else
                {
                    pminpre->next = pmin->next;
                }

            }
            if(newhead != NULL)
            {
                newp = NULL;
            }


            break;
        case 'B':
            pminpre = NULL;
            while(head!=NULL)
            {
                //找到最小值
                p = head;
                pmin = head;
                while(p->next!=NULL)
                {
                    if(p->next->number < pmin->number){
                        pminpre = p;
                        pmin = p->next;
                    }
                     p = p->next;
                }
                //存入新链表
                if(newhead == NULL)
                {
                    newhead = pmin;
                    newp = newhead;

                }
                else
                {
                    newp->next = pmin;
                    newp = newp->next;
                }
                //离开原来链表
                if(pmin == head)
                {
                    head = head->next;
                }
                else
                {
                    pminpre->next = pmin->next;
                }

            }
            if(newhead != NULL)
            {
                newp = NULL;
            }
            break;
        case 'C':
           pminpre = NULL;
            while(head!=NULL)
            {
                //找到最小值
                p = head;
                pmin = head;
                while(p->next!=NULL)
                {
                    if(p->next->dorm_num < pmin->dorm_num){
                        pminpre = p;
                        pmin = p->next;
                    }
                     p = p->next;
                }
                //存入新链表
                if(newhead == NULL)
                {
                    newhead = pmin;
                    newp = newhead;

                }
                else
                {
                    newp->next = pmin;
                    newp = newp->next;
                }
                //离开原来链表
                if(pmin == head)
                {
                    head = head->next;
                }
                else
                {
                    pminpre->next = pmin->next;
                }

            }
            if(newhead != NULL)
            {
                newp = NULL;
            }
            break;
        default:
            printf("未输入正确字符！\n");

    }
    return newhead;
}

void outputstu(stu *head)
{
    FILE *fp;
    fp = fopen("studentData.txt","w");
    stu *p;
    p = head;
    while(p)
    {
        fprintf(fp,"%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        p = p->next;
    }
    fclose(fp);
    printf("成功写入文件！\n");

}



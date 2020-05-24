#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include <windows.h>
#include "文件数据处理.h"
#include"非法检测.h"
#pragma warning(disable:4996)
/********************************结构体声明*********************************************/
struct people;//员工信息结构体声明

typedef struct people* pointer;//结构体指针声明

typedef pointer head;//员工信息结构体链表头指针

typedef pointer node;//员工信息结构体链表节点指针

/********************************结构体定义**********************************************/

typedef struct people//员工信息
{
	char name[10];//名字
	char num[10];//编号
	char sex[5];//性别
	char time[10];//时间
	char password[10];//密码
	int age;//年龄
	float base_wage;//基本工资
	float post_wage;//岗位工资
	float merit_pay;//绩效工资
	float subsidy;//住房补贴
	float bonus;//奖金
	float wages_payable;//应发工资
	float public_accumulation_fund;//公积金
	float tax;//税
	float paid_wages;//实发工资

	pointer next;//链表一的指针

}people1;


struct people pp[500];//建立结构体数组
struct people forsort;//用于模糊搜索
float tax_rate[7] = { 0.03,0.1,0.2,0.25,0.3,0.35,0.45 };//保存税率数组
int n;//员工人数



//============================================================================================================================================================================/
//=======================================================================================函数声明================================================================================/
//=============================================================================================================================================================================/
/********************************文件函数声明********************************************/


head Init(head L);                 //初始化函数

void Save(head L);                 //信息保存函数

void MakeFileEmpty();              //清空文件函数

/********************************链表函数声明********************************************/


head MakeEmpty(head L);                         //空链表创建函数

int IsEmpty(head L);                            //判断空链表函数

int IsLast(node P, head L);                  //判断链尾函数

void DeleteList(head L);                        //链表删除函数

node FindNumPrevious(char number[], head L);    //职工号前驱指针查找函数

node FindNamePrevious(char name[], head L);  //职工姓名前驱指针查找函数



/********************************菜单函数声明********************************************/


void adminMainMeun();              //管理员主菜单I

void peopleMainMeun();              //员工主菜单I

void searchpeopleMeun();		   //员工信息搜索菜单II

void viewpeopleMeun();             //员工信息显示菜单II

void sort_select_Meun();           //排序选项菜单III

void sort_select1_Meun();           //升序排序选项菜单IIII

void sort_select2_Meun();           //降序排序选项菜单IIII

void ModMeun();                    //修改员工信息菜单

void ModMeun1();                   //修改的部分菜单

void deleteMeun();                    //删除菜单

void dataMeun();                   //文件数据菜单


/********************************职工信息显示函数声明********************************************/

void Add(head L);                  //信息录入函数

void Viewpeople(char num[10]);       //职工信息显示函数

void Viewallpeople(head L);			//显示全部职工的数据

/********************************职工信息删除函数声明********************************************/
void DeleteNum(head L);

void DeleteName(head L);

/********************************职工查询函数声明********************************************/


int fuzzy_search(char key[], char str[]);// 模糊搜索函数

void search_num(head L);  //员工编号查询函数

void search_name(head L);  //员工编号查询函数

void   search_age(head L);  //员工编号查询函数

void   search_base(head L);

void   search_post(head L);

void   search_merit(head L);

void   search_subsidy(head L);

void   search_bonus(head L);

void   search_payable(head L);

void   search_fund(head L);

void comb_search(head L);//组合搜索

/**************************************员工信息排序函数**************************************************/


void show_sort();      //排序后显示排序结果函数

void sort_sex(struct people pp[500]);       //性别排序函数

void sort_up_num(struct people pp[500]);  //编号升序函数

void sort_down_num(struct people pp[500]);  //编号降序函数

void sort_up_age(struct people pp[500]);  //年龄升序函数

void sort_down_age(struct people pp[500]);  //年龄降序函数

void sort_up_base_wage(struct people pp[500]);  //基本工资升序函数

void sort_down_base_wage(struct people pp[500]);  //基本工资降序函数

void sort_up_post_wage(struct people pp[500]); //岗位工资升序函数

void sort_down_post_wage(struct people pp[500]);  //岗位工资降序函数

void sort_up_merit_pay(struct people pp[500]);  //绩效升序函数

void sort_down_merit_pay(struct people pp[500]);  //绩效降序函数

void sort_up_subsidy(struct people pp[500]);  //住房补贴升序函数

void sort_down_subsidy(struct people pp[500]);  //住房补贴降序函数

void sort_up_bonus(struct people pp[500]);  //奖金升序函数

void sort_down_bonus(struct people pp[500]);  //奖金降序函数

void sort_up_wages_payable(struct people pp[500]); //应发工资升序函数

void sort_down_wages_payable(struct people pp[500]);  //应发工资降序函数

void sort_up_public_accumulation_fund(struct people pp[500]);  //公积金升序函数

void sort_down_public_accumulation_fund(struct people pp[500]);  //公积金降序函数

void sort_up_tax(struct people pp[500]);  //税升序函数

void sort_down_tax(struct people pp[500]);  //税降序函数

void sort_up_paid_wages(struct people pp[500]);  //实发工资升序函数

void sort_down_paid_wages(struct people pp[500]);//实发工资降序函数


/*********************************税金函数声明**********************************************/
void calculate_tax(struct people pp[500]);//计算税金


/******************************修改类函数****************************************************/

void change_name(struct people pp[500]);//修改名字函数

void change_age(struct people pp[500]);//修改年龄函数

void change_base_wage(struct people pp[500]);//修改基本工资函数

void change_post_wage(struct people pp[500]);//修改岗位工资函数

void change_merit_pay(struct people pp[500]);//修改绩效工资函数

void change_subsidy(struct people pp[500]);//修改住房补贴函数

void change_bonus(struct people pp[500]);//修改奖金函数

void change_wages_payable(struct people pp[500]);//修改应发工资函数

void change_public_accumulation_fund(struct people pp[500]);//修改公积金函数

void admin_change_people_password();//管理员修改员工密码函数

void people_change_people_password();//员工修改自己密码函数

/******************************************统计数据函数*****************************************************************/


void show_sort_date(struct people pp[500]);


/**********************************登录函数声明*********************************************/


void identity_judge();//登录身份判断

void admin_judge_window();//管理员登录界面

void people_judge_window();//员工登录界面

int people_chance_judge(int* number);//员工登录剩余次数判断函数

int admin_chance_judge(int* number);//管理员登录剩余次数判断函数

void change_admin_password();//修改管理员密码

void change_people_password();//修改员工密码


//============================================================================================================================================================================/
//=======================================================================================函数实现================================================================================/
//=============================================================================================================================================================================/


/*********************************链表函数**********************************************/

//空链表创建函数
head MakeEmpty(head L)
{
	if (L)                                      //相当于 if(L!=NULL) ,即指针L指向的空间不为空
	{
		DeleteList(L);                       //删除原先链表
	}
	L = (head)malloc(sizeof(struct people));   //创建新的空链表
	if (!L)                                     //相当于 if(L==NULL) ,即指针L指向的空间为空
	{
		printf("\n\t\t\t\t\t\t\t创建失败,内存不足!!!");        //创建失败，提示内存不足
		printf("\n\t\t\t\t\t\t\t");
		system("pause");                       //暂停屏幕显示
		return NULL;                           //返回上一级菜单
	}
	L->next = NULL;                              //Next指针指向空
	return L;                                  //返回链表头
}

//判断空链表函数
int IsEmpty(head L)
{
	return L->next == NULL;       //头结点的Next指针为空，则链表为空，返回值为1
}

//判断链尾函数
int IsLast(node P, head L)
{
	if (P->next == NULL)
		return 1;
	else
		return 0;//结点P的Next指针为空，则P为最后一个结点，返回值为1
}
//链表删除函数
void DeleteList(head L)
{
	node p, tmp;
	p = L->next;//取链表头后的所有结点
	L->next = NULL; //链表头指向空结点      
	while (p != NULL)
	{
		tmp = p->next;//依次释放链表头后所有结点的空间
		free(p);
		p = tmp;
	}

}

//职工号前驱指针查找函数
node FindNumPrevious(char number[], head L)
{
	node P;
	P = L;
	while (P->next != NULL && strcmp(number, P->next->num) != 0)  //判断P的Next指针是否为空，且P的下一个结点的职工姓名是否为查找的职工姓名
		P = P->next;                                       //查找下一个
	return P;                                            //返回该职工号的前驱指针
}

//职工姓名前驱指针查找函数
node FindNamePrevious(char name[], head L)
{
	node P;
	P = L;
	while (P->next != NULL && strcmp(name, P->next->name) != 0)  //判断P的Next指针是否为空，且P的下一个结点的职工姓名是否为查找的职工姓名
		P = P->next;                                       //查找下一个
	return P;                                            //返回该职工号的前驱指针
}
/*********************************文件函数**************************************************/

//初始化函数

head Init(head L)
{
	FILE* fp;                                               //文件指针
	int num = 0;                                             //记录员工人数
	char name1[100];//名字
	char num1[100];//编号
	char sex1[100];//性别
	char time1[100];//时间
	char password1[100];//密码
	int age1;//年龄
	float base_wage1;//基本工资
	float post_wage1;//岗位工资
	float merit_pay1;//绩效工资
	float subsidy1;//住房补贴
	float bonus1;//奖金
	float wages_payable1;//应发工资
	float public_accumulation_fund1;//公积金
	float tax1;//税

	if ((fp = fopen("职工账号.txt", "r+")) == NULL)                //打开"职工信息.txt"文本文件
	{
		printf("\n\t\t\t\t\t\t\t无法打开文件或文件不存在\n");         //提示错误
		printf("\n\t\t\t\t\t\t\t正在尝试创建新文件....\n");
		fp = fopen("职工账号.txt", "w");                       //创建"职工信息.txt"文本文件
		if ((fp = fopen("职工账号.txt", "r+")) == NULL)           //再次打开判断是否成功
		{
			printf("\n\t\t\t\t\t\t\t文件创建失败!!!\n");
			printf("\n\t\t\t\t\t\t\t");
			system("pause");                                //暂停屏幕显示
			return NULL;
		}
	}
	fp = fopen("职工账号.txt", "r+");                           //以只读的方式打开"职工信息.txt"文本文件
	L = MakeEmpty(L);                                         //创建链表，以便存储文本文件中的信息
	node p;
	node newn;
	p = newn = L;
	while (fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", name1, num1, sex1, time1, password1, &age1, &base_wage1, &post_wage1
		, &merit_pay1, &subsidy1, &bonus1, &wages_payable1, &public_accumulation_fund1, &tax1) != EOF)
	{
		newn = (node)malloc(sizeof(struct people));  //创建新结点
		strcpy(newn->name, name1);
		strcpy(newn->num, num1);
		strcpy(newn->sex, sex1);
		strcpy(newn->time, time1);
		strcpy(newn->password, password1);
		newn->age = age1,
			newn->base_wage = base_wage1;
		newn->bonus = bonus1;
		newn->merit_pay = merit_pay1;
		newn->post_wage = post_wage1;
		newn->public_accumulation_fund = public_accumulation_fund1;
		newn->subsidy = subsidy1;
		newn->tax = tax1;
		newn->wages_payable = wages_payable1;
		p->next = newn;
		p = newn;
		num++;
	}
	p->next = NULL;
	n = num;
	fclose(fp);                                             //关闭文件
	return L;
}

//信息保存函数 
void Save(head L)
{
	FILE* fp;                                           //文件指针
	node p;
	p = L;
	if ((fp = fopen("职工账号.txt", "w+")) == NULL)           //打开"员工信息.txt"文本文件
	{
		printf("\n\t\t\t\t\t\t\t无法打开文件!!!\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");                                //暂停屏幕显示
		return;
	}
	fp = fopen("职工账号.txt", "w+");                      //以读写的方式打开"职工信息.txt"文本文件
	while (p->next != NULL)                                //将内存中的数据输出到磁盘中
	{
		p = p->next;	//信息从第一个有效结点开始保存,循环指向下一个有效结点
		char s1[20];
		char s2[20];
		char s3[20];
		char s4[20];
		char s5[20];
		char s6[20];
		char s7[20];
		char s8[20];
		char s9[20];
		sprintf(s1, "%d", p->age);
		sprintf(s2, "%.1f", p->base_wage);
		sprintf(s3, "%.1f", p->post_wage);
		sprintf(s4, "%.1f", p->merit_pay);
		sprintf(s5, "%.1f", p->subsidy);
		sprintf(s6, "%.1f", p->bonus);
		sprintf(s7, "%.1f", p->wages_payable);
		sprintf(s8, "%.1f", p->public_accumulation_fund);
		sprintf(s9, "%.1f", p->tax);
		if (fprintf(fp, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s \n", p->name, p->num, p->sex, p->time, p->password,
			s1, s2, s3, s4, s5, s6, s7, s8, s9) < 0)
			break;  //向文件写入信息
	}
	printf("                ");
	printf("\n\t\t\t\t\t\t\t员工信息保存成功!!!\n\n");
	fclose(fp);
}

//清空文件函数
void MakeFileEmpty()
{
	FILE* fp;                                       //文件指针
	if ((fp = fopen("职工账号.txt", "w+")) == NULL)       //新建"职工信息.txt"文本文件
	{
		printf("\n\t\t\t\t\t\t\t无法打开文件!!!\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");                            //暂停屏幕显示
		return;
	}
	printf("\n\n\t\t\t\t\t\t\t文件信息清空完毕!!!\n\n");
	return;
}

/*********************************帮助函数**************************************************/

void help()
{
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t帮助\n");
	printf("\n\t\t\t\t\t******************************************************************\n");
	printf("\n\t\t\t\t\t\t常见操作问题如下：\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t1、如何输入指令\n");
	printf("\n\t\t\t\t\t\t根据页面提示输入你想选择的指令的数字。\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t2、如何输入所需内容\n");
	printf("\n\t\t\t\t\t\t输入相关内容后请按下回车键即可。\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t3、遇到系统错误\n");
	printf("\n\t\t\t\t\t\t重启系统即可，系统会自动保存已完成的操作。\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t如遇其他问题，请您联系管理员解决\n");
	printf("\n\t\t\t\t\t\t感谢您使用工资管理系统！！！\n");
	printf("\n\t\t\t\t\t******************************************************************\n");
	printf("\n\t\t\t\t\t\t");
	system("pause");
	return;
}
/*********************************菜单函数**************************************************/

//管理人员菜单
void adminMainMeun()
{
	head L = NULL;
	L = Init(L);
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t------------------------------------------------\n");
	printf("\t\t\t\t\t|                                              |");
	printf("\n\t\t\t\t\t|             员工信息读取完成!!!              |\n");
	printf("\t\t\t\t\t|                                              |");
	printf("\n\t\t\t\t\t|             目前共有 %d 名员工信息            |\n", n);
	printf("\t\t\t\t\t|                                              |");
	printf("\n\t\t\t\t\t|             主菜单如下                       |");
	printf("\n\t\t\t\t\t------------------------------------------------");
	printf("\n\t\t\t\t\t|             1、员工信息录入                  |");
	printf("\n\t\t\t\t\t|             2、员工信息显示                  |");
	printf("\n\t\t\t\t\t|             3、员工信息修改                  |");
	printf("\n\t\t\t\t\t|             4、员工信息删除                  |");
	printf("\n\t\t\t\t\t|             5、员工信息查询                  |");
	printf("\n\t\t\t\t\t|             6、员工信息统计                  |");
	printf("\n\t\t\t\t\t|             7、管理员密码修改                |");
	printf("\n\t\t\t\t\t|             8、文件数据处理                  |");
	printf("\n\t\t\t\t\t|             9、帮助                          |");
	printf("\n\t\t\t\t\t|             10、退出登录                     |");
	printf("\n\t\t\t\t\t|             11、退出系统                     |");
	printf("\n\t\t\t\t\t------------------------------------------------");
	printf("\n\t\t\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test2(chose, 1, 11);
	switch (x)
	{
	case 1:	system("cls");  Add(L); getchar(); adminMainMeun();   break;  //员工信息录入
	case 2:	system("cls");  viewpeopleMeun(); break;//员工信息显示 
	case 3:	ModMeun();  break;//员工信息修改
	case 4:	 deleteMeun(); break;  //员工信息删除 
	case 5:	searchpeopleMeun(); break;//员工信息查询
	case 6:	show_sort_date(pp);  adminMainMeun(); break;//员工信息统计
	case 7:	change_admin_password(); adminMainMeun(); break;//管理员密码修改
	case 8:	dataMeun(); adminMainMeun(); break;//登录身份判断
	case 9:	help(); adminMainMeun(); break;//登录身份判断
	case 10:identity_judge();  break;//登录身份判断
	case 11: 
	{
		printf("\n\t\t\t\t\t\t系统已安全退出，欢迎您下次使用！！！\n\n");
		exit(0);
		return; 
	}
	}
}

void peopleMainMeun()
{
	head L = NULL;
	L = Init(L);
	char chose[1000];
	int x;
	printf("\n\t\t\t\t\t\t************************************************ \n");
	printf("\n\t\t\t\t\t\t 【1】修改密码    【2】退出登录  【3】退出系统");
	printf("\n\t\t\t\t\t\t************************************************ \n");
	printf("\n\t\t\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", &chose);
	x = Test1(chose, 1, 3);
	switch (x)
	{
	case 1:people_change_people_password(); identity_judge();    break;
	case 2:identity_judge(); break;
	case 3:exit(0);  break;//返回主菜单
	}
	printf("\n");
	printf("\n");
}


//职工信息查询菜单
void searchpeopleMeun()
{
	head L = NULL;
	L = Init(L);
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工信息查询菜单");
	printf("\n\t\t\t\t\t***********************************************");
	printf("\n\t\t\t\t\t*            1、员工编号查询显示                 *");
	printf("\n\t\t\t\t\t*            2、员工姓名查询显示                 *");
	printf("\n\t\t\t\t\t*            3、年龄查询显示                     *");
	printf("\n\t\t\t\t\t*            4、基本工资查询显示                 *");
	printf("\n\t\t\t\t\t*            5、岗位工资查询显示                 *");
	printf("\n\t\t\t\t\t*            6、绩效工资查询显示                 *");
	printf("\n\t\t\t\t\t*            7、住房补贴查询显示                 *");
	printf("\n\t\t\t\t\t*            8、奖金查询显示                     *");
	printf("\n\t\t\t\t\t*            9、应发工资查询显示                 *");
	printf("\n\t\t\t\t\t*            10、公积金查询显示                  *");
	printf("\n\t\t\t\t\t*            11、多条件查询显示                  *");
	printf("\n\t\t\t\t\t*            12、返回菜单                       *");
	printf("\n\t\t\t\t\t************************************************");
	printf("\n\t\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", &chose);
	x = Test2(chose, 1, 12);
	switch (x)
	{
	case 1:search_num(L); searchpeopleMeun(); break;
	case 2:search_name(L); searchpeopleMeun(); break;
	case 3:search_age(L); searchpeopleMeun(); break;
	case 4:search_base(L); searchpeopleMeun(); break;
	case 5:search_post(L); searchpeopleMeun(); break;
	case 6:search_merit(L); searchpeopleMeun(); break;
	case 7:search_subsidy(L); searchpeopleMeun(); break;
	case 8:search_bonus(L); searchpeopleMeun(); break;
	case 9:search_payable(L); searchpeopleMeun(); break;
	case 10:search_fund(L); searchpeopleMeun(); break;
	case 11:comb_search(L); searchpeopleMeun(); break;
	case 12:adminMainMeun();  break;//返回主菜单
	}
}

//员工信息显示菜单
void viewpeopleMeun()
{
	head L = NULL;
	L = Init(L);
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工信息显示菜单");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t*            1、显示全部员工信息           *");
	printf("\n\t\t\t\t\t*            2、排序显示员工信息           *");
	printf("\n\t\t\t\t\t*            3、返回菜单                   *");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test1(chose, 1, 3);
	switch (x)
	{
	case 1: system("cls");  Viewallpeople(L); system("pause"); viewpeopleMeun(); break;
	case 2: sort_select_Meun(); break;
	case 3:adminMainMeun(); break;//返回主菜单
	}
}

void sort_select_Meun()
{
	head L = NULL;
	L = Init(L);
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t升序降序选择");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t*            1、升序排序                   *");
	printf("\n\t\t\t\t\t*            2、降序排序                   *");
	printf("\n\t\t\t\t\t*            3、返回上一级菜单             *");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", &chose);
	x = Test1(chose, 1, 3);
	switch (x)
	{
	case 1:sort_select1_Meun(); break;
	case 2:sort_select2_Meun(); break;
	case 3:viewpeopleMeun();  break;//返回主菜单
	}
}

//升序排序菜单
void sort_select1_Meun()
{
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t排序选项");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\t\t\t\t\t+            1、编号                      +");
	printf("\n\t\t\t\t\t+            2、性别                      +");
	printf("\n\t\t\t\t\t+            3、年龄                      +");
	printf("\n\t\t\t\t\t+            4、基本工资                  +");
	printf("\n\t\t\t\t\t+            5、岗位工资                  +");
	printf("\n\t\t\t\t\t+            6、绩效工资                  +");
	printf("\n\t\t\t\t\t+            7、住房补贴                  +");
	printf("\n\t\t\t\t\t+            8、奖金                      +");
	printf("\n\t\t\t\t\t+            9、应发工资                  +");
	printf("\n\t\t\t\t\t+            10、公积金                   +");
	printf("\n\t\t\t\t\t+            11、税                       +");
	printf("\n\t\t\t\t\t+            12、实发工资                 +");
	printf("\n\t\t\t\t\t+            13、返回员工信息显示菜单     +");
	printf("\n\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\n\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test2(chose, 1, 13);
	switch (x)
	{
	case 1:sort_up_num(pp); break;
	case 2:sort_sex(pp); break;
	case 3:sort_up_age(pp); break;
	case 4:sort_up_base_wage(pp); break;
	case 5:sort_up_post_wage(pp); break;
	case 6:sort_up_merit_pay(pp); break;
	case 7:sort_up_subsidy(pp); break;
	case 8:sort_up_bonus(pp); break;
	case 9:sort_up_wages_payable(pp); break;
	case 10:sort_up_public_accumulation_fund(pp); break;
	case 11:sort_up_tax(pp); break;
	case 12:sort_up_paid_wages(pp); break;
	case 13:viewpeopleMeun(); break;//返回修改员工信息菜单
	}
}

//降序排序菜单
void sort_select2_Meun()
{
	char chose[1000];
	int x;
	system("cls");
	system("cls");
	printf("\n\t\t\t\t\t\t\t 排序选项");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\t\t\t\t\t+            1、编号                      +");
	printf("\n\t\t\t\t\t+            2、性别                      +");
	printf("\n\t\t\t\t\t+            3、年龄                      +");
	printf("\n\t\t\t\t\t+            4、基本工资                  +");
	printf("\n\t\t\t\t\t+            5、岗位工资                  +");
	printf("\n\t\t\t\t\t+            6、绩效工资                  +");
	printf("\n\t\t\t\t\t+            7、住房补贴                  +");
	printf("\n\t\t\t\t\t+            8、奖金                      +");
	printf("\n\t\t\t\t\t+            9、应发工资                  +");
	printf("\n\t\t\t\t\t+            10、公积金                   +");
	printf("\n\t\t\t\t\t+            11、税                       +");
	printf("\n\t\t\t\t\t+            12、实发工资                 +");
	printf("\n\t\t\t\t\t+            13、返回员工信息显示菜单     +");
	printf("\n\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\n\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test2(chose, 1, 13);
	switch (x)
	{
	case 1:sort_down_num(pp); break;
	case 2:sort_sex(pp); break;
	case 3:sort_down_age(pp); break;
	case 4:sort_down_base_wage(pp); break;
	case 5:sort_down_post_wage(pp); break;
	case 6:sort_down_merit_pay(pp); break;
	case 7:sort_down_subsidy(pp); break;
	case 8:sort_down_bonus(pp); break;
	case 9:sort_down_wages_payable(pp); break;
	case 10:sort_down_public_accumulation_fund(pp); break;
	case 11:sort_down_tax(pp); break;
	case 12:sort_down_paid_wages(pp); break;
	case 13:viewpeopleMeun(); break;//返回修改员工信息菜单
	}
}




//修改部分菜单
void ModMeun()
{
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t所要修改的部分");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t*            1、名字                      *");
	printf("\n\t\t\t\t\t*            2、年龄                      *");
	printf("\n\t\t\t\t\t*            3、基本工资                  *");
	printf("\n\t\t\t\t\t*            4、岗位工资                  *");
	printf("\n\t\t\t\t\t*            5、绩效工资                  *");
	printf("\n\t\t\t\t\t*            6、住房补贴                  *");
	printf("\n\t\t\t\t\t*            7、奖金                      *");
	printf("\n\t\t\t\t\t*            8、应发工资                  *");
	printf("\n\t\t\t\t\t*            9、公积金                    *");
	printf("\n\t\t\t\t\t*            10、密码                     *");
	printf("\n\t\t\t\t\t*            11、返回上一菜单             *");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\n\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test2(chose, 1, 11);
	switch (x)
	{
	case 1:change_name(pp); system("pause"); ModMeun(); break;
	case 2:change_age(pp); system("pause"); ModMeun(); break;
	case 3:change_base_wage(pp); system("pause"); ModMeun(); break;
	case 4:change_post_wage(pp); system("pause"); ModMeun(); break;
	case 5:change_merit_pay(pp); system("pause"); ModMeun(); break;
	case 6:change_subsidy(pp); system("pause"); ModMeun(); break;
	case 7:change_bonus(pp); system("pause"); ModMeun(); break;
	case 8:change_wages_payable(pp); system("pause"); ModMeun(); break;
	case 9:change_public_accumulation_fund(pp); system("pause"); ModMeun(); break;
	case 10:admin_change_people_password(); system("pause"); ModMeun(); break;
	case 11:adminMainMeun(); break;//返回修改员工信息菜单

	}
}

//删除菜单
void deleteMeun()
{
	head L = NULL;
	L = Init(L);
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工信息删除菜单");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t*            1、员工号查询删除             *");
	printf("\n\t\t\t\t\t*            2、员工姓名查询删除           *");
	printf("\n\t\t\t\t\t*            3、返回主菜单                 *");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test1(chose, 1, 3);
	switch (x)
	{
	case 1:DeleteNum(L); deleteMeun(); break;
	case 2:DeleteName(L); deleteMeun(); break;
	case 3:adminMainMeun();  break;//返回主菜单
	}
}

//文件数据菜单
void dataMeun()
{
	char chose[1000];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t文件数据菜单");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t*            1、数据备份                   *");
	printf("\n\t\t\t\t\t*            2、数据恢复                   *");
	printf("\n\t\t\t\t\t*            3、返回主菜单                 *");
	printf("\n\t\t\t\t\t********************************************");
	printf("\n\t\t\t\t\t\t请输入您的选择:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", chose);
	x = Test1(chose, 1, 3);
	switch (x)
	{
	case 1:file_backups(); break;
	case 2:file_recovers(); break;
	case 3:adminMainMeun();  break;//返回主菜单
	}


}
/*********************************职工管理函数**************************************************/

/*********************************录入函数**********************************************/



//信息录入函数
void Add(head L)
{
	char s1[20];
	char s2[20];
	char s3[20];
	char s4[20];
	char s5[20];
	char s6[20];
	char s7[20];
	char s8[20];
	char s9[20];
	char s10[20];
	char s13[20];
	char chose[1000];
	int x;
	node p;
	char number[100];
	char n[100];
	int testnum;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t请输入所要创建的8位员工编号:  ");                         //提示输入职工号
	scanf("%s", number);


	if (Test8(number))
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\t\t\t\t员工编号为8位数字 请确定后输入 ");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		Add(L);
		return;
	}
	if (!IsLast(FindNumPrevious(number, L), L))             //连续调用 职工号前驱指针查找函数 判断链尾函数,判断该职工号是否已存在
	{
		printf("\n\t\t\t\t\t\t员工编号 %s 已存在!!!\n\n", number);
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		return;                                     //退出并返回上一级菜单
	}

	printf("\n\t\t\t\t\t\t请输入该员工的姓名:  ");                       //保存职工姓名
	scanf("%s", n);
	if (Testx(n))
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\t\t\t\t请输入正确的员工姓名\n ");
		system("pause");
		Add(L);
		return;
	}
	if (!IsLast(FindNamePrevious(n, L), L))     //连续调用 职工姓名前驱指针查找函数 判断链尾函数,判断该职工姓名是否已存在
	{
		printf("\n\t\t\t\t\t\t员工姓名 %s 已存在!!!\n\n", n);
		printf("                ");
		system("pause");
		return;                                          //退出并返回上一级菜单
	}

	p = L->next;
	p = (node)malloc(sizeof(struct people));   //创建新结点
	if (p == NULL)
	{
		printf("\n\t\t\t\t\t\t\t添加失败,内存不足!!!\n\n");                  //添加失败，提示内存不足
		system("pause");                                 //暂停屏幕显示
		return;                                          //返回上一级菜单
	}


	strcpy(p->num, number);                                //保存职工号
	strcpy(p->name, n);                             //保存姓名


	printf("\n\t\t\t\t\t\t请输入该员工的性别:  ");
	printf("\n\t\t\t\t\t\t1、男        2、女  ");//保存性别
	char boy[100] = { "男" };
	char girl[100] = { "女" };
	scanf("%s", chose);
	x = Test1(chose, 1, 2);
	switch (x)
	{
	case 1:strcpy(p->sex, boy); break;
	case 2:strcpy(p->sex, girl); break;
	}

	printf("\n\t\t\t\t\t\t请输入该员工的入职时间(如0/0/0）:  ");                   //保存性别
	scanf("%s", s1);
	testnum = Testdate(s1);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的入职时间 ");
		scanf("%s", s1);
		testnum = Testdate(s1);
	}
	strcpy(p->time, s1);
	printf("\n\t\t\t\t\t\t请输入该员工的密码:  ");                   //保存性别
	scanf("%s", p->password);
	printf("\n\t\t\t\t\t\t请输入该员工的年龄:  ");                       //保存年龄
	scanf("%s", s2);
	testnum = Testnum1(s2);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的年龄 ");
		scanf("%s", s2);
		testnum = Testnum1(s2);
	}
	p->age = atoi(s2);
	printf("\n\t\t\t\t\t\t请输入该员工的基本工资(单位:元):  ");              //保存基本工资
	scanf("%s", s3);
	testnum = Testnum1(s3);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的基本工资 ");
		scanf("%s", s3);
		testnum = Testnum1(s3);
	}
	p->base_wage = atoi(s3);
	printf("\n\t\t\t\t\t\t请输入该员工的岗位工资(单位:元):  ");              //保存岗位工资
	scanf("%s", s4);
	testnum = Testnum1(s4);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的岗位工资 ");
		scanf("%s", s4);
		testnum = Testnum1(s4);
	}
	p->post_wage = atoi(s4);
	printf("\n\t\t\t\t\t\t请输入该员工的绩效工资(单位:元):  ");              //保存绩效工资
	scanf("%s", s5);
	testnum = Testnum1(s5);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的绩效工资 ");
		scanf("%s", s5);
		testnum = Testnum1(s5);
	}
	p->merit_pay = atoi(s5);
	printf("\n\t\t\t\t\t\t请输入该员工的住房补贴(单位:元):  ");              //保存住房补贴
	scanf("%s", s6);
	testnum = Testnum1(s6);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的住房补贴 ");
		scanf("%s", s6);
		testnum = Testnum1(s6);
	}
	p->subsidy = atoi(s6);
	printf("\n\t\t\t\t\t\t请输入该员工的奖金(单位:元):  ");              //保存奖金
	scanf("%s", s7);
	testnum = Testnum1(s7);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的奖金 ");
		scanf("%s", s7);
		testnum = Testnum1(s7);
	}
	p->bonus = atoi(s7);
	printf("\n\t\t\t\t\t\t请输入该员工的应发工资(单位:元):  ");              //保存应发工资
	scanf("%s", s8);
	testnum = Testnum1(s8);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的应发工资 ");
		scanf("%s", s8);
		testnum = Testnum1(s8);
	}
	p->wages_payable = atoi(s8);
	printf("\n\t\t\t\t\t\t请输入该员工的公积金(单位:元):  ");              //保存公积金
	scanf("%s", s9);
	testnum = Testnum1(s9);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的公积金 ");
		scanf("%s", s9);
		testnum = Testnum1(s9);
	}
	p->public_accumulation_fund = atoi(s9);
	printf("\n\t\t\t\t\t\t请输入该员工的税(单位:元):  ");              //保存税
	scanf("%s", s10);
	testnum = Testnum1(s10);
	while (testnum)
	{
		printf("\n\t\t\t\t\t\t请输入正确的税收 ");
		scanf("%s", s10);
		testnum = Testnum1(s10);
	}
	p->tax = atoi(s10);


	p->next = L->next;                               //将结点TmpCell插入到链表中
	L->next = p;
	printf("\n\t\t\t\t\t\t员工 %s 的信息创建成功!!!\n", p->name);   //提示创建成功
	printf("\n\t\t\t\t\t\t员工 %s 的信息已自动保存!!!\n", p->name);
	getchar();
	Save(L);    //调用 信息保存函数
}
/*********************************显示函数**********************************************/

//职工信息显示函数
void Viewpeople(char num[10])
{
	for (int i = 0; i < 500; i++)
	{
		if (strcmp(num, pp[i].num) == 0)
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
			printf("\n");
			printf("\n");
			pp[i].paid_wages = pp[i].base_wage + pp[i].post_wage + pp[i].merit_pay +
				pp[i].subsidy + pp[i].bonus +
				pp[i].public_accumulation_fund - pp[i].tax;
			printf("\n\t\t\t\t\t\t\t名字：");
			printf("%s", pp[i].name);
			printf("\n\t\t\t\t\t\t\t编号：");
			printf("%s", pp[i].num);
			printf("\n\t\t\t\t\t\t\t性别：");
			printf("%s", pp[i].sex);
			printf("\n\t\t\t\t\t\t\t入职时间：");
			printf("%s", pp[i].time);
			printf("\n\t\t\t\t\t\t\t年龄：");
			printf("%d", pp[i].age);
			printf("\n\t\t\t\t\t\t\t基本工资：");
			printf("%.1f", pp[i].base_wage);
			printf("\n\t\t\t\t\t\t\t岗位工资：");
			printf("%.1f", pp[i].post_wage);
			printf("\n\t\t\t\t\t\t\t绩效工资：");
			printf("%.1f", pp[i].merit_pay);
			printf("\n\t\t\t\t\t\t\t住房补贴：");
			printf("%.1f", pp[i].subsidy);
			printf("\n\t\t\t\t\t\t\t奖金：");
			printf("%.1f", pp[i].bonus);
			printf("\n\t\t\t\t\t\t\t公积金：");
			printf("%.1f", pp[i].public_accumulation_fund);
			printf("\n\t\t\t\t\t\t\t税：");
			printf("%.1f", pp[i].tax);
			printf("\n\t\t\t\t\t\t\t应发工资：");
			printf("%.1f", pp[i].wages_payable);
			printf("\n\t\t\t\t\t\t\t实发工资：");
			printf("%.1f", pp[i].paid_wages);
			break;
		}
	}
	getchar();
	putchar('\n');
	return;                                   //退出并返回上一级菜单
}

//显示全部职工的数据
void Viewallpeople(head L)
{
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
			p->subsidy + p->bonus +
			p->public_accumulation_fund - p->tax;
		printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
			p->age,
			p->base_wage, p->post_wage, p->merit_pay,
			p->subsidy, p->bonus, p->wages_payable,
			p->public_accumulation_fund, p->tax, p->paid_wages);
		p = p->next;
	}

	printf("\n");
	getchar();
	putchar('\n');
}


/********************************职工信息删除函数实现********************************************/

void DeleteNum(head L)
{
	node P, TmpCell;
	char number[20];
	printf("\n\t\t\t\t\t");
	printf("请输入所要修改的职工信息的职工号:  ");
	scanf("%s", number);
	P = FindNumPrevious(number, L);	 //调用职工号前驱指针查找函数,获得所需显示结点的前一结点
	if (IsLast(P, L) == 1)               //判断是否存在该员工
	{
		printf("\n\t\t\t\t\t无职工号为 %s 的员工!!!\n\t\t\t\t\t删除失败!!!\n\n", number);
		printf("\n\t\t\t\t\t");
		system("pause");
		deleteMeun();
	}
	else
	{
		Viewpeople(P->num);      //调用职工信息打印函数
		fflush(stdin);                   //清除键盘缓冲区
		printf("\n\t\t\t\t\t是否确认要删除？回复'Y'删除或其他字符取消删除\n");
		printf("\n\t\t\t\t\t");

		if (getchar() == 'Y')
		{
			TmpCell = P->next;
			P->next = TmpCell->next;
			free(TmpCell);
			printf("\n\t\t\t\t\t删除成功!!!\n\n");
			Save(L);                     //调用信息保存函数
			printf("\n\t\t\t\t\t");
			system("pause");
			deleteMeun();
		}
		else
		{
			printf("\n\t\t\t\t\t删除取消!!!\n\n");
			printf("\n\t\t\t\t\t");
			system("pause");
			deleteMeun();
		}

	}
	printf("\n\t\t\t\t\t");
	system("pause");
	deleteMeun();
}

void DeleteName(head L)
{
	node P, TmpCell;
	char name[20];
	printf("\n\t\t\t\t\t");
	printf("请输入所要查询的职工姓名:  ");
	scanf("%s", name);
	P = FindNamePrevious(name, L);	    //调用职工号前驱指针查找函数,获得所需显示结点的前一结点
	if (IsLast(P, L) == 1)               //判断是否存在该员工
	{
		printf("\n\t\t\t\t\t无职工号为 %s 的员工!!!\n\t\t\t\t\t删除失败!!!\n\n", name);
		printf("\n\t\t\t\t\t");
		system("pause");
		deleteMeun();
	}
	else
	{
		Viewpeople(P->num);      //调用职工信息打印函数
		fflush(stdin);                   //清除键盘缓冲区
		printf("\n\t\t\t\t\t是否确认要删除？回复'Y'删除或其他字符取消删除\n");
		printf("\n\t\t\t\t\t");

		if (getchar() == 'Y')
		{
			TmpCell = P->next;
			P->next = TmpCell->next;
			free(TmpCell);
			printf("\n\t\t\t\t\t删除成功!!!\n\n");
			Save(L);                     //调用信息保存函数
			printf("\n\t\t\t\t\t");
			system("pause");
			deleteMeun();
		}
		else
		{
			printf("\n\t\t\t\t\t删除取消!!!\n\n");
			printf("\n\t\t\t\t\t");
			system("pause");
			deleteMeun();
		}

	}
	printf("\n\t\t\t\t\t");
	system("pause");
}



/********************************职工查询函数实现********************************************/


int fuzzy_search(char key[20], char str[20])
{
	/*
	int len = strlen(str);
	int i, j;
	int mode = 0;
	if (mode == 1)
		if (strlen(key) != len)
			return 0;
	for (i = 0; i + len - 1 < (int)strlen(key); i++)
		if (key[i] == str[0])
			for (j = 1; j < len; j++)
			{
				if (key[i + j] != str[j])
					break;
				if (j == len - 1)
					return 1;
			}*/
	if (strstr(str, key) != NULL)
		return 1;

	return 0;
}


//员工编号查询函数
void search_num(head L)
{
	char input[20];
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的编号：");
	scanf("%s", input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t 员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	//system("cls");
	for (i = 0; i < n; i++)
	{
		if (fuzzy_search(input, pp[i].num))
		{
			pp[i].paid_wages = pp[i].base_wage + pp[i].post_wage + pp[i].merit_pay +
				pp[i].subsidy + pp[i].bonus +
				pp[i].public_accumulation_fund - pp[i].tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time,
				pp[i].age,
				pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay,
				pp[i].subsidy, pp[i].bonus, pp[i].wages_payable,
				pp[i].public_accumulation_fund, pp[i].tax, pp[i].paid_wages);
		}
	}
	printf("\n\t\t\t\t\t\t\t");
	system("pause");
}

//员工名字查询函数
void search_name(head L)
{
	char input[20];
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的名字：");
	scanf("%s", input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (fuzzy_search(input, p->name))
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}

	system("pause");
}
//员工年龄查询函数
void search_age(head L)
{
	int input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的年龄：");
	scanf("%d", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->age)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}

//员工基本工资查询函数
void search_base(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的基本工资：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->base_wage)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}
//员工岗位工资查询函数
void search_post(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的岗位工资：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->post_wage)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}

//员工绩效工资查询函数
void search_merit(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的名字：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->merit_pay)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}

//员工住房补贴查询函数
void search_subsidy(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的住房补贴：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->subsidy)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}
//员工奖金查询函数
void search_bonus(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的奖金：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->bonus)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}
//员工应发工资查询函数
void search_payable(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的应发工资：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->wages_payable)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}

//员工公积金查询函数
void search_fund(head L)
{
	float input;
	node p = L->next;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t输入查询员工的公积金：");
	scanf("%f", &input);
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p)
	{
		if (input == p->public_accumulation_fund)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
		}
		p = p->next;
	}
	system("pause");
}

//组合搜索
void comb_search(head L)
{
	float base_wage;//基本工资
	float post_wage;//岗位工资
	float merit_pay;//绩效工资
	float subsidy;//住房补贴
	float bonus;//奖金
	float wages_payable;//应发工资
	float public_accumulation_fund;//公积金
	float tax;//税
	float paid_wages;//实发工资
	char test[10] = "0";
	node p = L->next;
	int t = 0;
	printf("\n\t\t\t\t\t\t以下信息，不确定项请填为0：\n");
	printf("\n\t\t\t\t\t\t请输入基本工资：");
	scanf("%f", &base_wage);
	printf("\n\t\t\t\t\t\t请输入岗位工资：");
	scanf("%f", &post_wage);
	printf("\n\t\t\t\t\t\t请输入绩效工资：");
	scanf("%f", &merit_pay);
	printf("\n\t\t\t\t\t\t请输入住房补贴：");
	scanf("%f", &subsidy);
	printf("\n\t\t\t\t\t\t请输入奖金：");
	scanf("%f", &bonus);
	printf("\n\t\t\t\t\t\t请输入公积金：");
	scanf("%f", &public_accumulation_fund);
	printf("\n\t\t\t\t\t\t请输入应发工资：");
	scanf("%f", &wages_payable);

	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t您输入的查找内容为：\n");
	printf("f基本工资\tg岗位工资\th绩效工资\ti住房补贴\tj奖金\tl公积金\tk应发工资");
	printf("\nf:%f\t g:%f\t h:%f\t i:%f\t j:%f\t l:%f\t k:%f", base_wage, post_wage, merit_pay, subsidy, bonus, public_accumulation_fund, wages_payable);
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	while (p != NULL)
	{
		if (base_wage != 0 && p->base_wage == base_wage)
			t = 1;

		if (post_wage != 0 && p->post_wage == post_wage)
			t = 1;

		if (merit_pay != 0 && p->merit_pay == merit_pay)
			t = 1;

		if (subsidy != 0 && p->subsidy == subsidy)
			t = 1;

		if (bonus != 0 && p->bonus == bonus)
			t = 1;

		if (wages_payable != 0 && p->wages_payable == wages_payable)
			t = 1;

		if (public_accumulation_fund != 0 && p->subsidy == public_accumulation_fund)
			t = 1;

		if (t == 1)
		{
			p->paid_wages = p->base_wage + p->post_wage + p->merit_pay +
				p->subsidy + p->bonus +
				p->public_accumulation_fund - p->tax;
			printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n", p->name, p->num, p->sex, p->time,
				p->age,
				p->base_wage, p->post_wage, p->merit_pay,
				p->subsidy, p->bonus, p->wages_payable,
				p->public_accumulation_fund, p->tax, p->paid_wages);
			//break;
		}
		p = p->next;
		t = 0;
	}
	system("pause");
}
/************************************员工信息排序函数****************************************************/


//排序后显示排序结果函数
void show_sort()
{
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工信息如下:\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - - - - - - - ----- - - - ---- -\n");
	printf(" a姓名 b编号   c性别 d入职时间 e年龄  f基本工资   g岗位工资   h绩效工资   i住房补贴   j奖金   k应发工资   l公积金   m税     n实发工资\n");
	printf("- - - - - -- - - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - -  - - - - - - - - - - ---- -\n");
	for (int p = 0; p < n; p++)
	{
		pp[p].paid_wages = pp[p].base_wage + pp[p].post_wage + pp[p].merit_pay +
			pp[p].subsidy + pp[p].bonus +
			pp[p].public_accumulation_fund - pp[p].tax;
		printf("a:%s b:%s c:%s d:%s  e:%d  f:%.1f  g:%.1f  h:%.1f  i:%.1f  j:%.1f   k:%.1f  l:%.1f  m:%.1f  n:%.1f\n",
			pp[p].name, pp[p].num, pp[p].sex, pp[p].time,
			pp[p].age,
			pp[p].base_wage, pp[p].post_wage, pp[p].merit_pay,
			pp[p].subsidy, pp[p].bonus, pp[p].wages_payable,
			pp[p].public_accumulation_fund, pp[p].tax, pp[p].paid_wages);
	}
	printf("            ");
	system("pause");
	sort_select_Meun();
}

//性别排序函数
void sort_sex(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if ((strcmp("男", pp[j].sex) != 0) && (strcmp("男", pp[k].sex) == 0))
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//编号升序函数
void sort_up_num(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (atoi(pp[j].num) < atoi(pp[k].num))
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//编号降序函数
void sort_down_num(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (atoi(pp[j].num) > atoi(pp[k].num))
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//年龄升序函数
void sort_up_age(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].age < pp[k].age)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

void sort_down_age(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].age > pp[k].age)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//基本工资升序函数
void sort_up_base_wage(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].base_wage < pp[k].base_wage)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//基本工资降序函数
void sort_down_base_wage(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].base_wage > pp[k].base_wage)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//岗位工资升序函数
void sort_up_post_wage(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].post_wage < pp[k].post_wage)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//岗位工资降序函数
void sort_down_post_wage(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].post_wage > pp[k].post_wage)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//绩效升序函数
void sort_up_merit_pay(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].merit_pay < pp[k].merit_pay)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//绩效降序函数
void sort_down_merit_pay(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].merit_pay > pp[k].merit_pay)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//住房补贴升序函数
void sort_up_subsidy(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].subsidy < pp[k].subsidy)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//住房补贴降序函数
void sort_down_subsidy(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].subsidy > pp[k].subsidy)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//奖金升序函数
void sort_up_bonus(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].bonus < pp[k].bonus)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//奖金降序函数
void sort_down_bonus(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].bonus > pp[k].bonus)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//应发工资升序函数
void sort_up_wages_payable(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].wages_payable < pp[k].wages_payable)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}
//应发工资降序函数
void sort_down_wages_payable(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].wages_payable > pp[k].wages_payable)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//公积金升序函数
void sort_up_public_accumulation_fund(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].public_accumulation_fund < pp[k].public_accumulation_fund)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//公积金降序函数
void sort_down_public_accumulation_fund(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].public_accumulation_fund > pp[k].public_accumulation_fund)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//税升序函数
void sort_up_tax(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].tax < pp[k].tax)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//税降序函数
void sort_down_tax(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].tax > pp[k].tax)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

//实发工资升序函数
void sort_up_paid_wages(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (i = 0; i < n; i++)
	{
		pp[i].paid_wages = pp[i].base_wage + pp[i].post_wage + pp[i].merit_pay +
			pp[i].subsidy + pp[i].bonus +
			pp[i].public_accumulation_fund - pp[i].tax;
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].paid_wages < pp[k].paid_wages)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

void sort_down_paid_wages(struct people pp[500])
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (i = 0; i < n; i++)
	{
		pp[i].paid_wages = pp[i].base_wage + pp[i].post_wage + pp[i].merit_pay +
			pp[i].subsidy + pp[i].bonus +
			pp[i].public_accumulation_fund - pp[i].tax;
	}
	for (j = 0; j < n - 1; j++)
	{
		for (k = j + 1; k < n; k++)
		{
			if (pp[j].paid_wages > pp[k].paid_wages)
			{
				forsort = pp[j];
				pp[j] = pp[k];
				pp[k] = forsort;
			}
		}
	}
	show_sort();
	fclose(fp);
}

/*********************************修改函数**********************************************/

void change_name(struct people pp[500])
{
	head L = NULL;
	L = Init(L);
	system("cls");
	char num[10];
	char new_name[10];
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的名字：");
				scanf("%s", new_name);
				if (Testx(new_name))
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的员工姓名\n ");
					printf("\n\t\t\t\t\t\t\t");
					system("pause");
					break;
				}
				if (!IsLast(FindNamePrevious(new_name, L), L))             //连续调用 职工号前驱指针查找函数 判断链尾函数,判断该职工号是否已存在
				{
					printf("\n\t\t\t\t\t\t\t员工编号 %s 已存在!!!\n\n", new_name);
					printf("\n\t\t\t\t\t\t\t");
					system("pause");
					return;                                     //退出并返回上一级菜单
				}

				strcpy(pp[i].name, new_name);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}


void change_admin_password()//修改管理员密码
{
	char old_password[10];
	char new_password[10];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("管理员账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < 1; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您之前的密码用于验证您是否为本人操作：");
	scanf("%s", old_password);
	if (strlen(old_password) != 8)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\t\t\t\t\t管理员密码为8位,请确定后输入");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_admin_password();
		return;
	}
	for (int i = 0; i < 1; i++)
	{
		if (strcmp(old_password, pp[i].password) == 0)
		{
			printf("\n\t\t\t\t\t\t\t请输入新的密码：");
			scanf("%s", new_password);
			if (strlen(new_password) != 8)
			{
				printf("\n\t\t\t\t\t\t\t密码格式无效，请输入8位密码！！！");
				printf("\n\t\t\t\t\t\t\t");
				system("pause");
				change_admin_password();
				break;
			}
			strcpy(pp[i].password, new_password);
			printf("\n\t\t\t\t\t\t\t密码修改成功!!!");
			break;
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t密码错误！！！ 即将退出登录");
			printf("\n\t\t\t\t\t\t\t");
			system("pause");
			identity_judge();
		}
	}
	fclose(fp);
	fpw = fopen("管理员账号.txt", "w");
	for (int i = 0; i < 1; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void admin_change_people_password()//用于管理员修改职工密码
{
	char num[10];
	char new_password[10];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("                         文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	while (Test8(num))
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\t\t\t\t员工编号为8位数字,请确定后输入");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		admin_change_people_password();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) == 0)
		{
			printf("\n");
			printf("\n");
			printf("\n\t\t\t\t\t\t\t请输入新的8位密码：");
			scanf("%s", new_password);
			if (strlen(new_password) != 8)
			{
				printf("\n\t\t\t\t\t\t\t密码格式无效，请输入8位密码！！！");
				printf("\n\t\t\t\t\t\t\t");
				system("pause");
				admin_change_people_password();
				break;
			}
			strcpy(pp[i].password, new_password);
			printf("\n\t\t\t\t\t\t\t密码修改成功!!!");
			break;
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void people_change_people_password()//用于用户修改自己密码
{
	char old_password[10];
	char new_password[10];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您之前的密码用于验证您是否为本人操作：");
	scanf("%s", old_password);
	if (strlen(old_password) != 8)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
		printf("\n");
		printf("\n");
		printf("\n\t\t\t\t\t\t\t员工密码为8位,请确定后输入");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		people_change_people_password();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(old_password, pp[i].password) == 0)
		{
			printf("\n\t\t\t\t\t\t\t请输入新的密码：");
			scanf("%s", new_password);
			if (strlen(new_password) != 8)
			{
				printf("\n\t\t\t\t\t\t\t密码格式无效，请输入8位密码！！！");
				printf("\n\t\t\t\t\t\t\t");
				system("pause");
				admin_change_people_password();
				break;
			}
			strcpy(pp[i].password, new_password);
			printf("\n\t\t\t\t\t\t\t密码修改成功!!!");
			break;
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t密码错误！！！ 即将退出登录");
			printf("\n\t\t\t\t\t\t\t");
			system("pause");
			identity_judge();
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_age(struct people pp[500])
{
	char num[10];
	char new_age[10];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的年龄：");
				scanf("%s", new_age);
				testnum = Testnum1(new_age);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的年龄 ");
					scanf("%s", new_age);
					testnum = Testnum1(new_age);
				}
				pp[i].age = atoi(new_age);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_base_wage(struct people pp[500])
{
	char num[10];
	char base_wage[200];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的基本工资：");
				scanf("%s", base_wage);
				testnum = Testnum1(base_wage);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的基本工资 ");
					scanf("%s", base_wage);
					testnum = Testnum1(base_wage);
				}
				pp[i].base_wage = atoi(base_wage);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_post_wage(struct people pp[500])
{
	char num[10];
	char post_wage[10];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的岗位工资：");
				scanf("%s", post_wage);
				testnum = Testnum1(post_wage);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的岗位工资 ");
					scanf("%s", post_wage);
					testnum = Testnum1(post_wage);
				}
				pp[i].post_wage = atoi(post_wage);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_merit_pay(struct people pp[500])
{
	char num[10];
	char merit_pay[10];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的绩效工资：");
				scanf("%s", merit_pay);
				testnum = Testnum1(merit_pay);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的绩效工资 ");
					scanf("%s", merit_pay);
					testnum = Testnum1(merit_pay);
				}
				pp[i].merit_pay = atoi(merit_pay);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_subsidy(struct people pp[500])
{
	char num[10];
	char subsidy[10];
	int k = 0;
	int testnum;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的住房补贴：");
				scanf("%s", subsidy);
				testnum = Testnum1(subsidy);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的住房补贴 ");
					scanf("%s", subsidy);
					testnum = Testnum1(subsidy);
				}
				pp[i].subsidy = atoi(subsidy);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_bonus(struct people pp[500])
{
	char num[10];
	char bonus[10];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的奖金：");
				scanf("%s", bonus);
				testnum = Testnum1(bonus);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的奖金 ");
					scanf("%s", bonus);
					testnum = Testnum1(bonus);
				}
				pp[i].bonus = atoi(bonus);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_wages_payable(struct people pp[500])
{
	char num[10];
	char wages_payable[10];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的应发工资：");
				scanf("%s", wages_payable);
				testnum = Testnum1(wages_payable);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的应发工资 ");
					scanf("%s", wages_payable);
					testnum = Testnum1(wages_payable);
				}
				pp[i].wages_payable = atoi(wages_payable);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}

void change_public_accumulation_fund(struct people pp[500])
{
	char num[10];
	char public_accumulation_fund[10];
	int testnum;
	int k = 0;
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	printf("\n\t\t\t\t\t\t\t请输入您想修改的该员工的编号：");
	scanf("%s", num);
	if (Test8(num))
	{
		printf("\n\t\t\t\t\t\t\t请输入正确的8位员工编号！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(num, pp[i].num) != 0)
		{
			k++;
		}
	}
	if (k == n)
	{
		printf("\n\t\t\t\t\t\t\t您输入的员工编号错误，请重新输入！！！\n");
		printf("\n\t\t\t\t\t\t\t");
		system("pause");
		change_name(pp);
		return;
	}
	if (k < n)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(num, pp[i].num) == 0)
			{
				printf("\n\t\t\t\t\t\t\t请输入新的公积金：");
				scanf("%s", public_accumulation_fund);
				testnum = Testnum1(public_accumulation_fund);
				while (testnum)
				{
					printf("\n\t\t\t\t\t\t\t请输入正确的公积金 ");
					scanf("%s", public_accumulation_fund);
					testnum = Testnum1(public_accumulation_fund);
				}
				pp[i].public_accumulation_fund = atoi(public_accumulation_fund);
				printf("\n\t\t\t\t\t\t\t修改成功！！！");
				break;
			}
		}
	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}


/****************************************税金计算函数**********************************************************************/

void calculate_tax(struct people pp[500])//计算税金
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (int j = 0; j < n; j++)
	{
		pp[j].wages_payable = pp[j].base_wage + pp[j].post_wage + pp[j].merit_pay +
			pp[j].subsidy + pp[j].bonus + pp[j].public_accumulation_fund;
		if (pp[j].wages_payable <= 5000)
			pp[j].tax = 0;
		if (pp[j].wages_payable > 5000 && pp[j].wages_payable <= 8000)
			pp[j].tax = pp[j].wages_payable * tax_rate[0];
		if (pp[j].wages_payable > 8000 && pp[j].wages_payable <= 17000)
			pp[j].tax = pp[j].wages_payable * tax_rate[1];
		if (pp[j].wages_payable > 17000 && pp[j].wages_payable <= 30000)
			pp[j].tax = pp[j].wages_payable * tax_rate[2];
		if (pp[j].wages_payable > 30000 && pp[j].wages_payable <= 40000)
			pp[j].tax = pp[j].wages_payable * tax_rate[3];
		if (pp[j].wages_payable > 40000 && pp[j].wages_payable <= 60000)
			pp[j].tax = pp[j].wages_payable * tax_rate[4];
		if (pp[j].wages_payable > 60000 && pp[j].wages_payable <= 85000)
			pp[j].tax = pp[j].wages_payable * tax_rate[5];
		if (pp[j].wages_payable > 85000)
			pp[j].tax = pp[j].wages_payable * tax_rate[6];
	}
	fclose(fp);
}


/******************************************整理数据函数*****************************************************************/

void show_sort_date(struct people pp[500])
{
	FILE* fp;
	calculate_tax(pp);
	float max_base_wage = pp[0].base_wage, min_base_wage = pp[0].base_wage, aver_base_wage = 0;
	float max_post_wage = pp[0].post_wage, min_post_wage = pp[0].post_wage, aver_post_wage = 0;
	float max_merit_pay = pp[0].merit_pay, min_merit_pay = pp[0].merit_pay, aver_merit_pay = 0;
	float max_subsidy = pp[0].subsidy, min_subsidy = pp[0].subsidy, aver_subsidy = 0;
	float max_bonus = pp[0].bonus, min_bonus = pp[0].bonus, aver_bonus = 0;
	float max_wages_payable = pp[0].wages_payable, min_wages_payable = pp[0].wages_payable, aver_wages_payable = 0;
	float max_public_accumulation_fund = pp[0].public_accumulation_fund, min_public_accumulation_fund = pp[0].public_accumulation_fund, aver_public_accumulation_fund = 0;
	float max_tax = pp[0].tax, min_tax = pp[0].tax, aver_tax = 0;
	for (int i = 0; i < n; i++)
	{
		pp[i].paid_wages = pp[i].base_wage + pp[i].post_wage + pp[i].merit_pay + pp[i].subsidy + pp[i].bonus + pp[i].public_accumulation_fund
			- pp[i].tax;
	}
	float max_paid_wages = pp[0].paid_wages, min_paid_wages = pp[0].paid_wages, aver_paid_wages = 0;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
	}
	for (int i = 0; i < n; i++)
	{
		if (pp[i].base_wage > max_base_wage)
		{
			max_base_wage = pp[i].base_wage;
		}
		if (pp[i].base_wage < min_base_wage)
		{
			min_base_wage = pp[i].base_wage;
		}
	}//基本工资排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].post_wage > max_post_wage)
		{
			max_post_wage = pp[i].post_wage;
		}
		if (pp[i].post_wage < min_post_wage)
		{
			min_post_wage = pp[i].post_wage;
		}
	}
	//岗位工资排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].merit_pay > max_merit_pay)
		{
			max_merit_pay = pp[i].merit_pay;
		}
		if (pp[i].merit_pay < min_merit_pay)
		{
			min_merit_pay = pp[i].merit_pay;
		}
	}//绩效工资排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].subsidy > max_subsidy)
		{
			max_subsidy = pp[i].subsidy;
		}
		if (pp[i].subsidy < min_subsidy)
		{
			min_subsidy = pp[i].subsidy;
		}
	}//住房补贴排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].bonus > max_bonus)
		{
			max_bonus = pp[i].bonus;
		}
		if (pp[i].bonus < min_bonus)
		{
			min_bonus = pp[i].bonus;
		}
	}//奖金排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].wages_payable > max_wages_payable)
		{
			max_wages_payable = pp[i].wages_payable;
		}
		if (pp[i].wages_payable < min_wages_payable)
		{
			min_wages_payable = pp[i].wages_payable;
		}
	}//应发工资排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].public_accumulation_fund > max_public_accumulation_fund)
		{
			max_public_accumulation_fund = pp[i].public_accumulation_fund;
		}
		if (pp[i].public_accumulation_fund < min_public_accumulation_fund)
		{
			min_public_accumulation_fund = pp[i].public_accumulation_fund;
		}
	}//公积金排序
	for (int i = 0; i < n; i++)
	{
		if (pp[i].tax > max_tax)
		{
			max_tax = pp[i].tax;
		}
		if (pp[i].tax < min_tax)
		{
			min_tax = pp[i].tax;
		}
	}//税金排序
	for (int i = 0; i < n; i++)
	{
		pp[i].paid_wages = pp[i].base_wage + pp[i].post_wage + pp[i].merit_pay + pp[i].subsidy + pp[i].bonus + pp[i].public_accumulation_fund
			- pp[i].tax;
		aver_base_wage += pp[i].base_wage;
		aver_post_wage += pp[i].post_wage;
		aver_merit_pay += pp[i].merit_pay;
		aver_subsidy += pp[i].subsidy;
		aver_bonus += pp[i].bonus;
		aver_wages_payable += pp[i].wages_payable;
		aver_public_accumulation_fund += pp[i].public_accumulation_fund;
		aver_tax += pp[i].tax;
	}
	for (int i = 0; i < n; i++)
	{
		if (pp[i].paid_wages > max_paid_wages)
		{
			max_paid_wages = pp[i].paid_wages;
		}
		if (pp[i].paid_wages < min_paid_wages)
		{
			min_paid_wages = pp[i].paid_wages;
		}
	}//实发工资排序
	for (int i = 0; i < n; i++)
	{
		aver_paid_wages += pp[i].paid_wages;
	}
	aver_paid_wages /= 1.0 * n;
	aver_base_wage /= 1.0 * n;
	aver_post_wage /= 1.0 * n;
	aver_merit_pay /= 1.0 * n;
	aver_subsidy /= 1.0 * n;
	aver_bonus /= 1.0 * n;
	aver_wages_payable /= 1.0 * n;
	aver_public_accumulation_fund /= 1.0 * n;
	aver_tax /= 1.0 * n;
	printf("正在整理数据中，请稍候\n");
	printf("\n\t\t\t\t\t\t\t整理成功！！！\n");
	printf("\n\t\t\t\t\t\t\t所有的数据中：\n");
	printf("\n");
	printf("\n\t\t\t\t\t基本工资最高为：%.1f\t基本工资最低为：%.1f\t基本工资平均为：%.1f\n", max_base_wage, min_base_wage, aver_base_wage);
	printf("\n");
	printf("\n\t\t\t\t\t岗位工资最高为：%.1f\t岗位工资最低为：%.1f\t岗位工资平均为：%.1f\n", max_post_wage, min_post_wage, aver_post_wage);
	printf("\n");
	printf("\n\t\t\t\t\t绩效工资最高为：%.1f\t绩效工资最低为：%.1f\t绩效工资平均为：%.1f\n", max_merit_pay, min_merit_pay, aver_merit_pay);
	printf("\n");
	printf("\n\t\t\t\t\t住房津贴最高为：%.1f\t住房津贴最低为：%.1f\t住房津贴平均为：%.1f\n", max_subsidy, min_subsidy, aver_subsidy);
	printf("\n");
	printf("\n\t\t\t\t\t奖金最高为：%.1f\t奖金最低为：%.1f\t奖金平均为：%.1f\n", max_bonus, min_bonus, aver_bonus);
	printf("\n");
	printf("\n\t\t\t\t\t公积金最高为：%.1f\t公积金最低为：%.1f\t公积金平均为：%.1f\n", max_public_accumulation_fund, min_public_accumulation_fund, aver_public_accumulation_fund);
	printf("\n");
	printf("\n\t\t\t\t\t税最高为：%.1f\t税最低为：%.1f\t        税平均为：%.1f\n", max_tax, min_tax, aver_tax);
	printf("\n");
	printf("\n\t\t\t\t\t应发工资最高为：%.1f\t应发工资最低为：%.1f\t应发工资平均为：%.1f\n", max_wages_payable, min_wages_payable, aver_wages_payable);
	printf("\n");
	printf("\n\t\t\t\t\t实发工资最高为：%.1f\t实发工资最低为：%.1f\t实发工资平均为：%.1f\n", max_paid_wages, min_paid_wages, aver_paid_wages);

	system("pause");

	fclose(fp);
}

/***********************************************************************************************************************/



/*****************************登录判断，分管理员用户两个接口，分别接向不同的权限功能*******************************/


void identity_judge()//登录身份判断
{
	char identity_num[100];
	int x;
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t  ************************\n");
	printf("\n\t\t\t\t\t\t  ******1.我是管理员******\n");
	printf(" \n\t\t\t\t\t\t  ************************\n");
	printf("\n\t\t\t\t\t\t  *******2.我是员工*******\n");
	printf("\n\t\t\t\t\t\t  ************************\n");
	printf("\n");
	printf("\n\t\t\t\t\t          请输入对应数字选择您的身份:");
	fflush(stdin);                   //清除键盘缓冲区
	scanf("%s", identity_num);
	x = Test1(identity_num, 1, 2);
	switch (x)
	{
	case 1:admin_judge_window();//进入管理员登录界面
		break;
	case 2:people_judge_window();//进入员工登录界面
		break;
	}
}

void admin_judge_window()//管理员登录
{
	int number[3] = { 0,0,0 };
	admin_chance_judge(number);
	if (*number == 500)
	{
		printf("\n\n");
		printf("\t\t\t\t\t        输入错误，您还有2次机会,请重新输入\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		admin_chance_judge(number + 1);
	}
	if (*(number + 1) == 500)
	{
		printf("\n\n");
		printf("\t\t\t\t\t        输入错误，您还有1次机会,请重新输入\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		admin_chance_judge(number + 2);
	}
	if (*(number + 2) == 500)
	{
		printf("\n\n");
		printf("\t\t\t\t\t        三次机会已用完，系统将自动关闭，欢迎您的使用\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		exit(0);
	}
}

void people_judge_window()//员工登录
{
	int number[3] = { 0,0,0 };
	people_chance_judge(number);
	if (*number == 500)
	{
		printf("\n\n");
		printf("\t\t\t\t\t        输入错误，您还有2次机会,请重新输入\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		people_chance_judge(number + 1);
	}
	if (*(number + 1) == 500)
	{
		printf("\n\n");
		printf("\t\t\t\t\t        输入错误，您还有1次机会,请重新输入\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		people_chance_judge(number + 2);
	}
	if (*(number + 2) == 500)
	{
		printf("\n\n");
		printf("\t\t\t\t\t        三次机会已用完，系统将自动关闭，欢迎您的使用\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t");
		system("pause");
		exit(0);
	}
}

int admin_chance_judge(int* number)//管理员登录剩余次数判断函数
{
	FILE* fp;
	if ((fp = fopen("管理员账号.txt", "r")) == NULL)
	{
		printf("\n\t\t\t\t\t\t\t文件打开失败\n");
	}
	char num[20], password[10];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t请输入八位管理员账号：");
	scanf("%s", num);
	printf("\n");
	for (int i = 0; i < 500; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
		if (strcmp(num, pp[i].num) == 0)
		{
			printf("\n\t\t\t\t\t\t请输入八位管理员密码：");
			scanf("%s", password);
			if (strcmp(password, pp[i].password) == 0)
			{
				system("cls");
				printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n\t\t\t\t\t\t\t管理员登陆成功！");
				printf("\n");
				printf("\n");
				printf("\n\t\t\t\t\t\t\t");
				system("pause");
				adminMainMeun();
				break;
			}
			else
			{
				(*number)++;
			}
		}
		else
		{
			(*number)++;
		}
	}

	fclose(fp);
	return *number;
}


int people_chance_judge(int* number)//员工登录剩余次数判断函数
{
	FILE* fp;
	if ((fp = fopen("职工账号.txt", "r")) == NULL)
	{
		printf("\n\t\t\t\t\t文件打开失败\n");
	}
	char num[20], password[20];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t请输入八位员工账号：");
	scanf("%s", &num);
	printf("\n");
	for (int i = 0; i < 500; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax);
		if (strcmp(num, pp[i].num) == 0)
		{
			printf("\n\t\t\t\t\t\t请输入八位员工密码：");
			scanf("%s", &password);
			if (strcmp(password, pp[i].password) == 0)
			{
				printf("\n\t\t\t\t\t\t\t员工登陆成功！");
				Viewpeople(num);
				peopleMainMeun();
				break;
			}
			else
			{
				(*number)++;
			}
		}
		else
		{
			(*number)++;
		}
	}
	fclose(fp);
	return *number;
}

/*void change_admin_password()//修改管理员密码
{
	char inital_password[20];
	char new_password[20];
	char renew_password[20];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t请输入原密码：");
	scanf("%s", inital_password);
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("管理员账号.txt", "r+")) == NULL)
	{
		printf("                         文件打开失败\n");
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f", &pp[0].name, &pp[0].num, &pp[0].sex, &pp[0].time, &pp[0].password,
			&pp[0].age,
			&pp[0].base_wage, &pp[0].post_wage, &pp[0].merit_pay, &pp[0].subsidy, &pp[0].bonus, &pp[0].wages_payable, &pp[0].public_accumulation_fund,
			&pp[0].tax);
		if (strcmp(inital_password, pp[0].password) == 0)
		{
			printf("\n");
			printf("\n");
			printf("                         请输入要修改的新密码：");
			scanf("%s", new_password);
			printf("\n");
			printf("\n");
			printf("                         请再次输入要修改的新密码：");
			scanf("%s", renew_password);
			printf("\n");
			printf("\n");
			if (strcmp(new_password, renew_password) == 0)
			{
				strcpy(pp[0].password, renew_password);
				printf("                         管理员密码修改成功\n");
				printf("\n");
				printf("\n");
				printf("                         ");
				system("pause");
			}
			else
			{
				printf("\n                         密码错误,即将退出系统");
				printf("\n                         ");
				system("pause");
				identity_judge();
			}
			break;
		}
	}
	fclose(fp);
	fpw = fopen("管理员账号.txt", "w");
	fprintf(fpw, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[0].name, pp[0].num, pp[0].sex, pp[0].time, pp[0].password,
		pp[0].age,
		pp[0].base_wage, pp[0].post_wage, pp[0].merit_pay, pp[0].subsidy, pp[0].bonus, pp[0].wages_payable, pp[0].public_accumulation_fund,
		pp[0].tax);
	fclose(fpw);
}

void change_people_password()//修改职工密码
{
	int x;
	char inital_password[20];
	char new_password[20];
	char renew_password[20];
	system("cls");
	printf("\n\t\t\t\t\t\t\t员工工资管理系统\n");
	printf("\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t请输入原密码：");
	scanf("%s", inital_password);
	FILE* fp;
	FILE* fpw;
	if ((fp = fopen("职工账号.txt", "r+")) == NULL)
	{
		printf("                         文件打开失败\n");
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s %s %d %f %f %f %f %f %f %f %f %f", &pp[i].name, &pp[i].num, &pp[i].sex, &pp[i].time, &pp[i].password,
			&pp[i].age,
			&pp[i].base_wage, &pp[i].post_wage, &pp[i].merit_pay, &pp[i].subsidy, &pp[i].bonus, &pp[i].wages_payable, &pp[i].public_accumulation_fund,
			&pp[i].tax, &pp[i].paid_wages);
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(inital_password, pp[i].password) == 0)
		{

			printf("\n");
			printf("\n");
			printf("                         请输入要修改的新密码：");
			scanf("%s", new_password);
			printf("\n");
			printf("\n");
			printf("                         请再次输入要修改的新密码：");
			scanf("%s", renew_password);
			x = scanf("%s", renew_password);
			while (x)
			{

				if (strcmp(new_password, renew_password) == 0)
				{
					strcpy(pp[i].password, renew_password);
					printf("                         管理员密码修改成功\n");
					printf("\n");
					printf("\n");
					printf("                         ");
					system("pause");
					break;
				}
				else
				{
					printf("                         输入的密码不一致，密码修改失败");
					printf("\n");
					printf("\n");
					printf("                         ");
					system("pause");
					break;
				}
			}
		}
		else
		{
			printf("\n                         密码错误,即将退出登录");
			printf("\n                         ");
			system("pause");
			identity_judge();
			break;
		}

	}
	fclose(fp);
	fpw = fopen("职工账号.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s %s %s %s %s %d %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n", pp[i].name, pp[i].num, pp[i].sex, pp[i].time, pp[i].password,
			pp[i].age,
			pp[i].base_wage, pp[i].post_wage, pp[i].merit_pay, pp[i].subsidy, pp[i].bonus, pp[i].wages_payable, pp[i].public_accumulation_fund,
			pp[i].tax);
	}
	fclose(fpw);
}*/




/*******************************************************文件数据处理函数****************************************************/

//文件备份


//node copeData()
//{
//	head L = NULL;
//	node pm = L;
//	node head2 = NULL;
//	node end2 = NULL;
//	while (pm != NULL)
//	{
//		node pn = (node)malloc(sizeof(people1));//指向空间
//		strcpy(pn->num, pm->num);//赋值
//		strcpy(pn->name, pm->name);//赋值
//		strcpy(pn->sex, pm->sex);//赋值
//		strcpy(pn->time, pm->time);//赋值
//		strcpy(pn->password, pm->password);//赋值
//		pn->age = pm->age;//赋值
//		strcpy(pn->address, pm->address);//赋值
//		pn->scoreEnglish = pm->scoreEnglish;//赋值
//		pn->scoreMath = pm->scoreMath;//赋值
//		pn->scoreC = pm->scoreC;//赋值
//		strcpy(pn->password, pm->password);
//		pn->next = NULL;
//		pm = pm->next;
//		if (head2 == NULL || end2 == NULL)//原来链表为空情况
//		{
//			head2 = pn;
//			end2 = pn;
//		}
//		else//链表不为空情况
//		{
//			end2->next = pn;
//			end2 = pn;
//		}
//	}
//	return head2;
//}



/***************************************************主函数**********************************************************************/


int main()
{
	head L = NULL;
	L = Init(L);
	int* number1 = 00000000;
	int* number2 = 00000000;
	//更改标题
	system("title 工资管理系统");
	system("color f1");
	system("mode con cols=135 lines=30");
	//换行居中
	printf("\n                     ");
	identity_judge();
}





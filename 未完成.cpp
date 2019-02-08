#include<iostream>
#include<cstring>
#define MAXLINE 1024
using namespace std;
struct train
{
	int DingDanHao;
	char CheCi[20];
	char place[30][30];
	int Left=100;
};
train TR[50];
void welcome()
{ 
	cout << "________________________________________________________" << endl;	
	cout << "|             火 车 票 管 理 系 统                     |" << endl;	
	cout << "|                                                      |" << endl;	
	cout << "|             管理系统有以下功能:                      |" << endl;	
	cout << "|                                                      |" << endl;	
	cout << "|                 1 录入班次信息                       |" << endl;	
	cout << "|                 2 操作班次信息                       |" << endl;	
	cout << "|                 3 查询火车信息                       |" << endl;	
	cout << "|                 4 售票与退票系统                     |" << endl;	
	cout << "|                 5 导出票务系统                       |" << endl;	
	cout << "|                 6 退出系统                           |" << endl;	
	cout << "|______________________________________________________|" << endl;	
	cout << "请选择你所需的功能: " << endl;	
	choose();
}
void choose() 
{ 
	int i;
	cin >> i;
	if (i == 1)		
		write();	
	if (i == 2)		
		change();	
	if (i == 3)		
		select();	
	if (i == 4)		
		buy();	
	if (i == 5)		
		update();	
	if (i == 6)		
		quit();	
	else 
	{ 
		cout << "输入有误!请在数字1-5之间重新您的输入选择!" << endl;		
		choose(); 
	} 
}
void write()
{
	FILE *fp;
	fp = fopen("train.txt", "r");
	if (!fp)
	{
		cout << "File can't be opened" << endl;
		exit(0);
	}
	char buf[MAXLINE];       //缓冲区
	int len;                 //行字符个数  
	while (fgets(buf, MAXLINE, fp) != NULL)
	{
		len = strlen(buf);
		buf[len - 1] = '\0';  /*去掉换行符*/
		for (int i = 0; i < len; i++)
		{
			if (buf[i] == ',')
				continue;
			TR[0].CheCi[0] = buf[i];
		}
	}
}
void change()
{
	cout << "_____________________________" << endl;
	cout << "|      1.添加/修改班次      |" << endl;
	cout << "|      2.删除班次           |" << endl;
	cout << "|      3.返回主菜单         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "请选择你所需要的功能：" << endl;
	int j;
	cin >> j;
	if(j==1)

}
void quit()

{
	cout << "*********************谢谢使用本系统，欢迎下次继续使用***********************" << endl;
}
int main()
{
	welcome();
	choose();
	return 0;
}


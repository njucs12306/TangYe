#include<iostream>
#include<cstring>
void welcome();
void choose();
int write();
void change();
void search();
void quit();
#define MAXLINE 1024
using namespace std;
struct traininfo
{
	char num[20];
	char place[30][30];
	int left;
};
traininfo TR[50];
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
	int i;
	cin >> i;
	if (i == 1)		
		write();
	else if (i == 2)		change();
	else if (i == 3)
		search();
	else if (i == 4)
		buy();
	else if (i == 5)
		print();
	else if (i == 6)		
		quit();	
	else
	{
		cout << "输入有误!请在数字1-6之间重新您的输入选择!" << endl;
		welcome();
	}
}
int write()
{
	cout << "请输入文件名：";
	char filename[20];
	cin >> filename;
	FILE *fp;
	fp = fopen(filename, "r");
	if (!fp)
	{
		cout << "File can't be opened" << endl;
		cout << "文件无法被打开，录入火车信息失败，是否继续录入？（Y/N）";
		char ch2;
		cin >> ch2;
		if (ch2 == 'Y')
			write();
		else
			quit();
	}
	char buf[MAXLINE];       //缓冲区
	int len;                //行字符个数
	int j = 0;             //火车计数器
	int i, t, r;
	while (fgets(buf, MAXLINE, fp) != NULL)
	{
		len = strlen(buf);
		int k = 0;               //经停站计数器
		int n = 0;              //字符串计数器
		buf[len - 1] = '\0';   //去掉换行符
		for (i = 0; buf[i] != ','; i++)
			TR[j].num[i] = buf[i];
		for (t = i + 1; buf[t] != '|'; t++)
			TR[j].left = TR[j].left * 10 + buf[t] - '0';
		for (r = t + 1; r < len; r++)
		{
			if (buf[r] != '|')
			{
				TR[j].place[k][n] = buf[r];
				n++;
			}
			else
			{
				k++;
				n = 0;
			}
		}
		j++;
	}
	cout << "录入火车信息成功，是否继续？（Y/N）";
	char ch;
	cin >> ch;
	if (ch == 'Y')
		welcome();
	else
		quit();
}
void change()
{
	int w = write();
	cout << "_____________________________" << endl;
	cout << "|      1.添加/修改班次      |" << endl;
	cout << "|      2.删除班次           |" << endl;
	cout << "|      3.返回主菜单         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "请选择你所需要的功能：" << endl;
	int j;
	cin >> j;
	if (j == 1)
	{
		cout << "请输入班次信息：";
		char NewTrain[MAXLINE];
		cin >> NewTrain;
		int len = strlen(NewTrain);
		int k = 0;             
		int n = 0; 
		int i, t, r;
		for (i = 0; NewTrain[i] != ','; i++)
			TR[w+1].num[i] = NewTrain[i];
		for (t = i + 1; NewTrain[t] != '|'; t++)
			TR[w+1].left = TR[w + 1].left * 10 + NewTrain[t] - '0';
		for (r = t + 1; r < len; r++)
		{
			if (NewTrain[r] != '|')
			{
				TR[w + 1].place[k][n] = NewTrain[r];
				n++;
			}
			else
			{
				k++;
				n = 0;
			}
		}
		cout << "添加成功！";
	}
	else if(j==2)
	else
	{
		welcome();
	}
}
void search()
{
	cout << "_____________________________" << endl;
	cout << "|      1.按班次查询         |" << endl;
	cout << "|      2.按出发/到达站查询  |" << endl;
	cout << "|      3.返回主菜单         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "请选择你所需要的功能：" << endl;
	int j;
	cin >> j;
}
void buy()
{
	cout << "_____________________________" << endl;
	cout << "|      1.售票               |" << endl;
	cout << "|      2.订单浏览           |" << endl;
	cout << "|      3.退票               |" << endl;
	cout << "|      4.返回主菜单         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "请选择你所需要的功能：" << endl;
	int j;
	cin >> j;
}
void print()
{
	cout << "_____________________________" << endl;
	cout << "|      1.添加/修改班次      |" << endl;
	cout << "|      2.返回主菜单         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "请选择你所需要的功能：" << endl;
	int j;
	cin >> j;
}
void quit()

{
	cout << "*********************谢谢使用本系统，欢迎下次继续使用***********************" << endl;
}
int main()
{
	welcome();
	return 0;
}


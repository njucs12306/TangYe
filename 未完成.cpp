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
	cout << "|             �� �� Ʊ �� �� ϵ ͳ                     |" << endl;	
	cout << "|                                                      |" << endl;	
	cout << "|             ����ϵͳ�����¹���:                      |" << endl;	
	cout << "|                                                      |" << endl;	
	cout << "|                 1 ¼������Ϣ                       |" << endl;	
	cout << "|                 2 ���������Ϣ                       |" << endl;	
	cout << "|                 3 ��ѯ����Ϣ                       |" << endl;	
	cout << "|                 4 ��Ʊ����Ʊϵͳ                     |" << endl;	
	cout << "|                 5 ����Ʊ��ϵͳ                       |" << endl;	
	cout << "|                 6 �˳�ϵͳ                           |" << endl;	
	cout << "|______________________________________________________|" << endl;	
	cout << "��ѡ��������Ĺ���: " << endl;	
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
		cout << "��������!��������1-5֮��������������ѡ��!" << endl;		
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
	char buf[MAXLINE];       //������
	int len;                 //���ַ�����  
	while (fgets(buf, MAXLINE, fp) != NULL)
	{
		len = strlen(buf);
		buf[len - 1] = '\0';  /*ȥ�����з�*/
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
	cout << "|      1.���/�޸İ��      |" << endl;
	cout << "|      2.ɾ�����           |" << endl;
	cout << "|      3.�������˵�         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "��ѡ��������Ҫ�Ĺ��ܣ�" << endl;
	int j;
	cin >> j;
	if(j==1)

}
void quit()

{
	cout << "*********************ллʹ�ñ�ϵͳ����ӭ�´μ���ʹ��***********************" << endl;
}
int main()
{
	welcome();
	choose();
	return 0;
}


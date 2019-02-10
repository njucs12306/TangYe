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
		cout << "��������!��������1-6֮��������������ѡ��!" << endl;
		welcome();
	}
}
int write()
{
	cout << "�������ļ�����";
	char filename[20];
	cin >> filename;
	FILE *fp;
	fp = fopen(filename, "r");
	if (!fp)
	{
		cout << "File can't be opened" << endl;
		cout << "�ļ��޷����򿪣�¼�����Ϣʧ�ܣ��Ƿ����¼�룿��Y/N��";
		char ch2;
		cin >> ch2;
		if (ch2 == 'Y')
			write();
		else
			quit();
	}
	char buf[MAXLINE];       //������
	int len;                //���ַ�����
	int j = 0;             //�𳵼�����
	int i, t, r;
	while (fgets(buf, MAXLINE, fp) != NULL)
	{
		len = strlen(buf);
		int k = 0;               //��ͣվ������
		int n = 0;              //�ַ���������
		buf[len - 1] = '\0';   //ȥ�����з�
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
	cout << "¼�����Ϣ�ɹ����Ƿ��������Y/N��";
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
	cout << "|      1.���/�޸İ��      |" << endl;
	cout << "|      2.ɾ�����           |" << endl;
	cout << "|      3.�������˵�         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "��ѡ��������Ҫ�Ĺ��ܣ�" << endl;
	int j;
	cin >> j;
	if (j == 1)
	{
		cout << "����������Ϣ��";
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
		cout << "��ӳɹ���";
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
	cout << "|      1.����β�ѯ         |" << endl;
	cout << "|      2.������/����վ��ѯ  |" << endl;
	cout << "|      3.�������˵�         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "��ѡ��������Ҫ�Ĺ��ܣ�" << endl;
	int j;
	cin >> j;
}
void buy()
{
	cout << "_____________________________" << endl;
	cout << "|      1.��Ʊ               |" << endl;
	cout << "|      2.�������           |" << endl;
	cout << "|      3.��Ʊ               |" << endl;
	cout << "|      4.�������˵�         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "��ѡ��������Ҫ�Ĺ��ܣ�" << endl;
	int j;
	cin >> j;
}
void print()
{
	cout << "_____________________________" << endl;
	cout << "|      1.���/�޸İ��      |" << endl;
	cout << "|      2.�������˵�         |" << endl;
	cout << "|___________________________|" << endl;
	cout << "��ѡ��������Ҫ�Ĺ��ܣ�" << endl;
	int j;
	cin >> j;
}
void quit()

{
	cout << "*********************ллʹ�ñ�ϵͳ����ӭ�´μ���ʹ��***********************" << endl;
}
int main()
{
	welcome();
	return 0;
}


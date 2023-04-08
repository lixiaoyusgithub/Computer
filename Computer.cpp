#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N],q[N][2];
char c[N];
int n, flag=0;

void Second_Device(int Data_bus, int Address_bus, char Command)
{
	if (Command == 'I')
	{
		if (Address_bus > N)
		{
			cout << "�����洢�ռ䣡" << endl;
			return;
		}
		p[Address_bus] = Data_bus;
		cout << "�ļ�����ռ�" << endl;
	}
	else if (Command == 'O')
	{
		if (p[Address_bus] == 0)
		{
			cout << "�˿ռ�δ�洢�ļ�" << endl;
			return;
		}
		else
		{
			cout << "�ÿռ�洢������Ϊ: ";
			cout << p[Address_bus] << endl;
		}
	}
	else
	{
		exit(0);
	}
}
void Clock(int Data_bus, int Address_bus, char Command)
{
	if (Command == 'F')
	{
		Second_Device(Data_bus, Address_bus, Command);
		cout << "���Ȳ���" << endl;
		return;
	}
}
void Busy()
{
	flag++;
	if (flag > 10)
	{
		cout << "����æ" << endl;
		flag = 0;
		return;
	}
}
void Main_Device()
{
	int Data_bus = 0;
	int Address_bus = 0;
	char Command = '0';
	int l=0,r = 0;
	cout << "���ݺ͵�ַ���Լ����I��O��" << endl;
	while (Command != 'E')
	{
		cin >> Data_bus >> Address_bus >> Command;
		if (Command == 'E')break;
		q[r][0] = Data_bus, q[r][1] = Address_bus;
		c[r] = Command;
		r++;
		Clock(Data_bus, Address_bus, Command);
	}
	while (l != r)
	{
		if (Command != 'F')
		{
			Second_Device(q[l][0], q[l][1], c[l]);
		}
		l++;
		Busy();
	}
}
int main()
{
	cout << "��������" << endl;
	cout << "��Ϣѭ����ֱ���رմ���" << endl;
	Main_Device();
	return 0;
}
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
			cout << "超出存储空间！" << endl;
			return;
		}
		p[Address_bus] = Data_bus;
		cout << "文件存入空间" << endl;
	}
	else if (Command == 'O')
	{
		if (p[Address_bus] == 0)
		{
			cout << "此空间未存储文件" << endl;
			return;
		}
		else
		{
			cout << "该空间存储的数据为: ";
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
		cout << "优先操作" << endl;
		return;
	}
}
void Busy()
{
	flag++;
	if (flag > 10)
	{
		cout << "总线忙" << endl;
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
	cout << "数据和地址，以及命令（I，O）" << endl;
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
	cout << "程序运行" << endl;
	cout << "消息循环，直到关闭窗口" << endl;
	Main_Device();
	cout<<"right";
	cout << "11111";
	return 0;
}

#include <iostream>
#include <string> // C++ ���ڿ� ��ü ��������
#include <cstring>
//#include <string.h> c��� ���ڿ� ó�� ���̺귯��
using namespace std;
// �̸� ���� : ������ ������ ����� �Լ��� ���� ���� �ۼ�

namespace A {
	int g_nData;
	void PrintfData() { std::cout << "A : " << g_nData << std::endl; }
}

namespace B {
	int g_nData;
	void PrintfData() { std::cout << "B : " << g_nData << std::endl; }
}

using namespace B;
// �������� ���Ӱ����� ������ �ʰ� �̸����� ��� ����

void NameSpaceMain()
{
	A::g_nData = 10;
	A::PrintfData();
	B::g_nData = 20;
	B::PrintfData();

	cin >> g_nData;
	PrintfData();
}

void StringCMain()
{
	printf("########### C String Main #########\n");
	char strFullName[100];
	char strFirstName[50]="Clare";
	char strLastName[50]="Closet";
	// �ǻ�Ȱ�� ǥ���Ǵ� ���ڸ� ����Ϸ��� �迭�� �����
	// ��� �� ó���� �Լ��� �̿��ؼ� �����ϰ� ó���ؾ���
	// �� �Լ��� ���� �ִ� ���̺귯���� string.h �� cstring�� �ش�

	// �ѱ۷� ���ڸ� ���ļ� fullname�� �����ÿ�
	strcpy_s(strFullName, strLastName);
	strcat_s(strFullName, strFirstName);
	printf("kr:%s\n",strFullName);
	// ����� ���ڸ� ���ļ� fullname�� �����ÿ�
	memset(strFullName, 0, sizeof(strFullName));
	sprintf_s(strFullName, "%s %s", strFirstName, strLastName);
	printf("en:%s\n", strFullName);

	if (!strcmp(strFirstName, strLastName))
		printf("%s == %s\n", strFirstName, strLastName);
	else
		printf("%s != %s\n", strFirstName, strLastName);
	// strcmp�� �̿��� C����� ���ڿ� ��

}

void StringMain()
{
	std::cout << "########## C++ String Main ##########" << std::endl;
	std::string strFullName;
	std::string strFirstName = "Clare";
	std::string strLastName = "Closet";
	// C++ ���� ���ڿ��� ó���ϱ� ���� ��ü�� ������
	// C�ʹ� �ٸ��� �Լ� ��� �ʿ� ���� �Ϲ����� �����̳� ó���� ��� ����
	// �׷��� std::string������ ó���� �� ���� �۾��� �ֱ⿡ C����� ���ڿ��� �˾ƾ��Ѵ�.

	strFullName = strLastName + " " + strFirstName;
	std::cout << "kr : "+strFullName << std::endl;
	strFullName = strFirstName + " " + strLastName;
	std::cout << "en : " + strFullName << std::endl;

	if (strFirstName == strLastName) // C���� �ٸ��� ������ �Լ� ���� �񱳿��� ����
		cout << strFirstName + " == " + strLastName << endl;
	else
		cout << strFirstName << " != " << strLastName << endl;
}

void RefMain()
{
	int nData;
	int &refData = nData; // �����ڴ� �ݵ�� ���� �ʱ�ȭ���������
	// �����ڴ� �������� ����, NULL�� �ǰų� �����Ⱚ�� ������� ���ɼ��� ������.
	// �����ڿ� �����ϰ� �Ǹ� ������ �ٲ�

	nData = 10;
	cout << "nData : " << nData << endl;
	cout << "refData : " << refData << endl;
	refData = 20;
	cout << "nData : " << nData << endl;
	cout << "refData : " << refData << endl;
}

void HangManMain()
{
	string q;
	string answer;
	
	while (answer!="test")
	{
		cout << "Welcome to HangMan Game!!" << endl;
		cout << "Input Word(Downscale 1 char) : "; cin >> q;
		if (q == "t")
		{
			if (answer.find(q, 0))
			{
				answer.insert(0, q); answer.insert(3, q);
				cout << answer << endl;
			}
			else
			{
				cout << "already exists" << endl;
				cout << answer << endl;
			}
			
		}
		/*else if (q == 'e')
		{
			if (!answer.find("e", 1))
			{
				answer.insert(1, &q);
				cout << answer << endl;
			}
			else
			{
				cout << "already exists" << endl;
				cout << answer << endl;
			}
		}
		else if (q == 's')
		{
			if (!answer.find("s", 2))
			{
				answer.insert(2, &q);
				cout << answer << endl;
			}
			else
			{
				cout << "already exists" << endl;
				cout << answer << endl;
			}
		}*/
		else
		{
			cout << "\n\nThat is Wrong~" << endl;
			cout << answer << endl;
		}
	}
}

int main()
{
	HangManMain();
}
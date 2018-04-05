#include <iostream>
#include <cstdio>
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
	char strFirstName[50] = "Clare";
	char strLastName[50] = "Closet";
	// �ǻ�Ȱ�� ǥ���Ǵ� ���ڸ� ����Ϸ��� �迭�� �����
	// ��� �� ó���� �Լ��� �̿��ؼ� �����ϰ� ó���ؾ���
	// �� �Լ��� ���� �ִ� ���̺귯���� string.h �� cstring�� �ش�

	// �ѱ۷� ���ڸ� ���ļ� fullname�� �����ÿ�
	strcpy_s(strFullName, strLastName);
	strcat_s(strFullName, strFirstName);
	printf("kr:%s\n", strFullName);
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
	std::cout << "kr : " + strFullName << std::endl;
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

//test
//_ _ _ _
//t << �Է�
//t _ _ t
//e << �Է�
//t e _ t
//x << �Է�
//x is not find
//t e _ t
void HangManMain()
{
	string strQ = "test";
	string strA;
	string strT;
	for (int i = 0; i < strQ.size(); i++)
	{
		cout << "_ ";
		strT.append("_");
	}
	cout << endl;
	while (strT != "test")
	{
		cin >> strA;
		if (strA.at(0) == 't')
		{
			strT.replace(0, 1, "t"); strT.replace(3, 1, "t");
			cout << strT << endl;
		}
		else if (strA.at(0) == 'e')
		{
			strT.replace(1, 1, "e");
			cout << strT << endl;
		}
		else if (strA.at(0) == 's')
		{
			strT.replace(2, 1, "s");
			cout << strT << endl;
		}
		else
		{
			cout << "That is Wrong~\n" << strT << endl;
		}
	}
	cout << "It is Corrected. You Win." << endl;
}

void CHangManMain()
{
	char chA;
	char chT[5] = "____";
	char chQ[5] = "test";

	for (int i = 0; i < strlen(chQ); i++)
	{
		printf("_");
	}
	printf("\n\n");
	while (1)
	{
		scanf("%c", &chA);
		if (chT[0] == 't'&&chT[1] == 'e'&&chT[2] == 's')
			break;

		else if (chA == 't')
		{
			chT[0] = 't'; chT[3] = 't';
			printf("%s\n\n", chT);
		}
		else if (chA == 'e')
		{
			chT[1] = 'e';
			printf("%s\n\n", chT);
		}
		else if (chA == 's')
		{
			chT[2] = 's';
			printf("%s\n\n", chT);
		}
		else
		{
			printf("\n");
		}
		
	}
	printf("YoU WinNEr!\n");
}



int main()
{
	CHangManMain();
}
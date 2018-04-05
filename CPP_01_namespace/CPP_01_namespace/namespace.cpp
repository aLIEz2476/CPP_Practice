#include <iostream>
#include <cstdio>
#include <string> // C++ 문자열 객체 가져오기
#include <cstring>
//#include <string.h> c언어 문자열 처리 라이브러리
using namespace std;
// 이름 공간 : 별도의 공간을 만들어 함수나 변수 등을 작성

namespace A {
	int g_nData;
	void PrintfData() { std::cout << "A : " << g_nData << std::endl; }
}

namespace B {
	int g_nData;
	void PrintfData() { std::cout << "B : " << g_nData << std::endl; }
}

using namespace B;
// 전역에서 네임공간을 밝히지 않고 이름으로 사용 가능

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
	// 실생활에 표현되는 문자를 사용하려면 배열을 써야함
	// 고로 각 처리도 함수를 이용해서 복잡하게 처리해야함
	// 그 함수를 갖고 있는 라이브러리는 string.h 및 cstring이 해당

	// 한글로 문자를 합쳐서 fullname에 넣으시오
	strcpy_s(strFullName, strLastName);
	strcat_s(strFullName, strFirstName);
	printf("kr:%s\n", strFullName);
	// 영어로 문자를 합쳐서 fullname에 넣으시오
	memset(strFullName, 0, sizeof(strFullName));
	sprintf_s(strFullName, "%s %s", strFirstName, strLastName);
	printf("en:%s\n", strFullName);

	if (!strcmp(strFirstName, strLastName))
		printf("%s == %s\n", strFirstName, strLastName);
	else
		printf("%s != %s\n", strFirstName, strLastName);
	// strcmp를 이용한 C언어의 문자열 비교

}

void StringMain()
{
	std::cout << "########## C++ String Main ##########" << std::endl;
	std::string strFullName;
	std::string strFirstName = "Clare";
	std::string strLastName = "Closet";
	// C++ 부터 문자열을 처리하기 위한 객체가 제공됨
	// C와는 다르게 함수 사용 필요 없이 일반적인 연산이나 처리로 사용 가능
	// 그러나 std::string만으로 처리할 수 없는 작업도 있기에 C언어의 문자열도 알아야한다.

	strFullName = strLastName + " " + strFirstName;
	std::cout << "kr : " + strFullName << std::endl;
	strFullName = strFirstName + " " + strLastName;
	std::cout << "en : " + strFullName << std::endl;

	if (strFirstName == strLastName) // C언어와 다르게 별도의 함수 없이 비교연산 가능
		cout << strFirstName + " == " + strLastName << endl;
	else
		cout << strFirstName << " != " << strLastName << endl;
}

void RefMain()
{
	int nData;
	int &refData = nData; // 참조자는 반드시 값을 초기화시켜줘야함
	// 참조자는 포인터의 단점, NULL이 되거나 쓰래기값이 들어있을 가능성을 배제함.
	// 참조자에 대입하게 되면 원본이 바뀜

	nData = 10;
	cout << "nData : " << nData << endl;
	cout << "refData : " << refData << endl;
	refData = 20;
	cout << "nData : " << nData << endl;
	cout << "refData : " << refData << endl;
}

//test
//_ _ _ _
//t << 입력
//t _ _ t
//e << 입력
//t e _ t
//x << 입력
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
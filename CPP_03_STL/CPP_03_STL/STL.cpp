#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void VectorMain()
{
	// 백터 : 동적배열, 배열이지만 마음대로 크기를 늘이고 줄일 수 있음.

	vector<string> m_vecInventory;

	m_vecInventory.push_back("Wooden Sword");
	m_vecInventory.push_back("Wooden Shield");
	// 플레이어가 목검, 나무방패를 획득했다.

	for (int i = 0; i < m_vecInventory.size(); i++)
	{
		cout << m_vecInventory[i] << "\n";
	}
	cout << endl;

	m_vecInventory.push_back("Bone Sword");
	vector<string>::iterator it;
	for (it = m_vecInventory.begin(); it != m_vecInventory.end(); it++)
		cout << *it << "\n";
	cout << endl;

	m_vecInventory.erase(m_vecInventory.begin() + 1);
	for (it = m_vecInventory.begin(); it != m_vecInventory.end(); it++)
		cout << *it << "\n";
	cout << endl;
}

void ListMain()
{
	// 리스트 : 이중연결 리스트 형태로 구성되어 있음.

	list<string> m_listInventory;

	m_listInventory.push_back("Wooden Sword");
	m_listInventory.push_back("Wooden Shield");
	// 플레이어가 목검, 나무방패를 획득했다.

	/*for (int i = 0; i < m_listInventory.size(); i++)
	{
		cout << m_listInventory[i] << "\n";
	}*/
	// 배열식 접근 불가능
	cout << endl;

	m_listInventory.push_back("Bone Sword");
	list<string>::iterator it;
	for (it = m_listInventory.begin(); it != m_listInventory.end(); it++)
		cout << *it << "\n";
	cout << endl;

	/*m_listInventory.erase(m_listInventory.begin() + 1);*/
	// 두번째 요소를 비롯한 특정 요소 삭제 리스트는 랜덤접근이 안 되므로 위와 같이 삭제 할 수 없음.

	for (it = m_listInventory.begin(); it != m_listInventory.end(); it++)
	{
		if ("Wood Sword" == *it)
		{
			// 리스트는 이중연결리스트이므로 삭제 후 연결시 다시 검색할 필요가 없다.
			m_listInventory.erase(it);
			break;
		}
	}

	for (it = m_listInventory.begin(); it != m_listInventory.end(); it++)
		cout << *it << "\n";
	cout << endl;
}

void DequeueMain()
{

	deque<string> m_deqInventory;

	m_deqInventory.push_back("Wooden Sword");
	m_deqInventory.push_back("Wooden Shield");
	// 플레이어가 목검, 나무방패를 획득했다.

	for (int i = 0; i < m_deqInventory.size(); i++)
	{
		cout << m_deqInventory[i] << "\n";
	}
	cout << endl;

	m_deqInventory.push_back("Bone Sword");
	deque<string>::iterator it;
	for (it = m_deqInventory.begin(); it != m_deqInventory.end(); it++)
		cout << *it << "\n";
	cout << endl;

	m_deqInventory.erase(m_deqInventory.begin() + 1);
	for (it = m_deqInventory.begin(); it != m_deqInventory.end(); it++)
		cout << *it << "\n";
	cout << endl;
}

void MapMain()
{
	map<string, string>m_mapInventory;
	m_mapInventory["Wooden Sword"] = "increase damege +100";
	m_mapInventory["Sword of Witch"] = "increase damege +300, Cancel All Magic Skill";
	m_mapInventory["Chain Armor"] = "increase defence +100";
	m_mapInventory["Maria Armor"] = "Recover HP +100/sec";

	cout << m_mapInventory["Chain Armor"] << endl;
}

void StackMain()
{
	stack<string> m_stackMemory;

	m_stackMemory.push("shape");
	m_stackMemory.push("Rectangle");
	m_stackMemory.push("shape");
	m_stackMemory.push("Circle");
	
	while (!m_stackMemory.empty())
	{
		m_stackMemory.pop();
		cout << m_stackMemory.top() << endl;
	}
		
}

void QueueMain()
{
	queue<string> m_queue;
	m_queue.push("W");
	m_queue.push("A");
	m_queue.push("S");
	m_queue.push("D");

	while (!m_queue.empty())
	{
		m_queue.pop();
		cout << m_queue.front() << endl;
	}
}

int main()
{
	QueueMain();
}
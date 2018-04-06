
#include <iostream>
#include <string>
using namespace std;

class Car {
	//private: //Ŭ��������(����Լ�)������ �����Ҽ��ֵ����Ѵ�. Ŭ������ �⺻������ private �⺻�����̴�.
	//����Լ�(�Ӽ�)�� ��ü������ �ܺ��� ��Ұ� �ƴ� ���ο��� ��ȣ���� ����� �����ϰų� �����Ѵ�.
	//���۾��� ���� �ٲ�°��� �������� �Ϲ������� private�� ���� �����Ѵ�.
	int m_nSpeed;
	int m_nGear;
	string m_strColor;
	const int m_nCount = 0;
public:
	//�Ű������� ���� ������: ����Ʈ������ - ��ü�� �����Ҷ� ����Ʈ�����ڰ� ������ �Ű������� �־�߸� ������ ����������.
	//Car() //������ : ��ü�� �����ɶ� �Ҹ��� �Լ�.
	//	  //Ŭ������� ����. ���ϰ��� ����.
	//{
	//	Init("gray", 0, 0);
	//}
	//�����ڵ� �Լ��̹Ƿ� �Ű������� �����Ͽ� ���� �������ִ�.
	//������ ���� �����ε��� ���� ����Ʈ�Ű�����ó�� �̿��ϴ°͵� �����ϴ�.
	Car(string color = "gray", int speed = 0, int gear = 0)
	{
		//this: ��ü �ڱ��ڽ��� �ּҸ� ������.
		cout << typeid(*this).name() << ":" << this << endl;
		Init(color, speed, gear);
	}
	/*Car(string color)
	{
	Init(color, 0, 0);
	}*/
	//�Լ� �����ε�: �Ű������� ������ Ÿ���� �ٸ� �Լ��� ���� �̸��� �����ϴ� ��.
	//����Ʈ�Ű�����: �Ű������� ���� ���������ʾƵ� �⺻���� �����ɼ��ֵ����ϴ°�.
	//�ı���(=�Ҹ���): ��ü�� �ı��ɶ� ȣ��Ǵ� �Լ�.
	//�Ű������� ����. ���ϰ� ����. ~�Լ��� �̸�
	~Car()
	{
		cout << "~" << typeid(*this).name() << ":" << this << endl;
	}
public: //Ŭ���� �ܺο����� ���ٰ����ϰ��ϴ� ����������.
		//������ ���� �ܺο��� �޼����� ���� �����ϰ� �ǹǷ�, public�� ����ϴ� ���� �Ϲ����̴�.
	void Init(string color, int speed, int gear)//�ڵ��� �Ӽ� �ʱ�ȭ
	{
		m_strColor = color;
		m_nGear = gear;
		m_nSpeed = speed;
	}
	//Setter,Getter: �����Ҽ����� �ɹ������� ����/�б�
	//���� �ܺο��� ���浵 �����ϰ� Ȯ�ε� �����ؾ��Ѵ�. �׷��Ƿ� ���Ͱ��͸�� �������Ѵ�.
	//�Լ��� ���ο� �����ϸ� inline�� �ɼ��� �ִ�.
	void SetGear(int gear)
	{
		m_nGear = gear;
	}
	int GetGear()
	{
		return m_nGear;
	}
	//�ӵ��� ������ ������ �P�ų� �극��ũ�� ��Ƽ� �����ǹǷ� �ܺο��� �Ժη� �����Ҽ��ִ� ���� �ƴ�.
	//�׷��Ƿ� ���͸� ���� �б⸸ �����ϰ��Ѵ�.
	void GetSpeed(int speed)
	{
		m_nSpeed = speed;
	}
	//����Լ��� ����
	void Break();

	void Accel() //�����Ҷ��� �� ���� �ִ�ӵ��� ���ѵȴ�.
	{
		if (m_nGear == 1 && m_nSpeed < 20)
			m_nSpeed++;
		else if (m_nGear == 2 && m_nSpeed < 40)
			m_nSpeed++;
		else if (m_nGear == 3 && m_nSpeed < 60)
			m_nSpeed++;
		else if (m_nGear == 4 && m_nSpeed >= 60)
			m_nSpeed++;
	}
	void SpeedUp()
	{
		m_nSpeed += 10;
	}
	void SpeedDown()
	{
		m_nSpeed -= 10;
	}
	void Show() //�ڵ��� ���� ����
	{
		cout << "#### " << this << " ####" << endl;
		cout << "Color:" << m_strColor << endl;
		cout << "Gear:" << m_nGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
	}
};
//�Լ��� ȣ���.
//����Լ��� �ܺ�����
void Car::Break()
{
	m_nSpeed -= 10;
}

void CarMain()
{
	Car cCar, cCarA;
	//Car cCarB("yellow", 0, 0); //�����ڸ� ȣ���Ͽ� �ʱⰪ�� ������.
	Car cCarB("yellow"); //�����ڸ� ȣ���Ͽ� �ʱⰪ�� ������.
						 //cCar.m_nSpeed = 100; //private:��������� Ŭ���� ���ο����� �ٲܼ��ִ�.
	cCar.Init("red", 100, 3);
	cCar.SpeedUp();
	cCar.SpeedDown();
	cCar.Show();
	cCarA.Init("blue", 0, 0);
	cCarA.Show();

	Car* pCar = new Car();
	pCar->Init("green", 0, 0);
	pCar->Show();
	delete pCar;

	Car arrCar[3];
	for (int i = 0; i < 3; i++)
	{
		arrCar[i].Init("black", i * 10, i);
		arrCar[i].Show();
	}
}

class String {
	char* m_pStr;
public:
	String(const char* str = "")
	{
		m_pStr = new char[strlen(str) + 1];
		strcpy_s(m_pStr, sizeof(m_pStr), str);
		printf("String:%d\n", m_pStr);
	}
	//���������
	String(const String& str)
	{
		printf("��������� ���⼭ �׸��� ���� �ڵ带 �ۼ��Ͽ���.");
		printf("String:%d\n", m_pStr);
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy_s(m_pStr, sizeof(m_pStr) + 1, str.m_pStr);
		printf("CopyString:%d\n", str.m_pStr);
	}

	~String()
	{
		printf("~String:%d\n", m_pStr);
		delete m_pStr;
	}

	int size()
	{
		return strlen(m_pStr);
	}

	String add(String& string)
	{
		int len = size() + string.size();
		char* pStr = new char[len + 1];
		sprintf_s(pStr, sizeof(pStr), "%s%s", m_pStr, string.m_pStr);
		String str(pStr);
		return str;
	}
	//�����ڿ����ε�: �����ڸ� �����ε��Ͽ� ���� �ͼ��� �������̽��� �����ϴ� ���� ����.
	//�� �̰����� �����ؾ��ϴ°��� �ƴ�����, �̷����ϸ� ���� ����ڰ� ���ϰ� �����Ҽ��ִ�.
	String operator+(String& string)
	{
		int len = size() + string.size();
		char* pStr = new char[len + 1];
		sprintf_s(pStr, sizeof(pStr), "%s%s", m_pStr, string.m_pStr);
		String str(pStr);
		return str;
	}
	//�����忬����: private������� �����Ҽ��ְ� �ϴ� Ű����. Ŭ����,�Լ��� ��밡���ϴ�.
	//�׷���. �� ����ϴ� ��Ȳ �����ڿ����ε��� ���� ��Ȳ�� �ƴϸ� �Ϻη� �Ἥ�� �ȵȴ�.
	//�����ڿ����ε��� �Ű������� 2���� ���� friend�� �ٿ����Ѵ�.
	friend ostream& operator<<(ostream& os, const String& str)
	{
		os << str.m_pStr;
		return os;
	}

	bool operator==(String& string)
	{
		return false;
	}

	String operator=(String& string)
	{
		//�������� �����ϱ�
	}
};

void StringMain()
{
	string a("test");
	string b = a;
	//���ڿ��� ���ó�� ����ϸ� ���׸�Ʈ������ �޸𸮰� �Ҵ�Ǵµ�, �̶� �迭�� �̸��� �ּҸ� �����ϹǷ�,
	//������ �� ���� ������ ���� ���� �����Ҽ��ִ�. �׷��Ƿ� vs2017���Ĵ� ������ڿ��� �������� �ݵ�� const�� �־���Ѵ�.
	const char test[10] = "test";
	String strA(test);
	String strB = strA; //��ü �ʱ�ȭ�� ��ü���� �̶� ��������ڰ� ȣ��ȴ�.
	String strC = strB + strA;
	cout << strC << endl;
}

//�߻�Ŭ����: ���������Լ��� 1���̻� ���� Ŭ����
//��ü������ �Ұ���������.
class Shape {
protected: //�ڽ�Ŭ���������� �����Ҽ� �ִ� ����������
	int x, y;
public:
	Shape()
	{
		cout << "Shape()" << endl;
		x = 0;
		y = 0;
	}
	virtual ~Shape() = 0//�ı��ڴ� ����Ʈ�ı��ڸ� �����Ϸ��� �ڵ����� �����ϹǷ�, ���������Լ��� ������ ����Ҽ�����.
	{
		cout << "~Shape()" << endl;
	}
	//�����Լ�: �ڽİ�ü�� �������̵��� �Լ��� �θ� ���ְ���.
	virtual void Draw() = 0 //���������Լ�: �ڽİ�ü���� �������̵����������� �����Ͽ����� ����.
	{
		cout << "pos(" << x << "," << y << ")" << endl;
	};
};

class Circle : public Shape {
	//int x,y; //��ġ //����� �̿��ϸ� �������� �Ӽ��� �ٽ� ���� �����ʾƵ� �ȴ�.
	int rad; //������
public:
	Circle() //����� ������ �ڽĻ����ڰ� ȣ��ɶ� �θ��� �����ڰ� �ڵ����� ȣ��ȴ�.
	{
		cout << "Circle()" << endl;
		x = 0;
		y = 0;
		rad = 0;
	}
	//~Circle()
	//{
	//	cout << "~Circle()" << endl;
	//}
	//�������̵�: �ڽİ�ü���� �θ�ü�� ����Լ��� �����̸����� �����ϴ°�
	void Draw()
	{
		cout << "pos,radian(" << x << "," << y << "," << rad << ")" << endl;
	};
};

class Rectangle : public Shape {
	//int x, y; //��ġ
	int w, h; //����, ����
public:
	Rectangle()
	{
		cout << "Rectangle()" << endl;
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}
	~Rectangle()
	{
		cout << "~Rectangle()" << endl;
	}
	void Draw()
	{
		cout << "pos,width,height(" << x << "," << y << "," << w << "," << h << ")" << endl;
	};
};


void ShapeMain()
{
	//Rectangle cRect;
	//Circle cCircle;

	//cRect.Draw();
	//cCircle.Draw();
	//������: �����Լ��� �������̵������ �̿��Ͽ� ��ü�� ������ ������,
	//�������� �ٸ� �ൿ���� �����ϰ� ������ �����.
	//�������ε�: ��Ÿ���߿� �Լ��� ����� �����Ǵ°�.
	//�������ε�: �������߿� �Լ��� ����� �����Ǵ°�
	//Shape cShape; //�߻�Ŭ������ ��üȭ �Ҽ�����.
	Shape* arrShape[3];
	int nSelect;
	for (int i = 0; i < 3; i++)
	{
		cin >> nSelect;
		switch (nSelect)
		{
		case 0:
			arrShape[i] = new Rectangle();
			break;
		case 1:
			arrShape[i] = new Circle();
			break;
		}
	}
	for (int i = 0; i < 3; i++)
		arrShape[i]->Draw();
	for (int i = 0; i < 3; i++)
		delete arrShape[i];
}

//������ Ŭ���� ����� , ����(���Ͱ���Ȱ���ϱ�)
//�𵨸��� �Ҷ� �������� ��䰡���ؾ���.

int main()
{
	//CarMain();
	StringMain();
	//ShapeMain();
}
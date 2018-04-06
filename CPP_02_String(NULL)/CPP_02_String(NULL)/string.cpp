
#include <iostream>
#include <string>
using namespace std;

class Car {
	//private: //클래스내부(멤버함수)에서만 접근할수있도록한다. 클래스는 기본적으로 private 기본설정이다.
	//멤버함수(속성)은 대체적으로 외부의 요소가 아닌 내부에서 상호적인 관계로 증가하거나 감소한다.
	//동작없이 값이 바뀌는것을 막기위해 일반적으로 private를 많이 선택한다.
	int m_nSpeed;
	int m_nGear;
	string m_strColor;
	const int m_nCount = 0;
public:
	//매개변수가 없는 생성자: 디폴트생성자 - 객체를 생성할때 디폴트생성자가 없으면 매개변수를 넣어야만 생성이 가능해진다.
	//Car() //생성자 : 객체가 생성될때 불리는 함수.
	//	  //클래스명과 같다. 리턴값이 없다.
	//{
	//	Init("gray", 0, 0);
	//}
	//생성자도 함수이므로 매개변수를 지정하여 값을 받을수있다.
	//다음과 같이 오버로딩을 통해 디폴트매개변수처럼 이용하는것도 가능하다.
	Car(string color = "gray", int speed = 0, int gear = 0)
	{
		//this: 객체 자기자신의 주소를 가져옴.
		cout << typeid(*this).name() << ":" << this << endl;
		Init(color, speed, gear);
	}
	/*Car(string color)
	{
	Init(color, 0, 0);
	}*/
	//함수 오버로딩: 매개변수의 갯수나 타입이 다른 함수를 같은 이름을 정의하는 것.
	//디폴트매개변수: 매개변수의 값을 지정하지않아도 기본값이 설정될수있도록하는것.
	//파괴자(=소멸자): 객체가 파괴될때 호출되는 함수.
	//매개변수가 없다. 리턴값 없음. ~함수의 이름
	~Car()
	{
		cout << "~" << typeid(*this).name() << ":" << this << endl;
	}
public: //클래스 외부에서도 접근가능하게하는 접근제어자.
		//동작은 보통 외부에서 메세지를 통해 동작하게 되므로, public을 사용하는 것이 일반적이다.
	void Init(string color, int speed, int gear)//자동차 속성 초기화
	{
		m_strColor = color;
		m_nGear = gear;
		m_nSpeed = speed;
	}
	//Setter,Getter: 접근할수없는 맴버변수를 쓰기/읽기
	//기어는 외부에서 변경도 가능하고 확인도 가능해야한다. 그러므로 셋터겟터모두 가져야한다.
	//함수의 내부에 정의하면 inline이 될수도 있다.
	void SetGear(int gear)
	{
		m_nGear = gear;
	}
	int GetGear()
	{
		return m_nGear;
	}
	//속도는 오로지 엑셀을 밣거나 브레이크를 밟아서 조절되므로 외부에서 함부로 수정할수있는 값이 아님.
	//그러므로 셋터만 만들어서 읽기만 가능하게한다.
	void GetSpeed(int speed)
	{
		m_nSpeed = speed;
	}
	//멤버함수의 선언
	void Break();

	void Accel() //가속할때는 기어에 따라서 최대속도가 제한된다.
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
	void Show() //자동차 상태 보기
	{
		cout << "#### " << this << " ####" << endl;
		cout << "Color:" << m_strColor << endl;
		cout << "Gear:" << m_nGear << endl;
		cout << "Speed:" << m_nSpeed << endl;
	}
};
//함수가 호출됨.
//멤버함수의 외부정의
void Car::Break()
{
	m_nSpeed -= 10;
}

void CarMain()
{
	Car cCar, cCarA;
	//Car cCarB("yellow", 0, 0); //생성자를 호출하여 초기값을 지정함.
	Car cCarB("yellow"); //생성자를 호출하여 초기값을 지정함.
						 //cCar.m_nSpeed = 100; //private:멤버변수는 클래스 내부에서만 바꿀수있다.
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
	//복사생성자
	String(const String& str)
	{
		printf("복사생성자 여기서 그림과 같이 코드를 작성하여라.");
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
	//연산자오버로딩: 연산자를 오버로딩하여 좀더 익숙한 인터페이스를 제공하는 것이 목적.
	//꼭 이것으로 구현해야하는것은 아니지만, 이렇게하면 좀더 사용자가 편리하게 접근할수있다.
	String operator+(String& string)
	{
		int len = size() + string.size();
		char* pStr = new char[len + 1];
		sprintf_s(pStr, sizeof(pStr), "%s%s", m_pStr, string.m_pStr);
		String str(pStr);
		return str;
	}
	//프랜드연산자: private멤버에도 접근할수있게 하는 키워드. 클래스,함수에 사용가능하다.
	//그러나. 꼭 써야하는 상황 연산자오버로딩과 같은 상황이 아니면 일부러 써서는 안된다.
	//연산자오버로딩시 매개변수가 2개인 경우는 friend를 붙여야한다.
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
		//깊은대입 구현하기
	}
};

void StringMain()
{
	string a("test");
	string b = a;
	//문자열은 상수처럼 사용하면 세그먼트영역에 메모리가 할당되는데, 이때 배열의 이름은 주소를 전달하므로,
	//수정할 수 없는 영역의 값이 더라도 수정할수있다. 그러므로 vs2017이후는 상수문자열을 받으려면 반드시 const가 있어야한다.
	const char test[10] = "test";
	String strA(test);
	String strB = strA; //객체 초기화를 객체로함 이때 복사생성자가 호출된다.
	String strC = strB + strA;
	cout << strC << endl;
}

//추상클래스: 순수가상함수를 1개이상 가진 클래스
//객체생성이 불가능해진다.
class Shape {
protected: //자식클래스에서도 접근할수 있는 접근지정자
	int x, y;
public:
	Shape()
	{
		cout << "Shape()" << endl;
		x = 0;
		y = 0;
	}
	virtual ~Shape() = 0//파괴자는 디폴트파괴자를 컴파일러가 자동으로 생성하므로, 순수가상함수의 개념은 사용할수없다.
	{
		cout << "~Shape()" << endl;
	}
	//가상함수: 자식객체의 오버라이딩된 함수를 부를 수있게함.
	virtual void Draw() = 0 //순수가상함수: 자식객체에서 오버라이드하지않으면 컴파일에러가 난다.
	{
		cout << "pos(" << x << "," << y << ")" << endl;
	};
};

class Circle : public Shape {
	//int x,y; //위치 //상속을 이용하면 공통적인 속성을 다시 정의 하지않아도 된다.
	int rad; //반지름
public:
	Circle() //상속을 받으면 자식생성자가 호출될때 부모의 생성자가 자동으로 호출된다.
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
	//오버라이딩: 자식객체에서 부모객체의 멤버함수와 같은이름으로 정의하는것
	void Draw()
	{
		cout << "pos,radian(" << x << "," << y << "," << rad << ")" << endl;
	};
};

class Rectangle : public Shape {
	//int x, y; //위치
	int w, h; //넓이, 높이
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
	//다형성: 가상함수와 오버라이딩기법을 이용하여 객체가 동작은 같지만,
	//내부적을 다른 행동으로 구현하고 싶을때 사용함.
	//동적바인딩: 런타임중에 함수의 기능이 결정되는것.
	//정적바인딩: 컴파일중에 함수의 기능이 결정되는것
	//Shape cShape; //추상클래스는 객체화 할수없다.
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

//전구를 클래스 만들기 , 라디오(셋터겟터활용하기)
//모델링을 할때 한이유도 대답가능해야함.

int main()
{
	//CarMain();
	StringMain();
	//ShapeMain();
}
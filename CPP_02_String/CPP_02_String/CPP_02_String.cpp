// CPP_02_String.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

class Car {
private:
	
	int m_nSpeed;
	int m_nGear;
	string m_strColor;
	
public:
	~Car() {
		cout << typeid(*this).name() << " : " << this << endl;
	}
	//Car()
	//{

	//Init("Gray: ",o,o); // 생성자
	//
	//}
	Car(string color = "Gray", int speed = 0, int gear = 0)
	{
		//this : 자기 자신의 객체 typeid.name() : 타입이름 갖고오기
		cout << typeid(*this).name() << " : " << this << endl;
		Init(color, speed, gear);
	}
	void Init(string color, int speed, int gear)
	{
		m_strColor = color;
		m_nGear = gear;
		m_nSpeed = speed;
	}

	void SetGear(int Gear)
	{
		m_nGear = Gear;
	}

	int GetGear()
	{
		return m_nGear;
	}

	// 속도는 오롲 엑셀을 밟거나 브레이크를 밟아서 조절되므로 외부에서 함부로 수정할 수 있는 값이 아님
	void GetSpeed(int Speed)
	{
		m_nSpeed = Speed;
	}

	int SetSpeed()
	{
		return m_nSpeed;
	}

	void SpeedUp()
	{
		m_nSpeed += 10;
	}

	void SpeedDown()
	{
		m_nSpeed -= 10;
	}

	void Show()
	{
		cout << "Color : " << m_strColor << endl;
		cout << "Gear : " << m_nGear << endl;
		cout << "Speed : " << m_nSpeed << endl;
	}
};

class String {
	char* m_pStr;
public:
	String(const char* str="")
	{

		m_pStr = new char[strlen(str) + 1];
		strcpy_s(m_pStr, sizeof(str)+1, str);
	}
	String(const String& str)
	{
		printf("복사생성자 여기서 그림과 같이 코드를 구현해볼것\n");
		printf("String:%d\n, str");

	}
	~String()
	{
		delete m_pStr;
	}
};

void StringMain()
{
	string a = "test";

	// 문자열은 상수처럼 사용하면 세그먼트 영역에 메모리가 할당되는데, 이때 배열의 이름은 주소를 전달함.
	// 그 영역의 값이 다르더라도 수정할 수 있음. 고로 vs2017 이후는 상수 문자열을 받기 위해서 반드시 const가 필요함.

	String strA("test");
	String strB;
	strB = strA; // 객체 초기화를 객체로 함. 이때 복사생성자가 호출됨.
}

// 추상클래스 : 순수 가상함수를 1개 이상 가진 클래스
// 추상클래스로서 지정받게 되면 객체 생성을 할 수 없다.
class Shape {

protected:
	int x, y;
	// 자식 클래스에서도 접근 할 수 있는 접근지정자.(자바랑 비스무리함.)
public:
	Shape()
	{
		cout << "Shape()" << endl;
		x = y = 0;
	}

	// 가상함수 : 자식 객체의 오버라이딩된 함수를 부를 수 있게 함. 동적바인딩 용도로 주로 사용.
	// virtual void Draw()
	virtual void Draw()=0
	{
		cout << "pos(" << x << ", " << y << ")" << endl;
	}
	// 순수 가상함수 : 자식객체에서 오버라이드하지 않으면 컴파일 에러 발생.

	virtual ~Shape()
	{
		cout << "~Shape()" << endl;
	} // 자식 객체를 지울 때 가상 소멸자 사용
};

class Circle : public Shape {
	int rad;
	double pi = 3.14;

public:
	Circle () // 상속을 받으면 자식 생성자가 
	{
		cout << "Circle()" << endl;
		rad = 0; x = y = 0;
	}

	// 오버라이딩 : 자식객체에서 부모객체의 멤버함수와 같은 이름으로 정의하는 것.
	// 오버라이딩 조건 : 함수명, 반환 자료형, 매개변수(Parameter) 다 같아야함.
	// 말 그대로 같은 이름, 같은 조건으로 재정의하는 것.
	void Draw()
	{
		cout << "pos, radian(" << x << ", " << y << ", "<<rad<<")" << endl;
	}
	~Circle()
	{
		cout << "~Circle()" << endl;
	}
};

class Rectangle : public Shape {
	
	int w, h;
public:
	Rectangle ()
	{
		cout << "Rectangle()" << endl;
		w = h = 0; x = y = 0;
	}

	void Draw()
	{
		cout << "pos(" << x << ", " << y << ")" << endl;
	}
	~Rectangle()
	{
		cout << "~Rectangle()" << endl;
	}
};
// 전구, 라디오 클래스 만들기
class Lamp {
	bool onoff;
	int lux;
	void SetOn(bool sw)
	{
		onoff = sw;
	}
	bool GetOn()
	{
		return onoff;
	}
	void SetLux(int bri)
	{
		lux = bri;
	}
	int GetLux()
	{
		return lux;
	}
};

class radio {
	bool onoff;
	float hz;
	int vol;
	void SetOn(bool sw)
	{
		onoff = sw;
	}
	bool GetOn()
	{
		return onoff;
	}
	void SetHz(float freq)
	{
		hz = freq;
	}
	float GetHz()
	{
		return hz;
	}
	void SetVol(int sound)
	{
		vol = sound;
	}
	int GetVol()
	{
		return vol;
	}
};

void CarMain()
{
	Car cCar, cCarA;

	cCar.Init("red", 100, 4);
	cCar.SpeedUp();
	cCar.SpeedDown();
	cCar.Show();

	cCarA.Init("blue", 0, 0);
	cCarA.Show();

	Car* pCar = new Car();
	pCar->Init("green", 0, 0);
	pCar->Show();
	delete pCar;

	
	
}

void ShapeMain()
{
	/*Rectangle cRect;
	Circle cCircle;
*/
	/*cRect.Draw();
	cCircle.Draw();
*/
	// 다형성 : 가상함수와 오버라이딩 기법을 이용하여 객체가 동작은 같지만, 내부적으로 다른 행동을 구현하고 싶을 때 사용함.
	// 동적 바인딩 : 런타임 중에 함수의 기능이 결정되는 것.
	// 정적 바인딩 : 컴파일 중에 함수의 기능이 결정되는 것.

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
	{
		arrShape[i]->Draw();
	}
	for (int i = 0; i < 3; i++)
	{
		delete arrShape[i];
	}

}

int main()
{
	ShapeMain();


    return 0;
}


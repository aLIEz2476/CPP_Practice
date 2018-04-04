// CPP_02_String.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	int m_nSpeed;
	int m_nGear;
	string m_strColor;

	void Init(string color, int speed, int gear)
	{
		m_strColor = color;
		m_nGear = gear;
		m_nSpeed = speed;
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

	Car arrCar[3];
	for (int i = 0; i < 3; i++)
	{
		arrCar[i].Init("black", 10 * i, 0);
		arrCar[i].Show();
	}
	delete arrCar;


}

int main()
{
	CarMain();
    return 0;
}


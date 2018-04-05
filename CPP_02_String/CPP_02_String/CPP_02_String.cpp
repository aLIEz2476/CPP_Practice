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
	//Car()
	//{

	//Init("Gray: ",o,o); // 생성자
	//
	//}
	Car(string color = "Gray", int speed = 0, int gear = 0)
	{
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

int main()
{
	CarMain();
    return 0;
}


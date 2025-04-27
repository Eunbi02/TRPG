#pragma once
#include "pch.h"

class CSelectNum {
private:
	int iSize;
	string strName;
	string* strElements;  // 동적 배열


public:
	//생성자와 소멸자
	CSelectNum();
	explicit  CSelectNum(int _size, string _name, string* _elements);  // 사용자 정의 생성자
	~CSelectNum();

	static CSelectNum* Create()
	{
		CSelectNum* pCSelectNum = new CSelectNum;

		return pCSelectNum;
	}

	void Destroy()
	{
		if (this != nullptr)
			delete this;
	}
	
	//getter 함수
	int GetSelectSize() const;
	string GetSelectName() const;
	string GetElementName(int _idx) const;

	//자기 프린트 함수
	void Print()const;
};
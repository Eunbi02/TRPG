#pragma once
#include "pch.h"

class CSelectNum {
private:
	int iSize;
	string strName;
	string* strElements;  // ���� �迭


public:
	//�����ڿ� �Ҹ���
	CSelectNum();
	explicit  CSelectNum(int _size, string _name, string* _elements);  // ����� ���� ������
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
	
	//getter �Լ�
	int GetSelectSize() const;
	string GetSelectName() const;
	string GetElementName(int _idx) const;

	//�ڱ� ����Ʈ �Լ�
	void Print()const;
};
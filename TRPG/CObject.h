#pragma once
#include "pch.h"


class CObject {
protected: 
	string m_strName;
	int m_iHp;
	int m_iMp;
	int m_iAttack;

	// �����ڿ� �Ҹ���
public:
	CObject();
	explicit CObject(string _sName, int _iHp, int _iMp, int _iAttack);
	explicit CObject(const CObject& other);
	~CObject();

	// getter,setter func
public:
	string	GetName()	const { return m_strName; }
	int		GetHp()		const { return m_iHp; }
	int		GetMp()		const { return m_iMp; }
	int		GetAttack() const { return m_iAttack; }

	void	SetHp(int _hp);
	void	SetMp(int _mp);
	void	SetAttack(int _attack);
	void	SetName(string _name);

public:
	void	Initialize();
	void	Update(); //���� �� �Լ�
	void	Release(); //���� �� �Լ�

	// �� �� ��� �Լ���
public:
	//�ڱ� print �Լ�
	virtual void Print() const;

};

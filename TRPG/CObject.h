#pragma once
#include "pch.h"


class CObject {
protected: 
	string m_strName;
	int m_iHp;
	int m_iMp;
	int m_iAttack;

	// 생성자와 소멸자
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
	void	Update(); //아직 빈 함수
	void	Release(); //아직 빈 함수

	// 그 외 기능 함수들
public:
	//자기 print 함수
	virtual void Print() const;

};

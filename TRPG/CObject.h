#pragma once
#include "pch.h"
#include "Define.h"

//추상 클래스

class CObject {
protected: 
	INFO m_tagINFO;

	// 생성자와 소멸자
public:
	CObject(); // 기본 생성자
	explicit CObject(string _sName, int _iHp, int _iExp, int _iAttack, int _iLevel);
	virtual ~CObject();


	// getter,setter func
public:
	INFO	Get_Info()	const { return m_tagINFO; }
	string	GetName()	const { return this->m_tagINFO.strName; }
	int		GetHp()		const { return this->m_tagINFO.iHp; }
	int		GetExp()		const { return this->m_tagINFO.iExp; }
	int		GetAttack() const { return this->m_tagINFO.iAttack; }
	int		GetLevel()	const { return this->m_tagINFO.iLevel; }

	void	SetHp(int _hp);
	void	SetExp(int _mp);
	void	SetAttack(int _attack);
	void	SetLevel(int _level);
	void	SetName(string _name);

public:
	virtual void	Initialize() =0;
	virtual void	Update() = 0; //아직 빈 함수
	virtual void	Release() = 0; //아직 빈 함수

	// 기능 함수들
public:
	//자기 print 함수
	virtual void Print() const;
	void Attacked(int _attacked, int _mp);

	//player 함수
public:
	
	virtual int		GetDefense()	const { return 0; };
	virtual string	GetJob()		const { return ""; };

	
	virtual void	SetDefense(int _defense)	{ return; };
	virtual void	SetJob(string _job)			{ return; };

	virtual void	LevelUp(int _mp)			{ return; };


	//monster 함수
public:
	virtual int		GetGameNum()	const { return 0; };
	virtual bool	GetIsLose()		const { return 0; };
	
	virtual void	SetMonsterLevel(int _level) { return; };
	virtual void	SetGameNum()				{ return; };
	virtual void	SetIsLose(bool* _isLose)	{ return; };
	
	virtual void	SetGame()	{ return; };
	virtual void	PlayGame()	{ return; };

};

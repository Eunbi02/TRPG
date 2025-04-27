#pragma once
#include "pch.h"
#include "Define.h"

//�߻� Ŭ����

class CObject {
protected: 
	INFO m_tagINFO;

	// �����ڿ� �Ҹ���
public:
	CObject(); // �⺻ ������
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
	virtual void	Update() = 0; //���� �� �Լ�
	virtual void	Release() = 0; //���� �� �Լ�

	// ��� �Լ���
public:
	//�ڱ� print �Լ�
	virtual void Print() const;
	void Attacked(int _attacked, int _mp);

	//player �Լ�
public:
	
	virtual int		GetDefense()	const { return 0; };
	virtual string	GetJob()		const { return ""; };

	
	virtual void	SetDefense(int _defense)	{ return; };
	virtual void	SetJob(string _job)			{ return; };

	virtual void	LevelUp(int _mp)			{ return; };


	//monster �Լ�
public:
	virtual int		GetGameNum()	const { return 0; };
	virtual bool	GetIsLose()		const { return 0; };
	
	virtual void	SetMonsterLevel(int _level) { return; };
	virtual void	SetGameNum()				{ return; };
	virtual void	SetIsLose(bool* _isLose)	{ return; };
	
	virtual void	SetGame()	{ return; };
	virtual void	PlayGame()	{ return; };

};

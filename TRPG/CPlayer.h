#pragma once
#include "CObject.h"

class CMonster;

class CPlayer : public CObject {
private:
	int m_iLevel;
	int m_iDefense;
	int m_iMaxMp;
	string m_strJob;

	// 持失切 社瑚切
public:
	CPlayer();
	explicit CPlayer(string _name, string _job,int _hp, 
		int _mp, int _attack, int _level, int _defense, int _maxMp);
	~CPlayer();

	// get, set func
public:

	int		GetLevel()		const { return m_iLevel; };
	int		GetDefense()	const { return m_iDefense; };
	string	GetJob()		const { return m_strJob; };


	void SetLevel(int _level);
	void SetDefense(int _defense);
	void SetJob(string _job);

public:
	void	Initialize();
	void	Update();
	void	Release();

	
public:
	//print override
	void Print() const override;

	void Attacked(int _attacked, int _mp);
	void LevelUp(int _mp);
};
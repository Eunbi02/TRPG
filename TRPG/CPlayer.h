#pragma once
#include "CObject.h"

class CMonster;

class CPlayer : public CObject {
private:

	int m_iDefense;
	int m_iMaxExp;
	string m_strJob;

	CPlayer();
	explicit CPlayer(string _name, string _job, int _hp,
		int _mp, int _attack, int _level, int _defense, int _maxMp);
	virtual ~CPlayer();

	// 持失切 社瑚切
public:
	

	static CObject* Create()
	{
		CObject* pCPlayer = new CPlayer;

		return pCPlayer;
	}

	static CObject* Create(string _name, string _job, int _hp,
		int _mp, int _attack, int _level, int _defense, int _maxMp)
	{
		CObject* pCPlayer = new CPlayer (_name, _job, _hp,
			_mp, _attack, _level, _defense, _maxMp);

		return pCPlayer;
	}

	void Destroy()
	{
		if (this != nullptr)
			delete this;
	}

	// get, set func
public:

	int		GetDefense()	const { return m_iDefense; };
	string	GetJob()		const { return m_strJob; };


	void SetDefense(int _defense)override;
	void SetJob(string _job)override;

public:
	void	Initialize()override;
	void	Update()override;
	void	Release()override;

	
public:
	//print override
	void Print() const override;

	//void Attacked(int _attacked, int _mp);
	void LevelUp(int _mp) override;
};
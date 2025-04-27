#include "CPlayer.h"


CPlayer::CPlayer()
    : CObject("Unknown", 100, 0, 10,1),
      m_iDefense(5),
      m_iMaxExp(10),
      m_strJob("Nothing")
{
    cout << "�÷��̾� �⺻ ������ ����" << endl;
}

CPlayer::CPlayer(string _name, string _job, int _hp, int _mp,
                 int _attack, int _level, int _defense, int _maxExp)
    : CObject(_name, _hp, _mp, _attack, _level),
      m_iDefense(_defense),
      m_iMaxExp(_maxExp),
      m_strJob(_job)
{
    cout << _name << " �÷��̾� ������ ����" << endl;
}
CPlayer::~CPlayer() {
		cout << this->m_tagINFO.strName << " �÷��̾� ������ ����" << endl;
		Release();
}


//setter func
void CPlayer::SetDefense(int _defense) {
	if (_defense >= 0)
		this->m_iDefense = _defense;
}

void CPlayer::SetJob(string _job)
{
	this->m_strJob = _job;
}

void CPlayer::Initialize()
{
	m_tagINFO.strName	= "Unknown";
	m_tagINFO.iHp		= 100;
	m_tagINFO.iExp		= 0;
	m_tagINFO.iAttack	= 10;
	m_tagINFO.iLevel	= 1;
	m_iDefense	= 5;
	m_iMaxExp	= 10;
	m_strJob = "Nothing";
}

void CPlayer::Update()
{
	this->m_tagINFO.iExp -= m_iMaxExp;
	this->m_iMaxExp += 5;
	this->m_tagINFO.iLevel++;
}

void CPlayer::Release()
{

}

//print func (override)
void CPlayer::Print() const{
	CObject::Print();
	cout << "��� : " << this->m_iDefense << endl;
	cout << "���� : " << this->m_strJob << endl;
}

void CPlayer::LevelUp(int _exp) {
	this->m_tagINFO.iExp += _exp;
	//max ����ġ ��� ���ε�
	if (this->m_tagINFO.iExp > this->m_iMaxExp) {
		Update();
		cout << "����ġ ������Ʈ ���� �Ϸ�" << endl;
	}
}

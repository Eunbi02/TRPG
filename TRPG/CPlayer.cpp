#include "CPlayer.h"


CPlayer::CPlayer():CObject("Unknown", 100, 0, 10), 
m_iLevel(1),m_iDefense(5), m_iMaxMp(10) {
		cout << "플레이어 기본 생성자 생성" << endl;
	}
CPlayer::CPlayer(string _name , string _job , int _hp,
	int _mp, int _attack, int _level, int _defense,int _maxMp)
	:CObject(_name, _hp, _mp, _attack), m_iLevel(_level), 
	m_iDefense(_defense),m_iMaxMp(_maxMp),m_strJob(_job) {
		cout << _name << " 플레이어 기본 생성자 생성" << endl;
	}
CPlayer::~CPlayer() {
		cout << this->m_strName << " 플레이어 생성자 삭제" << endl;
		Release();
}


//setter func
void CPlayer::SetLevel(int _level) {
	if (_level >= 0)
		this->m_iLevel = _level;
}
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
	m_strName	= "Unknown";
	m_iHp		= 100;
	m_iMp		= 0;
	m_iAttack	= 10;
	m_iLevel	= 1;
	m_iDefense	= 5;
	m_iMaxMp	= 10;
}

void CPlayer::Update()
{
	this->m_iMp -= m_iMaxMp;
	this->m_iMaxMp += 5;
	this->m_iLevel++;
}

void CPlayer::Release()
{

}

//print func (override)
void CPlayer::Print() const{
	CObject::Print();
	cout << "직업 : " << this->m_strJob << endl;
	cout << "레벨 : " << this->m_iLevel << "\t방어 : " << this->m_iDefense << endl; 
}

void CPlayer::Attacked(int _attacked, int _mp){
	//공격 당함
	this->m_iHp -= _attacked;
	if (m_iHp < 0) m_iHp = 0;

	this->m_iMp -= _mp;
	if (m_iMp < 0) m_iMp = 0;
}

void CPlayer::LevelUp(int _mp) {
	this->m_iMp += _mp;
	//max 경험치 찍고 업로드
	if (this->m_iMp > this->m_iMaxMp) {
		Update();
		cout << "경험치 업데이트 진행 완료" << endl;
	}
}

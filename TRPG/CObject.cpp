#include "pch.h"
#include "CObject.h"

CObject::CObject()
	: m_tagINFO({ "Unknown", 100, 0, 10, 1 }) {
}

CObject::CObject(string _sName, int _iHp, int _iExp, int _iAttack,int _iLevel) {
	m_tagINFO.strName = _sName;
	m_tagINFO.iHp = _iHp;
	m_tagINFO.iExp = _iExp;
	m_tagINFO.iAttack = _iAttack;
	m_tagINFO.iLevel = _iLevel;
}
CObject::~CObject() {
	cout << this->m_tagINFO.strName << "������ ���� " << endl;
}


//setter �Լ���
void CObject::SetHp(int _hp) {
	if (_hp >= 0)
		this->m_tagINFO.iHp = _hp;
}
void CObject::SetExp(int _exp) {
	if (_exp >= 0)
		this->m_tagINFO.iExp = _exp;
}
void CObject::SetAttack(int _attack) {
	if (_attack >= 0)
		this->m_tagINFO.iAttack = _attack;
}

void CObject::SetLevel(int _level)
{
	if (_level >= 0)
		this->m_tagINFO.iLevel = _level;
}

void CObject::SetName(string _name)
{
	this->m_tagINFO.strName = _name;
}



//�ڱ� print �Լ�
void CObject::Print() const {
	cout << "=====================================" << endl;
	cout << "�̸� : " << this->m_tagINFO.strName << "\t���� : " << m_tagINFO.iLevel << endl;
	cout << "ü�� : " << this->m_tagINFO.iHp		<< "\t���� : "	<< this->m_tagINFO.iAttack	<< endl;
	cout << "����ġ : " << this->m_tagINFO.iExp << endl;
}

void CObject::Attacked(int _attacked, int _exp) {
	//���� ����
	this->m_tagINFO.iHp -= _attacked;
	if (m_tagINFO.iHp < 0) m_tagINFO.iHp = 0;

	this->m_tagINFO.iExp -= _exp;
	if (m_tagINFO.iExp < 0) m_tagINFO.iExp = 0;
}



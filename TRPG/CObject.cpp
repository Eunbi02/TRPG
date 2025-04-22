#include "pch.h"
#include "CObject.h"

//�����ڿ� �Ҹ���
CObject::CObject() : m_strName("Unknown"), m_iHp(100), m_iMp(0), m_iAttack(10) {
	cout << "�⺻ ������Ʈ ����" << endl;
}

CObject::CObject(string _sName, int _iHp, int _iMp, int _iAttack)
	: m_strName(_sName), m_iHp(_iHp) ,m_iMp(_iMp), m_iAttack(_iAttack) {
	cout << this->m_strName << " ������ ����" << endl;
}

CObject::CObject(const CObject& other)
	: m_strName(other.m_strName),m_iHp(other.m_iHp), m_iMp(other.m_iMp), m_iAttack(other.m_iAttack){
	cout << "���� ������ ȣ���: " << m_strName << endl;
}

CObject::~CObject() {
	cout << this->m_strName << "������ ���� " << endl;
}

//getter �Լ���



//setter �Լ���
void CObject::SetHp(int _hp) {
	if (_hp >= 0)
		this->m_iHp = _hp;
}
void CObject::SetMp(int _mp) {
	if (_mp >= 0)
		this->m_iMp = _mp;
}
void CObject::SetAttack(int _attack) {
	if (_attack >= 0)
		this->m_iAttack = _attack;
}

void CObject::SetName(string _name)
{
	this->m_strName = _name;
}

void CObject::Initialize()
{
	m_strName	="Unknown";
	m_iHp		= 100;
	m_iMp		= 0;
	m_iAttack	= 10;
}

void CObject::Update()
{
}

void CObject::Release()
{
}




//�ڱ� print �Լ�
void CObject::Print() const {
	cout << "=====================================" << endl;
	cout << "�̸� : " << this->m_strName	<< "\t����ġ : "	<< this->m_iMp		<< endl;
	cout << "ü�� : " << this->m_iHp		<< "\t���� : "	<< this->m_iAttack	<< endl;
}



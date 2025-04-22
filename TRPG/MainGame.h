#pragma once
//#include "GameSetting.cpp"
#include "CPlayer.h"
#include "CMonster.h"
#include "CSelectNum.h"

//game, isWin �����ͷ� �Ű��ֱ�

//������ �Լ�ȭ???

class MainGame
{
private:
	enum NUMBER { LOADING=0,NAME, JOB, HUNT, MONSTER, FIGHT,END, ERRO }; // ���� �������� ������� ���� ���⼭ �ϰ� �Ǹ� �װ͵� �߰�
	string jobList[4] = { "����", "������", "����", "�ҷ�����" };
	string huntList[3] = { "�����", "�����ϱ�", "����" };
	string monsterList[4] = { "�ʱ�", "�߱�", "���", "�� �ܰ�" };
	string attackList[2] = { "����", "����" };
	int m_GameStage;
	bool isRunning; 

	CPlayer* m_pPlayer;
	CMonster* m_pMonster;

	CSelectNum SelectJob;
	CSelectNum SelectHunt;
	CSelectNum SelectMonster;
	CSelectNum SelectAttack;

	int* m_pGameNum;
	bool* m_pIsWin;
	
public:
	MainGame();
	~MainGame();

public:
public:
	void		Initialize();
	void		InitializeMonster();
	void		Update();			// �� �����Ӹ��� ��ȭ�ϴ� ���� ����ϴ� �Լ�
	void		Release();			// ���� �Ҵ��� �������� �޸𸮸� �����ϴ� �ڵ带 ��Ƶδ� �Լ�
};
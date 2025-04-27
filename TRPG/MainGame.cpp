#include "MainGame.h"

int CMonster::m_iMonsterKilled = 0;

MainGame::MainGame() :
	isRunning(true),
	m_pPlayer(nullptr),
	m_pMonster(nullptr),
	m_GameStage(0),

	SelectJob(4, "��������", jobList),
	SelectHunt(3, "������� ����", huntList),
	SelectMonster(4, "���� ���̵� ����", monsterList),
	SelectAttack(2, "���ݵ��� ����", attackList),

	//m_pGameNum(nullptr),
	m_bIsWin(0)
{
	cout << "���ΰ��� ������ ����" << endl;
}



MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	
	if (!m_pPlayer) {
		m_pPlayer = CPlayer::Create();
	}
	m_pPlayer->Initialize();

	m_GameStage = NAME;

}

void MainGame::InitializeMonster() //�⺻ ����
{
	if (!m_pMonster) {
		m_pMonster = CMonster::Create();
	}
}

void MainGame::Update()
{
	while (m_GameStage != END) {
		int iInput;

		//system("pause");

		while (m_GameStage == NAME) {
			system("cls");
			string strName;
			cout << "�̸��� �Է� ���ּ��� ";
			cin >> strName;
			m_pPlayer->SetName(strName);

			m_GameStage++;
			system("pause");
		}

		//{ "����", "������", "����", "�ҷ�����" }
		while (m_GameStage == JOB) {
			system("cls");

			SelectJob.Print();
			cin >> iInput;
			// ���� ����
			if (0 < iInput && iInput <= SelectJob.GetSelectSize()) {
				// �ҷ�����
				if (iInput == 4) {
					//�ҷ����� ��������
					m_GameStage = END;
				}
				m_pPlayer->SetJob(SelectJob.GetElementName(iInput - 1));
				m_GameStage++;
			}
			// ����ó��
			else
				cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;
			system("pause");
		}

		//{ "�����", "�����ϱ�", "����" };
		while (m_GameStage == HUNT) {
			system("cls");

			m_pPlayer->Print();
			SelectHunt.Print();
			cin >> iInput;
			if (0 < iInput && iInput <= SelectHunt.GetSelectSize()) {
				switch (iInput)
				{
				case 1:
					m_GameStage++;
					break;
				case 2:
					//�����ϱ�
				case 3:
					m_GameStage = END;
					break;
				default:
					break;
				}
			}
			else
				cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;

			system("pause");

		}

		//"�ʱ�", "�߱�", "���", "�� �ܰ�"
		while (m_GameStage == MONSTER) {
			//���͸� ���� �Ҵ�
			InitializeMonster(); //monster->initailize ���� Game new�Ҵ����

			system("cls");
			m_pPlayer->Print();
			SelectMonster.Print();
			cin >> iInput;
			if (0 < iInput && iInput < SelectMonster.GetSelectSize()) {
				m_pMonster->SetMonsterLevel(iInput); //������ ���� mp,exp �Ҵ�
				//m_pMonster->SetIsLose(m_bIsWin);
				

				m_GameStage++;
			}
			else if (iInput == SelectMonster.GetSelectSize()) {
				m_GameStage--;
			}
			else
				cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;

			
			system("pause");
		}

		//{ "����", "����" };
		while (m_GameStage == FIGHT) {
			system("cls");

			m_pMonster->SetGameNum(); //�������� �̴� ���� ����
			m_pMonster->SetGame();

			m_pPlayer->Print();
			m_pMonster->Print();
			cout << "óġ�� ���� �� : " << CMonster::m_iMonsterKilled << endl;
			SelectAttack.Print();
			cin >> iInput;

			if (0 < iInput && iInput <= SelectAttack.GetSelectSize()) {
				if (iInput == 1) { // ����
					while (m_pMonster->GetHp() != 0 && m_pPlayer->GetHp() != 0) // ���� || �÷��̾� ���� �� ����
					{
						system("cls");
						m_pMonster->SetGame();
						m_pMonster->Print();
						cout << "���͸� óġ�ϼ���!" << endl;
						system("pause");
						m_pMonster->PlayGame();  // ���� ���� ȣ��

						if (m_pMonster->GetIsLose()) { // �÷��̾� �¸� ��
							m_pMonster->Attacked(m_pPlayer->GetAttack(), m_pPlayer->GetExp()); //���Ϳ��� ����
							m_pPlayer->LevelUp(m_pMonster->GetExp());  // ����ġ ȹ��
							 
						}
						else { // ���� �¸� ��
							m_pPlayer->Attacked(m_pMonster->GetAttack(), m_pMonster->GetExp()); //���Ϳ��� �ǰ���
						}
					}

					// ���� ���� �� ó��
					if (m_pMonster->GetHp() == 0) {
						system("cls");
						cout << "���� óġ�� �����ϼ̽��ϴ�!" << endl;
						system("pause");
						CMonster::CountMonsterKill(); //���� ų�� ī��Ʈ
						SAFE_DELETE(m_pMonster);  // ���� �� ���� ����
						m_GameStage--;  // ���� �ܰ� ����
					}
					if (m_pPlayer->GetHp() == 0) {
						system("cls");
						cout << "���� óġ�� �����ϼ̽��ϴ�!" << endl;
						system("pause");
						SAFE_DELETE(m_pPlayer);  // ���� �� �÷��̾� ����
						m_GameStage = END;  // ���� �ܰ� ����
					}
				}
				
				
				
			}
			else {
				cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;
			}

			system("pause");
		}


		system("cls");
		cout << "������ �����մϴ�" << endl;
	}

}


void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMonster);
}

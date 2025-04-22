#include "MainGame.h"



MainGame::MainGame() :
	isRunning(true),
	m_pPlayer(nullptr),
	m_pMonster(nullptr),
	m_GameStage(0),

	SelectJob(4, "��������", jobList),
	SelectHunt(3, "������� ����", huntList),
	SelectMonster(4, "���� ���̵� ����", monsterList),
	SelectAttack(2, "���ݵ��� ����", attackList),

	m_pGameNum(nullptr),
	m_pIsWin(nullptr)
{
	cout << "���ΰ��� ������ ����" << endl;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	if (!m_pGameNum){ m_pGameNum = new int(0); }
	
	if (!m_pIsWin) { m_pIsWin = new bool(false); }
	
	if (!m_pPlayer) {
		m_pPlayer = new CPlayer;
	}
	m_pPlayer->Initialize();

	m_GameStage = NAME;
}

void MainGame::InitializeMonster()
{
	if (!m_pMonster) {
		m_pMonster = new CMonster; //cgame ������ ����
	}
	m_pMonster->Initialize();

	/*int		level = 1;
	int		gameNum = 0;
	bool	isLose = false;*/
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
				m_pMonster->SetName(SelectMonster.GetElementName(iInput - 1));
				m_pMonster->SetLevel(iInput); //monster�� level, win, gamenum ����
				m_pMonster->SetIsLose(m_pIsWin);

				//���� ���� ��.
				/*srand(unsigned int(time(nullptr)));
				*m_pGameNum = rand() % 3 + 1;*/
				*m_pGameNum = 1;				//���� ���� 1���� ������ 1 ����
				m_pMonster->SetGameNum(m_pGameNum);

				m_GameStage++;
			}
			else if (iInput == SelectMonster.GetSelectSize()) {
				m_GameStage--;
			}
			else
				cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;

			m_pMonster->SetGame();//gmae�� level,gamenum,win �����ְ� initialize(minigame ���� ������ ȣ��, initialize, makeanswer)
			system("pause");
		}

		while (m_GameStage == FIGHT) {
			system("cls");

			m_pPlayer->Print();
			m_pMonster->Print();
			SelectAttack.Print();
			cin >> iInput;

			if (0 < iInput && iInput <= SelectAttack.GetSelectSize()) {
				if (iInput == 1) { // ����
					m_pMonster->PlayGame();  // ���� ���� ȣ��

					if (*m_pIsWin==true) { // �÷��̾� �¸� ��
						m_pPlayer->LevelUp(m_pMonster->GetMp());  // ����ġ ȹ��
					}
					else { // ���� �¸� ��
						m_pPlayer->Attacked(m_pMonster->GetAttack(), m_pMonster->GetMp());
					}
				}

				// ���� ���� �� ó��
				SAFE_DELETE(m_pMonster);  // ���� �� ���� ����
				m_GameStage--;  // ���� �ܰ� ����
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
	SAFE_DELETE(m_pGameNum);
	SAFE_DELETE(m_pIsWin);
}

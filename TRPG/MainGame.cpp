#include "MainGame.h"



MainGame::MainGame() :
	isRunning(true),
	m_pPlayer(nullptr),
	m_pMonster(nullptr),
	m_GameStage(0),

	SelectJob(4, "직업선택", jobList),
	SelectHunt(3, "사냥종료 선택", huntList),
	SelectMonster(4, "몬스터 난이도 선택", monsterList),
	SelectAttack(2, "공격도망 선택", attackList),

	m_pGameNum(nullptr),
	m_pIsWin(nullptr)
{
	cout << "메인게임 생성자 생성" << endl;
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
		m_pMonster = new CMonster; //cgame 생성자 까지
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
			cout << "이름을 입력 해주세요 ";
			cin >> strName;
			m_pPlayer->SetName(strName);

			m_GameStage++;
			system("pause");
		}


		while (m_GameStage == JOB) {
			system("cls");

			SelectJob.Print();
			cin >> iInput;
			// 직업 저장
			if (0 < iInput && iInput <= SelectJob.GetSelectSize()) {
				// 불러오기
				if (iInput == 4) {
					//불러오기 만들어야함
					m_GameStage = END;
				}
				m_pPlayer->SetJob(SelectJob.GetElementName(iInput - 1));
				m_GameStage++;
			}
			// 예외처리
			else
				cout << "잘못 입력 하셨습니다" << endl;
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
					//저장하기
				case 3:
					m_GameStage = END;
					break;
				default:
					break;
				}
			}
			else
				cout << "잘못 입력 하셨습니다" << endl;

			system("pause");

		}

		//"초급", "중급", "고급", "전 단계"
		while (m_GameStage == MONSTER) {
			//몬스터를 동적 할당
			InitializeMonster(); //monster->initailize 까지 Game new할당까지

			system("cls");
			m_pPlayer->Print();
			SelectMonster.Print();
			cin >> iInput;
			if (0 < iInput && iInput < SelectMonster.GetSelectSize()) {
				m_pMonster->SetName(SelectMonster.GetElementName(iInput - 1));
				m_pMonster->SetLevel(iInput); //monster에 level, win, gamenum 전달
				m_pMonster->SetIsLose(m_pIsWin);

				//게임 고르는 것.
				/*srand(unsigned int(time(nullptr)));
				*m_pGameNum = rand() % 3 + 1;*/
				*m_pGameNum = 1;				//아직 게임 1개라 무조건 1 대입
				m_pMonster->SetGameNum(m_pGameNum);

				m_GameStage++;
			}
			else if (iInput == SelectMonster.GetSelectSize()) {
				m_GameStage--;
			}
			else
				cout << "잘못 입력 하셨습니다" << endl;

			m_pMonster->SetGame();//gmae에 level,gamenum,win 전해주고 initialize(minigame 인자 생성자 호출, initialize, makeanswer)
			system("pause");
		}

		while (m_GameStage == FIGHT) {
			system("cls");

			m_pPlayer->Print();
			m_pMonster->Print();
			SelectAttack.Print();
			cin >> iInput;

			if (0 < iInput && iInput <= SelectAttack.GetSelectSize()) {
				if (iInput == 1) { // 공격
					m_pMonster->PlayGame();  // 게임 진행 호출

					if (*m_pIsWin==true) { // 플레이어 승리 시
						m_pPlayer->LevelUp(m_pMonster->GetMp());  // 경험치 획득
					}
					else { // 몬스터 승리 시
						m_pPlayer->Attacked(m_pMonster->GetAttack(), m_pMonster->GetMp());
					}
				}

				// 몬스터 게임 후 처리
				SAFE_DELETE(m_pMonster);  // 게임 후 몬스터 삭제
				m_GameStage--;  // 게임 단계 변경
			}
			else {
				cout << "잘못 입력 하셨습니다" << endl;
			}

			system("pause");
		}


		system("cls");
		cout << "게임을 종료합니다" << endl;
	}

}


void MainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pGameNum);
	SAFE_DELETE(m_pIsWin);
}

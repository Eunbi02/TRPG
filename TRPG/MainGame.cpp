#include "MainGame.h"

int CMonster::m_iMonsterKilled = 0;

MainGame::MainGame() :
	isRunning(true),
	m_pPlayer(nullptr),
	m_pMonster(nullptr),
	m_GameStage(0),

	SelectJob(4, "직업선택", jobList),
	SelectHunt(3, "사냥종료 선택", huntList),
	SelectMonster(4, "몬스터 난이도 선택", monsterList),
	SelectAttack(2, "공격도망 선택", attackList),

	//m_pGameNum(nullptr),
	m_bIsWin(0)
{
	cout << "메인게임 생성자 생성" << endl;
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

void MainGame::InitializeMonster() //기본 생성
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
			cout << "이름을 입력 해주세요 ";
			cin >> strName;
			m_pPlayer->SetName(strName);

			m_GameStage++;
			system("pause");
		}

		//{ "전사", "마법사", "도적", "불러오기" }
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

		//{ "사냥터", "저장하기", "종료" };
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
				m_pMonster->SetMonsterLevel(iInput); //레벨에 따라 mp,exp 할당
				//m_pMonster->SetIsLose(m_bIsWin);
				

				m_GameStage++;
			}
			else if (iInput == SelectMonster.GetSelectSize()) {
				m_GameStage--;
			}
			else
				cout << "잘못 입력 하셨습니다" << endl;

			
			system("pause");
		}

		//{ "공격", "도망" };
		while (m_GameStage == FIGHT) {
			system("cls");

			m_pMonster->SetGameNum(); //랜덤으로 미니 게임 생성
			m_pMonster->SetGame();

			m_pPlayer->Print();
			m_pMonster->Print();
			cout << "처치한 몬스터 수 : " << CMonster::m_iMonsterKilled << endl;
			SelectAttack.Print();
			cin >> iInput;

			if (0 < iInput && iInput <= SelectAttack.GetSelectSize()) {
				if (iInput == 1) { // 공격
					while (m_pMonster->GetHp() != 0 && m_pPlayer->GetHp() != 0) // 몬스터 || 플래이어 죽을 때 까지
					{
						system("cls");
						m_pMonster->SetGame();
						m_pMonster->Print();
						cout << "몬스터를 처치하세요!" << endl;
						system("pause");
						m_pMonster->PlayGame();  // 게임 진행 호출

						if (m_pMonster->GetIsLose()) { // 플레이어 승리 시
							m_pMonster->Attacked(m_pPlayer->GetAttack(), m_pPlayer->GetExp()); //몬스터에게 공격
							m_pPlayer->LevelUp(m_pMonster->GetExp());  // 경험치 획득
							 
						}
						else { // 몬스터 승리 시
							m_pPlayer->Attacked(m_pMonster->GetAttack(), m_pMonster->GetExp()); //몬스터에게 피공격
						}
					}

					// 몬스터 게임 후 처리
					if (m_pMonster->GetHp() == 0) {
						system("cls");
						cout << "몬스터 처치에 성공하셨습니다!" << endl;
						system("pause");
						CMonster::CountMonsterKill(); //몬스터 킬수 카운트
						SAFE_DELETE(m_pMonster);  // 게임 후 몬스터 삭제
						m_GameStage--;  // 게임 단계 변경
					}
					if (m_pPlayer->GetHp() == 0) {
						system("cls");
						cout << "몬스터 처치에 실패하셨습니다!" << endl;
						system("pause");
						SAFE_DELETE(m_pPlayer);  // 게임 후 플레이어 삭제
						m_GameStage = END;  // 게임 단계 변경
					}
				}
				
				
				
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
}

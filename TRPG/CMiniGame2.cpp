#include "CMiniGame2.h"

CMiniGame2::CMiniGame2() : CGame(1, nullptr)
{
	m_iSize		= 3;
	m_iRound	= 0;

	m_icomIdx1		= 0;
	m_icomIdx2		= 0;
	m_iuserIdx1		= 0;
	m_iuserIdx2		= 0;

	icomBingoNum	= 0;
	iuserBingoNum	= 0;
	icomElement		= 0;
	iuserElement	= 0;

	for (int i = 0; i < m_iSize * m_iSize; i++) {
		comNumChek[i] = i + 1;
	}

	comBingo	= new int*[m_iSize];
	userBingo	= new int*[m_iSize];

	for (int i = 0; i < m_iSize; ++i) {
		comBingo[i] = new int[m_iSize];   // 각 행에 대해 두 번째 차원 동적 할당
		userBingo[i] = new int[m_iSize];  // 각 행에 대해 두 번째 차원 동적 할당
	}
}

CMiniGame2::CMiniGame2(int _iLevel, bool* _bIsLose) :CGame(_iLevel, _bIsLose)
{
	m_iRound = 0;

	m_icomIdx1 = 0;
	m_icomIdx2 = 0;
	m_iuserIdx1 = 0;
	m_iuserIdx2 = 0;

	icomBingoNum = 0;
	iuserBingoNum = 0;
	icomElement = 0;
	iuserElement = 0;

	switch (m_iLevel) { //default 시 level = 3
	case 1:
		m_iSize = 3;
		break;
	case 2:
		m_iSize = 5;
		break;
	case 3:
	default:
		m_iSize = 7;
		m_iLevel = 3; //예외값 넣었을때 처리
		break;
	}

	for (int i = 0; i < m_iSize * m_iSize; i++) {
		comNumChek[i] = i + 1;
	}

	comBingo = new int* [m_iSize];
	userBingo = new int* [m_iSize];

	for (int i = 0; i < m_iSize; ++i) {
		comBingo[i] = new int[m_iSize];   // 각 행에 대해 두 번째 차원 동적 할당
		userBingo[i] = new int[m_iSize];  // 각 행에 대해 두 번째 차원 동적 할당
	}
}

CMiniGame2::~CMiniGame2()
{
	Release();
	cout << "미니게임2 소멸자" << endl;
}

void CMiniGame2::Initialize()
{
	MakeComBingo();
	MakeUserBingo();

	//comNumChek suffle
	for (int i = 0; i < 100; i++) {
		int iIdx1 = rand() % m_iSize * m_iSize;
		int iIdx2 = rand() % m_iSize * m_iSize;

		swap(comNumChek[iIdx1], comNumChek[iIdx2]);
	}
}

void CMiniGame2::Update()
{
}

void CMiniGame2::Release()
{
	for (int i = 0; i < m_iSize; ++i) {
		delete[] comBingo[i];
		delete[] userBingo[i];
	}

	// 배열 자체를 메모리 해제
	delete[] comBingo;
	delete[] userBingo;

}

void CMiniGame2::BingoSuffle()
{
	for (int i = 0; i < 100; i++) {
		int iR1 = rand() % m_iSize;
		int iR2 = rand() % m_iSize;
		int iC1 = rand() % m_iSize;
		int iC2 = rand() % m_iSize;

		swap(comBingo[iR1][iC1], comBingo[iR2][iC2]);
	}
}

void CMiniGame2::MakeComBingo()
{
	for (int i = 0; i < m_iSize; ++i) {
		for (int j = 0; j < m_iSize; ++j) {
			comBingo[i][j] = i * m_iSize + j + 1;  // 예시 값 할당
		}
	}
	BingoSuffle();
}

void CMiniGame2::MakeUserBingo()
{
	cout << "빙고를 완성하세요! 숫자는 1 부터 "<< m_iSize * m_iSize <<" 입니다. : ";
	for (int i = 0; i < m_iSize; ++i) {
		for (int j = 0; j < m_iSize; ++j) {
			cin >> userBingo[i][j];
		}
	}
}

void CMiniGame2::ArrIdx(int** _Bingo, int _iElement, int* _pIdx1, int* _pIdx2)
{
	for (int i = 0; i < m_iSize; i++) {
		for (int j = 0; j < m_iSize; j++) {
			if (_Bingo[i][j] == _iElement)
			{
				*_pIdx1 = i; //좌표 값을 넣어줌.
				*_pIdx2 = j;
				return;
			}
		}
	}
}

void CMiniGame2::BingoCheck(int** _Bingo, int _iIdx1, int _iIdx2, int* _iBNum)
{
	bool bIsBingo = true;
	// 가로 확인
	for (int i = 0; i < m_iSize; i++) {
		if (_Bingo[_iIdx1][i] != 0) {
			bIsBingo = false;
			break;
		}
	}
	//빙고가 되면 : 빙고개수++ 
	if (bIsBingo) *_iBNum += 1;
	//만약 빙고 개수가 5이면 함수 탈출
	if (*_iBNum >= m_iSize) return;


	// 세로 확인
	bIsBingo = true;
	for (int i = 0; i < m_iSize; i++) {
		if (_Bingo[i][_iIdx2] != 0) {
			bIsBingo = false;
			break;
		}
	}
	if (bIsBingo) *_iBNum += 1;
	if (*_iBNum >= m_iSize) return;



	// iIdx1 == iIdx2 || iIdx1 + iIdx2 == 5 일떄만 대각선 확인
	if (_iIdx1 == _iIdx2) {
		bIsBingo = true;
		for (int i = 0; i < m_iSize; i++) {
			if (_Bingo[i][i] != 0) {
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo) *_iBNum += 1;

		if (*_iBNum >= m_iSize) return;

	}

	if (_iIdx1 + _iIdx2 == m_iSize - 1) {
		bIsBingo = true;
		for (int i = 0; i < m_iSize; i++) {
			if (_Bingo[i][4 - i] != 0) {
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo) *_iBNum += 1;

		if (*_iBNum >= m_iSize) return;

	}
}

void CMiniGame2::PrintBingo(int** _Bingo)
{
	for (int i = 0; i < m_iSize; i++) {
		for (int j = 0; j < m_iSize; j++) {
			if (_Bingo[i][j] == 0) // 요소의 값이 0이면 * 출력
				cout << "*" << '\t';
			else
				cout << _Bingo[i][j] << '\t';
		}
		cout << endl;
	}
}

void CMiniGame2::PlayGame()
{
	while (m_iRound < m_iSize * m_iSize) {
		system("cls");
		cout << m_iRound + 1 << " 라운드" << endl;
		//컴 빙고와 유저 빙고 출력 (컴 빙고는 확인용)
		cout << "컴퓨터의 빙고판" << endl;
		PrintBingo(comBingo);
		cout << endl;
		cout << "당신의 빙고판" << endl;
		PrintBingo(userBingo);


		icomElement = comNumChek[m_iRound];
		cout << endl;
		cout << "숫자를 선택 해주세요. 1 부터 " << m_iSize * m_iSize << " 입니다. : ";
		cin >> iuserElement;

		//빙고 확인을 위해 좌표값 구해줌
		ArrIdx(comBingo, iuserElement, &m_icomIdx1, &m_icomIdx2);
		ArrIdx(userBingo, icomElement, &m_iuserIdx1, &m_iuserIdx2);

		//숫자를 0으로 바꿈.
		comBingo[m_icomIdx1][m_icomIdx2] = 0;
		userBingo[m_iuserIdx1][m_iuserIdx2] = 0;

		//둘다 빙고 확인(round 가 5이상일때)
		if (m_iRound >= m_iSize) {
			BingoCheck(comBingo, m_icomIdx1, m_icomIdx2, &iuserBingoNum);
			BingoCheck(userBingo, m_iuserIdx1, m_iuserIdx2, &icomBingoNum);
		}

		//bingo 개수 출력
		cout << "컴퓨터의 빙고 개수 : " << icomBingoNum << endl;
		cout << "당신의 빙고 개수 : " << iuserBingoNum << endl;

		//승패 결정
		if (icomBingoNum == 5 && iuserBingoNum == 5) { cout << "게임 결과 : 무승부" << endl; break; }
		else if (icomBingoNum == 5) { 
			cout << "게임 결과 : 패배" << endl; 
			*m_bIsLose = true; 
			return; 
		}
		else if (iuserBingoNum == 5) { 
			cout << "게임 결과 : 승리" << endl; 
			*m_bIsLose = false;
			return;
		}

		m_iRound++;
		system("pause");
	}
}

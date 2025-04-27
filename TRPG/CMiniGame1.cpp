#include "CMiniGame1.h"

CMiniGame1::CMiniGame1() : CGame(1,nullptr)
{
	m_iStrike	= 0;
	m_iBall		= 0;
	m_iRound	= 0;
	m_iMaxRound = 9;
	
	m_iNum		= 9;
	m_iSize		= 3;
	m_iAnswer	= new int[m_iSize];
	m_iGuess	= new int[m_iSize];
}

CMiniGame1::CMiniGame1(int _iLevel, bool* _bIsLose)
	: CGame(_iLevel, _bIsLose)
{
	m_iStrike = 0;
	m_iBall = 0;
	m_iRound = 0;
	
	switch (m_iLevel) { //default 시 level = 3
		case 1:
			m_iMaxRound = 9;
			m_iNum = 9;
			m_iSize = 3;
			break;
		case 2:
			m_iMaxRound = 9;
			m_iNum = 12;
			m_iSize = 4;
			break;
		case 3:
		default:
			m_iMaxRound = 9;
			m_iNum = 15;
			m_iSize = 5;
			m_iLevel = 3; //예외값 넣었을때 처리
			break;
	}

	m_iAnswer	= new int[m_iSize];
	m_iGuess	= new int[m_iSize];

}

CMiniGame1::~CMiniGame1()
{
	Release();
}


void CMiniGame1::Initialize()
{
	m_iStrike = 0;
	m_iBall = 0;
	m_iRound = 0;


	switch (m_iLevel) { //default 시 level = 3
	case 1:
		m_iMaxRound = 9;
		m_iNum = 9;
		m_iSize = 3;
		break;
	case 2:
		m_iMaxRound = 11;
		m_iNum = 9;
		m_iSize = 4;
		break;
	case 3:
	default:
		m_iMaxRound = 12;
		m_iNum = 9;
		m_iSize = 5;
		m_iLevel = 3; //예외값 넣었을때 처리
		break;
	}

	// 기존 배열 해제
	SAFE_DELETE_ARRAY(m_iAnswer);
	SAFE_DELETE_ARRAY(m_iGuess);

	// 새로 size 반영해서 할당
	m_iAnswer	= new int[m_iSize];
	m_iGuess	= new int[m_iSize];

}

void CMiniGame1::Update()
{
	m_iRound++;
	m_iStrike = 0;
	m_iBall = 0;
}

void CMiniGame1::Release()
{
	SAFE_DELETE_ARRAY(m_iAnswer);
	SAFE_DELETE_ARRAY(m_iGuess);
}

void CMiniGame1::MakeAnswer()
{
	SAFE_DELETE_ARRAY(m_iAnswer);
	m_iAnswer = new int[m_iSize];

	int* pArr = new int[m_iNum];

	for (int i = 0; i < m_iNum; ++i)
	{
		pArr[i] = i + 1;
	}
	for (int j = 0; j < 100; ++j)
	{
		int iDst = rand() % m_iNum;
		int iSrc = rand() % m_iNum;
		swap(pArr[iDst], pArr[iSrc]);
	}

	for (int i = 0; i < m_iSize; ++i)
	{
		m_iAnswer[i] = pArr[i];
	}

	SAFE_DELETE_ARRAY(pArr);
}

void CMiniGame1::StrikeBall()
{
	for (int i = 0; i < m_iSize; i++) {
		for (int j = 0; j < m_iSize; j++) {
			if (m_iAnswer[i] == m_iGuess[j] && i == j) {
				m_iStrike++;
			}
			else if (m_iAnswer[i] == m_iGuess[j]) {
				m_iBall++;
			}
		}
	}
}

void CMiniGame1::PlayGame()
{
	//check용
	for (int i = 0; i < m_iSize; i++) {
		cout << m_iAnswer[i] << '\t';
	}
	cout << endl;
	while (m_iRound < m_iMaxRound) {
		cout << "총 " << m_iMaxRound << "회 중 현재" << m_iRound + 1 << " 회" << endl;
		cout << "1부터 " << m_iNum << "까지 숫자 중에서 "<< m_iSize << "만큼 입력(중복x)";
		for (int i = 0; i < m_iSize; i++) {
			cin >> m_iGuess[i];
		}

		//스트라이크 볼 판정
		StrikeBall();
		cout << m_iStrike << " 스트라이크 " << m_iBall << " 볼" << endl;
		cout << endl;

		//이닝 종료 여부 판정
		if (m_iStrike == m_iSize) {
			//cout << "정답은 " << iAnswer << "이었습니다" << endl; //check 용
			cout << m_iRound + 1 << "회 종료!\n" << "승리 하셨습니다" << endl;
			*m_bIsLose = true;
			return;
		}
		
		Update();
	}

	//9회까지 못 맞췄을때 출력
	//cout << "정답은 " << iAnswer << "이었습니다" << endl; //check 용
	cout << "패배 하셨습니다." << endl;
	*m_bIsLose = false;
}

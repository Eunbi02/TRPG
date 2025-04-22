#include "CMiniGame1.h"
//#include "GamePointer.h"

CMiniGame1::CMiniGame1()
{
	m_pLevel = nullptr;
	//m_iGameNum = nullptr;
	m_pIsWin = nullptr;

	m_iStrike	= 0;
	m_iBall		= 0;
	m_iRound	= 0;
	m_iMaxRound = 9;
	
	m_iNum		= 9;
	m_iSize		= 3;
	m_iAnswer	= new int[m_iSize];
	m_iGuess	= new int[m_iSize];
}

CMiniGame1::CMiniGame1(int* _level, bool* _isWin)
{
	m_pLevel = _level;
	//m_iGameNum = 1;
	m_pIsWin = _isWin;

	m_iStrike = 0;
	m_iBall = 0;
	m_iRound = 0;
	

	switch (*_level) { //default �� level = 3
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
			*m_pLevel = 3; //���ܰ� �־����� ó��
			break;
	}

	m_iAnswer	= new int[m_iSize];
	m_iGuess	= new int[m_iSize];

}

CMiniGame1::~CMiniGame1()
{
	Release();
}

void CMiniGame1::SetLevel(int* _level)
{
	m_pLevel = _level;
}

void CMiniGame1::Initialize()
{
	/*m_iStrike = 0;
	m_iBall = 0;
	m_iRound = 0;*/


	switch (*m_pLevel) { //default �� level = 3
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
		*m_pLevel = 3; //���ܰ� �־����� ó��
		break;
	}

	/*m_iAnswer = new int[m_iSize];
	m_iGuess = new int[m_iSize];*/

	// ���� �迭 ����
	SAFE_DELETE_ARRAY(m_iAnswer);
	SAFE_DELETE_ARRAY(m_iGuess);

	// ���� size �ݿ��ؼ� �Ҵ�
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
	int* pArr = new int[m_iNum];

	SAFE_DELETE_ARRAY(m_iAnswer);
	m_iAnswer = new int[m_iSize];  // �� ���Ҵ� �߰�

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
	cout << "�� " << m_iMaxRound << "ȸ" << endl;
	while (m_iRound < m_iMaxRound) {
		cout << m_iRound + 1 << " ȸ" << endl;
		cout << "1���� " << m_iNum << "���� ���� �߿��� "<< m_iSize << "��ŭ �Է�(�ߺ�x)";
		for (int i = 0; i < m_iSize; i++) {
			cin >> m_iGuess[i];
		}

		//��Ʈ����ũ �� ����
		StrikeBall();
		cout << m_iStrike << " ��Ʈ����ũ " << m_iBall << " ��" << endl;
		cout << endl;

		//�̴� ���� ���� ����
		if (m_iStrike == 3) {
			//cout << "������ " << iAnswer << "�̾����ϴ�" << endl; //check ��
			cout << m_iRound + 1 << "ȸ ����!\n" << "�¸� �ϼ̽��ϴ�" << endl;
			*m_pIsWin = true;
			return;
		}
		
		Update();
	}

	//9ȸ���� �� �������� ���
	//cout << "������ " << iAnswer << "�̾����ϴ�" << endl; //check ��
	cout << "�й� �ϼ̽��ϴ�." << endl;
	*m_pIsWin = false;
}

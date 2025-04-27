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
		comBingo[i] = new int[m_iSize];   // �� �࿡ ���� �� ��° ���� ���� �Ҵ�
		userBingo[i] = new int[m_iSize];  // �� �࿡ ���� �� ��° ���� ���� �Ҵ�
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

	switch (m_iLevel) { //default �� level = 3
	case 1:
		m_iSize = 3;
		break;
	case 2:
		m_iSize = 5;
		break;
	case 3:
	default:
		m_iSize = 7;
		m_iLevel = 3; //���ܰ� �־����� ó��
		break;
	}

	for (int i = 0; i < m_iSize * m_iSize; i++) {
		comNumChek[i] = i + 1;
	}

	comBingo = new int* [m_iSize];
	userBingo = new int* [m_iSize];

	for (int i = 0; i < m_iSize; ++i) {
		comBingo[i] = new int[m_iSize];   // �� �࿡ ���� �� ��° ���� ���� �Ҵ�
		userBingo[i] = new int[m_iSize];  // �� �࿡ ���� �� ��° ���� ���� �Ҵ�
	}
}

CMiniGame2::~CMiniGame2()
{
	Release();
	cout << "�̴ϰ���2 �Ҹ���" << endl;
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

	// �迭 ��ü�� �޸� ����
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
			comBingo[i][j] = i * m_iSize + j + 1;  // ���� �� �Ҵ�
		}
	}
	BingoSuffle();
}

void CMiniGame2::MakeUserBingo()
{
	cout << "���� �ϼ��ϼ���! ���ڴ� 1 ���� "<< m_iSize * m_iSize <<" �Դϴ�. : ";
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
				*_pIdx1 = i; //��ǥ ���� �־���.
				*_pIdx2 = j;
				return;
			}
		}
	}
}

void CMiniGame2::BingoCheck(int** _Bingo, int _iIdx1, int _iIdx2, int* _iBNum)
{
	bool bIsBingo = true;
	// ���� Ȯ��
	for (int i = 0; i < m_iSize; i++) {
		if (_Bingo[_iIdx1][i] != 0) {
			bIsBingo = false;
			break;
		}
	}
	//���� �Ǹ� : ������++ 
	if (bIsBingo) *_iBNum += 1;
	//���� ���� ������ 5�̸� �Լ� Ż��
	if (*_iBNum >= m_iSize) return;


	// ���� Ȯ��
	bIsBingo = true;
	for (int i = 0; i < m_iSize; i++) {
		if (_Bingo[i][_iIdx2] != 0) {
			bIsBingo = false;
			break;
		}
	}
	if (bIsBingo) *_iBNum += 1;
	if (*_iBNum >= m_iSize) return;



	// iIdx1 == iIdx2 || iIdx1 + iIdx2 == 5 �ϋ��� �밢�� Ȯ��
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
			if (_Bingo[i][j] == 0) // ����� ���� 0�̸� * ���
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
		cout << m_iRound + 1 << " ����" << endl;
		//�� ����� ���� ���� ��� (�� ����� Ȯ�ο�)
		cout << "��ǻ���� ������" << endl;
		PrintBingo(comBingo);
		cout << endl;
		cout << "����� ������" << endl;
		PrintBingo(userBingo);


		icomElement = comNumChek[m_iRound];
		cout << endl;
		cout << "���ڸ� ���� ���ּ���. 1 ���� " << m_iSize * m_iSize << " �Դϴ�. : ";
		cin >> iuserElement;

		//���� Ȯ���� ���� ��ǥ�� ������
		ArrIdx(comBingo, iuserElement, &m_icomIdx1, &m_icomIdx2);
		ArrIdx(userBingo, icomElement, &m_iuserIdx1, &m_iuserIdx2);

		//���ڸ� 0���� �ٲ�.
		comBingo[m_icomIdx1][m_icomIdx2] = 0;
		userBingo[m_iuserIdx1][m_iuserIdx2] = 0;

		//�Ѵ� ���� Ȯ��(round �� 5�̻��϶�)
		if (m_iRound >= m_iSize) {
			BingoCheck(comBingo, m_icomIdx1, m_icomIdx2, &iuserBingoNum);
			BingoCheck(userBingo, m_iuserIdx1, m_iuserIdx2, &icomBingoNum);
		}

		//bingo ���� ���
		cout << "��ǻ���� ���� ���� : " << icomBingoNum << endl;
		cout << "����� ���� ���� : " << iuserBingoNum << endl;

		//���� ����
		if (icomBingoNum == 5 && iuserBingoNum == 5) { cout << "���� ��� : ���º�" << endl; break; }
		else if (icomBingoNum == 5) { 
			cout << "���� ��� : �й�" << endl; 
			*m_bIsLose = true; 
			return; 
		}
		else if (iuserBingoNum == 5) { 
			cout << "���� ��� : �¸�" << endl; 
			*m_bIsLose = false;
			return;
		}

		m_iRound++;
		system("pause");
	}
}

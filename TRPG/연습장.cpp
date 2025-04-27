//2. ���� ������.
//
//- 5 x 5 ������ �迭�� �̿��Ͽ� 1 ~25�� ���ڸ� ����϶�
//- ����ڰ� ���ڸ� �Է��ϰ� �Է��� ���ڿ� �迭�� ���� ��ġ�� ��� * �� ����Ѵ�
//- ����, ����, �밢�� ��������* �� �ټ����� �Ǹ� ���� �ϳ��� ���� ��Ų��.
//- 5 ���� �Ǹ� '�¸�' ��� ��, ������ �����Ѵ�.
//
//- (��ȭ)��ǻ�Ϳ� �����ϴ� ���� �������� �����
//- ������ �����ǰ� ��ǻ���� ���� ���� ȭ�鿡 ���ÿ� ���
//- ������ �Է� �޾Ƽ� ���� ��Ģ ��� ������ �Ѵ�
//- ���� �����̾ ������ �Է��� ��, ��ǻ�͵� ������ �̿��Ͽ� ���ڸ� ������.
//- ���� 5 ���� ����� ���� �¸�

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 5;

//�迭 ��� �Լ�
void PrintBingo(int _iBingo[SIZE][SIZE]);

//���� ���� �Լ�.
void SuffleArr(int _iBingo[SIZE][SIZE], int _iNum);
void SuffleArr(int _iBingo[], int _iSize, int _iNum);

//�ش� ����� �ε��� ��ȯ 
void ArrIdx(int _iBingo[SIZE][SIZE], int _iElment, int* _pIdx1, int* _pIdx2);

//bingo Ȯ�� �Լ�
void BingoCheck(int _iBingo[SIZE][SIZE], int _iIdx1, int _iIdx2, int* _iBNum);


int main() {
	srand(unsigned(time(NULL)));

	int comBingo[SIZE][SIZE];
	int userBingo[SIZE][SIZE];
	int comNumChek[25];

	//��ǻ���� �ߺ� ������ ���� ������
	for (int i = 0; i < SIZE * SIZE; i++) {
		comNumChek[i] = i + 1;
	}
	SuffleArr(comNumChek, 25, 100);

	// ��ǻ�� ���� �����
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			comBingo[i][j] = i * SIZE + j + 1;
		}
	}
	//����
	SuffleArr(comBingo, 100);

	// ���� ���� �����
	cout << "���� �ϼ��ϼ���! ���ڴ� 1 - 25 �Դϴ�. : ";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> userBingo[i][j];
		}
	}
	/////////////������ �ϼ�///////////////

	int iRound(0);
	int icomBingoNum(0);
	int iuserBingoNum(0);
	int icomElement(0);
	int iuserElement(0);
	int icomIdx1(0);
	int icomIdx2(0);
	int iuserIdx1(0);
	int iuserIdx2(0);

	while (iRound < 25) {
		system("cls");
		cout << iRound + 1 << " ����" << endl;
		//�� ����� ���� ���� ��� (�� ����� Ȯ�ο�)
		cout << "��ǻ���� ������" << endl;
		PrintBingo(comBingo);
		cout << endl;
		cout << "����� ������" << endl;
		PrintBingo(userBingo);


		//���� ����
		icomElement = comNumChek[iRound];
		cout << endl;
		cout << "���ڸ� ���� ���ּ��� 1 - 25. ���� ����� 0. : ";
		cin >> iuserElement;

		//���� �����
		if (iuserElement == 0) {
			cout << "������ ���� �ϼ̽��ϴ�" << endl;
			cout << "���� ��� : ���º�" << endl;
			break;
		}

		//���� Ȯ���� ���� ��ǥ�� ������
		ArrIdx(comBingo, iuserElement, &icomIdx1, &icomIdx2);
		ArrIdx(userBingo, icomElement, &iuserIdx1, &iuserIdx2);

		//���ڸ� 0���� �ٲ�.
		comBingo[icomIdx1][icomIdx2] = 0;
		userBingo[iuserIdx1][iuserIdx2] = 0;


		//�Ѵ� ���� Ȯ��(round �� 5�̻��϶�)
		if (iRound >= 4) {
			BingoCheck(comBingo, icomIdx1, icomIdx2, &iuserBingoNum);
			BingoCheck(userBingo, iuserIdx1, iuserIdx2, &icomBingoNum);
		}

		//bingo ���� ���
		cout << "��ǻ���� ���� ���� : " << icomBingoNum << endl;
		cout << "����� ���� ���� : " << iuserBingoNum << endl;

		//���� ����
		if (icomBingoNum == 5 && iuserBingoNum == 5) { cout << "���� ��� : ���º�" << endl; break; }
		else if (icomBingoNum == 5) { cout << "���� ��� : �й�" << endl; break; }
		else if (iuserBingoNum == 5) { cout << "���� ��� : �¸�" << endl; break; }

		iRound++;
		system("pause");
	}

	return 0;
}

/////////////////////�Լ� ����////////////////////
void PrintBingo(int _iBingo[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (_iBingo[i][j] == 0) // ����� ���� 0�̸� * ���
				cout << "*" << '\t';
			else
				cout << _iBingo[i][j] << '\t';
		}
		cout << endl;
	}
}


void SuffleArr(int _iBingo[SIZE][SIZE], int _iNum)
{
	for (int i = 0; i < _iNum; i++) {
		int iR1 = rand() % SIZE;
		int iR2 = rand() % SIZE;
		int iC1 = rand() % SIZE;
		int iC2 = rand() % SIZE;

		swap(_iBingo[iR1][iC1], _iBingo[iR2][iC2]);
	}
}

void SuffleArr(int _iBingo[], int _iSize, int _iNum)
{
	for (int i = 0; i < _iNum; i++) {
		int iIdx1 = rand() % _iSize;
		int iIdx2 = rand() % _iSize;

		swap(_iBingo[iIdx1], _iBingo[iIdx2]);
	}
}

void ArrIdx(int _iBingo[SIZE][SIZE], int _iElement, int* _pIdx1, int* _pIdx2)
{

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (_iBingo[i][j] == _iElement)
			{
				*_pIdx1 = i; //��ǥ ���� �־���.
				*_pIdx2 = j;
				return;
			}
		}
	}
}

void BingoCheck(int _iBingo[SIZE][SIZE], int _iIdx1, int _iIdx2, int* _iBNum)
{
	bool bIsBingo = true;
	// ���� Ȯ��
	for (int i = 0; i < SIZE; i++) {
		if (_iBingo[_iIdx1][i] != 0) {
			bIsBingo = false;
			break;
		}
	}
	//���� �Ǹ� : ������++ 
	if (bIsBingo) *_iBNum += 1;
	//���� ���� ������ 5�̸� �Լ� Ż��
	if (*_iBNum >= SIZE) return;


	// ���� Ȯ��
	bIsBingo = true;
	for (int i = 0; i < SIZE; i++) {
		if (_iBingo[i][_iIdx2] != 0) {
			bIsBingo = false;
			break;
		}
	}
	if (bIsBingo) *_iBNum += 1;
	if (*_iBNum >= SIZE) return;



	// iIdx1 == iIdx2 || iIdx1 + iIdx2 == 5 �ϋ��� �밢�� Ȯ��
	if (_iIdx1 == _iIdx2) {
		bIsBingo = true;
		for (int i = 0; i < SIZE; i++) {
			if (_iBingo[i][i] != 0) {
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo) *_iBNum += 1;

		if (*_iBNum >= SIZE) return;

	}

	if (_iIdx1 + _iIdx2 == SIZE - 1) {
		bIsBingo = true;
		for (int i = 0; i < SIZE; i++) {
			if (_iBingo[i][4 - i] != 0) {
				bIsBingo = false;
				break;
			}
		}

		if (bIsBingo) *_iBNum += 1;

		if (*_iBNum >= SIZE) return;

	}

}

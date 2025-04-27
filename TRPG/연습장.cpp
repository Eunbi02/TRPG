//2. 빙고를 만들어라.
//
//- 5 x 5 형태의 배열을 이용하여 1 ~25의 숫자를 출력하라
//- 사용자가 숫자를 입력하고 입력한 숫자와 배열의 값이 일치할 경우 * 로 출력한다
//- 가로, 세로, 대각선 방향으로* 이 다섯개가 되면 빙고 하나를 증가 시킨다.
//- 5 빙고가 되면 '승리' 출력 후, 게임을 종료한다.
//
//- (심화)컴퓨터와 대전하는 빙고 게임으로 만들기
//- 유저의 빙고판과 컴퓨터의 빙고 판을 화면에 동시에 출력
//- 유저는 입력 받아서 기존 규칙 대로 진행을 한다
//- 턴제 형식이어서 유저가 입력한 뒤, 컴퓨터도 난수를 이용하여 숫자를 만들어낸다.
//- 먼저 5 빙고를 만드는 쪽이 승리

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 5;

//배열 출력 함수
void PrintBingo(int _iBingo[SIZE][SIZE]);

//빙고 셔플 함수.
void SuffleArr(int _iBingo[SIZE][SIZE], int _iNum);
void SuffleArr(int _iBingo[], int _iSize, int _iNum);

//해당 요소의 인덱스 반환 
void ArrIdx(int _iBingo[SIZE][SIZE], int _iElment, int* _pIdx1, int* _pIdx2);

//bingo 확인 함수
void BingoCheck(int _iBingo[SIZE][SIZE], int _iIdx1, int _iIdx2, int* _iBNum);


int main() {
	srand(unsigned(time(NULL)));

	int comBingo[SIZE][SIZE];
	int userBingo[SIZE][SIZE];
	int comNumChek[25];

	//컴퓨터의 중복 방지를 위한 숫자판
	for (int i = 0; i < SIZE * SIZE; i++) {
		comNumChek[i] = i + 1;
	}
	SuffleArr(comNumChek, 25, 100);

	// 컴퓨터 빙고 만들기
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			comBingo[i][j] = i * SIZE + j + 1;
		}
	}
	//셔플
	SuffleArr(comBingo, 100);

	// 유저 빙고 만들기
	cout << "빙고를 완성하세요! 숫자는 1 - 25 입니다. : ";
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> userBingo[i][j];
		}
	}
	/////////////빙고판 완성///////////////

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
		cout << iRound + 1 << " 라운드" << endl;
		//컴 빙고와 유저 빙고 출력 (컴 빙고는 확인용)
		cout << "컴퓨터의 빙고판" << endl;
		PrintBingo(comBingo);
		cout << endl;
		cout << "당신의 빙고판" << endl;
		PrintBingo(userBingo);


		//숫자 선택
		icomElement = comNumChek[iRound];
		cout << endl;
		cout << "숫자를 선택 해주세요 1 - 25. 게임 종료는 0. : ";
		cin >> iuserElement;

		//게임 종료시
		if (iuserElement == 0) {
			cout << "게임을 종료 하셨습니다" << endl;
			cout << "게임 결과 : 무승부" << endl;
			break;
		}

		//빙고 확인을 위해 좌표값 구해줌
		ArrIdx(comBingo, iuserElement, &icomIdx1, &icomIdx2);
		ArrIdx(userBingo, icomElement, &iuserIdx1, &iuserIdx2);

		//숫자를 0으로 바꿈.
		comBingo[icomIdx1][icomIdx2] = 0;
		userBingo[iuserIdx1][iuserIdx2] = 0;


		//둘다 빙고 확인(round 가 5이상일때)
		if (iRound >= 4) {
			BingoCheck(comBingo, icomIdx1, icomIdx2, &iuserBingoNum);
			BingoCheck(userBingo, iuserIdx1, iuserIdx2, &icomBingoNum);
		}

		//bingo 개수 출력
		cout << "컴퓨터의 빙고 개수 : " << icomBingoNum << endl;
		cout << "당신의 빙고 개수 : " << iuserBingoNum << endl;

		//승패 결정
		if (icomBingoNum == 5 && iuserBingoNum == 5) { cout << "게임 결과 : 무승부" << endl; break; }
		else if (icomBingoNum == 5) { cout << "게임 결과 : 패배" << endl; break; }
		else if (iuserBingoNum == 5) { cout << "게임 결과 : 승리" << endl; break; }

		iRound++;
		system("pause");
	}

	return 0;
}

/////////////////////함수 정의////////////////////
void PrintBingo(int _iBingo[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (_iBingo[i][j] == 0) // 요소의 값이 0이면 * 출력
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
				*_pIdx1 = i; //좌표 값을 넣어줌.
				*_pIdx2 = j;
				return;
			}
		}
	}
}

void BingoCheck(int _iBingo[SIZE][SIZE], int _iIdx1, int _iIdx2, int* _iBNum)
{
	bool bIsBingo = true;
	// 가로 확인
	for (int i = 0; i < SIZE; i++) {
		if (_iBingo[_iIdx1][i] != 0) {
			bIsBingo = false;
			break;
		}
	}
	//빙고가 되면 : 빙고개수++ 
	if (bIsBingo) *_iBNum += 1;
	//만약 빙고 개수가 5이면 함수 탈출
	if (*_iBNum >= SIZE) return;


	// 세로 확인
	bIsBingo = true;
	for (int i = 0; i < SIZE; i++) {
		if (_iBingo[i][_iIdx2] != 0) {
			bIsBingo = false;
			break;
		}
	}
	if (bIsBingo) *_iBNum += 1;
	if (*_iBNum >= SIZE) return;



	// iIdx1 == iIdx2 || iIdx1 + iIdx2 == 5 일떄만 대각선 확인
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

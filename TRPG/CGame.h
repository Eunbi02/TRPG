#pragma once

class CMiniGame1;

class CGame{
private:
	int* m_pLevel;
	int* m_pGameNum;
	bool* m_pIsWin;

	CMiniGame1* MiniGame1;

public:
	CGame();
	explicit CGame(int* _level, int* _gameNum, bool* _isLose);
	~CGame();

public:
	int* GetLevel()	const { return m_pLevel; };
	int* GetNum()	const { return m_pGameNum; };

	void SetLevel(int* _level);
	void SetGameNum(int* _num);
	void SetIsWin(bool* _isWin);
	void SetLevel(int level);
	void SetGameNum(int num);

public:
	void	Initialize(); //���ӵ��� �ʱ�ȭ
	void	Update(); //���� �� �Լ�
	void	Release();

public:
	void PlayGame();

};
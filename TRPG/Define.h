#pragma once
#include <string>

#define SAFE_DELETE(p) if(p) { delete p ; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p ; p = nullptr;}

typedef struct tagInfo
{
	std::string strName;
	int iHp;
	int iExp;
	int iAttack;
	int iLevel;

}INFO;

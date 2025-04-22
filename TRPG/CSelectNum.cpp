#include "CSelectNum.h"

//생성자와 소멸자
CSelectNum::CSelectNum() : iSize(1), strName("Unknown") {
    strElements = new string[1];
    strElements[0] = "";
    cout << "셀렉 클래스 기본 생성자 생성" << endl;
}

CSelectNum::CSelectNum(int _size, string _name, string* _elements)
    : iSize(_size), strName(_name) {
    strElements = new string[iSize];
    for (int i = 0; i < iSize; ++i) {
        strElements[i] = _elements[i];
    }
    cout << this->strName << " 생성자 생성" << endl;
}

CSelectNum::	~CSelectNum() {
    delete[] strElements;
	cout << this->strName << " 생성자 삭제" << endl;
}

//getter 함수
int CSelectNum::GetSelectSize() const { return iSize; }
string CSelectNum::GetSelectName() const { return strName; }
string CSelectNum::GetElementName(int _idx) const{
	if (_idx < 0 || _idx > iSize)
		return "잘못 입력 하셨습니다";
	return strElements[_idx]; 
}

//자기 프린트 함수
void CSelectNum::Print() const{

	for (int i = 0; i < iSize; ++i) {
		cout << i+1 << ". " << strElements[i] << "  ";
	}
}

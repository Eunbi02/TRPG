#include "CSelectNum.h"

//�����ڿ� �Ҹ���
CSelectNum::CSelectNum() : iSize(1), strName("Unknown") {
    strElements = new string[1];
    strElements[0] = "";
    cout << "���� Ŭ���� �⺻ ������ ����" << endl;
}

CSelectNum::CSelectNum(int _size, string _name, string* _elements)
    : iSize(_size), strName(_name) {
    strElements = new string[iSize];
    for (int i = 0; i < iSize; ++i) {
        strElements[i] = _elements[i];
    }
    cout << this->strName << " ������ ����" << endl;
}

CSelectNum::	~CSelectNum() {
    delete[] strElements;
	cout << this->strName << " ������ ����" << endl;
}

//getter �Լ�
int CSelectNum::GetSelectSize() const { return iSize; }
string CSelectNum::GetSelectName() const { return strName; }
string CSelectNum::GetElementName(int _idx) const{
	if (_idx < 0 || _idx > iSize)
		return "�߸� �Է� �ϼ̽��ϴ�";
	return strElements[_idx]; 
}

//�ڱ� ����Ʈ �Լ�
void CSelectNum::Print() const{

	for (int i = 0; i < iSize; ++i) {
		cout << i+1 << ". " << strElements[i] << "  ";
	}
}

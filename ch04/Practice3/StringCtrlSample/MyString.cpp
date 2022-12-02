#include "MyString.h"
#include <iostream>
// #include <malloc/malloc.h>

using namespace std;

CMyString::CMyString():m_pszData(nullptr), m_Length(0) {}
CMyString::CMyString(const CMyString &rhs):m_pszData(nullptr), m_Length(0) {
    this->SetString(rhs);
}
CMyString::~CMyString() { this->Release(); }

void CMyString::SetString(const CMyString &rhs) {
    cout << "_CMyString(const CMyString &) " << rhs.m_pszData << endl;
    this->Release();
    this->m_Length = rhs.m_Length;
    this->m_pszData = new char[this->m_Length +1];
    strncpy(this->m_pszData, rhs.m_pszData, sizeof(char) * this->m_Length +1);
}

int CMyString::SetString(const char* pszParam) {
    if  (pszParam == nullptr) return 0;

    this->Release();

    this->m_Length = strlen(pszParam);
    if (this->m_Length == 0) return 0;

    this->m_pszData = new char[this->m_Length +1];
    strncpy(this->m_pszData, pszParam, sizeof(char) * this->m_Length +1);
    return 0;
}

const char* CMyString::GetString() const{
    return this->m_pszData;
}

void CMyString::Release() {
    if (this->m_pszData != nullptr){
        cout << "_out~" << this->m_pszData << endl;
        delete[] this->m_pszData;
    }
    
    this->m_pszData = nullptr;
    this->m_Length = 0;
}

CMyString& CMyString::operator=(const CMyString &rhs) {
    this->SetString(rhs);
    return *this;
}

void TestFunc(const CMyString& param) {
    const char* data = param.GetString();
    if (data != nullptr && (int)strlen(data) != 0) {
        cout << data << endl;
    }
}

int main(){
    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("H_World");

    // 복사 생성
    CMyString strNewData(strData);
    cout << strNewData.GetString() << endl;

    // 단순 대입 연산자 호출
    strNewData = strTest;
    cout << strNewData.GetString() << endl;
    
    cout << "___Done___" << endl;
    return 0;
}
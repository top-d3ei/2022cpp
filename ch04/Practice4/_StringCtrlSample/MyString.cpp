#include "MyString.h"
#include <iostream>
// #include <malloc/malloc.h>

using namespace std;

CMyString::CMyString():m_pszData(nullptr), m_Length(0) {}
CMyString::CMyString(const CMyString &rhs):m_pszData(nullptr), m_Length(0) {
    cout << "_CMyString(const CMyString &) " << rhs.GetString() << endl;
    this->SetString(rhs.GetString());
}
CMyString::CMyString(const char* str):m_pszData(nullptr), m_Length(0) {
    cout << "_CMyString(char*) " << str << endl;
    this->SetString(str);
}
CMyString::~CMyString() { this->Release(); }

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
    cout << "_operator=(const CMyString &) " << rhs.GetString() << endl;
    if (this != &rhs)   // 체크: 자기 자신에 대한 대입인가?
        this->SetString(rhs.GetString());
    
    return *this;
}

CMyString::operator char *(void) const {
    return this->m_pszData;
}
// void TestFunc(const CMyString& param) {
//     const char* data = param.GetString();
//     if (data != nullptr && (int)strlen(data) != 0) {
//         cout << data << endl;
//     }
// }

void TestFunc(const CMyString& strParam) {
    // cout << strParam.GetString() << endl;
    cout << strParam << endl;
}

int main(){
    CMyString strData("Hello");

    TestFunc(strData);
    // TestFunc("_hello");
    TestFunc(CMyString("World"));

    cout << "___Done___" << endl;
    return 0;
}
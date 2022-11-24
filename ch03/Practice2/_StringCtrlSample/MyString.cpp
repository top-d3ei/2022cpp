#include "MyString.h"
#include <iostream>
// #include <malloc/malloc.h>

using namespace std;

CMyString::CMyString():m_pszData(nullptr), m_Length(0) {}
CMyString::~CMyString() { this->Release(); }

int CMyString::SetString(const char* pszParam) {
    if  (pszParam == nullptr) return 0;

    this->Release();

    this->m_Length = strlen(pszParam);
    if (this->m_Length == 0) return 0;

    this->m_pszData = new char[this->m_Length +1];
    // strcpy(this->m_pszData, pszParam);
    strncpy(this->m_pszData, pszParam, sizeof(char) * this->m_Length +1);
    // cout << malloc_size(this->m_pszData) << endl;
    return 0;
}

const char* CMyString::GetString() const{
    return this->m_pszData;
}

void CMyString::Release() {
    if (this->m_pszData != nullptr){
        cout << "out~" << this->m_pszData << endl;
        delete[] this->m_pszData;
    }
    
    this->m_pszData = nullptr;
    this->m_Length = 0;
}

// void CMyString::Print(const char* pszParam) {
//     if (pszParam != nullptr && strlen(pszParam) != 0){
//         cout << pszParam << endl;
//     }
// }

void TestFunc(const CMyString& param) {
    const char* data = param.GetString();
    if (data != nullptr && (int)strlen(data) != 0) {
        cout << data << endl;
    }
}

int main(){
    CMyString strData;
    strData.SetString(nullptr);
    // strData.Print(strData.GetString());
    TestFunc(strData);

    strData.SetString("");
    // strData.Print(strData.GetString());
    TestFunc(strData);

    strData.SetString("Hello");
    // strData.Print(strData.GetString());
    TestFunc(strData);

    strData.SetString("Hello World");
    // strData.Print(strData.GetString());
    TestFunc(strData);
    return 0;
}
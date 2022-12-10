#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString():m_pszData(nullptr), m_Length(0) {}
//변환 생성자
CMyString::CMyString(const char* str):m_pszData(nullptr), m_Length(0) {
    cout << "_CMyString(char*) " << str << endl;
    this->SetString(str);
}
//복사 생성자
CMyString::CMyString(const CMyString& rhs):m_pszData(nullptr), m_Length(0) {
    cout << "_CMyString(const CMyString &) " << rhs.GetString() << endl;
    this->SetString(rhs.GetString());
}
//이동 생성자
CMyString::CMyString(CMyString&& rhs):m_pszData(nullptr), m_Length(0) {
    cout << "_CMyString(CMyString&&) " << rhs << endl;
    this->m_pszData = rhs.m_pszData;
    this->m_Length = rhs.m_Length;

    rhs.m_pszData = nullptr;
    rhs.m_Length = 0;
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

int CMyString::GetLength() const {
    return this->m_Length;
}

int CMyString::Append(const char* pszParam) {
    if (pszParam == nullptr) return 0;

    int nLenParam = strlen(pszParam);

    if (nLenParam == 0) return 0;

    if (this->m_pszData == nullptr) {
        this->SetString(pszParam);
        return m_Length;
    }

    int nLenCur = this->m_Length;

    char* pszResult = new char[nLenCur + nLenParam + 1];
    strncpy(pszResult, this->m_pszData, sizeof(char) * (nLenCur + 1));
    strncpy(pszResult + (sizeof(char) * nLenCur), pszParam, sizeof(char) * (nLenParam + 1));

    this->Release();
    this->m_pszData = pszResult;
    this->m_Length = nLenCur + nLenParam;

    return this->m_Length;
}

CMyString& CMyString::operator=(const CMyString& rhs) {
    cout << "_operator=(const CMyString &) " << rhs.GetString() << endl;
    if (this != &rhs)   // 체크: 자기 자신에 대한 대입인가?
        this->SetString(rhs.GetString());
    
    return *this;
}

CMyString& CMyString::operator=(CMyString&& rhs) {
    cout << "_operator=(const CMyString &&) " << rhs << endl;
    this->m_pszData = rhs.m_pszData;
    this->m_Length = rhs.m_Length;

    rhs.m_pszData = nullptr;
    rhs.m_Length = 0;   
    return *this;
}

CMyString::operator char *(void) const {
    // cout << "_operator char *" << endl;
    return this->m_pszData;
}

CMyString CMyString::operator+(const CMyString& rhs) {
    cout << "_operator+(const CMyString& rhs) " << rhs << endl;
    CMyString str(this->m_pszData);
    str.Append(rhs.m_pszData);
    return str;
}

CMyString& CMyString::operator+=(const CMyString& rhs) {
    cout << "_operator+=(const CMyString& rhs) " << rhs << endl;
    this->Append(rhs.m_pszData);
    return *this;
}
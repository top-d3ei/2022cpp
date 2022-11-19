#include "stdafx.h"
#include "MyString.h"
#include <malloc/malloc.h>

CMyString::CMyString()
: m_pszData(nullptr), m_nLength(0)
{
}

CMyString::~CMyString()
{
    this->Release();
}

int CMyString::SetString(const char* pszParam)
{
    this->Release();
    this->m_nLength = this->_strLen(pszParam);
    this->m_pszData = new char[this->m_nLength +1];
    // cout << malloc_size(this->m_pszData) << endl;
    this->_strCpy(pszParam);
    return 0;
}

const char* CMyString::GetString(void)
{
    return m_pszData;
}

void CMyString::Release()
{
    if (this->m_pszData != nullptr){
        // cout << "delete size" << this->_strLen(this->m_pszData) << endl;
        delete this->m_pszData;
    };

    this->m_pszData = nullptr;    
    this->m_nLength = 0;
}

int CMyString::_strLen(const char* str)
{
    int index = 0;
    while(str[index++] != '\0'){};
    return index -1;
}

void CMyString::_strCpy(const char* str)
{
    int i = 0;
    for (i=0; i<=this->m_nLength; i++){
        this->m_pszData[i] = str[i];
    }
}

// int _main(int argc, wchar_t** argv[])
// int main(int argc, char** argv)
int main(void)
{
    CMyString strData;
    strData.SetString("Hello");
    cout << strData.GetString() << endl;

    strData.SetString("World");
    cout << strData.GetString() << endl;

    return 0;
}
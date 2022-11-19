// #prama once

class CMyString
{
private:
    /* data */
    char* m_pszData;
    int m_nLength;
public:
    int SetString(const char* pszParam);
    const char* GetString();
    void Release();
    int _strLen(const char* str);
    void _strCpy(const char* str);

    CMyString(/* args */);
    ~CMyString();
};
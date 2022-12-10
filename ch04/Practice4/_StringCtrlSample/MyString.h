class CMyString {
private:
    char* m_pszData;
    int m_Length;
public:
    CMyString();
    //복사 생성자
    CMyString(const CMyString &);
    //변환 생성자
    explicit CMyString(const char*);
    ~CMyString();

    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();
    //대입 연산자 오버라이딩
    CMyString& operator=(const CMyString &);
    //허용되는 변환
    operator char*(void) const;

};
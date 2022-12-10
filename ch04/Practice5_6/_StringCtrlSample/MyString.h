class CMyString {
private:
    char* m_pszData;
    int m_Length;
public:
    CMyString();
    //변환 생성자
    explicit CMyString(const char*);
    //복사 생성자
    CMyString(const CMyString&);
    //이동 생성자
    CMyString(CMyString&&);
    ~CMyString();

    //대입 연산자 오버라이딩, 오버로딩
    CMyString& operator=(const CMyString &);
    CMyString& operator=(CMyString&&);
    //허용되는 변환
    operator char*(void) const;
    CMyString operator+(const CMyString&);
    CMyString& operator+=(const CMyString&);
    
    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();
    int GetLength() const;
    int Append(const char*);

    // Test This
    // void printThis() {
    //     cout << " this 주소 : " << this << endl;
    // }
    // CMyString* returnThis() {
    //     return this;
    // }
};
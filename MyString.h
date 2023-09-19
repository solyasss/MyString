class MyString
{
private:
    char *str;
    int length;
    static int count;

public:
    MyString();
    MyString(int size);
    MyString(const char *input);
    ~MyString();

    void input_string();
    void display_string() const;

    MyString operator+(const MyString &obj) const;
    MyString &operator+=(const MyString &obj);
    char &operator[](int index);
    const char &operator[](int index) const;
    bool operator==(const MyString &obj) const;
    bool operator!=(const MyString &obj) const;

    void my_strcpy(const MyString &obj);
    bool my_strstr(const char *str) const;
    int my_chr(char c) const;
    int my_strlen() const;
    void my_strcat(const MyString &obj);
    void my_del_chr(char c);
    int my_strcmp(const MyString &obj) const;

    static int get_object_count();
};

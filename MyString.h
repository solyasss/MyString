
class MyString
{
private:
    char *str;
    int length;
    static int object_count;

public:
    MyString();
    MyString(int size);
    MyString(const char *input);
    ~MyString();

    void input_string();
    void display_string() const;

    MyString operator+(const MyString &other) const;
    MyString &operator+=(const MyString &other);
    char &operator[](int index);
    const char &operator[](int index) const;
    bool operator==(const MyString &other) const;
    bool operator!=(const MyString &other) const;

    void my_strcpy(const MyString &other);
    bool my_strstr(const char *str) const;
    int my_chr(char c) const;
    int my_strlen() const;
    void my_strcat(const MyString &other);
    void my_del_chr(char c);
    int my_strcmp(const MyString &other) const;

    static int get_object_count();
};

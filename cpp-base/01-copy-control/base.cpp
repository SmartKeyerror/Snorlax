
#include <cstring>
#include <cstdio>
#include <algorithm>

class BuzzString {
private:
    int length;
    char* ptr;
public:
    BuzzString(int size = 0) : length(size) {
        puts("constructor");
        ptr = new char[size + 1];
    }
    ~BuzzString() {
        puts("destructor");
        delete ptr;
    }

    BuzzString(const BuzzString& other) {
        puts("copy constructor");
        this->length = other.length;
        this->ptr = new char[other.length + 1];
        strcpy(this->ptr, other.ptr);
    }

    BuzzString& operator= (const BuzzString& rhs) {
        puts("copy assignment");
        BuzzString temp = BuzzString(rhs);
        
        using std::swap;
        swap(this->length, temp.length);
        swap(this->ptr, temp.ptr);

        return *this;
    }

    /*
     * 移动构造简单的来说就是从 rvalue 中“窃取”数据。
     * 表现形式为将 this 的数据和 ths (右值引用)的数据进行交换，当函数执行完毕时，
     * 右值生命周期结束，调用析构函数，并将原有 this 的数据析构。
     */
    BuzzString& operator= (BuzzString&& ths) {
        using std::swap;
        swap(this->length, ths.length);
        swap(this->ptr, ths.ptr);
        return *this;
    }
};

int main() {
    BuzzString buz;
    puts("-------------------");
    buz = BuzzString(1024);
    puts("-------------------");
    return 0;
}
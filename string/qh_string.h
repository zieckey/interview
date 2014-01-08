#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <stdlib.h>

namespace qh
{
    class string {
    public:
        //ctor
        string();
        string(const char* s);
        string(const char* s, size_t len);
        string(const string& rhs);

        string& operator=(const string& rhs);

        //dtor
        ~string();

        //get
        size_t size() const;
        const char* data() const;
        const char* c_str() const;

        // set & get
        char* operator[](size_t index);

    private:
        char*  data_;
        size_t len_;
    };
}

#endif



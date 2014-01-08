#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

namespace qh
{
    template<class T>
    class vector {
    public:
        //ctor
        vector()
            : data_(NULL), size_(0)
        {
        }

        explicit vector( size_t n, const T& value = T())
        {
            data_ = new T[n];
            for (size_t i = 0; i < n; i++)
            {
                data_[0] = value;
            }
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
            data_ = rhs.data_;
            size_ = rhs.size_;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        // set & get
        T& operator[](size_t index);

        // set
        void push_back(const T& element);
        void pop_back(const T& element);
        void resize();
        void reserve();
        void clear();
        void empty();

    private:
        T*      data_;
        size_t  size_;
    };
}

#endif



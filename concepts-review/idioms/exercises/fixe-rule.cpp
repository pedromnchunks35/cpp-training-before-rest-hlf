#include <iostream>
class DynamicArray
{
public:
    //? size_t is a unsigned integer for size
    DynamicArray(size_t size) : size_(size), data_(new int[size])
    {
        std::fill(data_, data_ + size_, 0);
    }
    ~DynamicArray()
    {
        delete[] data_;
    }
    //? THE COPY
    DynamicArray(const DynamicArray &other) : size_(other.size_), data_(new int[other.size_])
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }
    //? Copy assignment
    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this == &other)
            return *this;
        int *newData = new int[other.size_];
        std::copy(other.data_, other.data_ + other.size_, newData);
        delete[] data_;
        data_ = newData;
        size_ = other.size_;
        return *this;
    }
    //? noexcept is used to indicate that a function is not expected to throw any exceptions
    //? Move constructor
    DynamicArray(DynamicArray &&other) noexcept : size_(other.size_), data_(other.data_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
    }

    //? Move assignment
    DynamicArray &operator=(DynamicArray &&other) noexcept
    {
        if (this == &other)
            return *this;
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
        return *this;
    }

private:
    size_t size_;
    int *data_;
};
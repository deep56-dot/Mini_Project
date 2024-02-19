#include<iostream>
#include<cstring>
#include "../Include/String.h"
#include"../Include/MyException.h"
using Type::String;

char& String::operator[](unsigned int index) {
    try {
        if (index >= m_size || index < 0)
            throw MyException("String Index Out of Bound");
        else
            return buffer.get()[index];
    }
    catch (MyException m) {
        std::cout << m.getmessage() << '\n';
    }
    return buffer.get()[m_size];
}

    String::String(const String& other) {
        auto len = other.m_size;
        buffer = std::make_unique<char[]>(len+1);
        memcpy(buffer.get(), other.buffer.get(), len);
        buffer.get()[len] = '\0';
        m_size = len;
    }

    String::String(String&& other) noexcept :buffer{ std::move(other.buffer) }, m_size{ std::move(other.m_size) } {}



    String& String::operator=(const String& other) {
        auto len = other.m_size;
      
        buffer = std::make_unique<char[]>(len+1);
        memcpy(buffer.get(), other.buffer.get(), len);
        buffer.get()[len] = '\0';
        m_size = len;
        return *this;
    }

String& String::operator=(String&& other) noexcept
{
    //std::cout << "move assignment\n";
    buffer = std::move(other.buffer);
    m_size = std::move(other.m_size);

    return *this;
};

String String::toString(int num) {
    if (num == 0) {
        return { "0" };
    }
    else {
        auto cnt{ 0 };
        auto tmp{ num };
        while (tmp > 0) {
            tmp = tmp / 10;
            cnt++;
        }

        char* str = new char[cnt + 1];
        for (int i = cnt - 1; i >= 0; i--) {
            int digit = num % 10;
            str[i] = '0' + digit;

            num /= 10;
        }
        str[cnt] = '\0';

        String result{ str };
        delete[] str;
        return result;
    }
}

String& String::append(const String& other) {
 
    auto len{ other.m_size };
    try {
        auto len = m_size + other.m_size;
        auto str = std::make_unique<char[]>(len + 1);
        memcpy(str.get(), buffer.get(), m_size);
        memcpy(str.get() + m_size, other.buffer.get(), other.m_size);
        str.get()[len] = '\0';
        this->m_size = len;
        this->buffer = std::move(str);
        return *this;
    }
    catch (std::bad_alloc) {
        throw "Dynamic memory is not available \n";
    }

    return *this;

}

String Type::operator+(const String& s1, const String& s2) {
    int len = s1.m_size + s2.m_size;
    auto concate = std::make_unique<char[]>(len + 1);
    memcpy(concate.get(), s1.buffer.get(), s1.m_size);
    memcpy(concate.get() + s1.m_size, s2.buffer.get(), s2.m_size);
    concate.get()[len] = '\0';
    String ans{ concate.get()};

    return ans;
}

String& String::to_lower() {
    // 65 - 90
    for (unsigned int i = 0; i < m_size; i++) {
        if ((buffer[i] >= 65) && (buffer[i] <= 90))
            buffer[i] += 32;
    }
    return *this;
}

String& String::to_upper() {
        // 97 - 122
        for (unsigned int i = 0; i < m_size; i++) {
            if ((buffer[i] >= 97) && (buffer[i] <= 122))
                buffer[i] -= 32;
        }
    return *this;
}

std::ostream& Type::operator<<(std::ostream& stream, const String& string)
{
    stream << string.String::buffer.get();
    return stream;
}
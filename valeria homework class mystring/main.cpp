//
//  main.cpp
//  valeria homework class mystring
//
//  Created by Valeria  Bukova on 08.10.2024.
//

#include <iostream>

class MyString {
private:
    char* str;
    size_t length;

    
    size_t my_strlen(const char* s) {
        size_t len = 0;
        while (s[len] != '\0') {
            ++len;
        }
        return len;
    }

   
    void my_strcpy(char* dest, const char* src) {
        size_t i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            ++i;
        }
        dest[i] = '\0';     }

public:
    
    MyString() : str(nullptr), length(0) {}

   
    MyString(const char* s) {
        length = my_strlen(s);
        str = new char[length + 1];
        my_strcpy(str, s);
    }

   
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        my_strcpy(str, other.str);
    }

  
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            my_strcpy(str, other.str);
        }
        return *this;
    }

    // Деструктор
    ~MyString() {
        delete[] str;
    }

    // Метод []
    char& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return str[index];
    }

    // Метод для вывода строки
    void print() const {
        if (str != nullptr) {
            std::cout << str << std::endl;
        }
    }
};

int main() {
    MyString s("Hello");
    s.print(); // Вывод строки "Hello"

    // Тестирование оператора []
    std::cout << "Первый символ строки: " << s[0] << std::endl;

    // Копирование объекта
    MyString s2 = s;
    s2.print(); // Вывод скопированной строки "Hello"

    return 0;
}

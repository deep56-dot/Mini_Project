
#ifndef string1
#define string1

#include<iostream>
#include<cstring>
#include<string.h>
#include<memory>
namespace Type {

	class String {
	private:
		std::unique_ptr<char[]> buffer;
		unsigned int m_size{ 0 };
	public:
		String(const char* string = "") {
			m_size = static_cast<unsigned int>(strlen(string));
			buffer = std::make_unique<char[]>(m_size + 1);
			memcpy(buffer.get(), string, m_size);
			buffer.get()[m_size] = 0;
		}

		String(const String& other);

		String(String&& other) noexcept;

		String& operator=(const String& other);

		String& operator=(String&& other)noexcept;

		char& operator[](unsigned int index);

		unsigned int length() const {
			return m_size;
		}


		String& append(const String& other);

		friend String operator+(const  String&, const  String&);

		static String toString(int num);

		String& to_lower();

		String& to_upper();


		friend std::ostream& operator<<(std::ostream& stream, const String& string);

	};

}

#endif


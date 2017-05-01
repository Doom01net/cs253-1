#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
class U{
	public:	
		U();
		U(const U &rhs);
		U(const std::string filename);
		~U();

		U& operator=(const U &rhs);
		void operator=(std::string rhs);
		U operator+(const U &rhs);
		U operator+(const std::string s);
		friend U operator+(const std::string lhs, const U &rhs);
		U operator+=(const U &rhs);
		U operator+=(const std::string s);
		std::string operator[](int index) const;
		friend std::ostream& operator<<(std::ostream &out, const U &rhs);
		operator bool() const;
		bool operator!();
		friend bool operator==(const U &lhs, const U &rhs);	
		friend bool operator!=(const U &lhs, const U &rhs);
		friend bool operator==(const U &lhs, const std::string s);
		friend bool operator==(const std::string lhs, const U &rhs);
		friend bool operator!=(const U &lhs, const std::string s);
		friend bool operator!=(const std::string lhs, const U &rhs);

		void readfile(const std::string filename);
		void append(const std::string literal);
		std::string get() const;
		std::string get(const int index) const;
		std::string get(const int start, const int end) const;
		int codepoint(const int index) const;
		int size() const;
		bool empty() const;
		void clear();
	private:
		int countBytes(const char c);
		int decoder(int coded, const int bytes);
		void reader(const std::string data);
		std::vector<std::string> acc;
		std::vector<int> codepoints;


};

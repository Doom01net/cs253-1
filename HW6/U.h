#include <set>
#include <string>
#include <vector>
#include <map>

class U {

        public:
                U();                               //Default ctor
                U(const U &rhs);                   //Copy ctor
                U(std::string data); //Test ctor
                const U &operator=(const U &rhs);  //Assignment operator
                ~U();                              //Dtor
                void readfile(const std::string filename);    //Reads UTF-8 characters into accumulated string
                int size() const;         			//Returns # of UTF-8 characters in accumulated string
                std::string get() const;                      //Returns accumulated string
                std::string get(int index) const;             //Returns acc[index]
                std::string get(int start, int limit) const;  //Returns a section of accumulated string
                int propcount(std::string property) const;    //Returns frequency of property in accumulated string
                std::set<std::string> props();          //Returns a set of all possible properties read from propfile
		void append(std::string utf_str);
		int codepoint(int index);
		bool empty() const;
		void clear();
        private:
		bool prop;
		int callCount;
		int sizeVal;
                std::string acc;
		std::vector<std::string> acc_vector;	
		std::vector<std::string> acc_str;
                std::vector<std::string> properties;
		std::vector<std::string> symArray;
		std::vector<long> hexArray;
		std::map<long, std::string> outmap;
		std::map<long, std::string> propmap;
		//helper methods
		std::vector<long> uni2long(std::string uni);
		std::vector<std::string> long2uni(std::vector<long> vl);
};


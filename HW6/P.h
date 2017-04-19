#include <string>
#include <vector>
#include <map>
#include <set>

class P {

        public:
                P();                               //Default ctor
                P(const P &rhs);                   //Copy ctor
                P(std::string properties); //Test ctor
                const P &operator=(const P &rhs);  //Assignment operator
                ~P();
		void count(int codepoint);                            
		int count(std::string prop_name);
                void readfile(const std::string properties);    //Reads UTF-8 characters into accumulated string
                int size() const;                               //Returns # of UTF-8 characters in accumulated string
                std::set<std::string> props();          //Returns a set of all possible properties read from propfile
                bool empty() const;
                void clear();
        private:
                bool prop;
		//int count;
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


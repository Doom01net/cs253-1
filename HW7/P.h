#include <string>
#include <vector>
#include <map>
#include <set>

class P {

        public:
                P();                               			//Default ctor
                P(const P &rhs);                   			//Copy ctor
                P(std::string propfile); 				//Filename ctor
                P &operator=(const P &rhs);  				//Assignment operator
                ~P();							//Dtor
                void readfile(const std::string properties);		//Reads property information from propfile
		std::set<std::string> props();				//Returns a set of all possible props read from propfile
		void count(int codepoint);                            	//Counts codepoint
		int count(std::string prop_name);			//Returns total count of unique occurrences of a property
                int size() const;                               	//Returns # of properties in propfile
                bool empty() const;					//Returns true iff object is empty
                void clear();						//Removes all data from the object
		operator bool();
		bool operator!();
        private:
		std::map<long,std::string> propmap;		//UTF8 to property mapping              
		std::vector<std::string> symArray;
		std::vector<long> hexArray;
		std::vector<std::string> unicodes;
		int counter;
		std::map<std::string, int> countmap;	
};


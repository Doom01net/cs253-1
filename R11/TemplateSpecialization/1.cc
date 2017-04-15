#include <iostream>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    /*void dump() {
	for (typename Con::iterator it=data.begin(); it!=data.end(); ++it)
	    cout << right << setw(10) << it->first << ' '
		 << string(it->second, '*') << '\n';
        cout << '\n';
    }*/
     friend ostream& operator<< (ostream& stream, const BarGraph<T>& barGraph){
	for (const auto &val : barGraph.data){
            stream << right << setw(10) << val.first << ' '
                 << string(val.second, '*') << '\n';
	}	
	return stream;
    }
  private:
    typedef map<T, unsigned> Con;
    Con data;
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha << '\n';

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta << '\n';

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma << '\n';

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    cout << delta << '\n';

    return 0;
}

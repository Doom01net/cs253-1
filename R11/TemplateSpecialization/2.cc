#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    void dump() const {
	for (const auto &val : data)
	    cout << right << setw(10) << val.first << ' '
		 << string(val.second, '*') << '\n';
        cout << '\n';
    }
  private:
   unordered_map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count, true_count;
  public:
    BarGraph() : false_count(0), true_count(0) {
    }
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
   /* void dump() const {
        cout << "     false " << string(false_count, '*') << "\n"
                "      true " << string(true_count,  '*') << "\n\n";
    }*/
     friend ostream& operator<< (ostream& stream, const BarGraph<bool>& barGraph){
        
	stream << "     false " << string(barGraph.false_count, '*') << "\n"
                "      true " << string(barGraph.true_count,  '*') << "\n\n";
	
		
	return stream;
    }
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    alpha.dump();

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    beta.dump();

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
    delta.dump();

    return 0;
}

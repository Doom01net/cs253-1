#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <bitset>



namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

using namespace std;


string letterGrade(double gradePercent)
{
	if(gradePercent >= .90) { return "A"; }
	else if (gradePercent >= .80) { return "B"; }
	else if(gradePercent >= .70) { return "C"; }
	else if (gradePercent >= .60) { return "D"; }
	else { return "F"; }
}


const string gradeOutputName="gradeOutput";   // ~ only works in shells
int main() {
    
	ifstream inputFile(gradeOutputName);
    if(!inputFile) { /* ERROR when opening file */ }

	vector<vector<string>> assignments;
	char character = ' ';
	int beginningOfLine = 1, pastDivide = 0;
	string assignmentLabel = "", pointsObtained = "", pointsPossible = "";
	while(inputFile.get(character))
	{
		if(character == '\n')
		{
			//new line, set the next line to be beginning and all other flags and add to vectors 
			if(1)
			{
				vector<string> assn;
				assn.push_back(assignmentLabel); assn.push_back(pointsObtained); assn.push_back(pointsPossible);
				assignments.push_back(assn);
			}
			assignmentLabel = "", pointsObtained = "", pointsPossible = "";
			beginningOfLine = 1;
			pastDivide = 0;
		}
		else if(character == ' ' || character == ':')
		{
			//ignore it, set not beginning of line so next if breaks and we get past the first assignment label
			beginningOfLine = 0; 
		}
		else if(beginningOfLine)
		{
			//if not space and has yet to hit space
			assignmentLabel += character;
		}
		else if(character != '/' && !pastDivide)
		{
			//points obtained
			pointsObtained += character;
		}
		else if(character == '/')
		{
			pastDivide = 1;
			//disregard
		}
		else if(character != '\n' && pastDivide)
		{
			pointsPossible += character;
		}
		else
		{
			//Shouldn't be here
		}
	}

	map<string, double> assignmentLabelToGrade;
	map<string, double> assignmentLabelToAchieved;
	map<string, double> assignmentLabelToPossible;

	
	for(vector<string> assnElem : assignments)
	{
		double achieved, possible;
		istringstream oss(assnElem[1]);
		oss >> achieved;
		istringstream oss2(assnElem[2]);
		oss2 >> possible;
		string assignmentName = assnElem[0];

		assignmentLabelToGrade[assignmentName] = achieved / possible;
		assignmentLabelToAchieved[assignmentName] = achieved;
		assignmentLabelToPossible[assignmentName] = possible;
	}


	//remove non-curved scores if there is a curved version
	string curved = "-curved";
	for( auto x : assignmentLabelToGrade)
	{
		size_t found = (x.first).find(curved);
		if(found != string::npos)
		{
			string toRemove;
			istringstream iss(x.first);
			char c;
			while(iss >> c)
			{
				if(c == '-')
				{
					break;
				}
				else
				{
					toRemove += c;
				}
			}
			assignmentLabelToGrade.erase(toRemove);
			assignmentLabelToAchieved.erase(toRemove);
			assignmentLabelToPossible.erase(toRemove);

		}
	}

	double totalPointsPossible = 0, totalPointsEarned = 0, pointsMissedSoFar = 0, currentGradePercent = 0; string currentScore = "";
	string currentGrade = "";


	Color::Modifier red(Color::FG_RED);
	Color::Modifier yel(Color::FG_YELLOW);
	Color::Modifier grn(Color::FG_GREEN);
	Color::Modifier def(Color::FG_DEFAULT);

	constexpr int width=20;
	cout << "\n\nRemember to update the gradeOutput if you have not done so by running: ~cs253/bin/grade > gradeOutput\n";
	cout << "\n\nGRADEBOOK:\n";
	cout << setw(width) << "Assignment" << def
		 << setw(width) << "Percent"
		 << setw(width) << "Score"
		 << setw(width) << "Grade"
		 << "\n";

    const string midterm = "MIDTERM";
    const string quiz = "Q";
	for(auto x : assignmentLabelToGrade)
	{
		totalPointsPossible += assignmentLabelToPossible[x.first];
		totalPointsEarned += assignmentLabelToAchieved[x.first];
		ostringstream fss;
		//if single digit add ' ' to front
		size_t foundMidterm = (x.first).find(midterm);
		size_t foundQuiz = (x.first).find(quiz);
		if(foundMidterm != string::npos)
		{
			((assignmentLabelToPossible[x.first]) - 10 < 0) ? fss << " " << assignmentLabelToPossible[x.first] : fss << assignmentLabelToPossible[x.first];
			cout << grn << setw(width) << x.first 
				 << setw(width) << x.second
				 << setw(width) << assignmentLabelToAchieved[x.first] << " / "  << fss.str()
				 << setw(width) << letterGrade(x.second) << def
				 << "\n";
		}
		else if(foundQuiz != string::npos)
		{
			((assignmentLabelToPossible[x.first]) - 10 < 0) ? fss << " " << assignmentLabelToPossible[x.first] : fss << assignmentLabelToPossible[x.first];
			cout << yel << setw(width) << x.first 
				 << setw(width) << x.second
				 << setw(width) << assignmentLabelToAchieved[x.first] << " / "  << fss.str()
				 << setw(width) << letterGrade(x.second) << def
				 << "\n";
		}
		else
		{
			((assignmentLabelToPossible[x.first]) - 10 < 0) ? fss << " " << assignmentLabelToPossible[x.first] : fss << assignmentLabelToPossible[x.first];
			cout << setw(width) << x.first 
				 << setw(width) << x.second
				 << setw(width) << assignmentLabelToAchieved[x.first] << " / "  << fss.str()
				 << setw(width) << letterGrade(x.second) 
				 << "\n";
		}
	}
	cout << "\n\n";


	pointsMissedSoFar = (-1) * (totalPointsPossible - totalPointsEarned);
	currentGradePercent = totalPointsEarned / totalPointsPossible;
	double ifIGotA100 = 100 + pointsMissedSoFar;
	ostringstream kss;
	kss << totalPointsEarned;
	currentScore += kss.str();
	currentScore += "/";
	ostringstream ksss;
	ksss << totalPointsPossible;
	currentScore += ksss.str();

	currentGrade = letterGrade(currentGradePercent);

	cout << "TOTALS:" << "\n";

	cout << setw(width) << "Percent" 
		 << setw(width) << "Score" 
		 << setw(width) << "Grade"
		 << setw(width) << "PTSMissed"
		 << setw(width) << "100AllElse"
	<< "\n";

	cout << grn << setw(width) << currentGradePercent << def
		 << setw(width) << currentScore
		 << yel << setw(width) << currentGrade << def
		 << red << setw(width) << pointsMissedSoFar << def
		 << setw(width) << ifIGotA100 
		 << "\n";


	cout << "\n\n";
    inputFile.close();


    return 0;
}
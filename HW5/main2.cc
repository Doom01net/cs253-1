#include "U.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
int main() {


                //Initial Test Case from Jack

	    /*string inputfile = "input";
            U foo(pub+"UnicodeData.txt", inputfile);
            cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';


            //cout <<"Now to try a file" << endl;


            string inputFileName = "input";
            foo.readfile(inputFileName);
            cout << "Should be 16: " << foo.size() << '\n'
                 << "Should be 4: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';
             */


            //Test reading file before multiple propfile calls 


            	string inputFileName = "input.txt";
                U foo;
                foo.readfile(inputFileName);
                foo.propfile(pub+"UnicodeData.txt");
                foo.propfile(pub+"UnicodeData.txt");
                foo.propfile(pub+"UnicodeData.txt");
                cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';
            


            /*Initial Test Case from Jack but with bad property file


            U foo(pub+"Uni___Data.txt", "a³+b³≠c³");
            cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';
            */


            /*Test reading file and calling counts 


            string inputFileName = "input.txt";
                U foo;
                foo.readfile(inputFileName);
                cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 0: " << foo.propcount("Gnarly DUDE!") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';


            */
            




            /*Test reading :q
properties file and calling counts
            string inputFileName = "input.txt";
                U foo;
                foo.propfile(pub+"UnicodeData.txt");
                foo.propfile(pub+"UnicodeData.txt");
                foo.propfile(pub+"UnicodeData.txt");
                foo.readfile(inputFileName);
                //cout << "Let's get the size() (should be zero): " << foo.size() << '\n';
        //cout << "Let's get the propcount(\"Sm\") (should be zero): " << foo.propcount("Sm") << '\n';
        //cout << "Let's get the entire string so far (should be empty): [\"" << foo.get() << "\"]\n";
        //cout << "Let's get an invalid index of 0 should be 'a': " << foo.get(0) << "\n";
        //cout << "Let's get an invalid index of -1 (should throw an error): \n" << foo.get(-1) << "\n";
        //cout << "Let's get an invalid index of 85 (should throw an error): \n" << foo.get(85) << "\n";
                //cout << "Let's get an invalid index range of (-1,500) (should throw an error): \n" << foo.get(-1,500) << "\n";
                //cout << "Let's get an invalid index range of (14,500) (should throw an error): \n" << foo.get(14,500) << "\n";
                //cout << "Let's get the entire string so far (should be 'a'): [\"" << foo.get(0,1) << "\"]\n";


            */


            /*Initial Test Case from Jack


            U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';


            //cout <<"Now to try a file" << endl;


            string inputFileName = "input.txt";
            foo.readfile(inputFileName);
            cout << "Should be 16: " << foo.size() << '\n'
                 << "Should be 4: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';
            */




            /* Multiple objects with base jack test 
            U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';
            cout << "Let's do it again!\n";
            U boo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Should be 8: " << boo.size() << '\n'
                 << "Should be 2: " << boo.propcount("Sm") << '\n'
                 << "Should be b³: " << boo.get(3,5) << '\n';


                */




            /* Multiple const objects with base jack test and props call 
            const U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Should be 8: " << foo.size() << '\n'
                 << "Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Should be b³: " << foo.get(3,5) << '\n';
            cout << "Let's do it again!\n";
            const U boo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Should be 8: " << boo.size() << '\n'
                 << "Should be 2: " << boo.propcount("Sm") << '\n'
                 << "Should be b³: " << boo.get(3,5) << '\n';
            cout << "Properties: ";
            for(string el : boo.props())
            {
                    cout << el << ",";
            }
            cout << "\n";
            */


            /* Hamlet 
            const string partOfHamlet = "hamlet.txt";
            const string hamlet = pub + partOfHamlet;
            const string propertyFile = pub + "UnicodeData.txt";
            U foo;
            foo.readfile(hamlet);
            foo.propfile(propertyFile);
            cout << "Hamlet Size: " << foo.size() << '\n';
            cout << "Properties: ";
            for(string el : foo.props())
            {
                    cout << el << ",";
            }
            cout << "\n";
            */


            /* Error Case 14 from HW4 
        try {
            const string error1 = "error1";
            const string propertyFile = pub + "UnicodeData.txt";
            U foo;
            cout << "readingfile\n";
            foo.readfile(error1);
            cout << "done readingfile\n";
            foo.propfile(propertyFile);
            cout << "Error1 Size: " << foo.size() << '\n';
            cout << "Properties: ";
            for(string el : foo.props())
            {
                    cout << el << ",";
            }
            cout << "\n";
            






                cout << "Begin counts:\n";
                cout << "Should be: Cc: 10412, it is: Cc: " << foo.propcount("Cc") << "\n";
            cout << "Should be: Cf: 0, it is: Cf: " << foo.propcount("Cf") << "\n";
            cout << "Should be: Co: 0, it is: Co: " << foo.propcount("Co") << "\n";
            cout << "Should be: Cs: 0, it is: Cs: " << foo.propcount("Cs") << "\n";
            cout << "Should be: Ll: 119683, it is: Ll: " << foo.propcount("Ll") << "\n";
            cout << "Should be: Lm: 0, it is: Lm: " << foo.propcount("Lm") << "\n";
            cout << "Should be: Lo: 0, it is: Lo: " << foo.propcount("Lo") << "\n";
            cout << "Should be: Lt: 0, it is: Lt: " << foo.propcount("Lt") << "\n";
            cout << "Should be: Lu: 16350, it is: Lu: " << foo.propcount("Lu") << "\n";
            cout << "Should be: Mc: 0, it is: Mc: " << foo.propcount("Mc") << "\n";
            cout << "Should be: Me: 0, it is: Me: " << foo.propcount("Me") << "\n";
            cout << "Should be: Mn: 0, it is: Mn: " << foo.propcount("Mn") << "\n";
            cout << "Should be: Nd: 0, it is: Nd: " << foo.propcount("Nd") << "\n";
            cout << "Should be: Nl: 0, it is: Nl: " << foo.propcount("Nl") << "\n";
            cout << "Should be: No: 0, it is: No: " << foo.propcount("No") << "\n";
            cout << "Should be: Pc: 0, it is: Pc: " << foo.propcount("Pc") << "\n";
            cout << "Should be: Pd: 422, it is: Pd: " << foo.propcount("Pd") << "\n";
            cout << "Should be: Pe: 261, it is: Pe: " << foo.propcount("Pe") << "\n";
            cout << "Should be: Pf: 0, it is: Pf: " << foo.propcount("Pf") << "\n";
            cout << "Should be: Pi: 0, it is: Pi: " << foo.propcount("Pi") << "\n";
            cout << "Should be: Po: 7418, it is: Po: " << foo.propcount("Po") << "\n";
            cout << "Should be: Ps: 261, it is: Ps: " << foo.propcount("Ps") << "\n";
            cout << "Should be: Sc: 0, it is: Sc: " << foo.propcount("Sc") << "\n";
            cout << "Should be: Sk: 0, it is: Sk: " << foo.propcount("Sk") << "\n";
            cout << "Should be: Sm: 48, it is: Sm: " << foo.propcount("Sm") << "\n";
            cout << "Should be: So: 0, it is: So: " << foo.propcount("So") << "\n";
            cout << "Should be: Zl: 0, it is: Zl: " << foo.propcount("Zl") << "\n";
            cout << "Should be: Zp: 0, it is: Zp: " << foo.propcount("Zp") << "\n";
            cout << "Should be: Zs: 27713, it is: Zs: " << foo.propcount("Zs") << "\n";
                cout << "Done\n";
                




        } 
        catch(string errorMessage)
        {
                cout << "Error caught: " << errorMessage << endl;
        }




        */


        /* Assignment and copy constructor 
        try {
                U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Foo: Should be 8: " << foo.size() << '\n'
                 << "Foo: Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Foo: Should be b³: " << foo.get(3,5) << '\n';
            U boo(pub+"UnicodeData.txt", "abc1");
            cout << "Boo: Should be 4: " << boo.size() << '\n'
                 << "Boo: Should be 3: " << boo.propcount("Ll") << '\n'
                 << "Boo: Should be '1': " << boo.get(3,4) << '\n';
            cout << "\nboo = foo\n";
            boo = foo;
            cout << "Boo: Should be 8: " << boo.size() << '\n'
                 << "Boo: Should be 2: " << boo.propcount("Sm") << '\n'
                 << "Boo: Should be b³: " << boo.get(3,5) << '\n';
            U koo(foo);
            cout << "Koo: Should be 8: " << koo.size() << '\n'
                 << "Koo: Should be 2: " << koo.propcount("Sm") << '\n'
                 << "Koo: Should be b³: " << koo.get(3,5) << '\n';
            U too(pub+"UnicodeData.txt", "abc1");
            cout << "Too: Should be 4: " << too.size() << '\n'
                 << "Too: Should be 3: " << too.propcount("Ll") << '\n'
                 << "Too: Should be '1': " << too.get(3,4) << '\n';
            cout << "\nfoo = too\n";
            foo = too;
            cout << "Foo: Should be 4: " << foo.size() << '\n'
                 << "Foo: Should be 3: " << foo.propcount("Ll") << '\n'
                 << "Foo: Should be '1': " << foo.get(3,4) << '\n';
            cout << "Boo: Should be 8: " << boo.size() << '\n'
                 << "Boo: Should be 2: " << boo.propcount("Sm") << '\n'
                 << "Boo: Should be b³: " << boo.get(3,5) << '\n';
        }
    catch(string errorMessage)
        {
                cout << "Error caught: " << errorMessage << endl;
        }


        */


        /* Bad Byte */
        // \xff is caught as an error
        // \xF0\x9F\x90\xAE\xFF is caught as an error
        // \xF0\x9F\x90\xAE\xAE is caught as an error
        // \xF0\x9F is caught as an error
        // \x9F is caught as an error
       // try 
       // {
         //       U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
           //     cout << foo.size() << '\n';
        //}
        //catch(string errorMessage)
        //{
          //      cout << "Error caught: " << errorMessage << endl;
        //}






        /* Const-ness mad-ness 
        try {
                U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
            cout << "Foo: Should be 8: " << foo.size() << '\n'
                 << "Foo: Should be 2: " << foo.propcount("Sm") << '\n'
                 << "Foo: Should be b³: " << foo.get(3,5) << '\n';
            U boo(pub+"UnicodeData.txt", "abc1");
            cout << "Boo: Should be 4: " << boo.size() << '\n'
                 << "Boo: Should be 3: " << boo.propcount("Ll") << '\n'
                 << "Boo: Should be '1': " << boo.get(3,4) << '\n';
            cout << "\nboo = foo\n";
            boo = foo;
            cout << "Boo: Should be 8: " << boo.size() << '\n'
                 << "Boo: Should be 2: " << boo.propcount("Sm") << '\n'
                 << "Boo: Should be b³: " << boo.get(3,5) << '\n';


            const U koo(foo);
            cout << "Const Koo: Should be 8: " << koo.size() << '\n'
                 << "Const Koo: Should be 2: " << koo.propcount("Sm") << '\n'
                 << "Const Koo: Should be b³: " << koo.get(3,5) << '\n'
                 << "Const Koo: Should be b: " << koo.get(3) << '\n'
                 << "Const Koo: Should be a³+b³≠c³: " << koo.get() << '\n';
            cout << "Const Koo Properties: ";
            for(string el : koo.props())
            {
                    cout << el << " :[" << koo.propcount(el) << "] " << ", ";
            }
            cout << "\n";


            U too(pub+"UnicodeData.txt", "abc1");
            const string abc1FileName = "abc1.txt";
            const string unicodeFileName = pub+"UnicodeData.txt";
            too.readfile(abc1FileName);
            too.propfile(unicodeFileName);
            cout << "Too: Should be 8: " << too.size() << '\n'
                 << "Too: Should be 6: " << too.propcount("Ll") << '\n'
                 << "Too: Should be '1': " << too.get(3,4) << '\n';
            cout << "\nfoo = too\n";
            foo = too;
            cout << "Foo: Should be 8: " << foo.size() << '\n'
                 << "Foo: Should be 6: " << foo.propcount("Ll") << '\n'
                 << "Foo: Should be '1': " << foo.get(3,4) << '\n';
            cout << "Boo: Should be 8: " << boo.size() << '\n'
                 << "Boo: Should be 2: " << boo.propcount("Sm") << '\n'
                 << "Boo: Should be b³: " << boo.get(3,5) << '\n';
            foo = koo;
            const U noo(koo);
            cout << "Const noo: Should be 8: " << koo.size() << '\n'
                 << "Const noo: Should be 2: " << koo.propcount("Sm") << '\n'
                 << "Const noo: Should be b³: " << koo.get(3,5) << '\n'
                 << "Const noo: Should be b: " << koo.get(3) << '\n'
                 << "Const noo: Should be a³+b³≠c³: " << koo.get() << '\n';
            cout << "foo: Should be 8: " << koo.size() << '\n'
                 << "foo: Should be 2: " << koo.propcount("Sm") << '\n'
                 << "foo: Should be b³: " << koo.get(3,5) << '\n'
                 << "foo: Should be b: " << koo.get(3) << '\n'
                 << "foo: Should be a³+b³≠c³: " << koo.get() << '\n';
            U emptyU(pub+"UnicodeData.txt", "");
            cout << "And to finish it off... AN ERROR!!! WOOO HOOO!\n";
            U errrr(pub+"THISISWRONG", "abc");


            
        }
            catch(string errorMessage)
        {
                cout << "Error caught: " << errorMessage << endl;
        }
        */






    return 0;
}




//ADD NEW ONES BELOW:


/* Bad Byte Through File and Default Ctor */
        // \xff is caught as an error
        // \xF0\x9F\x90\xAE\xFF is caught as an error
        // \xF0\x9F\x90\xAE\xAE is caught as an error
        // \xF0\x9F is caught as an error
        // \x9F is caught as an error
        /*try 
        {
                U foo;
                cout << foo.size() << '\n';
                cout << "Properties For Foo Empty: ";
            for(string el : foo.props())
            {
                    cout << el << ",";
            }
            cout << "\n";
            U boo;
            boo.propfile(pub+"UnicodeData.txt");
            const string property_file = pub+"UnicodeData.txt";
            foo = boo;
            foo.propfile(property_file);
            cout << "Properties For Foo non-Empty: ";
            for(string el : foo.props())
            {
                    cout << el << ",";
            }
            cout << "\n";
            boo.readfile("emptyFile.txt");
            cout << "boo (empty) .get(): output inside brackets-> [" << boo.get() << "]\n";
            const string bad_byte_name = "badByte.txt";
            ofstream outToFile(bad_byte_name);
            outToFile << "\xff" << flush;
            cout << "Reading badByte:\n";
            foo.readfile(bad_byte_name);
            cout << "UH OH, it didn't catch the error!\n";




        }
        catch(string errorMessage)
        {
                cout << "Error caught: " << errorMessage << endl;
        }
*/

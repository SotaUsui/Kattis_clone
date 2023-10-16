#include <iostream>
#include <stdlib.h> 
#include <filesystem>
#include <fstream>

using namespace std;

bool fileCompare (string file1, string file2){
    std::ifstream f1; f1.open(file1);
    std::ifstream f2; f2.open(file2);
    char f1char;
    char f2char;
    f1char = f1.get();
    f2char = f2.get();
    if(f1char == f2char){
        return true;
    }
    else{
        return false;
    }
}


int main(int argc, char** argv){
    if (argc != 3){
        cout << "syntax error"<< endl;
        exit(0);
    }

    else{
        string program = argv[1];
        string submission_code = argv[2];

        // caheck the how many test case we have
        int n_files = 0;
        std::filesystem::path pp {program};
        for (auto& p : std::filesystem::directory_iterator(pp)){
            ++n_files; 
        }
        int n_tests = n_files/2;

        submission_code = "user_code/" +submission_code;
        string exec_cmd = "g++ -o testing " + submission_code;
        system(exec_cmd.c_str());

        int count =0;
        while(count < n_tests){
            ofstream user_output("user_output.txt");

            int i = count+1;
            string j = to_string(i);
            string testing = program + "/test" +j +".input";
            string test_cmd = "./testing < " +testing + " > user_output.txt";

            system(test_cmd.c_str());
            user_output.close();

            string answer = program + "/test" +j +".output"; 

            // compare the test.output and user_output
            if(fileCompare("user_output.txt", answer) == true){
                cout << "test" << j << ": pass" << endl;
            }
            else{
                cout << "test" << j << ": fail" << endl;
            }

            std::filesystem::remove("user_output.txt");
            
            count++;
        }
        
    }
    return 0;
}

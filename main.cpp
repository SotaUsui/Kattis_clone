#include <iostream>
#include <stdlib.h> 
#include <filesystem>
#include <fstream>

using namespace std;

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
            string test_cmd = "./testing < " +testing;
            user_output << system(test_cmd.c_str()) << endl; //doesn't work
            user_output.close(); 
            string answer = program + "/test" +j +".output"; 

            // compre the test.output and user_output

            std::filesystem::remove("user_output.txt");
            
            count++;
        }
        cout << "done" << endl;
    }
    return 0;
}

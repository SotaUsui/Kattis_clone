#include <iostream>
#include <stdlib.h> 
using namespace std;

int main(int argc, char** argv){
    cout << "Hello_1¥¥" << endl;

    if (argc != 3){
        cout << "syntax error"<< endl;
        exit(0);
    }

    else{
        string program = argv[1];
        string submission_code = argv[2];

        cout << "program [" << program << "]" << endl;

        cout << "submissison code [" << submission_code << "]" << endl;
        submission_code = "user_code/" +submission_code;
        cout << "submissison code [" << submission_code << "]" << endl;

        string test = program + "/test1.input";
        string cmd = "g++ -o testing " + submission_code;
        cout << "executing cmd: [" << cmd << "]" << endl;
        system(cmd.c_str());

        cmd = "./testing < " +test;
        cout << "executing cmd: [" << cmd << "]" << endl;
        system(cmd.c_str());
        cout << "done" << endl;
    }
    return 0;
}

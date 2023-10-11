#include <iostream>
using namespace std;

int main(int argc, char** argv){

    if (argc != 3){
        cout << "syntax error"<< endl;
        exit(0);
    }

    else{
        string program = argv[1];
        string submission_code = argv[2];
        submission_code = "/user_code/" +submission_code;
        // try
        system("g++ " + submission_code + "-o testing")






        system("testing > program/test1.input");
    }
    return 0;
}

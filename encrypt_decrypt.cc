#include <iostream>
#include <string>
#include <sstream>
using namespace std;


string encrypt(string text, int shift) 
{ 
    string result = ""; 
    for (int i=0;i<text.length();i++) 
    { 
        if (isupper(text[i])) {
            result += char(int(text[i]+shift-65)%26 +65); 
        }
        
        else if (islower(text[i])) {
            result += char(int(text[i]+shift-97)%26 +97); 
        }
        else{
            result += text[i];
        }
    } 
    return result; 
}


string decrypt(string text, int shift) 
{ 
    string result = ""; 
    for (int i=0;i<text.length();i++) 
    {
        char chr = text[i]; 
        if (isupper(text[i])) {
            chr = chr - shift;
            if (chr < 'A'){
                chr = chr + 'Z' - 'A' + 1;
            }
            result += chr;
        }
        else if (islower(text[i])) {
            chr = chr - shift;
            if (chr < 'a'){
                chr = chr + 'z' - 'a' + 1;
            }
            result += chr;
        }
        else{
            result += text[i];
        }
    }
    return result; 
}

int main(int argc, char* argv[]){
    string line;
    
    if (argc == 1){
        
        while (getline(cin, line)){
            string ret;
            if (line[0] == 'q'){
                return 0;
            }
            if (line[0] == 'e'){
                line.erase(0,1);
                ret = encrypt(line, 3);
                cout << ret << endl;

            }
            else if (line[0] == 'd'){
                line.erase(0,1);
                ret = decrypt(line, 3);
                cout << ret << endl;

            }
            
        }
    }
    else if (argc == 2){
        istringstream iss(argv[1]);
        int shift;
        iss >> shift;
        if (shift < 0 || shift > 25){
            cout << "Shift value not in range!" << endl;
            return 0;
        }
        else{
                while (getline(cin, line)){
                string ret;
                if (line[0] == 'q'){
                    return 0;
                }
                if (line[0] == 'e'){
                    line.erase(0,1);
                    ret = encrypt(line, shift);
                    cout << ret << endl;

                }
                else if (line[0] == 'd'){
                    line.erase(0,1);
                    ret = decrypt(line, shift);
                    cout << ret << endl;

                }
            }  
        }

    }
    else if (argc == 3){
        istringstream iss(argv[1]);
        int shift;
        iss >> shift;
        if (shift < 0 || shift > 25){
            cout << "Shift value not in range!" << endl;
            return 0;
        }
        else{
            string direction;
            direction = argv[2];
            if (direction == "left"){
                while (getline(cin, line)){
                string ret;
                if (line[0] == 'q'){
                    return 0;
                }
                if (line[0] == 'e'){
                    line.erase(0,1);
                    ret = decrypt(line, shift);
                    cout << ret << endl;

                }
                else if (line[0] == 'd'){
                    line.erase(0,1);
                    ret = encrypt(line, shift);
                    cout << ret << endl;

                }
                }
            } 
            else if (direction == "right"){
                while (getline(cin, line)){
                string ret;
                if (line[0] == 'q'){
                    return 0;
                }
                if (line[0] == 'e'){
                    line.erase(0,1);
                    ret = encrypt(line, shift);
                    cout << ret << endl;

                }
                else if (line[0] == 'd'){
                    line.erase(0,1);
                    ret = decrypt(line, shift);
                    cout << ret << endl;

                }
                }
            }
            else{
                cout << "Incorrect direction!" << endl;
                return 0;
            }

        }

    }
    else{
        cout << "Too many arguments!" << endl;
    }

}

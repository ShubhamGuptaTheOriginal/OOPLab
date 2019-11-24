#include <iostream>
#include <fstream>
using namespace std;

enum type{
    rd,
    wr,
    app
};

bool read(string filename){
    ifstream file(filename,ios::in);
    if(!file.is_open())
        return false;
    
    cout << endl << "------------------------------------------------------------------------------------" << endl;
    while(file){
        char S = file.get();
        if(file)
            cout << S;
    }
    cout << endl << "------------------------------------------------------------------------------------" << endl;
    file.close();
    return true;
}

bool write(string filename,enum type X){
    ofstream file;
    if(X == wr)
        file.open(filename,ios::out);
    else if(X == app)
        file.open(filename,ios::app);
    else
        return false;
    
    char C = getchar();
    file << endl;
    while(C!='$'){
        file.put(C);
        C = getchar();
    }
    return true;
}

int main(){
    fstream file;
    string filename;

    cout << "Enter filename - ";
    cin >> filename;

    file.open(filename,ios::in);

    if(file.is_open()){
        cout << "Data already in file - ";
        read(filename);

        int c = 1;
        while(c){
            cout << "\n0. Exit.\n1. Read.\n2. Write.\n3. Append";
            cout << "\n Enter choice - ";
            cin >> c;
            switch(c){
                case 0: 
                    break;
                case 1:
                    cout << "Content in " << filename << " ->";
                    read(filename);
                    break;
                case 2:
                    cout << "Enter data to file ($ to end)  - ";
                    write(filename,wr);
                    break;
                case 3:
                    write(filename,app);
                    break;
                default:
                    cout << "\nEnter valid choice.";
                    break;
            }
        }

        file.close();
    }else
        cout << "Invalid filename " << filename << endl;
    
    return 0;
}
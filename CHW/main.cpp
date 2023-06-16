#include <bits/stdc++.h>

using namespace std;

// Fuctions

string addLocation(string location){
    fstream fout, fin;
    fout.open("locations.txt", ios::out | ios::app);
    fin.open("locations.txt", ios::in);
    string loc;
    while(fin){
         loc.clear();
         while (getline(fin, loc))
         {
             if (loc == location)
             {
                 fout.close();
                 fin.close();
                return "Location already exists";
             }
        }
        }
    fout << location << endl;
    
    fout.close();
    fin.close();
    return "Location " + location + " added successfully!";
}

void deleteLocation(string location){
    fstream fin, fout;
    fstream sfout,sfin;
    sfout.open("dataCopy.csv",ios::out | ios::app);
    sfin.open("data.csv",ios::in );
    fin.open("locations.txt", ios::in);
    fout.open("deleteLoc.txt", ios::out | ios::app);
    string loc;
    vector<string> row;
    if(fin && fout ){
        loc.clear();
        while(getline(fin,loc)){
            if(loc != location){
                fout << loc << endl;
            }
        }
        string loca;
        while(getline(sfin,loca)){
            row.clear();
            stringstream strm(loca);
            string word;

            while(getline(strm, word,'\t')){
                row.push_back(word);
        
            }
            
            if(row[0] != location){

                sfout << row[0] << '\t' << row[1] << '\t' << row[2] << endl;
            };
        }
        sfin.close();
        sfout.close();
        remove("data.csv");
        rename("dataCopy.csv", "data.csv");
    }else {
        cout << "Failed to delete " << endl;
    }
    
    fout.close();
    fin.close();
     remove("locations.txt");
    rename("deleteLoc.txt", "locations.txt");
}

void listLocations(){
    fstream  fin;
    fin.open("locations.txt", ios::in);
    string location;
    if(fin){
        while(getline(fin,location)){
             cout << location << endl;
        }
    }else {
        cout << "Failed to read locations" << endl;
    }
    fin.close();
    return;
}
string recordDiseaseToLocation(string location, string disease, int cases){
    fstream fin, fout;
    ifstream locIn;
    fout.open("data.csv", ios::out | ios::app);
    fin.open("data.csv", ios::in);
    locIn.open("locations.txt", ios::in);
    string loc;
    int count = 0;
    if(locIn && fout && fin){
             loc.clear();
        while(getline(locIn, loc)){
             if (loc == location)
             {
                count = 1;
                fout << location << "\t" << disease << "\t" << cases << endl;
            }
        }
        if(count == 0){
            fout.close();
                fin.close();
                locIn.close();
                return "Location doesn't exist, Add it first!";
        }
              
    }else {
       return "Failed to open file";
    }
                 fout.close();
                fin.close();
                locIn.close();
    return "Added successfully";
}
void listDiseases(){
    fstream fin;
    fin.open("data.csv", ios::in);
    string data;
    string disease;
    vector<string> row;
    vector<string> diseases;
    if(fin){
        
       while(getline(fin,data)){
                row.clear();
                stringstream strm(data);
                string word;
                while (getline(strm, word, '\t'))
                {
                row.push_back(word);
                }
                disease = row[1];
                bool found = false;
                for (int i = 0; i < diseases.size(); i++)
                {
                if (diseases[i] == disease)
                {
                    found = true;
                    break;
                }
 
                    }
                    if(!found){
                        
                diseases.push_back(disease);
    
                    }
                
            
       }
       for (int i = 0; i < diseases.size();i++){
                cout << diseases[i] << endl;
       }
    }else {
       cout << "Failed to open file";
    }
    fin.close();
}
void listLocationsWithDisease(string disease){
    fstream fin;
    string data;
    string dis;
    string location;
    vector<string> row;
    vector<string> locations;
    fin.open("data.csv", ios::in);
    if(fin){
       while(getline(fin,data)){
                string word;
                stringstream strm(data);
                while (getline(strm, word, '\t')){
                row.push_back(word);
                }

                dis = row[1];
                if(dis == disease){
                location = row[0];
                bool exists = false;
                for (int i = 0; i < locations.size(); i++)
                {
                    if (locations[i] == location)
                    {
                        exists = true;
                    }
       }
       if(!exists){

 locations.push_back(location);
       }
                }
       }
       for (int i = 0; i < locations.size(); i++){
                cout << locations[i] << endl;
       }
    }else {
       cout << "Failed to read from file";
       
    }
    fin.close();
}
string findTotalCases(string disease){
    fstream fin;
    string data;
    string word;
    vector<string> row;
    int cases = 0;
   
    fin.open("data.csv", ios::in);
    if(fin){
            while(getline(fin,data)){
                vector<string> row;
                stringstream strm(data);
                while (getline(strm, word, '\t'))
                {
                  row.push_back(word);
                 }
                if(row[1] == disease){
                  cases += stoi(row[2]);
                }
            }
        

            string result= "Total cases of " + disease + " are " + to_string(cases);
            return result;
        }else {
       return "Failed to read file";
    }
}


string displayCasesFromLocation(string location, string disease){
      fstream fin;
    string data;
    string word;
    vector<string> row;
    int cases = 0;
   
    fin.open("data.csv", ios::in);
    if(fin){
            while(getline(fin,data)){
                row.clear();
                stringstream strm(data);
                while (getline(strm, word, '\t'))
                {
                  row.push_back(word);
                 }
                if(row[1] == disease && row[0] == location){
                  cases += stoi(row[2]);
                }
            }
            string result= "Total cases of " + disease + " in " +location+ " are " + to_string(cases);
        
            return result;
        }else {
       return "Failed to read file";
    }
}
void projectTempDisplay(){
    printf("===============================================================================================================\n");
    printf("*                              Welcome to Disease Cases Reporting System                                       *\n");
    printf("*        **************************************************************************************                 \n");
    printf("*                                                                                                              *\n");
    printf("*                               It is developed by Gisele as practical                                         *\n");
    printf("*                               Evaluation of end of Year 3                                                    *\n");
    printf("================================================================================================================\n");
    printf("================================================================================================================\n\n");
    printf("String Time: %s\n");
    printf("Need a help? Type help then press Enter key.\n");

    printf("Console - > ");

}
void displayHelpMenu(){
    printf("================================================================================================================\n");
    printf("*                                                HELP MENU                                                     *\n");
    printf("================================================================================================================\n\n");
    printf("add <Location>                                                         : Add new location\n"); 
    printf("delete <Location>                                                      : Delete an existing location\n");
    printf("record <Location> <disease> <cases>                                    : Record a disease and its cases\n");
    printf("list locations                                                         : List all existing Locations\n");
    printf("list diseases                                                          : List existing diseases in Locations\n");
    printf("where <disease>                                                        : Find where disease exists\n");
    printf("cases <location> <disease>                                             : Find cases of a disease in a location\n");
    printf("cases <disease>                                                        : Find total cases of a given disease\n");
    printf("help                                                                   : Prints user manual\n");
    printf("exit                                                                   : Exit the program\n");
}
bool checkAllowedCommand(string check, int args){
    map<string, int> ALLOWED = {{"add", 1}, {"delete", 1},{"where", 1}, {"record", 3}, {"list", 1}, {"cases", 1}, {"help", 0}, {"exit", 0}};

  
    for(auto &pair: ALLOWED){
      
        if(check == pair.first){
            if(pair.first =="cases"){
                  pair.second = args == 1 ? 1 : 2;
            }
            if(args== pair.second){
                return true;
            }
        }
    }
    return false;

}


int main(){


    string command;
    string cmnd;

   

    bool exit = false;
    projectTempDisplay();
    while(1){
    vector<string> givenCommands;
    bool enteredCommand = false;
    while(!enteredCommand){
            command.clear();
            getline(cin, command);
            if (!command.empty())
            {
                enteredCommand = true;
                break;
        }
    }
    stringstream strm(command);
    cmnd.clear();
    while(getline(strm, cmnd, ' ' )){
        givenCommands.push_back(cmnd);
    }
    
    string prefix= givenCommands[0];
    int args = givenCommands.size() -1 ;

        if (checkAllowedCommand(prefix, args))
        {
            if(prefix == "add"){
            string location = givenCommands[1];

            cout << addLocation(location);

            }else if(prefix =="record"){
            string location = givenCommands[1];
            string disease = givenCommands[2];
            int cases = stoi(givenCommands[3]);
            cout << recordDiseaseToLocation(location, disease, cases);
            }else if(prefix == "delete"){
            string location = givenCommands[1];
            deleteLocation(location);
            }else if(prefix == "cases"){
                string disease = givenCommands[1];
            if (args == 1)
            {
                string disease = givenCommands[1];
                cout << findTotalCases(disease);
                }else if(args == 2){
                string location = givenCommands[1];
               
                string disease = givenCommands[2];
                cout << displayCasesFromLocation(location, disease);
                }

            }else if(prefix == "list"){
            string desc = givenCommands[1];
            if(desc== "locations"){
                listLocations();
            }else if(desc =="diseases"){
                listDiseases();
            }
            }else if(prefix == "where") {
            string disease = givenCommands[1];
            listLocationsWithDisease(disease);
            }else if(prefix == "help"){
            displayHelpMenu();
            }else if(prefix == "exit"){
            return 0;
            }
        }
        else
        {
            printf("Command not allowed");
      
    }
            printf("\n\nConsole -> ");
    }
    

    return 0;
};
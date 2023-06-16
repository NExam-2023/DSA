#include <bits/stdc++.h>

using namespace std;

struct Customer {
    string name;
    string category;
    string cash_power_no;
};

void addToFile(string filename, string data){
    ofstream outFile;
    outFile.open(filename, ios::out | ios::app);

    if(!outFile){
        printf("Failed to add to file!");
        return;
    }

    while(outFile){

    string word;
    stringstream strm(data);
    while(getline(strm,word, '\t')){
      
    outFile<< word << '\t' ;
    }
    
    outFile << endl;
    outFile.close();
    }
}

bool searchFromFile(string filename, string data){
    ifstream inFile;
    inFile.open(filename);
   
    if(inFile){
    string line;
    while (getline(inFile, line)){
    
        if(line.find(data)  != string::npos){
            inFile.close();
            return true;
        }
    
    }
    inFile.close();
    }
  
    return false;
}
void editData(string filaname, string data){
    fstream inFile, outFile;
    inFile.open(filename, ios::in);
    outFile.open(filename, ios::out | ios::app);

    
}
vector<string> getCategoryAndUnits(string cash_power_no){
    ifstream fin, inFile;
    string category;
    string units;
    string line;
    vector<string> result;

    fin.open("data.csv");
    inFile.open("customers.csv");

    while(getline(fin, line)){

        if (line.find(cash_power_no) != string::npos)
        {
            vector<string> row;
            string word;
            stringstream strm(line);
            while (getline(strm,word,'\t')){
                row.push_back(word);
                if(row.size() == 2){
                    units = row[1];
                }
            }

            }
    }
    fin.close();
    line.clear();
    while(getline(inFile,line)){
      if(line.find(cash_power_no) != string::npos){
           vector<string> row;
        string word;
        stringstream strm(line);
        while (getline(strm,word,'\t')){
            row.push_back(word);
            if(row.size() == 2){
                category = row[1];
            }
        }
    
      }
    }
    inFile.close();
    result.push_back(category),
    result.push_back(units);
    return result;
}
string randomGenerator(string filename,int length){
    random_device rd;
    // mt19937 generates unsigned 32 bit digits
    //gen() generates an unpredictable string from a random number generated by rd()

    mt19937 gen(rd()); 
    // creates a uniform distribution for generating random integers in the range [0, 9]. 
    uniform_int_distribution<> dis(0, 9);
    string token="";
    for (int i = 0; i < length; i++){
    token += to_string(dis(gen));
    }

    if(searchFromFile(filename, token)){
       randomGenerator(filename, length);
    }
    return token;
}
float calculateUnits(vector<string> categoryAndUnits, float amount){
    string category = categoryAndUnits[0];
    int usedUnits = stoi(categoryAndUnits[1]);

    int boughtUnits = 0;
    float remainder;
    int units1, units2, units3;

    if(category == "residential"){
        if(usedUnits >=0 && usedUnits < 15){
         remainder = amount - (15*89) ;
       

         if (remainder < 0){
            units1 = amount / 89;
            boughtUnits += units1;
            usedUnits += units1;
        
            return boughtUnits;
             }
             else {
            amount = remainder;
            units1 = 15;
            boughtUnits += units1;
            usedUnits += units1;
          
             }
        }
            //  Second range 
            if (usedUnits >= 15 && usedUnits < 50)
            {
                remainder = amount - (35 * 212);

                if (remainder < 0)
                {
                    units2 = amount / 212;
                    boughtUnits += units2;
                    usedUnits += units2;
             
                    return boughtUnits;
                }
                else
                {
                    amount = remainder;
                    units2 = 35;
                    boughtUnits += units2;
                    usedUnits += units2;
                
                  }
                }
                    if (usedUnits >= 50)
                    {
                        units3 = amount / 249;
                        boughtUnits += units3;
                        usedUnits += units3;
                
                        return boughtUnits;
                    }
                
         }

        else if(category == "non-residential"){
    
    if(usedUnits >=0 && usedUnits < 100){
         remainder = amount - (100*227) ;
       

         if (remainder < 0){
            units1 = amount / 227;
            boughtUnits += units1;
            usedUnits += units1;
        
            return boughtUnits;
             }
             else {
            amount = remainder;
            units1 = 100;
            boughtUnits += units1;
            usedUnits += units1 ;
          
             }
        }
            //  Second range 
       
                    if (usedUnits >= 100)
                    {
                        units3 = amount / 255;
                        boughtUnits += units3;
                        usedUnits += units3;
                
                        return boughtUnits;
                    }

    }else if(category == "telecom towers"){
      boughtUnits += amount / 201;
      usedUnits += boughtUnits;
    }else if(category == "wtplants"){
      boughtUnits = amount / 126;
      usedUnits += boughtUnits;
    }else if(category == "hotels"){
      boughtUnits = amount / 157;
      usedUnits += boughtUnits;
    }else if(category == "health facilities"){
      boughtUnits = amount / 186;
      usedUnits += boughtUnits;
    } else if(category == "broadcasters"){
      boughtUnits = amount / 192;
      usedUnits += boughtUnits;
    } else if(category == "Commercial data centers"){
      boughtUnits = amount / 179;
      usedUnits += boughtUnits;
    }

    editData("customers.csv", usedUnits);
    return boughtUnits;
}


void buyElectricity(){
    string cash_power_no;
    float cash;
    string token;
    printf("\t\t\tEnter the cash power number:  ");
    getline(cin, cash_power_no);
    fflush(stdin);
    if(!searchFromFile("customers.csv",cash_power_no)){
    printf("\t\t\tUnknown cash power number\n");
    return;
    }
    printf("\t\t\tEnter the amount in RWF:  ");
    cin >> cash;
    token = randomGenerator("tokens.txt",16);
    vector<string> categAndUnits = getCategoryAndUnits(cash_power_no);
    
    float units = calculateUnits(categAndUnits, cash);
    
 
   printf("\n\n+________________________________________________________________________________________________________+\n");
   printf("+________________________________________________________________________________________________________+\n");
  printf("+                                                                                                        +\n");
  cout << "++++++++++++++++++++++++        Number of units:\t"<< units<< "\t\t\t++++++++++++++++++++++++++\n";
  cout << "++++++++++++++++++++++++        Your token:\t\t" << token<<"\t++++++++++++++++++++++++++\n";
  printf("+                                                                                                        +\n");
  printf("+________________________________________________________________________________________________________+\n");
  printf("+________________________________________________________________________________________________________+\n\n\n\n\n");

  

}


void resetDiscount(){
    fstream fin, fout;
    fin.open("data.csv",ios::in);
    fout.open("newData.csv",ios::out | ios::app);
    vector<string> row;
    string line;
    string word;
  while(fin && fout){
    
    line.clear();
    while (getline(fin, line))
    {
    row.clear();
    stringstream strm(line);

    word.clear();
    while (getline(strm, word, '\t'))
    {
        row.push_back(word);
    }
    
    fout << row[0] << "\t" << "0" << endl;
    }
    fout.close();
    fin.close();
  }

  remove("data.csv");
  rename("newData.csv", "data.csv");
}

bool checkTheBegginingofTheMonth()
{

    time_t now = time(nullptr);
    tm *current_time = localtime(&now);

    if(current_time->tm_mday == 1){
       resetDiscount();
       return true;
    }
    return false;

}

void addCustomer(Customer customer)
{
    string input;
    printf("\n\t\t\tEnter customer name: ");
    getline(cin, customer.name);
    if(customer.name.length() <10){
       printf("\t\t\tName should be atleast 10 characters\n");
       return;
    } 
    printf("\n\t\t\tChoose category: ");
    printf("\n\t\t\t1.Residential");
    printf("\n\t\t\t2.Non-residential");
    printf("\n\t\t\t3.Telecom Towers");
    printf("\n\t\t\t4.Water Treatment plants and Water pumping stations");
    printf("\n\t\t\t5.Hotels");
    printf("\n\t\t\t6.Health Facilities");
    printf("\n\t\t\t7.Broadcasters");
    printf("\n\t\t\t8.Commercial Data Centers");
    printf("\n\n\t\t\t==> ");

    int choice;
    getline(cin, input);
    stringstream strm(input);
    strm >> choice;
    switch (choice)
    {
    case 1:
    customer.category = "residential";
    break; 
     case 2:
    customer.category = "non-residential";
    break; 
     case 3:
    customer.category = "telecom towers";
    break; 
     case 4:
    customer.category = "wtplants";
    break;
      case 5:
    customer.category = "hotels";
    case 6:
    customer.category = "health facilities";
    case 7:
    customer.category = "broadcasters";
    case 8:
    customer.category = "Commercial data centers";
    break;
    default:
    printf("\t\t\t\t\tInvalid choice!");
    return;
    break;
    }

    customer.cash_power_no = randomGenerator("customers.csv",11);
    string newCustomer = customer.name + "\t" + customer.category + "\t" + customer.cash_power_no ;
    string data = customer.cash_power_no + "\t"+"0" ;
     addToFile("customers.csv", newCustomer);
     addToFile("data.csv", data);   
   
}

void displayHelp(){
    
    printf("**********************************************************************************************************\n");
    printf("*                                          BUY ELECTRICITY [EASY & FAST]                                 *\n");
    printf("**********************************************************************************************************\n");
    printf("|________________________________________________________________________________________________________|\n");
    printf("|                                                                                                        |\n");
    printf("|                                                                                                        |\n");
    printf("|                                                                                                        |\n");
    printf("|                                       1. Register customer                                             |\n");
    printf("|                                       2. Buy Electricity                                               |\n");
    printf("|                                       0. Exit                                                          |\n");
    printf("|                                                                                                        |\n");
    printf("|                                                                                                        |\n");
    printf("|                                                                                                        |\n");
    printf("|________________________________________________________________________________________________________|\n");
    printf("\n\n\t\t\tEnter choice: ");
}

void getCommand(){
    string command;
     Customer customer;
   getline(cin, command);
    if(command == "1"){
     addCustomer(customer);
   }else if(command == "2"){
     buyElectricity(); 
      fflush(stdin);
   }else if(command == "0"){
     exit(0);
   }else {
     printf("\t\t\tInvalid command!\n");
  }
}




int main(){
    
    while(1){
    checkTheBegginingofTheMonth();
    displayHelp();
    getCommand();
    }

    return 0;
}
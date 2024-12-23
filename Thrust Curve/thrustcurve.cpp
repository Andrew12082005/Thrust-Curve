#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    ifstream fin("thrustcurve.csv");
    ofstream fout("thrustcurve.eng");

    string line;
    cout<<"Enter Desination Diameter(mm) Length(mm) Delay(P) Propellantweight(kg) TotalWeight(kg) Manufacture Unit of csv(Kgf/N) Unit of .eng(N/Kgf) (Seperate by blankspace)"<<endl;
    string Desination,Diameter,Length,Delay,Propellantweight,TotalWeight,Manufacture,unit1,unit2;
    cin>>Desination>>Diameter>>Length>>Delay>>Propellantweight>>TotalWeight>>Manufacture>>unit1>>unit2;

    fout<<Desination<<" "<<Diameter<<" "<<Length<<" "<<Delay<<" "<<Propellantweight<<" "<<TotalWeight<<" "<<Manufacture<<endl;
    while(getline(fin,line)){
        for(int i = 0 ; i<line.length() ; i++){
            if(line[i] == ','){
                line[i] = ' ';
            }
        }
        istringstream iss(line);
        string time, thrust;
        iss>>time>>thrust;
        double thrust_d = stod(thrust);
        double thrust_f;
        if(unit1 == "Kgf" && unit2 =="N"){
            double thrust_f = thrust_d*9.80665;
        }
        else if(unit1 == "Kgf" && unit2 =="N"){
            double thrust_f = thrust_d/9.80665;
        }
        fout<<"   "<<time<<" "<<thrust_f<<endl;
    }
    
    


}
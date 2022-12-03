#include "header.h"
#include "Functions.cpp"
#include "Move.cpp"
#include "System.cpp"

int main() {
    
    ofstream fw("C:\\Users\\leagr\\Documents\\PdM\\General\\Result.txt", std::ofstream::out);
    ofstream fw_count("C:\\Users\\leagr\\Documents\\PdM\\General\\Count.txt", std::ofstream::out);
    ofstream fw_prop("C:\\Users\\leagr\\Documents\\PdM\\General\\Prop.txt", std::ofstream::out);
    ofstream fw_time("C:\\Users\\leagr\\Documents\\PdM\\General\\Time.txt", std::ofstream::out);
    ofstream fw_time1("C:\\Users\\leagr\\Documents\\PdM\\General\\Time1.txt", std::ofstream::out);
    ofstream fw_time2("C:\\Users\\leagr\\Documents\\PdM\\General\\Time2.txt", std::ofstream::out);
    ofstream fw_time3("C:\\Users\\leagr\\Documents\\PdM\\General\\Time3.txt", std::ofstream::out);
    ofstream flux12("C:\\Users\\leagr\\Documents\\PdM\\General\\flux12.txt", std::ofstream::out);
    ofstream flux13("C:\\Users\\leagr\\Documents\\PdM\\General\\flux13.txt", std::ofstream::out);
    ofstream flux23("C:\\Users\\leagr\\Documents\\PdM\\General\\flux23.txt", std::ofstream::out);

    vector<int> count(length, 0);
    vector<double> prop; 
    //vector<double> V = {0,0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2,2.3,2.4, 2.5, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> V = {0, 0.5, 1, 2, 10}; 
     
     /* for (auto& i: V)
     { */ 
        //set_V0(0.1*i);
        //set_V0(i);
    

        //DEFINE SYSTEM
        System S(length, nbr_part);
        S.syst_initialize_moves();

        for (size_t j = 0; j < length; j++){
            if(write_state){
                fw << S.get_syst_state()[j]<< " " ;
            }
            if (S.get_syst_state()[j] != 0){
                count[j] += 1;
            }
                } 
        fw << "\n";


        //begin Gillespie
        int step = 1;
        while (step <= step_max) {
            D(cout<< "begin step:" << step << endl <<endl;);
            S.syst_evolve();
            D(cout<< "end" <<endl <<endl;);

            if(step % 1 == 0){
            if (fw.is_open() ){
            for (size_t j = 0; j < length; j++){
                if(write_state){
                    fw << S.get_syst_state()[j] << " ";
                }
                if (S.get_syst_state()[j] != 0){
                    count[j] += 1;
                }
                
            } 
            fw << "\n";
            } else {cout << "Problem with opening file";} }
            step += 1;
        }; 
        
        double lhs = 0; double rhs = 0;
        for (size_t j = 0; j < count.size(); j++){
                fw_count << count[j] << " ";
                if(j < 50){
                    lhs += count[j];
                } else {
                    rhs += count[j];
                }
        }

        prop.push_back(rhs/lhs);
        //cout << "prop " << rhs/lhs << endl;

        vector<double> K12 = rate_vector(1,2);  vector<double> K21 = rate_vector(2,1);
        vector<double> K13 = rate_vector(1,3);  vector<double> K31 = rate_vector(3,1);
        vector<double> K23 = rate_vector(2,3);  vector<double> K32 = rate_vector(3,2);

    for (size_t i = 0; i < S.get_syst_state_time().size(); i++)
    {
        fw_time << (1/S.get_syst_time())*S.get_syst_state_time()[i] << " ";
        flux12 << K21[i] <<" ";//*1/S.get_syst_time()*S.get_syst_state_time1()[i] - K21[i]*1/S.get_syst_time()*S.get_syst_state_time2()[i] << " ";
        fw_time1 << (1/S.get_syst_time())*S.get_syst_state_time1()[i] << " ";  
        flux13 << K31[i] <<" ";//*1/S.get_syst_time()*S.get_syst_state_time1()[i] - K31[i]*1/S.get_syst_time()*S.get_syst_state_time3()[i] << " ";
        fw_time2 << (1/S.get_syst_time())*S.get_syst_state_time2()[i] << " ";
        flux23 << K32[i] <<" ";//*1/S.get_syst_time()*S.get_syst_state_time2()[i] - K32[i]*1/S.get_syst_time()*S.get_syst_state_time3()[i] << " ";
        fw_time3 << (1/S.get_syst_time())*S.get_syst_state_time3()[i] << " ";
    }
        fw_time << "\n"; 
        fw_time1 << "\n"; flux12 << "\n";
        fw_time2 << "\n"; flux13 << "\n";
        fw_time3 << "\n"; flux23 << "\n";

    //} // END for

    fw.close();
    fw_count.close();

    for (size_t j = 0; j < prop.size(); j++){
                fw_prop << prop[j] << " ";
    }
    
    fw_prop.close();

    
    
};
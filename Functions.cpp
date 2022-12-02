#include "Functions.h"
#include "header.h"

/* double Potential(int localization){
        /* if (localization < step) return 0;
    else return V0;   
    return (tanh(0.1*(localization - length/2))+1)*0.5;

}; */

double Potential_type(int localization, int type){
    if (type == 1){
             /* if (localization < step) return 0;
        else return V0;   */ 
        return (tanh(0.07*(localization - length/2))+1)*0.5;
    } else if (type == 2) {
              /* if (localization < step) return 0;
        else return V0; */   
        return (tanh(0.1*(localization - length/2))+1)*0.5;
    } else if (type == 3) {
            /* if (localization < step) return 0;
        else return V0;   */
        return (tanh(0.2*(localization - length/2))+1)*0.5;
    }
    return 0;
};

/* double compute_rate(double init_pot, double final_pot, bool diff = true, bool chem = false){
    if (diff){
        return (1/t0_diff)*exp(- (final_pot-init_pot));
    }
    if (chem){
        return (1/t0_chem)*exp(- (final_pot-init_pot));//REVOIR!!!!!!!
    }
    return 0.;
}; */

/* vector<int> state_generator(int length, int nbr_part){
    
    vector<int> X0(length,0);// initial state

    //Random assignment of  particles to an initial localization in X0
    vector<int> temp = {};
    for (size_t i = 1; i <= nbr_part; i++)
    {
        static std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution (0.,length);
        int id = (int)distribution(generator);
        // accept answer if not already occupied
        if(find(temp.begin(), temp.end(), id) == temp.end()){
            //If no elements match, the function returns last
            X0[id]= type;
            temp.push_back(id);
        } 
        else {i = i-1;};
         
    }
    cout << "state generator  ";
    return X0;
}; */
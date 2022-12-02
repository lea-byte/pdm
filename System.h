#ifndef SYSTEM_H // include guard
#define SYSTEM_H

#include "header.h"


class System{
    private: 
        int Length; int Nbr_Part;
        sym_map2D<int, Move*> moves;
        vector<int> state;
        vector<double> state_time; vector<double> state_time1; vector<double> state_time2; vector<double> state_time3;
        double time;
        vector<double> flux12; vector<double> flux13; vector<double> flux23;


        void syst_actualize_state(const Move* m);// used in syst_evolve
        void compute_syst_cum_rates( vector<double>& cum_rates, vector<Move*>& ID_moves);
        vector<int> neighborhood(int I);//used in syst_evolve
        void add_chem(int loc);

    public:
        System(double t = 0);//initialize time of the system 
        System(int length, int nbr_part); // constructor : initialize random state

        vector<int> get_syst_state() const;
        vector<double> get_syst_state_time() const;
        vector<double> get_syst_state_time1() const;
        vector<double> get_syst_state_time2() const;
        vector<double> get_syst_state_time3() const;
        sym_map2D<int, Move> get_syst_moves() const;
        double get_syst_time() const;

        void syst_initialize_moves();
        void syst_evolve() ;//select move and delete it + update states
        //void syst_actualize_move(int init, int final);


};
#endif
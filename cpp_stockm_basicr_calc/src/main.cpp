#include "std_lib_facilities.h"
#include "fstream"

random_device rd;  // Will be used to obtain a seed for the random number engine
mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

double randNorNumGen(double mean=0.0, double sd=1.0){
    normal_distribution<> d{mean,sd};
    return d(gen);
};


vector<string> read_csv(string file_name) {
    string line;
    vector<string> DataStore;

    ifstream file;
    file.open(file_name, ios::in);

    while(getline(file, line )){
        DataStore.push_back(line);
    }

    file.close();
    return DataStore;
}

void print_vec(vector<double> vec_to_print){
    cout<<"(";
    for(unsigned int i = 0; i < vec_to_print.size(); i++ ){
        cout << vec_to_print[i];
        if(i != vec_to_print.size()-1)cout << ",";}
    cout<<")"<<endl;
}

vector<double> conv_str_to_double_vect(vector<string> v) {
    vector<double> rebuild;

    for (int i = 0; i < v.size(); i++) {
        rebuild.push_back(stod(v[i])); //converts  vector<string> to  vector<double>
    }
    return rebuild;
}


void cal_optimal_port_weights(vector<double> v1, vector<double> v2, vector<double> v3,
                              vector<double> v4, vector<double> v5){
    vector<double> optimal_weights(5);
    double old_t = 0;
    for(int i = 0; i < 100000; i++){
        vector<double> temp_random_weight;
        for(int j = 0; j < 5; j++) {temp_random_weight.push_back(randNorNumGen(20,5));}//weights are not allowed to deviate a lot.

        double tot_w = accumulate(temp_random_weight.begin(), temp_random_weight.end(), 0.0);
        double tot_money_tot_weight = 1000000/tot_w;

        double money_nflx = tot_money_tot_weight * temp_random_weight[0];
        double money_f = tot_money_tot_weight * temp_random_weight[1];
        double money_v = tot_money_tot_weight * temp_random_weight[2];
        double money_nvda = tot_money_tot_weight * temp_random_weight[3];
        double money_aapl = tot_money_tot_weight * temp_random_weight[4];

        vector<double> money_nflx_daily_val(148);
        vector<double> money_f_daily_val(148);
        vector<double> money_v_daily_val(148);
        vector<double> money_nvda_daily_val(148);
        vector<double> money_aapl_daily_val(148);
        vector<double> port_daily_val(148);

        for(int s = 0; s < 148; s++){
            money_nflx_daily_val[s] = money_nflx * (1+v1[s]);
            money_f_daily_val[s] = money_f * (1+v2[s]);
            money_v_daily_val[s] = money_v * (1+v3[s]);
            money_nvda_daily_val[s] = money_nvda * (1+v4[s]);
            money_aapl_daily_val[s] = money_aapl * (1+v5[s]);
            port_daily_val[s] = money_nflx_daily_val[s] + money_f_daily_val[s] + money_v_daily_val[s] +
                    money_aapl_daily_val[s] + money_nvda_daily_val[s];
        }


        double sum_port_daily_avg = accumulate(port_daily_val.begin(), port_daily_val.end(), 0.0)/148;

        vector<double> daily_dev_from_mean(148);
        for(int s = 0; s < 148; s++){daily_dev_from_mean[s] = sum_port_daily_avg - port_daily_val[s];}

        double risk_free = 1.0;
        double port_ret = port_daily_val[147] - port_daily_val[0];
        double port_sd = accumulate(daily_dev_from_mean.begin(), daily_dev_from_mean.end(), 0.0);

        double treynor_r = (port_ret - risk_free)/port_sd;
        if(treynor_r > old_t)
        {optimal_weights = temp_random_weight;
            old_t = treynor_r;}

    }
    cout<<"Optimal weights based on best treynor ratio is :" << endl;
    print_vec(optimal_weights);
}



vector<double> calc_return(vector<double> vec){
    vector<double> return_vec;
    for(int k = 1; k < vec.size(); k++){
        double temp = (vec[k]- vec[k-1])/vec[k];
        return_vec.push_back(temp);
    }
    return return_vec;
}

int main()

{
    //read data from file as string
    vector<string> nflx_s, aapl_s, f_s, v_s, nvda_s;
    nflx_s = read_csv("../../data/nflx.csv");
    aapl_s = read_csv("../../data/aapl.csv");
    f_s = read_csv("../../data/f.csv");
    v_s = read_csv("../../data/v.csv");
    nvda_s = read_csv("../../data/nvda.csv");

    //erase first element
    nflx_s.erase(nflx_s.begin());
    aapl_s.erase(aapl_s.begin());
    f_s.erase(f_s.begin());
    v_s.erase(v_s.begin());
    nvda_s.erase(nvda_s.begin());

    /* error checking and debugging code
    cout<<nflx[1]<<endl;
    cout<<nflx.size();
    */

    //convert string vector to double vector
    vector<double> nflx(nflx_s.size());
    vector<double> aapl(aapl_s.size());
    vector<double> f(f_s.size());
    vector<double> v(v_s.size());
    vector<double> nvda(nvda_s.size());
    nflx = conv_str_to_double_vect(nflx_s);
    v = conv_str_to_double_vect(v_s);
    f = conv_str_to_double_vect(f_s);
    nvda = conv_str_to_double_vect(nvda_s);
    aapl = conv_str_to_double_vect(aapl_s);

    //calculate return
    vector<double> nflx_r = calc_return(nflx);
    vector<double> f_r = calc_return(f);
    vector<double> v_r = calc_return(v);
    vector<double> nvda_r = calc_return(nvda);
    vector<double> aapl_r = calc_return(aapl);

    //print_vec(nflx_r);
    //cout<<calc_return(nflx)[1];

    /*check if they are all of the same size
    cout<<nflx_r.size()<<endl;
    cout<<v_r.size()<<endl;
    cout<<f_r.size()<<endl;
    cout<<aapl_r.size()<<endl;
    cout<<nvda_r.size()<<endl;*/

    cal_optimal_port_weights(nflx_r, f_r, v_r, nvda_r, aapl_r);
    //it seems from the results my stock pick is really good that the best way to invest 1M in the my stocks is to give them almost
    // equal weights, that is approximately 20% in each of the stocks.

    return 0;
}

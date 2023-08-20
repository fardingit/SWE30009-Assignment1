#include <iostream>
#include <map>
#include <functional>
#include <vector>

int main() {
    std::map<char, std::function<double(double, double)>> operatorList = 
    {
        {'+', std::plus<double>()},
        {'-', std::minus<double>()},
        {'*', std::multiplies<double>()},
        {'/', std::divides<double>()}
    };  
    for (int a = -100; a < 100; ++a) {       
        int b = 1;       
        std::vector<double> results;
        for (const auto& x : operatorList) 
        {
            auto operator1 = x.second;
            for (const auto& y : operatorList) 
            {
                auto operator2 = y.second;
                double A = operator1(a, b);
                double C = operator2(A, 2);
                if (x.first == '-' && y.first == '*') 
                {
                    double expectedoutcome = C;
                }
                else 
                {
                    results.push_back(C);
                }
            }
        }       
        bool concrete = true;
        double expectedoutcome = (a-b)*2;
        for (const double& result : results) {
            if (expectedoutcome == result) {
                concrete = false;
                break;
            }
        }     
        if (!concrete) {
            std::cout << "A = " << a << ", B = " << b << " is not a concrete test case" << std::endl;
            std::cout << expectedoutcome << " is present in result ";
            for (const double& result : results) {
                std::cout << result << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

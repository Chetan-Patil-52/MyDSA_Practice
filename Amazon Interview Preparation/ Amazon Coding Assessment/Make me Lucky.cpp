#include <iostream>
#include <string>

void make_me_lucky(const std::string &S, const std::string &U) {
    // Write your logic here.
    std::string result;
    int u_len = U.length();
    for(char c : S){
        result.push_back(c);
        if(result.length() >= u_len && result.substr(result.length()- u_len)==U){
            result.erase(result.length() - u_len);
        }
    }
    std::cout<<result<<std::endl;
}

int main() {
    std::string S, U;
    std::cin >> S >> U;
    make_me_lucky(S, U);
    return 0;
}

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> split_domain(string&& domain){
        vector<string> domains;
        int l = domain.length();
        for(int i=l-1; i>=0; i--){
            if(domain[i] == '.'){
                domains.emplace_back(move(domain.substr(i+1)));
            }
        }
        domains.push_back(domain);
        return domains;
    }


    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        for(auto& count_paired_domain: cpdomains){
            int space = count_paired_domain.find(' ');
            int count = stoi(count_paired_domain.substr(0, space));
            vector<string> domains = split_domain(count_paired_domain.substr(space+1));
            for(auto& domain: domains){
                counts[domain] += count;
            }
        }
        vector<string> result;
        for(auto& c: counts){
            result.emplace_back(move(to_string(c.second) + " " + c.first));
        }
        return result;
    }
};
#include "city.h"
#include "country.h"
#include "world-util.h"

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <parallel/numeric>

using namespace std;
using namespace world;

std::map<int,std::shared_ptr<world::city>> cities;
std::map<std::string,std::shared_ptr<world::country>> countries;

int main(int argc, char* argv[]){
    create_world();
    // 1. external loop
    set<string> continents;
    for (const auto & a_country : countries){
        continents.insert(a_country.second->continent);
    }
    for(auto const& [code,a_country] :countries){
        continents.insert(a_country->continent);
    }
    // 2. functional programming
    auto kitalar =
    accumulate(countries.begin(),countries.end(),
               set<string>(),
                [](set<string>& partial_continents,pair<const string,shared_ptr<country>> &a_country) -> set<string>& {
                  partial_continents.insert(a_country.second->continent);
                  return partial_continents;
                }
    );

    for (auto& continent: continents){
        cout << continent << endl;
    }
    for (auto& continent: kitalar){
        cout << continent << endl;
    }
    return 0;
}
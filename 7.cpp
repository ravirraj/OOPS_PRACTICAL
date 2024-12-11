#include<iostream>
#include<map>
#include<string>
#include<algorithm> // For transform and tolower
using namespace std;

int main()
{
    typedef map<string, int> mapType;
    mapType populationMap;
    populationMap.insert(pair<string, int>("maharashtra", 7026357));
    populationMap.insert(pair<string, int>("rajasthan", 6578936));
    populationMap.insert(pair<string, int>("karnataka", 6678993));
    populationMap.insert(pair<string, int>("punjab", 5789032));
    populationMap.insert(pair<string, int>("west bengal", 6676291));

    mapType::iterator iter;
    cout << "======== Population of states in India ==========\n";
    cout << "\n Size of populationMap: " << populationMap.size() << "\n";
    
    string state_name;
    cout << "\n Enter name of the state: ";
    cin >> state_name;

    // Convert state_name to lowercase
    transform(state_name.begin(), state_name.end(), state_name.begin(), ::tolower);

    iter = populationMap.find(state_name);
    if (iter != populationMap.end()) {
        cout << state_name << "'s population is " << iter->second << endl;
    } else {
        cout << "State not found in populationMap.\n";
    }

    populationMap.clear();
}

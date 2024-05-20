#include <iostream>
#include <iostream>
#include <string>
#include "appcomponent/Concurrent.hpp"
#include "appcomponent/Classement.hpp"
#include "front/AppPanel.hpp"
using namespace std;

int main() {
    AppPanel appPanel;
    appPanel.run();

    // Concurrent c;
    //     vector<Concurrent> cs = c.select();
    //     for (Concurrent element  : cs) {
    //         cout << element.getId() << "\n";
    //     }
    // cout << endl;

    return 0;
}
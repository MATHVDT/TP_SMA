#include <iostream>
#include <vector>

#include "Manager.hpp"

using namespace std;

int main()
{

    Agent agent0Bleu{2, 2, EQUIPE::BLEU};
    Agent agent0Rouge{4, 4, EQUIPE::ROUGE};

    Manager manager{agent0Bleu, agent0Rouge};

    manager.afficherCarte();
    for (int i = 0; i < 50; ++i)
    {
        system("clear");
        manager.tour();
        manager.afficherCarte();
        std::this_thread::sleep_for(20ms);
    }

    // cout << false * true << endl;
    // cout << !false * true << endl;
    // cout << !false * true << endl;
    return 0;
}
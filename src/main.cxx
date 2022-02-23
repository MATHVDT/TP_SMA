#include <iostream>
#include <vector>

#include "Manager.hpp"

using namespace std;

int main()
{

    Agent *agent0Bleu = new Agent{0, 0, EQUIPE::BLEU};
    Agent *agent0Rouge = new Agent{4,4, EQUIPE::ROUGE};

    agent0Rouge->gagneLevel(5);

    Manager manager{agent0Bleu, agent0Rouge};
    try
    {

        manager.afficherCarte();
        for (int i = 0; i < 50; ++i)
        {
            system("clear");
            cerr << "tour " << i << endl;
            manager.tour();
            manager.afficherCarte();
            std::this_thread::sleep_for(150ms);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // manager.afficherCarte();

    return 0;
}
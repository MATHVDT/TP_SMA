#include "Carte.hpp"
#include "Agent.hpp"
#include "Direction.hpp"
#include <iostream>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";

Carte::Carte(Agent *agent0Bleu, Agent *agent0Rouge)
{
    int j;
    int i;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            _grille[i][j] = EQUIPE::NEUTRE;
            _grilleAgents[i][j] = nullptr;
        }
    }
    _grilleAgents[agent0Bleu->getX()][agent0Bleu->getY()] = agent0Bleu;
    _grilleAgents[agent0Rouge->getX()][agent0Rouge->getY()] = agent0Rouge;
}

void Carte::afficherCarte() const
{
    int j;
    int i;

    for (i = 0; i < TAILLE; i++)
    {
        //if (i % 2 == 1) cout << " ";
        for (j = 0; j < i; j++)
        {
            std::cout << " ";
        }
        for (j = 0; j < TAILLE; j++)
        {
            if (_grilleAgents[i][j] != nullptr)
            {
                switch (_grilleAgents[i][j]->getMemoire().getEquipe())
                {
                case EQUIPE::ROUGE:
                    std::cout << RED << "A ";
                    break;
                case EQUIPE::BLEU:
                    std::cout << BLUE << "A ";
                    break;
                default:
                    std::cout << GREEN << "E ";
                    break;
                }
            }
            else
            {
                switch (_grille[i][j])
                {
                case EQUIPE::NEUTRE:
                    std::cout << RESET << ". ";
                    break;
                case EQUIPE::ROUGE:
                    std::cout << RED << ". ";
                    break;
                case EQUIPE::BLEU:
                    std::cout << BLUE << ". ";
                    break;
                default:
                    std::cout << RESET << "? ";
                    break;
                }
            }
        }
        std::cout << endl;
    }
}

Agent *Carte::getAgent(int i, int j) const
{
    return _grilleAgents[i][j];
}

void Carte::setAgent(int i, int j, Agent *agent)
{
    _grilleAgents[i][j] = agent;
}

void Carte::changerCase(int i, int j, EQUIPE equipe)
{
    _grille[i][j] = equipe;
}

bool Carte::estVide(int i, int j) const
{
    return _grilleAgents[i][j] == nullptr;
}

void Carte::casesAdjacentes(Agent * agent, EQUIPE voisinage[6]) const {
    voisinage[0] = _grille[(agent->getY() - 1) % TAILLE][agent->getX()];
    voisinage[1] = _grille[agent->getY()][(agent->getX() - 1) %TAILLE];
    voisinage[2] = _grille[(agent->getY() + 1) % TAILLE][(agent->getX() - 1) % TAILLE];
    voisinage[3] = _grille[(agent->getY() + 1) % TAILLE][agent->getX()];
    voisinage[4] = _grille[agent->getY()][(agent->getX() + 1) % TAILLE];
    voisinage[5] = _grille[(agent->getY() - 1) % TAILLE][(agent->getX() + 1) % TAILLE];
}

void Carte::agentsAdjacents(Agent * agent, Agent * voisinage[6]) const {
    voisinage[0] = _grilleAgents[(agent->getY() - 1) % TAILLE][agent->getX()];
    voisinage[1] = _grilleAgents[agent->getY()][(agent->getX() - 1) %TAILLE];
    voisinage[2] = _grilleAgents[(agent->getY() + 1) % TAILLE][(agent->getX() - 1) % TAILLE];
    voisinage[3] = _grilleAgents[(agent->getY() + 1) % TAILLE][agent->getX()];
    voisinage[4] = _grilleAgents[agent->getY()][(agent->getX() + 1) % TAILLE];
    voisinage[5] = _grilleAgents[(agent->getY() - 1) % TAILLE][(agent->getX() + 1) % TAILLE];
}

void Carte::deplacerAgent(Agent *agent, Point origine, Point destination)
{
    setAgent(origine.getY(), origine.getX(), nullptr);
    setAgent(destination.getY(), destination.getX(), agent);
    changerCase(destination.getY(), destination.getX(), agent->getMemoire().getEquipe());
}

void Carte::deplacerAgent(Agent *agent, Point Destination)
{
    deplacerAgent(agent, agent->getPosition(), Destination);
}
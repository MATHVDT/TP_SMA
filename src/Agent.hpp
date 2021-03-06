/**
 * @file Agent.hpp
 * @brief Fichier entête de la classe Agent.
 */
#ifndef AGENT_HPP
#define AGENT_HPP

#include <iostream>
#include <exception>

#include "Direction.hpp"
#include "Memoire.hpp"
#include "Action.hpp"
#include "mt.hpp"

using namespace std;

#include "Point.hpp"

enum class EQUIPE;
enum class ACTION;

/**
 * @class Agent
 * @brief Classe Agent
 */
class Agent
{
private:
    static const int _levelMax = 10;

private:
    Point _position;
    int _level;
    Memoire _memoire;
    ACTION _action;

public:
    Agent(int x, int y, EQUIPE equipe);
    Agent(Point position, EQUIPE equipe);
    Agent(const Agent &agent) = default;
    ~Agent();

    // Getter
    Point getPosition() const { return _position; }
    int getX() const { return _position.getX(); }
    int getY() const { return _position.getY(); }
    int getLevel() const { return _level; }
    ACTION getAction() const { return _action; }
    EQUIPE getEquipe() const { return getMemoire().getEquipe(); }
    Memoire getMemoire() const { return _memoire; }
    EQUIPE getTraceMort() const { return _memoire.getTraceMort(); }

    // Setter
    void setX(int x) { _position.setX(x); }
    void setY(int y) { _position.setY(y); }

    Agent *agir(Agent *voisinageAgentVoisins[6],
                EQUIPE voisinageAgentCases[6]);

    int examenVoisinage(Agent *voisinageAgentVoisins[6],
                        int &levelEnnemis, int &levelAmis,
                        bool direction[6]);

    Agent &operator=(const Agent &agent);

    ACTION choixAction(int levelEnnemis, int nbDirPossible);
    void correctionPositionAgent();

    // Division
    Agent *divisionAgent();
    void deplacementApresNaissance(bool direction[6]);

    // Déplacement
    void deplacer(DIRECTION dir);
    DIRECTION choixDirectionDeplacement(bool directionsPossibles[6]);

    // Combat
    ACTION issueAttaque(int levelEnnemis, int levelAmis);

    // Renforcement
    void gagneLevel(int nbLevel = 1) { _level += (_level + nbLevel <= _levelMax ? nbLevel : 0); }

    // Modification mémoire
    void consequenceAction(const bool caseCapture);
    // Partage de la mémoire
    void partagerMemoireAuVoisinage(Agent *voisinage[6]);
    void partagerMemoireACopain(Agent *copainAdjacent);
    void aquerirMemoire(int levelAgentTransmetteur, const ACTION action);

    // Classe Exception
public:
    class ExceptionAucuneDirectionsLibres : public exception
    {
    };
};

#endif

/**
 * @file Memoire.hpp
 * @brief Fichier entête de la classe Memoire.
 */
#ifndef MEMOIRE_HPP
#define MEMOIRE_HPP

#include <iostream>

enum class EQUIPE
{
    BLEU,
    ROUGE
};

/**
 * @class Memoire
 * @brief Classe contenant la Memoire d'un Agent.
 */
class Memoire
{


private:
    const float _tailleMemoire = 1.;
    float _division;
    float _deplacement;
    float _renforcement;
    EQUIPE _equipe;
    static const float _epsilon ;

public:
    Memoire(EQUIPE equipe);
    Memoire(float division,
            float depalcement,
            float renforcement,
            EQUIPE equipe);

    // Getter
    float getDivision() const { return _division; }
    float getDeplacement() const { return _deplacement; }
    float getRenforcement() const { return _renforcement; }
    EQUIPE getEquipe() const { return _equipe; }

    static float getEpsilon()  {return _epsilon;}

    // Setter
    void setDivision(float valeur) { _division = valeur; }
    void setDeplacement(float valeur) { _deplacement = valeur; }
    void setRenforcement(float valeur) { _renforcement = valeur; }
    void setEquipe(EQUIPE equipe) { _equipe = equipe; }


    float getInfluence(int differenceLevel);
    void apprentissage(float influence, const Memoire &memoire);

private:
    void correctionMemoire();
};

#endif
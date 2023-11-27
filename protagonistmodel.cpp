#include "protagonistmodel.h"
#include <iostream>

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> prot)
{
    xPos = prot->getXPos();
    yPos = prot->getYPos();
    maxHealth = prot->getHealth();
    currentHealth = maxHealth;
    energy = prot->getEnergy();
}

int ProtagonistModel::getPositionX() const
{
    return xPos;
}

int ProtagonistModel::getPositionY() const
{
    return yPos;
}

float ProtagonistModel::getHealth() const
{
    return maxHealth;
}

void ProtagonistModel::setHealth(float value)
{
    maxHealth = value;
}

float ProtagonistModel::getEnergy() const
{
    return energy;
}

void ProtagonistModel::setEnergy(float value)
{
    energy = value;
}

void ProtagonistModel::addHealth(int hpValue)
{
    maxHealth += hpValue;
    currentHealth = maxHealth;

}




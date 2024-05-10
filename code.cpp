#include <iostream>
#include <cmath>
using namespace std;

class BeamCalculator
{
public:
    float beamLength, supportPositions[5], pointLoadPosition, pointLoadValue, distributedLoadStartPos, distributedLoadEndPos, distributedLoadValue;
    float distributedLoad, finalDistributedLoadPosition;
    string supportType;
    float momentPosition, momentValue, reactionAtA, reactionAtB;
    float reactionA, reactionB;
    float a[5];
    int supportCount, pointLoadDecision;
    int yesNo = 0;
    void inputBeamLength();
    void inputSupport();
    void inputPointLoad();
    void inputDistributedLoad();
    void inputMoment();
    int calculateReactions();
    void setValues();

};

void BeamCalculator::inputBeamLength()
{
    cout << "\tEnter beam length: ";
    cin >> beamLength;
    cout << endl;
}

void BeamCalculator::inputSupport()
{
    cout << "\tHow many supports do you want to add: ";
    cin >> supportCount;
    cout << endl;
    for (int i = 0; i < supportCount; i++)
    {
        cout << "\tEnter support type: " << endl;
        cout << "\t1. Pin Support" << endl;
        cout << "\t2. Roller Support" << endl;
        cin >> supportType;
        cout << "\tEnter support position: ";
        cin >> supportPositions[i];
        cout << endl;
    }
}

void BeamCalculator::inputPointLoad()
{
    cout << "\tDo you want to add a point load?" << endl;
    cout << "\t 1. Yes   2. No" << endl;
    cin >> pointLoadDecision;
    if (pointLoadDecision == 1)
    {
        cout << "\tIf the point load is upward, use a negative sign." << endl;
        cout << "\tEnter the position and value of the point load (space separated): ";
        cin >> pointLoadPosition >> pointLoadValue;
        cout << endl;
    }
    else
    {
        pointLoadPosition = 0;
        pointLoadValue = 0;
    }
}

void BeamCalculator::inputDistributedLoad()
{
    cout << "\tInformation about distributed load" << endl;
    cout << "\tIf the distributed load is upward, use a negative sign." << endl;
    cout << "\tEnter the starting position and its value (space separated): ";
    cin >> distributedLoadStartPos >> distributedLoadValue;
    cout << endl;
    cout << "\tEnter the ending position and its value (space separated): ";
    cin >> distributedLoadEndPos >> distributedLoadValue;
    cout << endl;
    if (distributedLoadValue == distributedLoadValue)
    {
        distributedLoad = distributedLoadValue * (distributedLoadEndPos - distributedLoadStartPos);
        finalDistributedLoadPosition = distributedLoadStartPos + (distributedLoadEndPos - distributedLoadStartPos) * 0.5;
    }
    if (distributedLoadValue < distributedLoadValue)
    {
        distributedLoad = 0.5 * (distributedLoadEndPos - distributedLoadStartPos) * distributedLoadValue;
        finalDistributedLoadPosition = distributedLoadEndPos - (distributedLoadEndPos - distributedLoadStartPos) * 0.3333;
    }
    if (distributedLoadValue > distributedLoadValue)
    {
        distributedLoad = 0.5 * (distributedLoadEndPos - distributedLoadStartPos) * distributedLoadValue;
        finalDistributedLoadPosition = distributedLoadStartPos + (distributedLoadEndPos - distributedLoadStartPos) * 0.3333;
    }
}

void BeamCalculator::inputMoment()
{
    cout << "\tIs there any moment?" << endl;
    cout << "\t1. Yes 2. No" << endl;
    cin >> yesNo;
    if (yesNo == 1)
    {
        cout << "\tTake counterclockwise moment as positive." << endl;
        cout << "\tEnter moment position and value (space separated): ";
        cin >> momentPosition >> momentValue;
        cout << endl;
    }
    else
    {
        momentPosition = 0;
        momentValue = 0;
    }
}

int BeamCalculator::calculateReactions()
{
    float supportDistance, temp, a, b;
    supportDistance = supportPositions[1] - supportPositions[0];
    a = (distributedLoad * (finalDistributedLoadPosition - supportPositions[0]));
    b = pointLoadValue * (pointLoadPosition - supportPositions[0]);
    temp = round(a) + b - momentValue;
    reactionAtB = temp / supportDistance;
    reactionAtA = pointLoadValue + distributedLoad - reactionAtB;

    cout << "\tReaction at A: " << reactionAtA << endl;
    cout << "\tReaction at B: " << reactionAtB << endl;
}

void BeamCalculator::setValues()
{
    reactionA = supportPositions[0];
    reactionB = reactionAtA;
}

class Point : public BeamCalculator
{
    double x;
    double y;

public:
    Point(double xx, double yy)
    {
        x = xx;
        y = yy;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }
};

int main()
{
    BeamCalculator beam;
    // Accessing all the information about the beam
    beam.inputBeamLength();
    beam.inputSupport();
    beam.inputPointLoad();
    beam.inputDistributedLoad();
    beam.inputMoment();
    // Calculation
    beam.calculateReactions();
}

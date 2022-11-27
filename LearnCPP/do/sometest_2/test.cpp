#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "test.h"

using namespace std;
class StatTrackerSolution : public StatTracker
{
public:
    StatTrackerSolution() : m_totalYards(0), m_totalPlays(0), m_minYards(0), m_maxYards(0) {}
    virtual ~StatTrackerSolution() {}
    virtual void AddPlay(float yards, PlayType type)
    {
        if (type == INVALID)
        {
            return;
        }
        m_totalYards += yards;
        m_totalPlays++;
        if (m_totalPlays == 1)
        {
            m_minYards = yards;
            m_maxYards = yards;
        }
        else
        {
            if (yards < m_minYards)
                m_minYards = yards;
            if (yards > m_maxYards)
                m_maxYards = yards;
        }
        m_yardsPerPlayType[type] += yards;
        m_playsPerPlayType[type]++;
    }
    virtual float GetAverageYardsPerPlay() const
    {
        return m_totalYards / m_totalPlays;
    }
    virtual float GetAverageYardsPerPlayType(PlayType playType) const
    {
        //store it in float 
        float averageYardsPerPlayType = m_yardsPerPlayType[playType] / m_playsPerPlayType[playType];
        // if avg is -nan
        if (averageYardsPerPlayType != averageYardsPerPlayType)
        {
            return 0;
        }
    }
    virtual int GetMinimumYardage() const
    {
        return m_minYards;
    }
    virtual int GetMaximumYardage() const
    {
        return m_maxYards;
    }
    virtual void Reset()
    {
        m_totalYards = 0;
        m_totalPlays = 0;
        m_minYards = 0;
        m_maxYards = 0;
        for (int i = 0; i < NUM_PLAYTYPES; ++i)
        {
            m_yardsPerPlayType[i] = 0;
            m_playsPerPlayType[i] = 0;
        }
    }
private:
    float m_totalYards;
    int m_totalPlays;
    int m_minYards;
    int m_maxYards;
    float m_yardsPerPlayType[NUM_PLAYTYPES];
    int m_playsPerPlayType[NUM_PLAYTYPES];
};

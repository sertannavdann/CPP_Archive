class StatTracker
{
public:
    enum PlayType
    {
        RUN_PLAY = 0,
        PASS_PLAY,
        KICK_PLAY,
        NUM_PLAYTYPES,
        INVALID
    };
    virtual ~StatTracker() {};
    virtual void AddPlay(float yards, PlayType type) = 0;
    virtual float GetAverageYardsPerPlay() const = 0;
    virtual float GetAverageYardsPerPlayType(PlayType playType) const = 0;
    virtual int GetMinimumYardage() const = 0;
    virtual int GetMaximumYardage() const = 0;
    virtual void Reset() = 0;
};
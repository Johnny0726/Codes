#ifndef TABTENN1_H_INCLUDED
#define TABTENN1_H_INCLUDED

#include <string>
using std::string;

//simple class
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennisPlayer(const string& fn = "none", const string& ln = "onne", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable;};
    void ResetTable(bool v) {hasTable = v;};
};

class RatedPlayer : public TableTennisPlayer
{
};

#endif // TABTENN1_H_INCLUDED

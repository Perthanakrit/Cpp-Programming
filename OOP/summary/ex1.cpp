#include <iostream>
using namespace std;

class FootBallTeam {
    private:
        string name;
        int numberOfPlayers;
        int wins, draws, losses;
    public:
        FootBallTeam(string n) {
            this->name = n;
            this->numberOfPlayers = 0;
            this->wins = 0;
            this->draws = 0;
            this->losses = 0;
        }

        string getName() {
            return name;
        }

        void setWins(int w) {
            wins = w;
        }

        void setDraws(int d) {
            draws = d;
        }

        void setLosses(int l) {
            losses = l;
        }

        int totalPoints() {
            return wins * 3 + draws;
        }

        void printInfo() {
            cout << "Team: " << name << "\n";
            cout << "Wins: " << wins << "\n";
            cout << "Draws: " << draws << "\n";
            cout << "Losses: " << losses << "\n";
            cout << "Total points: " << totalPoints() << "\n";
        }
};

class PremierLeague {
    private:
        string name, year;
        FootBallTeam **teams;
        int numberOfTeams;

    public:
    PremierLeague(string name) {
        this->name = name;
        this->year = "2021";
        this->numberOfTeams = 0;
    }

    void addTeam(FootBallTeam *team) {
        teams[numberOfTeams++] = team;
    }

    FootBallTeam *findMaxScoreTeam() {
        int max = 0, score, i, maxIndex;

        for(i=0; i < numberOfTeams; i++){
            score = teams[i]->totalPoints();
            if(score > max){
                max = score;
                maxIndex = i;
            }
        }

        return teams[maxIndex];
    }

};

int main(int argc, char const *argv[])
{
    PremierLeague pl("Premier League");
    FootBallTeam team1("Liverpool");
    FootBallTeam *team2 = new FootBallTeam("Chelsea");

    pl.addTeam(&team1);
    pl.addTeam(team2);

    team1.setWins(10);
    team1.setDraws(5);
    team1.setLosses(3);

    team2->setWins(8);
    team2->setDraws(7);
    team2->setLosses(3);
    
    cout << "Max score team:" << endl;
    pl.findMaxScoreTeam()->printInfo(); 

    cout << "--others---" << endl;
    team2->printInfo();

    return 0;
}

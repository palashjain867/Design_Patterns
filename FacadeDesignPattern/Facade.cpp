#include "iostream"
#include "string"

using namespace std;

class Amplifier {
public:
    void On() { cout << "Amplifier ON" << endl; }
    void SetVolume(int level) { cout << "Setting volume to " << level << endl; }
};

class Projector {
public:
    void On() { cout << "Projector ON" << endl; }
    void SetWideScreen() { cout << "Setting projector to Widescreen mode" << endl; }
};

class DVDPlayer {
public:
    void On() { cout << "DVD Player ON" << endl; }
    void play(const string& movieName) { cout << "Playing Movie ---- " << movieName << endl; }
};


class HomeThreaterFacade{
    Amplifier* Amp;
    DVDPlayer* Dvd;
    Projector* Pro;

    public:
        HomeThreaterFacade(Amplifier* amp, DVDPlayer* dvd, Projector* pro) : Amp(amp), Dvd(dvd), Pro(pro){

        }

        void watchMovie(const string& movieName)
        {
            cout<< "Get Ready to watch the movie ......" <<endl;
            Amp->On();
            Amp->SetVolume(5);
            Dvd->On();
            Dvd->play(movieName);
            Pro->On();
            Pro->SetWideScreen();
        }

};

int main()
{
    Amplifier amp;
    DVDPlayer dvd;
    Projector pro;

    HomeThreaterFacade homethreater(&amp, &dvd, &pro);
    homethreater.watchMovie("Raid");

    return 0;

}   
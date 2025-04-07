#include "mutex"
#include "iostream"

using namespace std;

class GameSetting{
    private:
        static GameSetting* instance;
        static mutex mutex_x;
        int volume{100};
        GameSetting() = default;

    public:
        static GameSetting* getInstance(){
            // std::lock_guard<std::mutex> lock(mutex_x);
            // if(instance == nullptr)
            // {
            //     instance = new GameSetting();
            //     cout << "Creating the GameSetting object" << endl;
            // }
            // return instance;

            //alternate method, recommended
            static GameSetting instance;
            return &instance;
        }

        GameSetting(const GameSetting&) = delete;
        GameSetting& operator=(const GameSetting&) = delete;
        GameSetting(const GameSetting&&) = delete;
        GameSetting& operator=(const GameSetting&&) = delete;

        ~GameSetting() = default;

        void setVolume(int vol) { volume = vol; }
        int getVolume() const { return volume; }
};

//GameSetting* GameSetting::instance = nullptr;
std::mutex GameSetting::mutex_x;

int main()
{
    GameSetting* obj = GameSetting::getInstance();
    obj->setVolume(200);
    GameSetting* obj1 = GameSetting::getInstance();
    cout << "Volume : " << obj1->getVolume() << endl;
}
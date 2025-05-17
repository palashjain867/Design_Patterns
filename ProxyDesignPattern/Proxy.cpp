#include "iostream"
#include "string"

using namespace std;

class Image{
    public:
        virtual void display() = 0;
        virtual ~Image() = default;
};

class RealImage : public Image{
    string m_fileName;

    public:
        RealImage(const string& fileName) : m_fileName(fileName){
            LoadImageFromDisk(m_fileName);
        }
        void LoadImageFromDisk(const string& fileName){
            cout<<"Loading Image " << fileName << endl;
        }

        void display() override{
            cout<<"Displaying Image - " << m_fileName << endl;
        }
};

class ProxyImage : public Image{
    RealImage* image {nullptr};
    string m_fileName;
    public:
        ProxyImage(const string& fileName) : m_fileName(fileName){}

        void display() override{
            if(!image){
                image = new RealImage(m_fileName);
            }
            image->display();
        }
        ~ProxyImage(){
            delete image;
        }
};

int main()
{
    ProxyImage img1("mypic.jpg");
    img1.display();

    Image* img2 = new ProxyImage("mydp.jpg");
    img2->display();
    
    return 0;
}
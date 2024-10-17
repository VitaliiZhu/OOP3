#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class motor {
private:
    float V;
    float P;
    string ZavNomer;

public:

    motor(float volume, float power, string ZavodNomer)
        : V(volume), P(power), ZavNomer(ZavodNomer) {}

    void operator+=(const float dv) {
        P += dv;
    }
    float getVolume() const { return V; }
    string getZavodNomer() const { return ZavNomer; }
    float getPower() const { return P; }
    void setVolume(float vol) { V=vol; }
    void setPower(float pow) { P = pow; }
    void setZavodNomer(string num) { ZavNomer = num; }


    void info() const {
        cout << "Volume: " << V << ", Power: " << P
            << ", Nomer Zavoda: " << ZavNomer << endl;
    }
    
};
class automobil {
private:
   // motor Dvygun; 
    int NomerReg;
    string Marka;
    string Color;
public:
    motor Dvygun;
    automobil(int Nomer, string color, string marka, motor mot)
        : NomerReg(Nomer),Marka(marka),Color(color), Dvygun(mot){}

    void setMotor(motor mot) {
        Dvygun = mot;
    }
    void setMarka() {
        cin >> Marka;
    }
    void setColor() {
        cin >> Color;
    }
    void setNomerReg() {
        cin >> NomerReg;
    }
    int getNomerReg() {
        return NomerReg;
    }
    string getColor() {
        return Color;
    }
    string getMarka() {
        return Marka;
    }

    void info() {
        cout << "Marka: " << Marka << ", Color: " << Color
            << ", Registration Nomer: " << NomerReg << endl;
        cout << "Motor: ";
        Dvygun.info();

    }
    friend istream& operator>>(istream& is, automobil& p) {
        cout << "Insert Marka: ";
        is >> p.Marka;
        cout << "Insert reg nomer: ";
        is >> p.NomerReg;
        cout << "Insert color: ";
        is >> p.Color;
        return is;
    }

    friend ostream& operator<<(ostream& os, const automobil& p) {
        os << "Color: " << p.Color << "\n"
            << "Reg Nomer: " << p.NomerReg << "\n"
            << "Marka: " << p.Marka << "\n"
            << "Power: " << p.Dvygun.getPower() << "\n"
            << "Volume: " << p.Dvygun.getVolume()
            << "\n"
            << "Nomer Zavoda: " << p.Dvygun.getZavodNomer()<<"\n";
        return os;
    }

};
int main()
{
    motor Fiat(10,10,"Fatta");
    Fiat.info();
    Fiat += 2;
    Fiat.info();
    motor Lambo(20, 15, "Cool");
    Lambo.info();
    automobil Skoda(1234,"Red","Skoda",Fiat);
    cout << Skoda;
    bool option = 0;
    cout << "Do you want to change something?(1-yes,0-no): ";
    cin >> option;
    while (option != 0) {
        Skoda.setMotor(Lambo);
        cin >> Skoda;
        cout << Skoda;
        cout << "Do you want to change something?(1-yes,0-no): ";
        cin >> option;
    }
}



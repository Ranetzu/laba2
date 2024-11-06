#include <iostream>
#include <string>;

using namespace std;

class Tarifs {

private:

    int SellWater;
    int SellGaz;
    int SellElectric;

public:

    Tarifs(int sw, int sg, int se);

    int GetSellWater() const;
    int GetSellGaz() const;
    int GetSellElectric() const;

    void AddSellWater(int f) {
        if (f < 0 or f > 100000 or cin.fail()) {

            cout << "Unknown number." << endl;

        }
        else {
            SellWater = f;
        }
    }
    void AddSellGaz(int c) {
        if (c < 0 or c > 100000) {

            cout << "Unknown number." << endl;

        }
        else {
            SellGaz = c;
        }
    }
    void AddSellElectric(int l) {
        if (l < 0 or l > 100000) {

            cout << "Unknown number." << endl;

        }
        else {
            SellElectric = l;
        }
    }
};

Tarifs::Tarifs(int sw, int sg, int se) {

    if (sw < 0 or sg < 0 or se < 0) {

        throw std::out_of_range("You Dead!");

    }

    SellWater = sw;
    SellGaz = sg;
    SellElectric = se;
}

int Tarifs::GetSellWater() const {

    return SellWater;

}
int Tarifs::GetSellGaz() const {

    return SellGaz;

}
int Tarifs::GetSellElectric() const {

    return SellElectric;

}

class Human {

private:

    string secondName;
    int dolg = 0;

public:

    Human(string name);

    string GetSecondName() const;
    int GetDolg() const;

    void AddSecondName(string na) {

        secondName = na;

    }
    void Adddolg(int k) {
        dolg += k;
    }
};

string Human::GetSecondName() const {

    return secondName;

}
int Human::GetDolg() const {

    return dolg;

}

Human::Human(string f) {

    secondName = f;


}

class NumberHouse {

private:

    int numberHouse;
    int numberKV;

public:

    NumberHouse(int nh, int nkv);

    int GetnumberHouse() const;
    int GetnumberKV() const;

    void AddnumberHouse(int nh) {

        numberHouse = nh;

    }

    void AddnumberKV(int nkv) {

        numberKV = nkv;

    }
};

int NumberHouse::GetnumberHouse() const {

    return numberHouse;

}
int NumberHouse::GetnumberKV() const {

    return numberKV;

}

NumberHouse::NumberHouse(int nh, int nkv) {

    if (nh < 0 or nkv < 0) {

        throw std::out_of_range("You Dead!");

    }

    numberHouse = nh;
    numberKV = nkv;
}
void addUslElectr(Tarifs& tarif, Human& human) {

    cout << tarif.GetSellElectric() << " to " << human.GetSecondName() << endl;
    human.Adddolg(tarif.GetSellElectric());

}
void addUslGaz(Tarifs& tarif, Human& human) {

    cout << tarif.GetSellGaz() << " to " << human.GetSecondName() << endl;
    human.Adddolg(tarif.GetSellGaz());

}
void addUslWater(Tarifs& tarif, Human& human) {

    cout << tarif.GetSellWater() << " to " << human.GetSecondName() << endl;;
    human.Adddolg(tarif.GetSellWater());

}
void DolgName(Human& human, string name) {

    if (human.GetSecondName() == name) {
        cout << human.GetDolg() << endl;
    }
    else {
        cout << "Unknown name." << endl;
    }

}

int menuNum;
void menu() {
    cout << "Menu:" << endl;
    cout << "Enter 1 for enter a new sell of water." << endl;
    cout << "Enter 2 for enter a new sell of Gaz." << endl;
    cout << "Enter 3 for enter a new sell of Electric." << endl;
    cout << "Enter 4 for enter a second name of human." << endl;
    cout << "Enter 5 for get a dolg with name." << endl;
    cout << "Enter 6 for add tarif of Water for human." << endl;
    cout << "Enter 7 for add tarif of Gaz for human." << endl;
    cout << "Enter 8 for add tarif of Electric for human." << endl;
    cout << "Enter 9 for end of work." << endl;
    cout << "Your choice is: ";
    cin >> menuNum;
}
void syst() {
    system("pause");
    system("cls");
}

int main()
{
    Tarifs Tarif(0, 0, 12);
    Tarifs& tarif = Tarif;
    Human human("name");
    NumberHouse numberHouse(0, 0);
    string name;
    string vvod;


    
    while (menuNum !=9) {
        menu();
        switch (menuNum){
        case 1:
            cout << "Enter a new sell of Water:";
            int k;
            cin >> k;
            Tarif.AddSellWater(k);
            cout << endl << "New sell of water:" << Tarif.GetSellWater() << endl;
            syst();
            break;
        case 2:
            cout << "Enter a new number of Gaz:";
            cin >> k;
            Tarif.AddSellGaz(k);
            cout << endl << "New sell of gaz:" << Tarif.GetSellGaz() << endl;
            syst();
            break;
        case 3:
            cout << "Enter a new number of Electric:";
            cin >> k;
            Tarif.AddSellElectric(k);
            cout << endl << "New sell of electric:" << Tarif.GetSellElectric() << endl;
            syst();
            break;
        case 4:
            cout << "Get second name of human:";
            cin >> name;
            human.AddSecondName(name);
            cout << human.GetSecondName() << endl;
            syst();
            break;
        case 5:
            cout << "Enter name:" << " " << endl;
            cin >> vvod;
            DolgName(human, vvod);
            syst();
            break;
        case 6:
            addUslWater(tarif, human);
            syst();
            break;
        case 7:
            addUslGaz(tarif, human);
            syst();
            break;
        case 8:
            addUslElectr(tarif, human);
            syst();
            break;
        default:
            cout << "Unknown number." << endl;
            syst();
            break;
        }// end switch
    }// end while
    return 0;
}


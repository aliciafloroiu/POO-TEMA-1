
#include <iostream>

using namespace std;

class Vector
{
private:
    int nrelemente;
    int *v;
public:

    Vector (int nrelemente,int val);/// initializare
    Vector (Vector& vector1);/// constructor copiere
    Vector& operator=(Vector &vector1);
    int& operator[](int i) const;
    void afisare(ostream &out);
    void citire(istream &in);
    void update( int nrelemente, int val);
    friend istream& operator>>(istream &in, Vector& v);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, Vector& v);
    friend Vector& operator + (Vector& vector1, Vector& vector2); ///supraincarcare operator +
    friend Vector& operator - (Vector& vector1, Vector& vector2); ///supraincarcare operator -
    friend Vector& operator -=(Vector& vector1, int i);           ///supraincarcare operator +=
    friend Vector& operator +=(Vector& vector1, int i);
    friend Vector& operator ==(Vector& vector1, Vector& vector2);
    friend Vector& operator !=(Vector& vector1, Vector& vector2);
    friend int length(Vector& vector1);
};
/// initializare
Vector::Vector(int nrelemente,int val=0)
{
    int i;
    this->nrelemente = nrelemente;
    this->v = new int[nrelemente];
    for(i=0; i<nrelemente; i++)
        this->v[i]=val;
}

/// constructor de copiere
Vector::Vector(Vector &vector1)
{
    int i;
    this->nrelemente=vector1.nrelemente;
    this->v=new int[nrelemente];
    for(i=0; i<nrelemente; i++)
        this->v[i]=vector1.v[i];
}
///operator de atribuire
Vector& Vector::operator=(Vector& vector1)
{
    int i;
    this->nrelemente = vector1.nrelemente;
    for(i=0; i<nrelemente; i++)
        v[i] = vector1.v[i];
}///operator []
int& Vector::operator[](int i)const
{
    return v[i];
}
///citire
void Vector::citire(istream &in)
{
    int i;
    cout<<"Numar elemente: ";
    in>>nrelemente;
    this->v = new int(nrelemente);
    cout<<"Elementele vectorului:";
    for(i=0; i<nrelemente; i++)
        in>>v[i];
}
istream& operator>>(istream& in,Vector& v)
{
    v.citire(in);
    return in;
}


///afisare
void Vector::afisare(ostream &out)
{
    int i;
    if(this!=NULL)
    {
        out<<"vectorul este: ";
        for(i=0; i<nrelemente; i++)
            out<<v[i]<<" ";
        out<<endl;
    }
    else
        cout<<"eroare";
}
ostream& operator<<(ostream& out, Vector& v)
{
    v.afisare(out);
    return out;
}
///reactualizare
void Vector::update(int nrelemente, int val)
{
    int i;
    this->nrelemente = nrelemente;
    delete[] this->v;
    this->v=new int[nrelemente];
    for(i=0; i<nrelemente; i++)
        v[i]=val;

}///returnare nr elemente
int length(Vector& vector1)
{
    return vector1.nrelemente;
}
//adunarea a 2 vect
Vector& operator+( Vector &vector1,  Vector &vector2)
{
    int i;
    Vector *vector3 ;


    if (vector2.nrelemente>vector1.nrelemente)
    {
        vector3 = new Vector(vector2.nrelemente);
        for(i=0; i<vector1.nrelemente; i++)
            vector3->v[i]= vector1.v[i]+vector2.v[i];
        for(i=vector1.nrelemente; i<vector2.nrelemente; i++)
            vector3->v[i]= vector2.v[i];
    }
    else
    {
        vector3=new Vector(vector1.nrelemente);
        for(i=0; i<vector2.nrelemente; i++)
            vector3->v[i]= vector1.v[i]+vector2.v[i];
        for(i=vector2.nrelemente; i<vector1.nrelemente; i++)
            vector3->v[i]= vector1.v[i];
    }


    return *vector3;
}
///scaderea a 2 vect
Vector& operator-( Vector &vector1,  Vector &vector2)
{
    int i;
    Vector *vector3 ;


    if (vector2.nrelemente>vector1.nrelemente)
    {
        vector3 = new Vector(vector2.nrelemente);
        for(i=0; i<vector1.nrelemente; i++)
            vector3->v[i]= vector1.v[i]-vector2.v[i];
        for(i=vector1.nrelemente; i<vector2.nrelemente; i++)
            vector3->v[i]= vector2.v[i];
    }
    else
    {
        vector3=new Vector(vector1.nrelemente);
        for(i=0; i<vector2.nrelemente; i++)
            vector3->v[i]= vector1.v[i]-vector2.v[i];
        for(i=vector2.nrelemente; i<vector1.nrelemente; i++)
            vector3->v[i]= vector1.v[i];
    }


    return *vector3;
}
///verif egalitate
Vector& operator==(Vector &vector1, Vector &vector2)
{
    int ok=1;
    if(vector1.nrelemente!=vector2.nrelemente)
        ok=0;
    if(ok==1)
    {
        for(int i=0; i<vector1.nrelemente; i++)
            if(vector1.v[i]==vector2.v[i])
                ok=1;
            else
                ok=2;
    }
    if(ok==0)
        cout<<"dimensiuni diferite, elementele nu sunt egale"<<endl;;
    if (ok==1)
        cout<<"elementele sunt egale "<<endl;
    if (ok==2)
        cout<<"elementele nu sunt egale"<<endl;
}
///verif neegalitatea
Vector& operator!=(Vector &vector1, Vector &vector2)
{
    int ok=1;
    if(vector1.nrelemente!=vector2.nrelemente)
        ok=0;
    if(ok==1)
    {
        for(int i=0; i<vector1.nrelemente; i++)
            if(vector1.v[i]!=vector2.v[i])
                ok=1;
            else
                ok=2;
    }
    if(ok==0)
        cout<<"dimensiuni diferite, elementele nu sunt egale"<<endl;
    if (ok==1)
        cout<<"elementele nu sunt egale"<<endl;
    if (ok==2)
        cout<<"elementele sunt egale"<<endl;
}
///adauga valuarea i la elem din vect
Vector& operator+=(Vector &vector1,int i)
{
    int nrelemente,j;
    for(j=0; j<vector1.nrelemente; j++)
        vector1.v[j]+=i;
}
///scade valuarea i la elem din vect
Vector& operator-=(Vector &vector1,int i)
{
    int nrelemente,j;
    for(j=0; j<vector1.nrelemente; j++)
        vector1.v[j]-=i;

}
void menu_output()
{
    cout<<"\n Floroiu Alicia_211 - Proiect 14 - Nume proiect:  Clasa Vector  \n";
    cout<<"\n\t MENIU:";
    cout<<"\n-----------------------------------\n";
    cout<<"\n";
    cout<<"1. Actiune 1 din meniu"<<endl;
    cout<<"2. Actiune 2 din meniu"<<endl;
    cout<<"3. Actiune 3 din meniu"<<endl;
    cout<<"4. Actiune 4 din meniu"<<endl;
    cout<<"5. Actiune 5 din meniu"<<endl;
    cout<<"6. Actiune 6 din meniu"<<endl;
    cout<<"0. Iesire."<<endl;
}

void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;
    menu_output();
    do
    {


        cout<<"\nIntroduceti numarul actiunii:";
        cin>>option;

        if (option==1)
        {
            Vector vector1(0),vector2(0),vector3(0);
            cin>>vector1;
            cin>>vector2;
            cout<<"Verific egalitatea vectorilor: "<<endl;
            vector1 == vector2;
            cout<<"Adunarea  vectorilor: "<<endl;
            vector3 = vector2+vector1;
            cout<<vector3;
        }
        if (option==2)
        {
            Vector vector1(0),vector2(0),vector3(0),vector4(0);
            cin>>vector1;
            cin>>vector2;
            cin>>vector3;
            cout<<"Scaderea vectorilor"<<endl;
            vector4=vector1-vector2-vector3;
            cout<<vector4;
        }
        if (option==3)
        {
            int nrupdate,val;
            Vector vector1(0);
            cin>>vector1;
            cout<<"Inainte de actualizare vectorul are:  "<<length(vector1)<<"  elemente"<<endl;
            cout<<"NRupdate = ";
            cin>>nrupdate;
            cout<<"VAL = ";
            cin>>val;
            vector1.update(nrupdate,val);
            cout<<"Dupa actualizare vectorul are:  "<<length(vector1)<<"  elemente"<<endl;
            cout<<vector1;
        }
        if (option==4)
        {
            Vector vector1(0);
            int val;
            cin>>vector1;
            cout<<"Val = ";
            cin>>val;
            vector1+=val;
            cout<<"Adunand val ";
            cout<<vector1;

        }
        if (option==5)
        {
            Vector vector1(0);
            int val;
            cin>>vector1;
            cout<<"Val = ";
            cin>>val;
            vector1-=val;
            cout<<"Scazand val ";
            cout<<vector1;

        }
        if(option == 6 )
        {
            int Maxim=0,i;
            Vector vector1(0);
            cin>>vector1;
            for(i=0; i<length(vector1); i++)
            {
                if(vector1[i]>Maxim)
                    Maxim = vector1[i];
            }
            cout<<"Maximul din vector este: "<<Maxim;

        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>6)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
    }
    while(option!=0);
}
int main()
{
    menu();
    return 0;
}









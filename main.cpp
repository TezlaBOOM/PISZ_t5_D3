#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;
struct Plik_Naglowek {
    short Type;
    int Size;
    short Reserved1;
    short Reserved2;
    int OffBits;
} Plik;

void info(){
    FILE* f = fopen("test.bmp", "rb");

    if (f == nullptr)
    {
        cout<<"Nie można otworzyć tego pliku"<<endl;    
    }
    else
    {
       cout<<"Plik jest otwary poprawnie"<<endl;
    
    cout<<endl;
    cout<<" ===================== "<<endl;
    cout<<" INFORMACJE O BITMAPIE "<<endl;
    cout<<" ===================== "<<endl;


    fread(&Plik.Type, sizeof(Plik.Type), 1, f);
    fread(&Plik.Size, sizeof(Plik.Size), 1, f);
    fread(&Plik.Reserved1, sizeof(Plik.Reserved1), 1, f);
    fread(&Plik.Reserved2, sizeof(Plik.Reserved2), 1, f);
    fread(&Plik.OffBits, sizeof(Plik.OffBits), 1, f);
    cout<<"Typ: "<<Plik.Type<<endl;
    cout<<"rozmiar pliku: " << Plik.Size << " bajtow" << endl;
    cout<<"Reserved1: "<<Plik.Reserved1<<endl;
    cout<<"Reserved2: "<<Plik.Reserved2<<endl;
    cout<<"Pozycja danych obrazkowych: "<<Plik.OffBits<<endl;

    fclose(f);
    }
}
int main(int arc, char * argv[]) {


    info();
    
    return 0;
}
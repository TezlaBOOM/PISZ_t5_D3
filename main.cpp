#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;
struct File_Header {
    short Type;
    int Size;
    short Reserved1;
    short Reserved2;
    int OffBits;
} File;

struct Picture_Header {
    int Size;
    int Width;
    int Height;
    short Planes;
    short BitCount;
    int Compression;
    int SizeImage;
    int XPelsPerMeter;
    int YPelsPerMeter;
    int ClrUsed;
    int ClrImportant;
} Picture;


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


    fread(&File.Type, sizeof(File.Type), 1, f);
    fread(&File.Size, sizeof(File.Size), 1, f);
    fread(&File.Reserved1, sizeof(File.Reserved1), 1, f);
    fread(&File.Reserved2, sizeof(File.Reserved2), 1, f);
    fread(&File.OffBits, sizeof(File.OffBits), 1, f);
    cout<<"Typ: "<<File.Type<<endl;
    cout<<"rozmiar pliku: " << File.Size << " bajtow" << endl;
    cout<<"Reserved1: "<<File.Reserved1<<endl;
    cout<<"Reserved2: "<<File.Reserved2<<endl;
    cout<<"Pozycja danych obrazkowych: "<<File.OffBits<<endl;

    

    fseek(f, 14, SEEK_SET);
    fread(&Picture.Size, sizeof(Picture.Size), 1, f);
    fread(&Picture.Width, sizeof(Picture.Width), 1, f);
    fread(&Picture.Height, sizeof(Picture.Height), 1, f);
    fread(&Picture.Planes, sizeof(Picture.Planes), 1, f);
    fread(&Picture.BitCount, sizeof(Picture.BitCount), 1, f);
    fread(&Picture.Compression, sizeof(Picture.Compression), 1, f);
    fread(&Picture.SizeImage, sizeof(Picture.SizeImage), 1, f);
    fread(&Picture.XPelsPerMeter, sizeof(Picture.XPelsPerMeter), 1, f);
    fread(&Picture.YPelsPerMeter, sizeof(Picture.YPelsPerMeter), 1, f);
    fread(&Picture.ClrUsed, sizeof(Picture.ClrUsed), 1, f);
    fread(&Picture.ClrImportant, sizeof(Picture.ClrImportant), 1, f);
    cout<<endl;
    cout<<"Wielkosc naglowka informacyjnego: "<<Picture.Size<<endl;
    cout << "Szerokosc: " << Picture.Width << " pikseli" << endl;
    cout << "Wysokosc: " << Picture.Height << " pikseli" << endl;
    cout<<"Liczba platow: "<<Picture.Planes<<endl;
    cout<<"Liczba bitow na piksel: "<<Picture.BitCount<<endl;
    cout<<"Kompresja: "<<Picture.Compression<<endl;
    cout<<"Rozmiar obrazka: "<<Picture.SizeImage<<endl;
    cout<<"Liczba pikseli na metr: "<<Picture.XPelsPerMeter<<endl;
    cout<<"Liczba pikseli na metr: "<<Picture.YPelsPerMeter<<endl;
    cout<<"Liczba uzytych kolorow: "<<Picture.ClrUsed<<endl;
    cout<<"Liczba kolorow ktore sa wazne: "<<Picture.ClrImportant<<endl;
    cout<<endl;
    fclose(f);
    }
}
void negatyw(){
    FILE* f = fopen("test.bmp", "rb");

    if (f == nullptr)
    {
        cout<<"Nie można otworzyć tego pliku"<<endl;     
    }
    else
    {
       cout<<"Plik jest otwary poprawnie"<<endl;
    
     FILE* w = fopen("negatyw_test.bmp", "wb");
    if (w == nullptr)
    {
        cout<<"Nie można otworzyć tego pliku"<<endl;
    }
    else
    {
        cout<<"Plik jest otwary poprawnie"<<endl;
        cout<<"negatyw jest wtorzony..."<<endl;
        

        fseek(w, 0, SEEK_SET);
        fwrite(&File.Type, sizeof(File.Type), 1, w);
        fwrite(&File.Size, sizeof(File.Size), 1, w);
        fwrite(&File.Reserved1, sizeof(File.Reserved1), 1, w);
        fwrite(&File.Reserved2, sizeof(File.Reserved2), 1, w);
        fwrite(&File.OffBits, sizeof(File.OffBits), 1, w);

        fseek(w, 14, SEEK_SET);
        fwrite(&Picture.Size, sizeof(Picture.Size), 1, w);
        fwrite(&Picture.Width, sizeof(Picture.Width), 1, w);
        fwrite(&Picture.Height, sizeof(Picture.Height), 1, w);
        fwrite(&Picture.Planes, sizeof(Picture.Planes), 1, w);
        fwrite(&Picture.BitCount, sizeof(Picture.BitCount), 1, w);
        fwrite(&Picture.Compression, sizeof(Picture.Compression), 1, w);
        fwrite(&Picture.SizeImage, sizeof(Picture.SizeImage), 1, w);
        fwrite(&Picture.XPelsPerMeter, sizeof(Picture.XPelsPerMeter), 1, w);
        fwrite(&Picture.YPelsPerMeter, sizeof(Picture.YPelsPerMeter), 1, w);
        fwrite(&Picture.ClrUsed, sizeof(Picture.ClrUsed), 1, w);
        fwrite(&Picture.ClrImportant, sizeof(Picture.ClrImportant), 1, w);

        fseek(w, sizeof(File.OffBits), SEEK_SET);

        int bmpImg;
        for (int i = File.OffBits; i < File.Size; i++)
        {
            fseek(f, i, SEEK_SET);
            fseek(w, i, SEEK_SET);
            fread(&bmpImg, 3, 1, f);
            bmpImg = INT_MAX - bmpImg; 
            fwrite(&bmpImg, 3, 1, w);

            
        }
        cout<<endl;
        cout<<"proces przebiegł pomyślnie"<<endl;
       
    }
    fclose(f);
    fclose(w);

    }
}


int main(int arc, char * argv[]) {


    info();
    negatyw();
    return 0;
}
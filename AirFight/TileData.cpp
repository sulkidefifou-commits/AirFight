#include "TileData.h"


void TileData::AnalyseOctet(uint8_t* octetPtr)
{

    for (int position = 6; position >= 0; position -= TwoBitPerBit)
    {
        
        uint8_t currentPixel = (*octetPtr >> position) & 0b11;

        if (currentPixel == maskWhitePixel)
        {
      
            cout << char(176) << char(176);

        }
        else if (currentPixel == maskGrayPixel)
        {
    
            cout << char(177) << char(177);

        }
        else if (currentPixel == maskDarkPixel)
        {
 
            cout << char(178) << char(178);

        }
        else if (currentPixel == maskBlackPixel)
        {
       
            cout << char(219) << char(219);
        }

        compteur++;
    }

    if (compteur % 8 == 0)
    {
        cout << endl;
    }

    if (octetNumber < DataSize)
    {
        octetNumber++;

        octetPtr++;

        AnalyseOctet(octetPtr);
    }
    else
    {
        compteur = 0;
        octetNumber = 1;
    }
    
}


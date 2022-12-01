#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void SoruSec(int sayi)
{

    char soruSayisi[12];
    snprintf(soruSayisi, 12, "soru_%d.txt", sayi);

    FILE *dosya = fopen(soruSayisi, "r");

    while (!feof(dosya))
    {
        putchar(fgetc(dosya));
    }

    fclose(dosya);
}

int Rand()
{

    int sayi;

    srand(time(NULL));

    sayi = rand() % 7;

    return sayi;
}

char Cevap(int sayi)
{

    char cevaplar[] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};

    return cevaplar[sayi];
}

int kontrolDizi[10];

bool kontrol(int sayi, int cikacakSoru)
{

    for (int i = 0; i < 10; i++)
    {
        if (kontrolDizi[i] == sayi)
        {
            return false;
        }
    }
    kontrolDizi[cikacakSoru] = sayi;

    for (int i = 0; i < 10; i++)
    {
        printf("dizinin elemani %d\n", kontrolDizi[i]);
    }
    return true;
}

int main()
{
    int cikacakSoru = 0;
    char cevap;
    char kullaniciCevap;
    int soruSayi;

    printf("Kim Milyoner Olmak Ister'e hos geldiniz.\n");
    printf("Yarismamiz 5 sorudan olusmaktadir.\n");
    printf("Ilk soru baraj sorusudur sonra bilemediginiz sorulardan q yazarak ayrilma hakkiniz bulunmaktadir.\n");

    soruSayi = Rand();
    printf("sayi %d\n", soruSayi);
    kontrol(soruSayi, cikacakSoru);
    SoruSec(soruSayi);
    cevap = Cevap(soruSayi);

    do
    {
        printf("\n");
        printf("cevabiniz: ");
        scanf("%s", &kullaniciCevap);

        cikacakSoru += 1;
        if (cevap == kullaniciCevap)
        {
            printf("dogru cevap\n");
            soruSayi = Rand();
            printf("cikacak soru %d\n", cikacakSoru);
            while (!kontrol(soruSayi, cikacakSoru))
            {
                soruSayi = Rand();
            }
            SoruSec(soruSayi);
            cevap = Cevap(soruSayi);
        }
        else if (kullaniciCevap == 'q')
        {
            printf("cekilme basarili");
            break;
        }

        else
        {
            printf("yanlis cevap");
            break;
        }

    } while (cikacakSoru < 8);

    return 0;
}
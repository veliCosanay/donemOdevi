#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

void selectQuestion(int number)
{

    char questionText[20];
    snprintf(questionText, 20, "sorular/soru_%d.txt", number);

    FILE *dosya = fopen(questionText, "r");

    while (!feof(dosya))
    {
        putchar(fgetc(dosya));
    }

    fclose(dosya);
}

int random()
{

    int number;

    srand(time(NULL));

    number = rand() % 51;

    return number;
}

char correntAnswer(int number)
{

    char answers[] = {'C', 'D', 'B', 'D', 'B', 'D', 'D', 'A', 'B', 'B',
                      'C', 'A', 'C', 'B', 'C', 'B', 'D', 'A', 'C', 'D',
                      'B', 'B', 'C', 'D', 'D', 'C', 'B', 'C', 'D', 'A',
                      'B', 'A', 'B', 'D', 'B', 'C', 'A', 'B', 'D', 'D',
                      'D', 'B', 'B', 'C', 'D', 'B', 'A', 'C', 'A', 'C'};

    return answers[number - 1];
}

int controlArray[10];

bool controlAnswers(int number, int numberOfQuestion)
{

    for (int i = 0; i < 10; i++)
    {
        if (controlArray[i] == number)
        {
            return false;
        }
    }
    controlArray[numberOfQuestion] = number;

    return true;
}

int main()
{
    int numberOfQuestion = 0;
    char correctAnswer;
    char userAnswer;
    int randomNumber;

    printf("*******Kim Milyoner Olmak Ister'e hos geldiniz.*******\n");
    Sleep(1000);
    printf("Yarismamiz 10 sorudan olusmaktadir.\n");
    Sleep(1000);
    printf("Istediginiz soruda q yazarak sorudan cekilme hakkiniz bulunmaktadir.\n\n");
    Sleep(1000);
    printf("*******1. SORU*******\n");
    Sleep(1000);

    randomNumber = random();
    controlAnswers(randomNumber, numberOfQuestion);
    selectQuestion(randomNumber);
    correctAnswer = correntAnswer(randomNumber);

    do
    {
        printf("\n");
        // Sleep(1000);
        printf("Cevabiniz: ");
        scanf("%s", &userAnswer);
        userAnswer = toupper(userAnswer);

        numberOfQuestion += 1;
        if (correctAnswer == userAnswer)
        {
            Sleep(1000);
            printf("Tebrikler ! Dogru Cevap\n");
            Sleep(1000);
            system("cls");

            if (numberOfQuestion == 9)
            {
                printf("Son soruya ulastiniz\n");
                Sleep(1000);
            }
            else if (numberOfQuestion == 10)
            {
                printf("Yarismayi kazanip buyuk odul olan 1.000.000TL'yi kazandiniz tebrikler!");
                break;
            }

            randomNumber = random();
            if (numberOfQuestion != 10)
            {
                printf("*******%d. SORU*******\n", numberOfQuestion + 1);
                Sleep(1000);
            }
            while (!controlAnswers(randomNumber, numberOfQuestion))
            {
                randomNumber = random();
            }
            selectQuestion(randomNumber);
            correctAnswer = correntAnswer(randomNumber);
        }
        else if (userAnswer == 'Q')
        {
            Sleep(1000);
            printf("Yarismadan cekildiniz.");
            printf("%d tl kazandiniz. Sonraki yarismada basarilar", (numberOfQuestion - 1) * 1000);
            break;
        }
        else
        {
            Sleep(1000);
            printf("Yanlis cevap ! Elendiniz.Dogru cevap: %c", correctAnswer);
            Sleep(3000);
            system("cls");
            break;
        }

    } while (numberOfQuestion < 10);

    return 0;
}
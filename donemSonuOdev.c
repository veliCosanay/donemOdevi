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

    FILE *file = fopen(questionText, "r");

    while (!feof(file))
    {
        putchar(fgetc(file));
    }

    fclose(file);
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
                      'B', 'B', 'C', 'D', 'C', 'C', 'B', 'C', 'D', 'A',
                      'B', 'A', 'B', 'D', 'B', 'C', 'A', 'B', 'D', 'D',
                      'D', 'B', 'B', 'C', 'D', 'B', 'A', 'C', 'A', 'C'};

    return answers[number - 1];
}

int controlArray[12];
bool controlAnswers(int number, int numberOfQuestion)
{

    for (int i = 0; i < 12; i++)
    {
        if (controlArray[i] == number)
        {
            return false;
        }
    }
    controlArray[numberOfQuestion] = number;

    return true;
}

char userAnswerOptions[5] = {'A', 'B', 'C', 'D', 'Q'};
bool answerOptions(char userAnswer)
{
    for (int i = 0; i < 5; i++)
    {
        if (userAnswer == userAnswerOptions[i])
        {
            return true;
        }
    }
    return false;
}

int moneyArray[13] = {1000, 2000, 3000, 5000, 7500, 10000, 30000, 50000, 100000, 200000, 400000, 1000000};
int main()
{
    char correctAnswer;
    char userAnswer;
    int numberOfQuestion = 0;
    int randomNumber;

    system("cls");

    printf("*******Kim Milyoner Olmak Ister'e hos geldiniz.*******\n");
    Sleep(1000);
    printf("Yarismamiz 12 sorudan olusmaktadir.\n");
    Sleep(1000);
    printf("Ilk soru baraj sorusudur. Daha sonraki sorularda q yazarak yarismadan ayrilma hakkiniz bulunmaktadir.\n\n");
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
        printf("Cevabiniz: ");
        scanf("%s", &userAnswer);
        userAnswer = toupper(userAnswer);

        numberOfQuestion += 1;

        if (answerOptions(userAnswer))
        {
            if (correctAnswer == userAnswer)
            {
                Sleep(1000);
                printf("Tebrikler ! Dogru Cevap\n");
                Sleep(1000);
                system("cls");

                if (numberOfQuestion == 11)
                {
                    printf("Son soruya ulastiniz\n");
                    Sleep(1000);
                }
                else if (numberOfQuestion == 12)
                {
                    printf("Yarismayi kazanip buyuk odul olan 1.000.000TL'yi kazandiniz tebrikler!");
                    break;
                }

                randomNumber = random();
                if (numberOfQuestion != 12)
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
                if (numberOfQuestion == 1)
                {
                    printf("Ilk sorudan ayrilamazsiniz!");
                    numberOfQuestion -= 1;
                    continue;
                }
                else
                {
                    Sleep(1000);
                    printf("Yarismadan cekildiniz.");
                    printf("%d tl kazandiniz. Sonraki yarismada basarilar", moneyArray[numberOfQuestion - 2]);
                    break;
                }
            }
            else
            {
                Sleep(1000);
                printf("Yanlis cevap ! Sorunun dogru cevabi: %c\n", correctAnswer);
                printf("Ne yazik ki yarismamiza veda ediyorsunuz.\n");
                if (numberOfQuestion == 1)
                {
                    printf("Baraj sorusunu bilemediginiz icin para odulu kazanamadiniz.");
                }
                else
                {
                    printf("Kazandiginiz odul: %d tl", moneyArray[0]);
                }

                Sleep(3000);
                system("cls");
                break;
            }
        }
        else
        {
            printf("Lutfen gecerli siklardan birini giriniz!");
            numberOfQuestion -= 1;
            continue;
        }
    } while (numberOfQuestion < 12);

    return 0;
}
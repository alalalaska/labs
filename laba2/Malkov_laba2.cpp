#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");


    /// ���������� �������

    cout << "���������� �������" << endl;
    cout << endl;

    /// 1
    cout << "������� 1:" << endl;
    int massiv[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "������: [";
    for(int i = 0; i < 10; i++)
    {
        cout << massiv[i] << " ";
    }
    cout << "]";


    cout << endl;
    cout << endl;


    /// 2
    cout << "������� 2:" << endl;
    int massiv1[10];

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        massiv1[i] = rand() % 21 - 10;
    }

    cout << "������: [";
    for (int i = 0; i < 10; i++) {
        cout << massiv1[i] << " ";
    }
    cout << "]";


    cout << endl;
    cout << endl;


    /// 3
    cout << "������� 3:" << endl;
    int massiv2[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "������� ������� ������� " << i+1 << ": ";
        cin >> massiv2[i];
    }

    cout << "������: [ ";
    for (int i = 0; i < 5; i++)
        cout << massiv2[i] << " ";
    cout << "]" << endl;


    cout << endl;
    cout << endl;



    /// 4
    cout << "������� 4:" << endl;
    int massiv3[10];

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        massiv3[i] = rand() % 21 - 10;
    }

    cout << "�������� ������: [";
    for (int i = 0; i < 10; i++) {
        cout << massiv3[i] << " ";
    }
    cout << "]" << endl;


    for (int i = 0; i < 10; i++)
    {
        if (massiv3[i]%2 == 0)
            massiv3[i] *= 3;
        else
            massiv3[i] *= 5;
    }


    cout << "��������������� ������: [";
    for (int i = 0; i < 10; i++)
        cout << massiv3[i] << " ";
    cout << "]" << endl;


    cout << endl;
    cout << endl;



    /// ��������� ������

    cout << "��������� �������" << endl;
    cout << endl;

    /// 1
    cout << "�������� ������:" << endl;
    int massiv4[5][5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            massiv4[i][j] = rand()%21 - 10;
        }
    }

     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massiv4[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;


    cout << "����� ��������� � ������ ������:" << endl;

    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += massiv4[i][j];
        }
        cout << "������ " << i + 1 << ": " << sum << endl;
    }


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(massiv4[i][j] < 0)
                massiv4[i][j] = 0;
        }
    }

    cout << endl;

    cout << "��������������� ������:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massiv4[i][j] << "\t";
        }
        cout << endl;
    }


    return 0;
}




#include <iostream>

using namespace std;

int main()
{
    int num;
    setlocale(LC_ALL, "Russian");
    wcout << "������� �������������� �����" << endl;
    cin >> num;
    for (int i = 0; i <= 50; i++) // ����� i <= 50 ���� �� �������� ��� ��� �����, � ������ ������ 50
        cout <<i<<endl;


    cout << "׸���� �� ����:"<<endl;
    for (int i = 0; i <= 50;)
    {
        while(i <= 50)
        {
            if (i%2==0)
                cout << i <<endl;
            i++;
        }
    }


    cout << "���� ����������" << endl;
    for (int i = 0; i < num; i++)
    {
        if (i%1000 == 0)
            {
            cout << i;
            cout << " ���" << endl;
            }
    }

    return 0;
}



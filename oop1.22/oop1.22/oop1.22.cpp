#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

#define MAX 20

class StudGroup
{
private:
    char Surname[MAX][20];
    char Name[MAX][20];
    int Birthday[MAX][3];
    long long PhoneNum[MAX];

public:
    void Find(char* FindName);    // Поиск записи о студенте по фамилии 
    void GetInfo(int ID);    // Вывод записи о студенте. 
    void Create();        // Создание новой запись о студенте.
    StudGroup();
};
StudGroup::StudGroup()
{
    for (int i = 0; i < MAX; i++)
    {
        Name[i][0] = '\0';
        Surname[i][0] = '\0';
        Birthday[i][0] = 0;
        Birthday[i][1] = 0;
        Birthday[i][2] = 0;
        PhoneNum[i] = 0;
    }
}
void StudGroup::Create()
{
    int i = 0;
    for (; i < MAX; i++)
    {
        if (Name[i][0] == '\0')
        {
            cout<<"Фамилия ";
            cin >> Surname[i];
            cout << "Имя ";
            cin>> Name[i];
            cout<<"Дата рождения <День Месяц Год> : "<<endl;
            cin >> Birthday[i][0];
            cin >> Birthday[i][1];
            cin>> Birthday[i][2];
            cout<<"Телефон: ";
            cin>>PhoneNum[i];
            return;
        }
    }
    if (i == MAX) cout<<"Место в группе закончилось."<<endl;
}
void StudGroup::Find(char* FindName)
{
    bool inf = 0;
        for (int i = 0; i < MAX; i++)
        {
            if (strcmp(FindName, Surname[i]) == 0)
            {
                GetInfo(i);
                inf = 1;
            }
        }
    if (inf == 0) cout<<"Совпадений не найдено"<<endl;
}
void StudGroup::GetInfo(int ID)
{
        cout<<"Найдено совпадение"<<endl;
        cout << "Фамилия Имя " << Surname[ID] << " " << Name[ID] << endl;
        cout<<"Дата рождения: "<< Birthday[ID][0]<<"." << Birthday[ID][1]<<"." << Birthday[ID][2] << endl;
        cout << "Тел: " << PhoneNum[ID] << endl;
        cout << "=================================================="<<endl;

}
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    StudGroup Group1;

    int s = 0;
    char FindName[20];


    while (1)
    {
        cout << "1-добавить студента 2-поиск по фамилий "<<endl;
        cout<<"Введите номер пункта меню >: ";
        cin >> s;
        switch (s)
        {

        case 1: Group1.Create(); break;

        case 2: printf("Введите фамилию: ");
           cin>>FindName;
                cout<<endl;
            Group1.Find(FindName); 
            break;
        
        }
    }
}

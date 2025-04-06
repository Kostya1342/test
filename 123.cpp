
#include <iostream>
#include <limits>
using namespace std;
const int MaxSong = 100;
struct Song {
    char Name[30];
    char Author[20];
    char TextSong[100];
    int relize;
};
struct Songs {
    Song list[MaxSong];
    int count = 0;
};
void addText(Song& song) {
    cout << "Заполните текст песни -> " << endl;
    cin.getline(song.TextSong, 100);
}
void addSongWithList(Songs& songs, Song& song) {// добавление песни в альбом
    if (songs.count > 100)
    {
        return;
    }
    songs.list[songs.count] = song;
    songs.count++;
}
void addTextFile(Song& song) {
    //filestpream чето там
}
void initializationSong(Songs& songs, Song& song, bool checkTextFile) {//инициализация песни и добавление в альбом
    cout << "Заполните данные о песне: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Заполните название -> " << endl;
    cin.getline(song.Name, 30);
    cout << "Заполните автора -> " << endl;
    cin.getline(song.Author, 20);
    if (checkTextFile)
    {
        addTextFile(song);
    }
    else
    {
        addText(song);
    }
    cout << "Заполните год выпуска -> " << endl;
    cin >> song.relize;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    addSongWithList(songs, song);

}
void catalogSong(Songs songs) {//просмотр имен песен в альбоме
    cout << "Cборник песен содержит (названия): " << endl;
    for (int i = 0; i < songs.count; i++) {
        cout << i << ". - " << songs.list[i].Name << endl;
    }
}
void removeText(Songs& songs, const char* nameSongToRemove) {
    for (int i = 0; i < songs.count; i++) {
        if (strcmp(songs.list[i].Name, nameSongToRemove) == 0) {
            songs.list[i].TextSong[0] = '\0';
            break;
        }
    }
}
void updateText(Songs& songs, char* nameSongToUpdate) {// добавление нового текста в песню
    char a[100];
    for (int i = 0; i < songs.count; i++)
    {
        if (strcmp(songs.list[i].Name, nameSongToUpdate) == 0)
        {
            cout << "Введите новый текст песни -> : \n";
            cin.getline(a, 100);
            strncpy_s(songs.list[i].TextSong, a, 100);
            break;
        }
    }
}
void printText(Songs songs, char* nameSongToPrint) {// просмотр текста в песне
    for (int i = 0; i < songs.count; i++)
    {
        if (strcmp(songs.list[i].Name, nameSongToPrint) == 0)
        {
            cout << "Текст песни -> \n";
            cout << songs.list[i].TextSong << endl;
            break;
        }
    }

}
void saveText(Songs songs, char* nameSongToSave) {
    for (int i = 0; i < songs.count; i++)
    {
        if (strcmp(songs.list[i].Name, nameSongToSave) == 0)
        {
            //filestream чето там
        }
    }

}
void findAllSongWithAutor(Songs songs, char* author) {// поиск песен по автору
    int j = 1;
    cout << "Все песни автора ->  " << author << " :" << endl;
    for (int i = 0; i < songs.count; i++)
    {
        if (strcmp(songs.list[i].Author, author) == 0)
        {
            cout << j << " " << songs.list[i].Name << endl;
            j++;
        }
    }
}
void findAllSongWithWord(Songs songs, char* word) {// поиск песен по слову
    char str[100];
    char* context;
    char* token;
    int y = 1;
    cout << "Названия песен содержащих слово -> " << word << endl;
    for (int i = 0; i < songs.count; i++)
    {
        strncpy_s(str, songs.list[i].TextSong, 100);

        token = strtok_s(str, " ,-;.?!", &context);

        while (token) {
            //std::cout << token << std::endl;
            if (strcmp(token, word) == 0) {
                cout << y << ". " << songs.list[i].Name << endl;
                break;
            }
            token = strtok_s(nullptr, " ,-;.?!", &context);
        }
    }

}
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Каталог песен: " << endl;
    bool exit = false;
    bool newsong;
    bool fileread;
    int choice;
    char nameSongToDelete[30];
    char nameSongToUpdate[30];
    char nameSongToPrint[30];
    char nameSongToSave[30];
    char nameAuthor[30];
    char word[15];
    Songs songList;
    Song song;
    do {
        cout << "\tФункционал: " << endl;
        cout << "1. Добавление текста песни(через файл(не работает) или ввод с клавиатуры): " << endl;
        cout << "2. Удаление текста песни: " << endl;
        cout << "3. Изменение текста песни: " << endl;
        cout << "4. Отображение текста песни на экран: " << endl;
        cout << "5. Сохранение текста песни в файл(Не работает): " << endl;
        cout << "6. Поиск и отображение всех песен одного автора: " << endl;
        cout << "7. Поиск и отображение всех песен, содержащих слово, указанное пользователем: " << endl;
        cout << "Введите номер -> ";
        cin >> choice;
        cout << "<------------------------------------------------------------------------------------------->" << endl;
        switch (choice)
        {
        case 1:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Добавить новую песню?\n(1 - да\n0 - нет)" << endl;
            cin >> newsong;
            if (newsong) {
                cout << "Загрузить текст из файла?\n(1 - да\n0 - нет)" << endl;
                cin >> fileread;
                if (fileread) {
                    initializationSong(songList, song, true);
                }
                else {
                    cout << "Введите данные вручную" << endl;
                    initializationSong(songList, song, false);
                }
            }
            else {
                //не придумал
            }
            break;
        case 2:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите название песни для удаления текста в ней -> : " << endl;
            cin.getline(nameSongToDelete, 30);
            removeText(songList, nameSongToDelete);
            break;
        case 3:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите название песни для изменения текста песни -> : " << endl;
            cin.getline(nameSongToUpdate, 30);
            updateText(songList, nameSongToUpdate);
            break;
        case 4:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите название песни для отображения текста песни на экран -> : " << endl;
            cin.getline(nameSongToPrint, 30);
            printText(songList, nameSongToPrint);
            break;
        case 5:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите название песни для сохранения текста песни в файл -> : " << endl;
            cin.getline(nameSongToSave, 30);
            saveText(songList, nameSongToSave);
            break;
        case 6:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Поиск и отображение всех песен одного автора: " << endl;
            cout << "Введите автора -> : " << endl;
            cin.getline(nameAuthor, 30);
            findAllSongWithAutor(songList, nameAuthor);
            break;
        case 7:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Поиск и отображение всех песен, содержащих слово, указанное пользователем -> : " << endl;
            cout << "Введите слово -> : " << endl;
            cin.getline(word, 15);
            findAllSongWithWord(songList, word);
            break;
        default:
            cout << "Номер не верный" << endl;
            break;
        }
        cout << "<------------------------------------------------------------------------------------------->" << endl;
        cout << "Выйти из программы или начать заного?\n(1 - Выйти из программы\n0 - продолжить работу с приложением)" << endl;
        cin >> exit;
    } while (exit != true);

    /*
    * Создайте приложение «Каталог текстов песен».
    Приложение должно иметь следующие возможности:
    ■ Добавление текста песни:
    • Текст песни:
    может быть введен с клавиатуры;
    загружен из файла.
    • Для каждой песни нужно указывать название песни, автора текста и
    год создания песни (если он известен).
    ■ Удаление текста песни.
    ■ Изменение текста песни.
    ■ Отображение текста песни на экран.
    ■ Сохранение текста песни в файл.
    ■ Поиск и отображение всех песен одного автора.
    ■ Поиск и отображение всех песен, содержащих слово, указанное пользователем.
    */
}

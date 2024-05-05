// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "music.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukr");
    vector<Music> musics;
    string filename = "musics.txt";

    while (true) {
        cout << "1. Додати музику\n"
            << "2. Видалити музику\n"
            << "3. Редагувати музику\n"
            << "4. Сортувати музику за назвою\n"
            << "5. Сортувати музику за ціною\n"
            << "6. Пошук музики за назвою\n"
            << "7. Пошук музики за артистом\n"
            << "8. Зберегти музику в файл\n"
            << "9. Завантажити музику з файлу\n"
            << "10. Вийти\n"
            << "Виберіть опцію: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addMusic(musics);
            break;
        case 2:
            removeMusic(musics);
            break;
        case 3:
            editMusic(musics);
            break;
        case 4:
            sortMusicsByName(musics);
            break;
        case 5:
            sortMusicsByPrice(musics);
            break;
        case 6:
            searchMusicByName(musics);
            break;
        case 7:
            searchMusicByArtist(musics);
            break;
        case 8:
            saveMusicsToFile(musics, filename);
            break;
        case 9:
            loadMusicsFromFile(musics, filename);
            break;
        case 10:
            return 0;
        default:
            cout << "Невірний вибір\n";
        }
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "music.h"

void addMusic(vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    Music music;
    cout << "Введіть назву музики: ";
    cin.ignore();
    getline(cin, music.title);
    cout << "Введіть ім'я артиста: ";
    getline(cin, music.artist);
    cout << "Введіть жанр музики: ";
    getline(cin, music.genre);
    cout << "Введіть ціну: ";
    cin >> music.price;
    musics.push_back(music);
}

void removeMusic(vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    string title, artist;
    cout << "Введіть назву музики для видалення: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "Введіть артиста для видалення: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, artist);
    musics.erase(remove_if(musics.begin(), musics.end(),
        [&title, &artist](const Music& music) {
            return music.title == title && music.artist == artist;
            
        }),
        
        musics.end());
    
}

void editMusic(vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    string title;
    cout << "Введіть назву музики для редагування: ";
    cin.ignore();
    getline(cin, title);
    for (auto& music : musics) {
        if (music.title == title) {
            cout << "Введіть нову назву: ";
            getline(cin, music.title);
            cout << "Введіть нове ім'я артиста: ";
            getline(cin, music.artist);
            cout << "Введіть новий жанр: ";
            getline(cin, music.genre);
            cout << "Введіть нову ціну: ";
            cin >> music.price;
            return;
        }
    }
    cout << "Музика не знайдена\n";
}

void sortMusicsByName(vector<Music>& musics) {
    sort(musics.begin(), musics.end(),
        [](const Music& a, const Music& b) {
            return a.title < b.title;
        });
}

void sortMusicsByPrice(vector<Music>& musics) {
    sort(musics.begin(), musics.end(),
        [](const Music& a, const Music& b) {
            return a.price < b.price;
        });
}

void searchMusicByName(const vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    string title;
    cout << "Введіть назву музики для пошуку: ";
    cin.ignore();
    getline(cin, title);
    for (const auto& music : musics) {
        if (music.title == title) {
            cout << "Музика знайдена\n";
            cout << "Назва: " << music.title << "\n";
            cout << "Артист: " << music.artist << "\n";
            cout << "Жанр: " << music.genre << "\n";
            cout << "Ціна: " << music.price << "\n";
            return;
        }
    }
    cout << "Музика не знайдена\n";
}

void searchMusicByArtist(const vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    string artist;
    cout << "Введіть ім'я артиста для пошуку: ";
    cin.ignore();
    getline(cin, artist);
    for (const auto& music : musics) {
        if (music.artist == artist) {
            cout << "Музика знайдена\n";
            cout << "Назва: " << music.title << "\n";
            cout << "Артист: " << music.artist << "\n";
            cout << "Жанр: " << music.genre << "\n";
            cout << "Ціна: " << music.price << "\n";
        }
    }
    cout << "Артист не знайдений\n";
}

void saveMusicsToFile(const vector<Music>& musics, const string& filename) {
    setlocale(LC_ALL, "Ukr");
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& music : musics) {
            file << music.title << ",";
            file << music.artist << ",";
            file << music.genre << ",";
            file << music.price << "\n";
        }
        file.close();
        cout << "Музика збережена у файл\n";
    }
    else {
        cout << "Не вдалося відкрити файл для збереження\n";
    }
}

void loadMusicsFromFile(vector<Music>& musics, const string& filename) {
    setlocale(LC_ALL, "Ukr");
    musics.clear();
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            Music music;
            string title, artist, genre;
            double price;
            getline(iss, title, ',');
            getline(iss, artist, ',');
            getline(iss, genre, ',');
            iss >> price;
            music.title = title;
            music.artist = artist;
            music.genre = genre;
            music.price = price;
            musics.push_back(music);
        }
        file.close();
        cout << "Музика завантажена з файлу\n";
    }
    else {
        cout << "Не вдалося відкрити файл для завантаження\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

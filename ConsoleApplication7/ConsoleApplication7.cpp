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
        cout << "1. ������ ������\n"
            << "2. �������� ������\n"
            << "3. ���������� ������\n"
            << "4. ��������� ������ �� ������\n"
            << "5. ��������� ������ �� �����\n"
            << "6. ����� ������ �� ������\n"
            << "7. ����� ������ �� ��������\n"
            << "8. �������� ������ � ����\n"
            << "9. ����������� ������ � �����\n"
            << "10. �����\n"
            << "������� �����: ";

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
            cout << "������� ����\n";
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
    cout << "������ ����� ������: ";
    cin.ignore();
    getline(cin, music.title);
    cout << "������ ��'� �������: ";
    getline(cin, music.artist);
    cout << "������ ���� ������: ";
    getline(cin, music.genre);
    cout << "������ ����: ";
    cin >> music.price;
    musics.push_back(music);
}

void removeMusic(vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    string title, artist;
    cout << "������ ����� ������ ��� ���������: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "������ ������� ��� ���������: ";
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
    cout << "������ ����� ������ ��� �����������: ";
    cin.ignore();
    getline(cin, title);
    for (auto& music : musics) {
        if (music.title == title) {
            cout << "������ ���� �����: ";
            getline(cin, music.title);
            cout << "������ ���� ��'� �������: ";
            getline(cin, music.artist);
            cout << "������ ����� ����: ";
            getline(cin, music.genre);
            cout << "������ ���� ����: ";
            cin >> music.price;
            return;
        }
    }
    cout << "������ �� ��������\n";
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
    cout << "������ ����� ������ ��� ������: ";
    cin.ignore();
    getline(cin, title);
    for (const auto& music : musics) {
        if (music.title == title) {
            cout << "������ ��������\n";
            cout << "�����: " << music.title << "\n";
            cout << "������: " << music.artist << "\n";
            cout << "����: " << music.genre << "\n";
            cout << "ֳ��: " << music.price << "\n";
            return;
        }
    }
    cout << "������ �� ��������\n";
}

void searchMusicByArtist(const vector<Music>& musics) {
    setlocale(LC_ALL, "Ukr");
    string artist;
    cout << "������ ��'� ������� ��� ������: ";
    cin.ignore();
    getline(cin, artist);
    for (const auto& music : musics) {
        if (music.artist == artist) {
            cout << "������ ��������\n";
            cout << "�����: " << music.title << "\n";
            cout << "������: " << music.artist << "\n";
            cout << "����: " << music.genre << "\n";
            cout << "ֳ��: " << music.price << "\n";
        }
    }
    cout << "������ �� ���������\n";
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
        cout << "������ ��������� � ����\n";
    }
    else {
        cout << "�� ������� ������� ���� ��� ����������\n";
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
        cout << "������ ����������� � �����\n";
    }
    else {
        cout << "�� ������� ������� ���� ��� ������������\n";
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

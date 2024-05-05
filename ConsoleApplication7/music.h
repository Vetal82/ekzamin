#pragma once
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Music {
    string title;
    string artist;
    string genre;
    double price;
};

void addMusic(vector<Music>&);          //Ця функція призначена для додавання нового об'єкта
void removeMusic(vector<Music>&);       // Ця функція призначена для видалення об'єкта 
void editMusic(vector<Music>&);         //Ця функція призначена для редагування існуючого об'єкта 
void sortMusicsByName(vector<Music>&);  //Ця функція призначена для сортування об'єктів
void sortMusicsByPrice(vector<Music>&); //Ця функція призначена для сортування об'єктів
void searchMusicByName(const vector<Music>&);    //Ця функція призначена для пошуку об'єктів
void searchMusicByArtist(const vector<Music>&); //Ця функція призначена для пошуку об'єктів 
void saveMusicsToFile(const vector<Music>&, const string&); //Ця функція призначена для збереження об'єктів
void loadMusicsFromFile(vector<Music>&, const string&); //Ця функція призначена для завантаження об'єктів

#endif  MUSIC_H
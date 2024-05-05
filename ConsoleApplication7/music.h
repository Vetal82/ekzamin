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

void addMusic(vector<Music>&);          //�� ������� ���������� ��� ��������� ������ ��'����
void removeMusic(vector<Music>&);       // �� ������� ���������� ��� ��������� ��'���� 
void editMusic(vector<Music>&);         //�� ������� ���������� ��� ����������� ��������� ��'���� 
void sortMusicsByName(vector<Music>&);  //�� ������� ���������� ��� ���������� ��'����
void sortMusicsByPrice(vector<Music>&); //�� ������� ���������� ��� ���������� ��'����
void searchMusicByName(const vector<Music>&);    //�� ������� ���������� ��� ������ ��'����
void searchMusicByArtist(const vector<Music>&); //�� ������� ���������� ��� ������ ��'���� 
void saveMusicsToFile(const vector<Music>&, const string&); //�� ������� ���������� ��� ���������� ��'����
void loadMusicsFromFile(vector<Music>&, const string&); //�� ������� ���������� ��� ������������ ��'����

#endif  MUSIC_H
//
//  main.cpp
//  exam
//
//  Created by Danial on 11/12/18.
//  Copyright © 2018 Danial. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <time.h>
#include <fstream>
using namespace std;

struct Group
{
    Group() {
        name = "null";
        preferences = "null";
    }
    Group(string c_name, string c_preferences) {
        name = c_name;
        preferences = c_preferences;
    }
    string get_name() const {
        return name;
    }
private:
    string name;
    string preferences;
};
//#######################################################################
struct Date {
    Date() {
        year = 1970;
        month = 1;
        day = 1;
    }
    Date(int c_year, int c_month = 1, int c_day = 1) {
        year = c_year;
        month = c_month;
        day = c_day;
    }
    int date_diff(Date& other_date) const {
        if ((other_date.year - this->year) == 0 )
            return 1;
        return other_date.year - year;
    }
    void show_date() const {
        cout << year << "/" << month << "/" << day << endl;
    }
private:
    int year;
    int month;
    int day;
};
//#######################################################################
class Songs
{
public:
    Songs() {
        popularity = 0;
        name = "null";
        genre = "null";
    }
    Songs(string c_name, string c_genre, Group c_group, Date c_date) {
        name = c_name;
        genre = c_genre;
        group = c_group;
        date = c_date;
    }
    bool operator<(const Songs& obj) const {
        return this->popularity > obj.popularity;
    }
    void set_populerity(Date& c_date) {
        popularity = 100;

        // random factor
        int score_random = rand() % 21;
        
        // time from presentation
        int date_score = 30;
        int score_time_from_presentation = date_score / date.date_diff(c_date);
        
        // popularity other songs of this group
        int score_other_songs_by_group = rand() % 11;
        
        // popularity other songs of this genre
        int score_other_songs_by_genre = rand() % 21;
        
        // similarity with previous genre
        int score_similarity_prev_genre = rand() % 21;
        
        popularity = score_random + score_time_from_presentation + score_other_songs_by_genre + score_other_songs_by_group + score_similarity_prev_genre;
    }
    void show_details() const {
        cout << "Song name   : " << name << endl;
        cout << "Release date: ";
        date.show_date();
        cout << "Genre       : " << genre << endl;
        cout << "Group       : " << group.get_name() << endl;
    }
    string get_song_name() const {
        return name;
    }
    string get_group_name() const {
        return group.get_name();
    }
    string get_genre_name() const {
        return genre;
    }
    int get_popularity() const {
        return popularity;
    }
private:
    int popularity;
    string name;
    string genre;
    Date date;
    Group group;
};
//#######################################################################

class Interface {
public:
    Interface() {
        cout << "Starting..." << endl;
        this->load_songs();
    }
    void menu() {
        bool try_more = false;
        do {
            try_more = false;
            cout << "1. Show all songs" << endl;
            cout << "2. Choose song for more details" << endl;
            cout << "3. Exit" << endl;
        
            char choice = '\0';
            cin >> choice;
        
            switch (choice) {
                case '1':
                    choose_songs_sort_type();
                    break;
                case '2':
                    show_details();
                    break;
                case '3':
                    say_goodbye();
                    break;
                default:
                    say_wrong();
                    try_more = true;
            }
        } while(try_more == true);
    }
    void choose_songs_sort_type() {
        cout << "Input year for checking the popularity: " << endl;
        int tmp_song_year;
        cin >> tmp_song_year;
        Date tmp_date(tmp_song_year);
        
        cout << "1. Among all songs" << endl;
        cout << "2. Among specified group" << endl;
        cout << "3. Among specified genre" << endl;
        
        char choice = '\0';
        cin >> choice;
        
        switch (choice) {
            case '1':
                show_all_songs(tmp_date);
                break;
            case '2':
            {
                cout << "Input name of group: " << endl;
                string tmp_group_name;
                //while(cin.get() != '\0');
                //getline(cin, tmp_group_name);
                cin >> tmp_group_name;
                show_by_group(tmp_date, tmp_group_name);
                break;
            }
            case '3':
            {
                cout << "Input name of genre: " << endl;
                string tmp_genre_name;
                //while(cin.get() != '\0');
                //getline(cin, tmp_genre_name);
                cin >> tmp_genre_name;
                show_by_genre(tmp_date, tmp_genre_name);
                break;
            }
            default:
                say_wrong();
        }
    }
    void show_details() {
        cout << "Enter the number of song to see more details: " << endl;
        int song_index;
        cin >> song_index;
        vec.at(song_index - 1).show_details();
    }
    
private:
    void say_goodbye() {
        cout << "Goodbye! :)" << endl;
        exit(0);
    }
    void say_wrong() {
        system("cls");
        cout << "Wrong input, try again... ";
    }
    void show_all_songs(Date& c_date) {
        set<Songs> st;
        for(auto i : vec) {
            i.set_populerity(c_date);
            st.insert(i);
        }
        
        int index = 1;
        for(auto i = st.begin(); i != st.end(); i++, index++) {
            cout << index << ". " << i->get_group_name() << " - " << i->get_song_name() << "   score: " << i->get_popularity() << endl;
        }
    }
    void show_by_group(Date& c_date, string group_name) {
        set<Songs> st;
        for(auto i : vec) {
            i.set_populerity(c_date);
            if (i.get_group_name() == group_name) {
                st.insert(i);
            }
        }
        int index = 1;
        for(auto i = st.begin(); i != st.end(); i++, index++) {
            cout << index << ". " << i->get_song_name() << "   score: " << i->get_popularity() << endl;
        }
    }
    void show_by_genre(Date& c_date, string genre_name) {
        set<Songs> st;
        for(auto i : vec) {
            i.set_populerity(c_date);
            if (i.get_genre_name() == genre_name) {
                st.insert(i);
            }
        }
        int index = 1;
        for(auto i = st.begin(); i != st.end(); i++, index++) {
            cout << index << ". " << i->get_song_name() << " - " << i->get_song_name() << "   score: " << i->get_popularity() << endl;
        }
    }
private:
    void load_songs() {
        ifstream file("/Users/danial/Desktop/exam/songs_list.txt");
        if (!file) {
            cout << "Wrong filename :(" << endl;
            exit(1);
        }
        
        string song_name;
        string song_genre;
        string group_name;
        string group_preferences;
        
        int year;
        int month;
        int day;
        
        string tmp_str;
        while (file >> tmp_str) {
            song_name = tmp_str;
            file >> song_genre >> group_name >> group_preferences >> year >> month >> day;
            
            Date tmp_date(year, month, day);
            Group tmp_group(group_name, group_preferences);
            Songs tmp_song(song_name, song_genre, tmp_group, tmp_date);
            vec.push_back(tmp_song);
        }
    }
    vector<Songs> vec;
};


int main(){
    srand(time(NULL));
    Interface run;
    run.menu();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>

#include <windows.h>

using namespace std;
using namespace boost::filesystem;

typedef std::vector<std::string> stringvec;

//custom data type for the song
struct Song{
    string title;
    string artist;
    string album;
    string year;
    string comment;
    string fileLocation;
};

class Album{
    private:
        string albumTitle;
        vector<Song> songs;
    public:
        Album(string title);
        ~Album();
        string getAlbumTitle();
        void addSong(Song song);
        vector<Song> getSongVector();
        int getArraySize();
};

class Artist{
    private:
        string artistName;
        vector<Album> albums;
    public:
        Artist(string name);
        ~Artist();
        string getArtistName();
        void addAlbum(Album newAlbum);
        vector<Album> getAlbums();
};

class Library{
    private:
        vector<Artist> artists;
    public:
        Library();
        ~Library();
        vector<Artist> getArtists();
        void addArtist(Artist art);
        int getArtistVectorSize();
};

Album::Album(string title){
    albumTitle = title;
}

Album::~Album(){
}

string Album::getAlbumTitle(){
    return albumTitle;
}

void Album::addSong(Song song){
    songs.push_back(song);
}

vector<Song> Album::getSongVector(){
    return songs;
}

int Album::getArraySize(){
    return songs.size();
}

Library::Library(){
}

Library::~Library(){
}

vector<Artist> Library::getArtists(){
    return artists;
}

void Library::addArtist(Artist art){
    artists.push_back(art);
}

int Library::getArtistVectorSize(){
    return artists.size();
}

Artist::Artist(string name){
    artistName = name;
}

Artist::~Artist(){
}

string Artist::getArtistName(){
    return artistName;
}

void Artist::addAlbum(Album newAlbum){
    albums.push_back(newAlbum);
}

vector<Album> Artist::getAlbums(){
    return albums;
}

//checks if file is a .mp3 file
bool checkIfMP3(string fileLocation){
    int fileNameLength = fileLocation.length() - 4;
    string fileType = fileLocation.substr(fileNameLength, 4);
    if(fileType == ".mp3"){
        return true;
    } else {
        return false;
    }
}

//reads from directory and adds all files to a vector if the file is a mp3 file
void read_directory(const std::string& name, stringvec& v)
{
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    string file_location;
    string file_location_explicit;
    string file_location_parent;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE){
        do {
            file_location = name + "\\" + data.cFileName;
            file_location_explicit = name + "\\.";
            file_location_parent = name + "\\..";

            path dir = file_location;

            if(is_directory(dir) && file_location == file_location_explicit){
            } else if(is_directory(dir) && file_location == file_location_parent){
            } else if(is_directory(dir)){
                read_directory(file_location, v);
            } else {
                if(checkIfMP3(file_location)){
                    v.push_back(file_location);
                }
            }
        }while(FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
};

//outputs file size in bites
int getFileSize(FILE *file){
    int loc = ftell(file);
    fseek(file,0,SEEK_END);
    int size = ftell(file);
    fseek(file,loc,SEEK_SET);
    return size;
};

//reads in blocks of 30 for artist album title and comments
string readInfo(FILE *file, int readLines){
    char len[30];
    fseek(file, readLines, SEEK_SET);
    fread(len, 1, 30, file);
    string result(len);
    return result;
}

//reads for the year that the song was made
string readYear(FILE *file, int readLines){
    char len[4];
    fseek(file, readLines, SEEK_SET);
    fread(len, 1, 4, file);
    string result(len);
    return result;
}

//reads information and puts it on the custom data type
void readFile(FILE* file, Song& song, string fileLocation){
    int readLocation = getFileSize(file)-125;
    song.title = readInfo(file, readLocation);
    readLocation = readLocation + 30;
    song.artist = readInfo(file, readLocation);
    readLocation = readLocation + 30;
    song.album = readInfo(file, readLocation);
    readLocation = readLocation + 30;

    string yearStringTemp = readYear(file, readLocation);
    string tempYear = yearStringTemp.c_str();
    string temp;
    for(int i=0; i<4; i++){
        temp += tempYear[i];
    }
    song.year = temp;

    readLocation = readLocation + 4;
    song.comment = readInfo(file, readLocation);

    song.fileLocation = fileLocation;
}

//adds all the files to the library in the song struct type
void addFilesToLibrary(string arrayOfFiles[], int size, vector<Song>& library){
    Song sam;
    int readingPoint;
    FILE *sample;
    for(int i=0; i<size; i++){
        sample = fopen(arrayOfFiles[i].c_str(), "r");
        readingPoint = getFileSize(sample);
        readFile(sample, sam, arrayOfFiles[i]);
        library.push_back(sam);
    }
}

void addSongsToAlbum(Song library[], int librarySize, Library& songLibrary){

}

void runThroughLibrary(Song library[], int librarySize, Library& songLibrary){
    Album temp("first album");

    temp.addSong(library[0]);
    temp.addSong(library[1]);
    temp.addSong(library[2]);

    int tempSize = temp.getArraySize();

    for(int i=0; i<temp.getArraySize(); i++){
        //cout << temp.getSongVector().at(i).fileLocation << endl;
    }

    Artist sampleArtist(library[0].artist);
    Album sampleAlbum(library[0].album);
    Song sampleSong = library[0];
    sampleAlbum.addSong(sampleSong);
    sampleArtist.addAlbum(sampleAlbum);
    songLibrary.addArtist(sampleArtist);
    cout << songLibrary.getArtists().at(0).getAlbums().at(0).getSongVector().at(0).fileLocation << endl;


    //use hashtables or map or multimap depending on what c++ calls it
}

int main()
{

    string library_location = "C:\\Users\\Carl\\Music";

    stringvec v;
    read_directory(library_location, v);

    string arrayOfFiles[v.size()];
    copy(v.begin(), v.end(), arrayOfFiles);

    vector<Song> libraryVector;
    addFilesToLibrary(arrayOfFiles, v.size(), libraryVector);
    Song library[libraryVector.size()];
    copy(libraryVector.begin(), libraryVector.end(), library);

    Library songLibrary;
    runThroughLibrary(library, libraryVector.size(), songLibrary);

    return 0;
}

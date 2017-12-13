/***************************************************************
 * Name:      Winters_GateMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Carl Dibert ()
 * Created:   2017-11-10
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#include "Winters_GateMain.h"
#include <wx/msgdlg.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/thread.h>
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdlib.h>
//(*InternalHeaders(Winters_GateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

using namespace std;
using namespace boost::filesystem;

typedef std::vector<std::string> stringvec;

string fileName;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif //wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Winters_GateDialog)
const long Winters_GateDialog::ID_LISTBOX2 = wxNewId();
const long Winters_GateDialog::ID_STATICTEXT1 = wxNewId();
const long Winters_GateDialog::ID_BUTTON2 = wxNewId();
const long Winters_GateDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Winters_GateDialog,wxDialog)
    //(*EventTable(Winters_GateDialog)
    //*)
END_EVENT_TABLE()

Winters_GateDialog::Winters_GateDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Winters_GateDialog)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Winter\'s Gate"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetMaxSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    LibraryListBox = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxSize(650,353), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    BoxSizer2->Add(LibraryListBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, wxEmptyString, wxDefaultPosition, wxSize(265,186), 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PauseButton = new wxButton(this, ID_BUTTON2, _("Pause"), wxDefaultPosition, wxSize(114,88), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    PauseButton->Hide();
    BoxSizer3->Add(PauseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StopButton = new wxButton(this, ID_BUTTON1, _("Stop"), wxDefaultPosition, wxSize(111,49), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StopButton->Hide();
    BoxSizer3->Add(StopButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();
    PopulateListBox();

    Connect(ID_LISTBOX2,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&Winters_GateDialog::OnLibraryListBoxSelect);
    Connect(ID_LISTBOX2,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&Winters_GateDialog::OnLibraryListBoxDClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Winters_GateDialog::PauseButtonOnClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Winters_GateDialog::StopButtonOnClick);
    //*)
}

Winters_GateDialog::~Winters_GateDialog()
{
    //(*Destroy(Winters_GateDialog)
    //*)
}

//action for the Pause Button
void Winters_GateDialog::PauseButtonOnClick(wxCommandEvent& event){
}

//action for the Stop Button
void Winters_GateDialog::StopButtonOnClick(wxCommandEvent& event){
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

//checks if file is a .WAV file
bool checkIfWAV(string fileLocation){
    int fileNameLength = fileLocation.length() - 4;
    string fileType = fileLocation.substr(fileNameLength, 4);
    if(fileType == ".wav"){
        return true;
    } else {
        return false;
    }
}

//reads from directory and adds all files to a vector if the file is a mp3 file
void read_directory(const std::string& name, stringvec& v){
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    string file_location;
    string file_location_explicit;
    string file_location_parent;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE){
        do {
            ostringstream convert;
            convert <<name <<"\\"<<data.cFileName;
            file_location = convert.str();
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
                } else if (checkIfWAV(file_location)){
                    v.push_back(file_location);
                }
            }
        }while(FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

//populates the library with all of the files
void Winters_GateDialog::PopulateListBox(){
    string library_location = "C:\\Users\\Carl\\Music";
    stringvec v;
    read_directory(library_location, v);

    int sizeOf = v.size();

    for(int i=0; i<sizeOf; i++){
        string stringStuff = v.at(i);
        const char* chars = stringStuff.c_str();
        wxString wxStringItem = wxString::FromUTF8(chars);
        LibraryListBox->Append(wxStringItem);
    }
}

//custom data type for the song
struct Song{
    string title;
    string artist;
    string album;
    string year;
    string comment;
    string fileLocation;
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

//adds the song info for the info title to the right on single click
void Winters_GateDialog::OnLibraryListBoxSelect(wxCommandEvent& event){

    string library_location = "C:\\Users\\Carl\\Music";
    stringvec v;
    read_directory(library_location, v);

    int posOfLibrary = LibraryListBox->GetSelection();
    string som = v.at(posOfLibrary);

    FILE* sample = fopen(som.c_str(), "r");
    Song song;
    readFile(sample, song, som);

    string songInfo = song.artist + "\n" + song.album + "\n" + song.title + "\n" + song.year;

    const char* chars = songInfo.c_str();
    wxString wxStringItem = wxString::FromUTF8(chars);
    StaticText1->SetLabel(wxStringItem);
}

//plays selected song
void playMusic (string fileLocation){

    const char* stuff = fileLocation.c_str();
    size_t size = strlen(stuff);
    wchar_t* arr = new wchar_t[size];
    for(size_t i=0; i<size; i++){
        arr[i] = stuff[i];
    }

    PlaySound(arr, NULL, SND_FILENAME);

}

//action for double clicking on a selection on the LibraryListView
void Winters_GateDialog::OnLibraryListBoxDClick(wxCommandEvent& event){
    string library_location = "C:\\Users\\Carl\\Music";
    stringvec v;
    read_directory(library_location, v);

    int posOfLibrary = LibraryListBox->GetSelection();
    string som = v.at(posOfLibrary);

    if(checkIfWAV(som)){
        string stuff = "";
        const char* chars = stuff.c_str();
        wxString wxStringItem = wxString::FromUTF8(chars);
        StaticText1->SetLabel(wxStringItem);
    }

    playMusic(som);


}




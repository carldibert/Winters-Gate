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
#include <portaudio.h>
#include <boost/filesystem.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <portaudio.h>
#include <SFML/Audio.hpp>
//(*InternalHeaders(Winters_GateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

using namespace std;
using namespace boost::filesystem;

typedef std::vector<std::string> stringvec;

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
const long Winters_GateDialog::ID_LISTBOX1 = wxNewId();
const long Winters_GateDialog::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Winters_GateDialog,wxDialog)
    //(*EventTable(Winters_GateDialog)
    //*)
END_EVENT_TABLE()

void makeBoxes(){

}

Winters_GateDialog::Winters_GateDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Winters_GateDialog)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Winter\'s Gate"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(716,602));
    SetMaxSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    ListBox2 = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxSize(338,274), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    BoxSizer2->Add(ListBox2, 10, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Artist\nAlbum\nTrack\nYear\nTrack Number\nComment"), wxDefaultPosition, wxSize(182,78), 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(303,186), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer3->Add(ListBox1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Sample Play Button"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Winters_GateDialog::OnQuit);
    //*)
}

Winters_GateDialog::~Winters_GateDialog()
{
    //(*Destroy(Winters_GateDialog)
    //*)
}

void Winters_GateDialog::OnQuit(wxCommandEvent& event)
{
    wxString myString = wxString::FromUTF8("Changed");
    StaticText1->SetLabel(myString);

    //sf::SoundBuffer buffer;
    //if(!buffer.loadFromFile("K:\\Sample Library\\FLAC\\Amorphis\\Albums\\(2015) Under the Red Cloud\\01 Under the Red Cloud.flac"));

    wstring stemp = wstring("K:\\Sample Library\\03 Dreamwalkers.wav".begin(), "K:\\Sample Library\\03 Dreamwalkers.wav".end());
    const wchar_t* zname = stemp.c_str();

    PlaySound(zname, NULL, SND_FILENAME);

}

//reads from directory and adds all files to a vector if the file is a mp3 file
void read_directory(const std::string& name, stringvec& v){
    //string pattern(name);
    //pattern.append("\\*");
    //WIN32_FIND_DATA data;
    //HANDLE hFind;
    //string file_location;
    //string file_location_explicit;
    //string file_location_parent;
    //wstring stemp = wstring(pattern.begin(), pattern.end());
    //const wchar_t* zname = stemp.c_str();
    //hFind = FindFirstFile(zname, &data);
    //if (hFind != INVALID_HANDLE_VALUE){
        //do {
            //file_location = name + "\\" + data.cFileName;
            //file_location.append(name);
            //file_location.append("\\");
            //file_location += data.cFileName;
            //data.cFileName
            //file_location.append(data.cFileName);
            //file_location_explicit = name + "\\.";
            //file_location_parent = name + "\\..";

            //path dir = file_location;

            //if(is_directory(dir) && file_location == file_location_explicit){
            //} else if(is_directory(dir) && file_location == file_location_parent){
            //} else if(is_directory(dir)){
                //read_directory(file_location, v);
            //} else {
                //if(checkIfMP3(file_location)){
                    //v.push_back(file_location);
                //}
            //}
        //}while(FindNextFile(hFind, &data) != 0);
        //FindClose(hFind);
        //}
    //};
}
//populates the library with all of the files
void Winters_GateDialog::PopulateListBox(){
    string library_location = "C:\\Users\\Carl\\Music";
    stringvec v;
    read_directory(library_location, v);
}

void Winters_GateDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Winters_GateDialog::OnLibrary_List_BoxSelect(wxCommandEvent& event)
{
}

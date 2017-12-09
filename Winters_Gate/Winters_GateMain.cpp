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
#include <boost/filesystem.hpp>
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

void makeBoxes(){

}

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
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Artist\nAlbum\nTitle\nYear\n"), wxDefaultPosition, wxSize(265,186), 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(StaticText1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PauseButton = new wxButton(this, ID_BUTTON2, _("Pause"), wxDefaultPosition, wxSize(114,88), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(PauseButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StopButton = new wxButton(this, ID_BUTTON1, _("Stop"), wxDefaultPosition, wxSize(111,49), 0, wxDefaultValidator, _T("ID_BUTTON1"));
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
    wxString myString = wxString::FromUTF8("Changed");
    const char* chars = "hello";
    wxString newString = wxString::FromUTF8(chars);
    StaticText1->SetLabel(newString);
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

void Winters_GateDialog::OnLibraryListBoxSelect(wxCommandEvent& event)
{
}

void Winters_GateDialog::OnLibraryListBoxDClick(wxCommandEvent& event)
{
}




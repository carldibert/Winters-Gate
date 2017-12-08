/***************************************************************
 * Name:      Test_ProjectMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Carl Dibert ()
 * Created:   2017-12-07
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#include "Test_ProjectMain.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/string.h>

//(*InternalHeaders(Test_ProjectDialog)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

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
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Test_ProjectDialog)
const long Test_ProjectDialog::ID_STATICTEXT1 = wxNewId();
const long Test_ProjectDialog::ID_BUTTON1 = wxNewId();
const long Test_ProjectDialog::ID_STATICLINE1 = wxNewId();
const long Test_ProjectDialog::ID_BUTTON2 = wxNewId();
const long Test_ProjectDialog::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Test_ProjectDialog,wxDialog)
    //(*EventTable(Test_ProjectDialog)
    //*)
END_EVENT_TABLE()

Test_ProjectDialog::Test_ProjectDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Test_ProjectDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to\nwxWidgets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Test_ProjectDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Test_ProjectDialog::OnQuit);
    //*)
}

Test_ProjectDialog::~Test_ProjectDialog()
{
    //(*Destroy(Test_ProjectDialog)
    //*)
}

void Test_ProjectDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Test_ProjectDialog::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    //wxMessageBox(msg, _("Welcome to..."));

     wxFileDialog openFile(this, wxT("Open File"));
     wxString mystring = wxString::FromUTF8("C:\\users\\");
     openFile.SetDirectory(mystring);
     openFile.ShowModal();
}

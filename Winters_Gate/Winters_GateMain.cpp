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
//(*InternalHeaders(Winters_GateDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

using namespace std;
using namespace boost::filesystem;

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

//(*IdInit(Winters_GateDialog)
const long Winters_GateDialog::ID_TREECTRL1 = wxNewId();
const long Winters_GateDialog::ID_TEXTCTRL1 = wxNewId();
const long Winters_GateDialog::ID_BUTTON1 = wxNewId();
const long Winters_GateDialog::ID_STATICTEXT1 = wxNewId();
const long Winters_GateDialog::ID_STATICBITMAP1 = wxNewId();
const long Winters_GateDialog::ID_LISTBOX1 = wxNewId();
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
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Winter\'s Gate"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(516,311));
    SetMaxSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    TreeCtrl1 = new wxTreeCtrl(this, ID_TREECTRL1, wxDefaultPosition, wxSize(239,248), wxTR_LINES_AT_ROOT|wxTR_HIDE_ROOT|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    wxTreeItemId TreeCtrl1_Item1 = TreeCtrl1->AddRoot(_T("root"));
    wxTreeItemId TreeCtrl1_Item2 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("item 1"));
    wxTreeItemId TreeCtrl1_Item3 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("item 2"));
    wxTreeItemId TreeCtrl1_Item4 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("item 3"));
    wxTreeItemId TreeCtrl1_Item5 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("item 4"));
    wxTreeItemId TreeCtrl1_Item6 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("item 5"));
    for(int i=0; i<3; i++){
        wxTreeItemId TreeCtrl1_Item6 = TreeCtrl1->AppendItem(TreeCtrl1_Item1, _T("item 5"));
    }

    makeBoxes();
    TreeCtrl1->ScrollTo(TreeCtrl1_Item2);
    BoxSizer2->Add(TreeCtrl1, 6, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetToolTip(_("Filter"));
    TextCtrl1->SetHelpText(_("Filter"));
    BoxSizer7->Add(TextCtrl1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Filter"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer7->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Artist\nAlbum\nTrack\nYear\nTrack Number\nComment"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText1, 10, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(67,72), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    BoxSizer4->Add(StaticBitmap1, 5, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(241,186), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer3->Add(ListBox1, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();
    Center();

    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_BEGIN_DRAG,(wxObjectEventFunction)&Winters_GateDialog::OnTreeCtrl1BeginDrag);
    //*)
}

Winters_GateDialog::~Winters_GateDialog()
{
    //(*Destroy(Winters_GateDialog)
    //*)
}

void Winters_GateDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Winters_GateDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Winters_GateDialog::OnLibrary_List_BoxSelect(wxCommandEvent& event)
{
}

void Winters_GateDialog::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void Winters_GateDialog::OnTreeCtrl1BeginDrag(wxTreeEvent& event)
{
}

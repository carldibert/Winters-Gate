/***************************************************************
 * Name:      Winters_GateMain.h
 * Purpose:   Defines Application Frame
 * Author:    Carl Dibert ()
 * Created:   2017-11-10
 * Copyright: Carl Dibert ()
 * License:
 **************************************************************/

#ifndef WINTERS_GATEMAIN_H
#define WINTERS_GATEMAIN_H

//(*Headers(Winters_GateDialog)
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Winters_GateDialog: public wxDialog
{
    public:

        Winters_GateDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Winters_GateDialog();

    private:

        //(*Handlers(Winters_GateDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLibrary_List_BoxSelect(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(Winters_GateDialog)
        static const long ID_TREECTRL1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICBITMAP1;
        static const long ID_LISTBOX1;
        //*)

        //(*Declarations(Winters_GateDialog)
        wxButton* Button1;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText1;
        wxTreeCtrl* TreeCtrl1;
        wxTextCtrl* TextCtrl1;
        wxListBox* ListBox1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WINTERS_GATEMAIN_H
